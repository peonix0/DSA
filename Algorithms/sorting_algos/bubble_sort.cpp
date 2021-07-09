// Repeatedly swap to adjacents element of unsorted array if they are in wrong order


#include<iostream>
using namespace std;

void sortme(int *arr, int size){

  for(int i=0;i<size-1;i++){
    for(int j=1;j<size-i;j++){
      if(arr[j-1]>arr[j]){
        swap(arr[j-1],arr[j]);
      } // this loop put the largest element at end of unsorted array([0,i])
    }
  }
}


int main(){
  int arr[9] = {1,2,5,-1,-9,0,2,7,4};
  sortme(arr,9);

  for(auto i : arr){
    cout <<i<<" ";
  }
}
