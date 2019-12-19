#include <iostream>
// Linear Search
using namespace std;
void Linear_Search(int arr[], int searched_elem, int length_arr){
    int flag =0;
    for(int i=0;i<length_arr;i++){
        if(searched_elem==arr[i]){
            cout<<"Searched elem is:"<<searched_elem<<" and it is on position:"<<i<<endl;
            flag=1;
        }
}
if(flag==0){
cout<<"The element you are searching for is not present in the array"<<endl;
}
return;
}
int main(){
int arr[]={10,20,3,8,6,44,21};
int length_arr = sizeof(arr)/sizeof(arr[0]);
Linear_Search(arr,21,length_arr);
    return 0;
}
