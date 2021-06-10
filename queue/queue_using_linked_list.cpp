#include <iostream>
#include <climits>
using namespace std;

struct node{
  int data;
  node *nxt;
};

struct queue{
  node *front;
  node *rear;
};

queue *createQueue(){
  queue *Q = new(nothrow) queue;
  if(!Q) {
    cout <<"~ Memory error ~\n";
    return NULL;
  }
  Q->rear = NULL;
  Q->front = NULL;
  return Q;
}

bool isEmpty(queue *Q){
  return(Q->rear == NULL && Q->front == NULL);
}

int size(queue *Q){
  node* temp = Q->front;
  int Count=0;
  if(isEmpty(Q)){
    return 0;
  }
  while(temp!= Q->rear){
    temp = temp->nxt;
    Count++;
  }
  return Count+1;
}

void enqueue(queue *Q, int data){
  node *newnode = new(nothrow) node;
  if(!newnode){
    cout <<"~ Memory Error ~";
    return ;
  }
  newnode->data = data;
  newnode->nxt = NULL;
  if(isEmpty(Q)){
    Q->rear = Q->front = newnode;
  }
  else{
    Q->rear->nxt = newnode;
    Q->rear = newnode;
  }

}

int dequeue(queue *Q){
  if(isEmpty(Q)){
    cout <<"~ Queue is empty ~\n";
    return INT_MIN;
  }
  int data = Q->front->data;
  node *temp = Q->front;
  if(Q->front == Q->rear)  //only one element in queue
  {
    Q->front = Q->rear = Q->front->nxt;
  }
  else{
    Q->front = Q->front->nxt;
  }
  //cout <<"~ Front element dequeued ~\n";
  delete(temp);
  return data;
}

void deleteQueue(queue *Q){
  node *temp = Q->front;
  while(temp){
    temp = temp->nxt;
    delete(temp);
  }
  delete(Q);
  cout <<"~ Queue deleted ~\n";
}

void printQueue(queue *Q){
  if(isEmpty(Q)){
    cout<<"~ Queue is empty ~\n";
    return ;
  }
  cout <<"Queue: ";
  node *temp = Q->front;
  while(temp){
    cout <<temp->data<<" ";
    temp = temp->nxt;
  }
  cout <<"\n";
}


//test
int main(){
  queue *Q = createQueue();
  enqueue(Q,1);
  enqueue(Q,2);
  enqueue(Q,3);
  enqueue(Q,4);
  enqueue(Q,5);
  printQueue(Q);
  cout <<"Size: "<<size(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  enqueue(Q,9);
  enqueue(Q,8);
  enqueue(Q,7);
  printQueue(Q);
  cout <<"Size: "<<size(Q)<<"\n";
  cout << "Dequeue:"<<dequeue(Q)<<"\n";
  
  enqueue(Q,10);
  printQueue(Q);


}
