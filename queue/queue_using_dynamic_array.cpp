#include <iostream>
#include <climits>
using namespace std;

struct queue{
  int front,rear;
  int capacity;
  int *array;
};

queue *create_queue(int capacity){

  queue *Q = (queue*)malloc(sizeof(queue));
  if(!Q){return NULL;}

  Q->front = Q->rear = 0;
  Q->capacity = capacity;
  Q->array = (int*)malloc(sizeof(int));
  if(!Q->array){return NULL;}
  return Q;
}


int size(queue *Q){
  return (Q->rear - Q->front);
}
bool isFull(queue *Q){
  return(Q->rear-Q->front == Q->capacity);
}
bool isEmpty(queue *Q){
  return(Q->rear == Q->front);
}

void resizeQueue(queue *Q){
  int prev_c = Q->capacity;
  Q->capacity = Q->capacity*2;
  Q->array = (int*)realloc(Q->array, sizeof(int)*Q->capacity);
  if(!Q){cout <<"Memory Error"; return ;}

  if(Q->front>Q->rear){
    for(int i=0;i<Q->capacity;i++){
      Q->array[i+prev_c] = Q->array[i];
    }
    Q->rear += prev_c;
  }
}

//Adding element to queue
void enqueue(queue *Q, int data){
  if(isFull(Q)){
    cout <<"~ Queue is Full, resized to double capacity ~\n";
    resizeQueue(Q);
  }
  int CI = Q->rear%Q->capacity;   //circular index
  Q->array[CI] = data;
  Q->rear = CI+1;

}

// Removing and return first inserted element
int dequeue(queue *Q){
  if(isEmpty(Q)){
    cout<<"~ Queue is empty ~";
    return INT_MIN;
  }

  int CI = Q->front%Q->capacity;
  int data = Q->array[CI];
  Q->front = CI+1;
  return data;
}

void delete_queue(queue* Q){
  if(Q){
    if(Q->array){
      free(Q->array);
    }
    free(Q);
    cout <<"~ Queue deleted ~\n";
  }
}

//test

int main(){
  queue *Q = create_queue(5);
  enqueue(Q,5);
  enqueue(Q,4);
  enqueue(Q,3);
  enqueue(Q,2);
  cout << "Size: "<<size(Q)<<"\n";
  cout <<"capacity: "<<Q->capacity<<"\n";
  enqueue(Q,1);
  enqueue(Q,0);

  cout << "Size: "<<size(Q)<<"\n";
  cout <<"capacity: "<<Q->capacity<<"\n";

  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout <<"Dequeue: "<< dequeue(Q)<<"\n";
  cout << "Size: "<< size(Q)<<"\n";

  delete_queue(Q);


}
