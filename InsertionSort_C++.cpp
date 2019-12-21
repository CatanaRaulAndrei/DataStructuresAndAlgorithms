#include <iostream>

using namespace std;
//Enunt :Sa se sorteze crescator urmatoarele elemente: 54 7 5 90;
/*
Pentru a rezolva aceasta problema folosim algoritmul insertion sort
*/
//INPUT : 54 7 5 90 70
int main()
{int tablou[100],numarul_de_element_din_tablou=5;//tabloul poate gazdui 100 de elemente dar noi vom adauga doar 5 elemente in tablou.Locurile libere se vor complecta cu zerouri.
//dam de la tastatura aceste 5 elemente
for(int contor=1;contor<=numarul_de_element_din_tablou;contor++){
    cin>>tablou[contor];
}

//Elementele nesortate
cout<<"Elementele Nesortate:"<<"\n";
for(int contor=1;contor<=numarul_de_element_din_tablou;contor++){
    cout<<tablou[contor]<<" ";
}
cout<<endl;
//Implementam algoritmul de sortare Insertion Sort.
//inceput insertion sort
for(int j=2;j<=numarul_de_element_din_tablou;j++){
    int element=tablou[j];
    int k;
    for(k=j-1;k>0&&tablou[k]>element;k--){
        tablou[k+1]=tablou[k];
    }
    tablou[k+1]=element;
}
//sfarsit insertion sort

//Afisam elementele sortate
cout<<"Elementele sortate:"<<"\n";
for(int contor=1;contor<=numarul_de_element_din_tablou;contor++){
    cout<<tablou[contor]<<" ";
}
//mijlocul
cout<<"\n"<<"Mijlocul este:"<<"\n";
cout<<tablou[numarul_de_element_din_tablou/2];
//OUTPUT : 5 7 54 70 90

    return 0;
}
