#include <iostream>

using namespace std;
void Interschimbare(int *x,int *y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}
void SelectionSort(int A[],int n){
int MIN;
for(int i=0;i<n;i++){
    MIN=i;
    for(int j=i+1;j<n;j++){
        if(A[MIN]>A[j]){
            MIN=j;
        }
    }
    Interschimbare(&A[MIN],&A[i]);
}

}
int main()
{int A[200],n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>A[i];
}
SelectionSort(A,n);
for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
}
    return 0;
}
