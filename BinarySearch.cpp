#include <iostream>

using namespace std;
int BinarySearch(int A[],int n,int s,int d,int x){
    while(d>=s){
        int m=(s+d)/2; //mijlocul listei
        if(A[m]==x){   //daca elementul cautat este elementul din mijloc
            return m;
        }
       if(A[m]<x){   //partea drapata a listei
        s=m+1;
       }
       else{    //partea stanga a listei
        d=m-1;
       }
}
  return -1;
}
int main()
{int A[200],n,x;
cin>>n;
for(int i=0;i<n;i++){
    cin>>A[i];
}
cin>>x;
int rezultat=BinarySearch(A,n,0,n-1,x);
if(rezultat==-1){
    cout<<"Elementul nu se afla in lista";
}
else{
    cout<<"Elementul se afla in lista";
}

    return 0;
}
