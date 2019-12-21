#include <iostream>
//Structura coada cu liste inlantuite
using namespace std;
//Aspectul nodurilor listei inlantuite.
class NodCoada{
private:
int informatie;
NodCoada* urmatorul;
NodCoada*inceput_coada,*sfarsit_coada;
public:
    NodCoada* nodNou(int informatie);
    NodCoada* CreareCoada();
    void Adaugare_In_Coada(NodCoada*coada,int informatie);
    void Afisare_Coada(NodCoada*coada);
    NodCoada*Stergere_Din_Coada(NodCoada*coada);
    void PrimulNod(NodCoada*coada);
    void UltimulNod(NodCoada*coada);
};
//functie care creaza un nod nou in lista inlantuita
NodCoada* NodCoada::nodNou(int info){
NodCoada*temporar=new NodCoada; // am alocat memeorie pentru un nod nou
temporar->informatie=info;// am adaugat o valoare in noul nod creat
temporar->urmatorul=NULL;//noul nod nu pointeaza catre nimic
return temporar;
}
//creare coada
NodCoada*NodCoada::CreareCoada(){
NodCoada*coada=new NodCoada;
coada->inceput_coada=NULL;
coada->sfarsit_coada=NULL;
return coada;
}
//nodNou(info)- este o functie care este apelata in Adaugare_In_Coada.
//Aadaugare in coada
void NodCoada::Adaugare_In_Coada(NodCoada*coada,int info){
NodCoada*temporar=nodNou(info);//am apelat functia care creaza un nod nou si am salvat adresa in pointerul temporar
//cazul daca coada are un singur element inseamna ca sfarsitul si inceputul  cozii este acelasi.
if(coada->sfarsit_coada==NULL){
    coada->inceput_coada=temporar;
    coada->sfarsit_coada=temporar;
    return;
}
//adaugam un nod nou la sfarsitul cozii si schimbam sfarsitul cozii
coada->sfarsit_coada->urmatorul=temporar;//penultimul nod din coada
coada->sfarsit_coada=temporar;//sfarsitul cozii
}
//stergere nod din coada
NodCoada* NodCoada::Stergere_Din_Coada(NodCoada*coada){
//verificam daca coada este nula
if(coada->inceput_coada==NULL){
    cout<<"Coada este nula"<<endl;
    return NULL;
}
//stocheaza inceputul anterior si muta inceputul  cu un nod in fata
NodCoada*temp=coada->inceput_coada;
coada->inceput_coada=coada->inceput_coada->urmatorul;
//daca inceputul este null atunci si sfarsitul este null
if(coada->inceput_coada==NULL){
    coada->sfarsit_coada=NULL;
}
cout<<"Elementul sters este:"<<temp->informatie;
return temp;
}
void NodCoada::PrimulNod(NodCoada*coada){
cout<<coada->inceput_coada->informatie;
}
void NodCoada::UltimulNod(NodCoada*coada){
cout<<coada->sfarsit_coada->informatie;
}
//primul nod din coada
//afisare elemente coada
void NodCoada::Afisare_Coada(NodCoada*coada){
NodCoada*temp=coada->inceput_coada;
cout<<"Elementele cozii sunt:";
while(temp!=NULL){
cout<<temp->informatie<<" ";
temp=temp->urmatorul;
}
return;
}

int main()
{NodCoada *coada=NULL;
coada=coada->CreareCoada();
coada->Adaugare_In_Coada(coada,11);
coada->Adaugare_In_Coada(coada,12);
coada->Adaugare_In_Coada(coada,13);
coada->Adaugare_In_Coada(coada,14);
coada->Afisare_Coada(coada);
cout<<endl;coada->Stergere_Din_Coada(coada);
cout<<endl;coada->Afisare_Coada(coada);
coada->Adaugare_In_Coada(coada,15);
cout<<endl;coada->Afisare_Coada(coada);
cout<<endl<<"Primul nod este:";
coada->PrimulNod(coada);
cout<<endl<<"Ultimul nod este:";
coada->UltimulNod(coada);
    return 0;
}
