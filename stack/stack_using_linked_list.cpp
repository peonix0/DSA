#include<iostream>
#include<climits>
using namespace std;

struct node{
  int data;
  node *prev;
};

struct stack{
  node *top;
  int size;
};

stack *create_stack(){
  stack *S = (stack*)malloc(sizeof(stack));
  if(!S){
    return NULL;
  }
  S->top = NULL;
  S->size = 0;
  return S;
}

bool isEmpty(stack *S){
  return(S->top==NULL);
}
int size(stack *S){
  return(S->size);
}

void push(stack *S, int data){
  node *temp;
  temp = (node*)malloc(sizeof(node));
  if(!temp){
    return ;
  }
  temp->data = data;
  temp->prev = S->top;
  S->top  = temp;
  S->size++;

}

int pop(stack *S){
  node *temp;
  temp = S->top;
  if(isEmpty(S)){
    cout <<"No element in stack";
    return INT_MIN;
  }
  int data = temp->data;
  S->top = temp->prev;
  free(temp);
  S->size--;
  return data;
}

int top(stack * S){
  if(isEmpty(S)){
    cout <<"No element in stack";
    return INT_MIN;
  }
  return (S->top->data);

}

void delete_stack(stack *S){
  if(!S){
    node *temp = S->top;
    while(!temp){
      free(temp);
      temp = temp->prev;
    }
    free(S);
  }
  cout<<"~ Stack deleted ~\n";
}

//test

int main(){
  stack *S = create_stack();
  push(S,5);
  push(S,7);
  push(S,11);
  push(S,10);
  push(S,9);
  push(S,12);
  cout <<top(S)<<"\n";

  cout << "Pop: "<<pop(S)<<"\n";
  push(S,12);
  cout <<top(S)<<"\n";
  cout <<"Size: "<<size(S)<<"\n";
  delete_stack(S);


}
