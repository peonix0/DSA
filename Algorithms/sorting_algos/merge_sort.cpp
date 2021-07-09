#include<iostream>
using namespace std;


void merge(int *A, int l, int mid, int r){
  int n1 = mid-l+1;
  int n2 = r - mid;

  int a[n1];
  int b[n2];

  for(int i=0;i<n1;i++){
    a[i] = A[l+i];
  }

  for(int i=0;i<n2;i++){
    b[i] = A[mid+1+i];
  }

  int i=0;
  int j=0;
  int k=l;
  while(i<n1 && j<n2){
    if(a[i]<=b[j]){
      A[k] = a[i];
      k++;
      i++;
    }
    else{
      A[k] = b[j];
      j++; k++;
    }

  }
  while(i<n1){
    A[k] = a[i];
    k++;
    i++;
  }
  while(j<n1){
    A[k] = b[j];
    k++;
    j++;
  }
}

void mergeSort(int *A, int l, int r){

  if(l<r){
    int mid = (l+r)/2;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,r);

    merge(A,l,mid,r);
  }

}


int main(){
  int A[] = {1,2};
  mergeSort(A,0,1);
  for(int i=0;i<2;i++){
    cout << A[i]<<" ";
  }

}
