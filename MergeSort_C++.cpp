#include <iostream>

using namespace std;
void Merge(int A[],int s,int mid,int d){
int i,j,k;

//dimensiunea tabloului temporar L[] la stanga
int n1=mid-s+1;

//dimensiunea tabloului temporar R[] la dreapta
int n2=d-mid;

//tablourile temporare
int L[n1],R[n2];

//partea stanga
for(i=0;i<n1;i++){
    L[i]=A[s+i];
}

//partea dreapta
for(j=0;j<n2;j++){
    R[j]=A[mid+1+j];
}
//concatenam
i=0;
j=0;
k=s;
while(i<n1&&j<n2){
    if(L[i]<=R[j]){
        A[k]=L[i];
        i++;
    }
    else{
         A[k]=R[j];
        j++;
    }
    k++;
}
//cautam dupa elementele ramase sa le adugam in array
//partea stanga
while(i<n1){
    A[k]=L[i];
    i++;
    k++;
}
//partea dreapta
while(j<n2){
    A[k]=R[j];
    j++;
    k++;
}
}

void MergeSort(int A[],int s,int d){
    if(s<d){
    int mid=(s+d)/2;
    //stanga
    MergeSort(A,s,mid);
    //dreapta
    MergeSort(A,mid+1,d);
    //uniunea lor (concatenarea lor)
    Merge(A,s,mid,d);
    }
}

int main()
{int A[200],n;
cout<<"Dati dimensiunea Arry-ului:";
cin>>n;
cout<<"Dati elementele Array-ului"<<endl;
for(int i=0;i<n;i++){
    cin>>A[i];
}
MergeSort(A,0,n-1);
cout<<"Elementele sortate cu  Algoritmul MergeSort sunt:"<<endl;
for(int i=0;i<n;i++){
    cout<<A[i]<<" ";
}


    return 0;
}
