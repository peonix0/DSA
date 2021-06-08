#include<iostream>
#include<climits>
using namespace std;

struct stack{
  int top;
  int capacity;
  int *array;
};

stack  *create_stack(int capacity){
  stack *S = (stack*)malloc(sizeof(stack));
  if(!S){return NULL;}
  else{
    S->capacity = capacity;
    S->top = -1;
    S->array = (int *)malloc(capacity*sizeof(int));
    if(!S->array){return NULL;}
    return S;
  }
}

int size(stack *S){
  return (S->top+1);
}

bool isEmpty(stack *S){
  return(S->top == -1);
}
bool isFull(stack *S){
  return(S->top == S->capacity-1 );
}

//add element at top of stack
void push(stack *S, int data){
  if(isFull(S)){
    cout <<"~ Stack is full, can't push anymore ~\n";
    return;
  }
  S->top +=1;
  S->array[S->top] = data;
}

// remove top most element
int pop(stack *S){
  if(isEmpty(S)){
    cout <<"~ Stack is empty ~\n";
    return INT_MIN;
  }
  int data = S->array[S->top];
  S->top -=1;
  return data;
}

//return top most element without removing it
int top(stack *S){
  if(isEmpty(S)){
    cout <<"~ Stack is empty ~\n";
    return INT_MIN;
  }
  return S->array[S->top];
}


void delete_stack(stack *S){
  if(S){
    if(S->array){
      free(S->array);
    }
    free(S);
    cout <<"~ Stack deleted ~\n";
  }
}




//test

// int main(){
//   stack *S = create_stack(5);
//   push(S,5);
//   push(S,7);
//   push(S,11);
//   push(S,10);
//   push(S,9);
//   push(S,12);
//   cout <<top(S)<<"\n";
//   cout <<"Capacity: "<< S->capacity<<"\n";
//   cout << "Pop: "<<pop(S)<<"\n";
//   push(S,12);
//   cout <<top(S)<<"\n";
//   cout <<"Size: "<<size(S)<<"\n";
//   delete_stack(S);
//
//
// }
