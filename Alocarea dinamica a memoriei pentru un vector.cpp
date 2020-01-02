#include <iostream>
using namespace std;


/*
Alocarea dinamica a memoriei(p,n,temporar) :
	
	1. Initializare
	p=nullptr
	n=valoare
	temporar=0
	
	2. Se aloca memorie dinamic
	p=new int[n]
	
	3. Se insereaza valori in zona de memorie alocata din heap
	pt. i apartine [0,valoare) :
		citeste temporar
		p[i]=temporar
		
*/

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
p=nullptr; // stergem legatura dintre pointer si locatia de memorie stearsa . Pointerul indica catre valoarea 0.
// nullptr este pointerul null , adica pointerul cu valoarea zero. 
  return 0;
}
