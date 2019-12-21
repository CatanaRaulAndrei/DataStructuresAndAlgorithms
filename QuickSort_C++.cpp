#include <iostream>
//Quick Sort implementare
using namespace std;
void Interschimbare(int *x, int *y){
int temp = *y;
*y=*x;
*x=temp;
}
int Partitionare(int *A,int indexInceput,int indexSfarsit){
int pivot = A[indexSfarsit];
int indexPartitionare = indexInceput;
for(int i=indexInceput;i<indexSfarsit;i++){
    if(A[i]<=pivot){
        Interschimbare(&A[i],&A[indexPartitionare]);
        indexPartitionare++;
    }
}
Interschimbare(&A[indexPartitionare],&A[indexSfarsit]);
return indexPartitionare;
}
void Qsort(int *A ,int indexInceput,int indexSfarsit){
if(indexInceput<indexSfarsit){
int indexPartitionare=Partitionare(A,indexInceput,indexSfarsit);
Qsort(A,indexInceput,indexPartitionare-1);
Qsort(A,indexPartitionare+1,indexSfarsit);
}
return;
}
int main()
{int A[8]={7,2,1,6,8,5,3,4};
Qsort(A,0,7);
for(int i=0;i<8;i++){
    cout<<A[i]<<" ";
}

    return 0;
}
