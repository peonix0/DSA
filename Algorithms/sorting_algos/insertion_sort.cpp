// find minimum element in unsorted array and swap it with element at begining

#include<iostream>
using namespace std;

void sortme(int* arr, int size){
  for(int i=1;i<size-1;i++){
    int data = arr[i];
    int j=i;
    while( arr[j-1]>data && j>=0){
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = data;
  }

}

int main(){
  int arr[9] = {1,2,5,-1,-9,0,2,7,4};
  sortme(arr,9);

  for(auto i : arr){
    cout <<i<<" ";
  }
}
