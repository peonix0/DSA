//Bucket sort is mainly useful when input is uniformly distributed over a range.
//sortin number in range(0,1);
#include<iostream>
using namespace std;

struct node{
  float val;
  node *next;
};
node *sorted = NULL;

void sortedInsert(node* current){

  node* temp = sorted;
  while(temp != current && temp){
    if(temp->val > current->val){
      cout <<current<<" ";
      swap(temp->val, current->val);
      cout <<current<<"\n";
    }
    temp = temp->next;
  }
}


void insertionSort(node* head)
{
    if(head==NULL){
      return;
    }
    node* temp = head->next;
    sorted = head;
    while(temp){
      sortedInsert(temp);
      temp = temp->next;
    }

}
void printlist(node *head){
  while(head){
    cout <<head->val<<" ";
    head = head->next;
  }
  cout <<"\n";
}

void bucketSort(float *A, int size){
  node* arr[10];
  for(int i=0;i<10;i++){
    arr[i] = NULL;
  }
  for(int i=0;i<size;i++){
    int index = A[i]*10;
    if(arr[index]){
      node* temp = arr[index];
      while(temp->next){
        temp = temp->next;
      }
      temp->next = new node;
      temp->next->val = A[i];
      temp->next->next = NULL;
    }
    else{
      arr[index] = new node;
      arr[index]->next = NULL;
      arr[index]->val = A[i];
    }
  }

  for(int i=0;i<10;i++){
    insertionSort(arr[i]);
  }

  for(int i=0;i<10;i++){
    printlist(arr[i]);
  }
}

int main(){
  float A[5]= {0.342,0.5343,0.231,0.434,0.01};
  bucketSort(A,5);

}
