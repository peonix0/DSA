#include<iostream>
using namespace std;

int partition(int *A, int l, int r){
  int i=l-1;
  int pivot = A[r];


  for(int j=l; j<r;j++){
    if(A[j] < pivot ){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

void quickSort(int *A, int l, int r){
  if(l<r){
    int pi = partition(A,l,r);

    quickSort(A,l,pi-1);
    quickSort(A,pi+1,r);

  }
}

int main(){
  int A[] = {1,2,-1,9,4,5};
  quickSort(A,0,5);
  for(int i=0; i<6;i++){
    cout<< A[i]<<" ";
  }
}
