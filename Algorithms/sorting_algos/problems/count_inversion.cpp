#include<iostream>
using namespace std;

int bruteforce(int *A, int size){
  int count = 0;

  for(int i=0;i<size-1;i++){
    for(int j=i+1;j<size;j++){
      if(A[i]>A[j]){
        count++;
      }
    }
  }
  return count;
}


int merge(int *A, int l, int mid, int r){
  int inv =0;
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
      inv += n1-i;
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
  return inv;
}

int mergeSort(int *A, int l, int r){
  int inv=0;
  if(l<r){
    int mid = (l+r)/2;
    inv += mergeSort(A,l,mid);
    inv += mergeSort(A,mid+1,r);

    inv += merge(A,l,mid,r);
  }
  return inv;

}


int main(){
  int A[] = {3,5,6,9,1,2,7,8};
  //cout << bruteforce(A,6);
  cout << mergeSort(A,0,7);

}
