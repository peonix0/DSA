#include<iostream>
using namespace std;

void waveSort(int *A, int size){

  for(int i=1;i<size;i=i+2){
    if(A[i]>A[i-1]){
      swap(A[i],A[i-1]);
    }
    if(A[i]>A[i+1] && i < size-1){
      swap(A[i],A[i+1]);
    }

  }
}

int main(){
  int A[] = {1,3,5,0,6};
  waveSort(A,5);

  for(int i=0;i<5;i++){
    cout <<A[i] << " ";
  }
}
