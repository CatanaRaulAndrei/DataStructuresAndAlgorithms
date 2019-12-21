#include <iostream>

using namespace std;
/* A[i] a carui secventa o citim de la tastatura
   n = numarul de elemente din vector
   incepem de la al doi-lea element pentru ca primul e deja sortat
   de aceea vom scrie:
   for j=2 to A.length
   key =A[j] ; // key este variabila care va tine minte elemente din secventa pentru a le ordona
   i=j-1;
   while A[i]>key and i>0 //i>0 pentru ca sa se ordoneze toate valorile
     A[i]>key pentru a vedea daca valoarea din stanga e mai mare ca cea din dreapa
     A[i+1]=A[i];
     i=i-1;// pt. a face toare verificarile de sortare
     A[i+1]=key;
*/

int main()
{int A[100],n=9; // tabloul A poate contine 100 de intregi.El tine doar 9 integi pentru ca n=9.
for(int i=1;i<=n;i++){
    cin>>A[i]; //i ul incepe de la 1 si merge pana la n.Aici da utilizatorul elementele vectorului de la tastatura.
}
for(int j=2;j<=n;j++){ //j-ul incepe de la 2 pentru ca banuim ca primul element este deja sortat corespunzator.
    int key = A[j];
    int i=j-1;
    while(i>0&&A[i]>key){
       A[i+1]=A[i];
       i=i-1;
    }
    A[i+1]=key;
}

for(int i=1;i<=n;i++){
    cout<<A[i]<<" ";
}

    return 0;
}
