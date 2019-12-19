#include <iostream>

using namespace std;
int Binary_Search(int arr[], int right, int left, int searched){
    int flag=0;
    if(right>=left){
        int middle = left+(right-left)/2;
        if(arr[middle]==searched){
            cout<<"Searched element is:"<<searched<<" to index:"<<middle<<endl;
            flag=1;
        }
        if(arr[middle]>searched){
            flag=1;
            return Binary_Search(arr,middle-1,left,searched);

        }
        if(arr[middle]<searched){
             flag=1;
            return Binary_Search(arr,right,middle+1,searched);
        }
    }
    if(flag==0){
        cout<<"Searched element "<<searched<<" is not present in the array"<<endl;
    }
   return -1;
}
int main()
{int arr[]= {1,2,7,40,44,55,80,111};
 int arr_lenght=sizeof(arr)/sizeof(arr[0]);
 Binary_Search(arr,arr_lenght-1,0,999);

    return 0;
}
