#include <iostream>

using namespace std;
int Maxim(int A[],int n){
int maxim=A[0];
for(int i=1;i<n;i++){
    if(maxim<A[i])
       maxim=A[i];
}
return maxim;
}
int main()
{int A[200],n,rezultat;
cout<<"Dati dimensiunea vectorului:";
cin>>n;
cout<<"Dati elementele vectorului:";
for(int i=0;i<n;i++){
    cin>>A[i];
}
rezultat = Maxim(A,n);
cout<<"Maximul este:"<<rezultat;

    return 0;
}
