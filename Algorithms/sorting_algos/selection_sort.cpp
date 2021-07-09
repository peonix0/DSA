// find minimum element in unsorted array and swap it with element at begining

#include<iostream>
using namespace std;

void sortme(int* arr, int size){

  for(int i=0;i<size-1;i++){
    int min = i;
    for(int j=i+1;j<size;j++){
      if(arr[j]<arr[min]){
        min = j;
      }
    }
    swap(arr[min], arr[i]);
  }

}

int main(){
  int arr[9] = {1,2,5,-1,-9,0,2,7,4};
  sortme(arr,9);

  for(auto i : arr){
    cout <<i<<" ";
  }
}
