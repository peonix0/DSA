// Putting 0's at starting and 2's at last.

#include<iostream>
using namespace std;

void dnfSort(int *A, int size){
  int low=0, mid = 0;
  int high = size-1;

  while(mid != high){
    if(A[mid]==0){
      swap(A[mid],A[low]);
      low++;
    }
    else if(A[mid]==1){
      mid++;
    }
    else{
      swap(A[mid],A[high]);
      high--;
    }
  }
}

int main(){
  int A[] = {1,2,0,0,0,1,1,1,2,2};
  dnfSort(A,10);
  for(int i=0;i<10;i++){
    cout<<A[i]<<" ";
  }
}
