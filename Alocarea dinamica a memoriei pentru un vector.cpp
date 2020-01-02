#include <iostream>
using namespace std;
//Alocarea dinamica a memoriei pentru un vector
int main()
{int* p=nullptr,n,temporar;
cout<<"Dati numarul de elemente ale vectorului:";cin>>n;
p=new int[n];
for(int i=0;i<n;i++){
    cout<<"Dati elementul numarul "<<i+1<<":";
    cin>>temporar;
    p[i]=temporar;//*(p+i)=temporar
}
cout<<"Elementele vecorului sunt:";
for(int i=0;i<n;i++){
    cout<<p[i]<<" ";//*(p+i)
}
delete[] p;//eliberam memoria din heap
p=nullptr;
  return 0;
}
