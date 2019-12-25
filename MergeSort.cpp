#include <iostream>
// Merge Sort
using namespace std;
void Merge(int arr[], int left, int right, int middle){
    int Left[middle-left+1], Right[right-middle];
    // left side
    for(int i=0; i<(middle-left+1); i++){
        Left[i]=arr[left+i];
    }
    // right side
    for(int j=0; j<(right-middle); j++){
        Right[j]=arr[middle+1+j];
    }
    // Left[i] and Right[j] become arr[left...right]
    int i=0,j=0,k=left;
    while((i<middle-left+1) && (j<right-middle)){
        if( Left[i]<=Right[j]){arr[k++]=Left[i++];}
        else{arr[k++]=Right[j++];}
    }
    // copy remaining elements
    while(i<middle-left+1){arr[k++]=Left[i++];}
    while(j<right-middle){arr[k++]=Right[j++];}

}
void MergeSort(int arr[], int left, int right){
    if(left<right){
        int middle = (left+right)/2;
        MergeSort(arr,left,middle); // left half
        MergeSort(arr,middle+1,right); // right half
        Merge(arr,left,right,middle);
    }
}

int main(){
    int arr[]={45,22,88,66,23,1,90,101,86,7};
    int arr_length = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,arr_length-1);
    for(int i=0;i<arr_length;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
