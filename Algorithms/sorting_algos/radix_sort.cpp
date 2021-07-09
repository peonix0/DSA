#include<iostream>
#include<cmath>
using namespace std;

int maxA(int *A, int size){
  int maxE = A[0];
  for(int i=1;i<size;i++){
    if(maxE<A[i]){
      maxE = A[i];
    }
  }
  return maxE;
}

void countSort(int *A, int size, int df){
  int maxE = 9;
  int C[maxE+1]={0};

  for(int i=0;i<size;i++){
    C[(A[i]/df)%10]++;
  }


  for(int i=1;i<=maxE;i++){
    C[i] += C[i-1];
  }

  int B[size];

  for(int i=size-1; i>=0; i--){
    C[(A[i]/df)%10]--;
    B[C[(A[i]/df)%10]] = A[i];
  }
  for(int i=0;i<size;i++){
    A[i] = B[i];
  }
}

void radixSort(int *Arr, int size){
  int maxE = maxA(Arr,size);
  int d = log10(maxE)+1;

  for(int i=1;i<=d;i++){
    int dividingfactor = pow(10,i);
    countSort(Arr,size,dividingfactor);
  }
}

int main(){
  int A[] = {324,325,300,12,1000};
  radixSort(A,5);
  for(int i=0;i<5;i++){
    cout << A[i] <<" ";
  }
}
