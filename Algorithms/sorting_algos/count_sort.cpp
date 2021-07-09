#include<iostream>
using namespace std;

int findMax(int *A,int n){
  int maxE = A[0];
  for(int i=1;i<n;i++){
    if(A[i]>maxE){
      maxE = A[i];
    }
  }
  return maxE;
}

void countSort(int *A, int n){
  int ME = findMax(A,n);
  int C[ME+1]={0};

  for(int i=0;i<n;i++){
    C[A[i]]++;
  }


  for(int i=1;i<=ME;i++){

    C[i] += C[i-1];
  }

  int output[n];
  for(int i=n-1;i>=0;i--){
    C[A[i]]--;
    output[C[A[i]]] = A[i];
  }
  for(int i=0;i<n;i++){
    A[i] = output[i];
  }


}

int main(){
  int A[] = {1,4,2,5,6,7};
  countSort(A,6);
  for(int i=0;i<6;i++){
    cout << A[i]<<" ";
  }
}
