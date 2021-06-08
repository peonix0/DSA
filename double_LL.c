#include<stdio.h>
#include<stdlib.h>
typedef struct listnode {
  int data;
  struct listnode *nxt;
  struct listnode *prev;
}listnode;
listnode *head=NULL;

int is_empty(listnode *head){
  if(head==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

void insert(int data, int position, listnode *head){

  if(is_empty(head)){
    head = (listnode *)malloc(sizeof(listnode));
    head->data = data;
    head->nxt = NULL;
    head->prev = NULL;
  }
  else if(position ==  0){
    listnode *temp;
    temp = head;
    head = (listnode *)malloc(sizeof(listnode));
    head->data = data;
    head->nxt = temp;
    head->prev = NULL;

  }
  else{
    listnode *temp=head, *temp2;
    int pos = 0;
    while(temp!=NULL && pos!= position-1){
      temp = temp->nxt;
      pos++;
    }
    if(pos==position-1){
      temp2 = temp->nxt;
      temp->nxt = (listnode *)malloc(sizeof(listnode));
      temp->nxt->data = data;
      temp->nxt->prev = temp;
      temp->nxt->nxt = temp2;
    }
  }


}
int main(){
  insert(10,0,head);
  insert(20,1,head);
  printf("%d",head->data);
}
