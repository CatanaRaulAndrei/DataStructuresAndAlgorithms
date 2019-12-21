#include <iostream>
#include <stdlib.h>
using namespace std;
//LISTA SIMPLU INLANTUITA
//un nod este defapt o structura;
//un nod este alcatuit din informatie(informatia poate fi de orice tip) si un pointer(pointerul este de tipul structurii);
struct NOD{
 int info;
 NOD *leaga;
};

//FUNCTIA DE ADAUGARE LA INCEPUT
NOD*AdaugareInceput(NOD*inceput,int num){
if(inceput==NULL){          //daca nodul este primul nod din lista
   NOD*temp=new NOD;        //alocam memorie pentru nod
   temp->info=num;          //adaugam un tip de data in nod
   temp->leaga=NULL;       //nodul este singur in lista deci in fata lui este NULL
   inceput=temp;           //am salvat in inceput adresa lui temp acum inceput este legat de primul nod din lista
   return inceput;        //returnez primul nod;
}
else{NOD*temp=new NOD;       //am alocat memorie pentru urmatorul nod
     temp->info=num;          //am adaugat un tip de data in nod
     temp->leaga=inceput;     //am legat nodul nou de fostul nod care a fost primul
     inceput=temp;           //am legat inceput de noul nod
     return inceput;         //returnez noul nod care este acum primul
}
return inceput;              //returnez nodul care este acum primul
}

//FUNCTIA DE AFISARE A LISTEI
void Afisare(NOD*inceput){
if(inceput==NULL){
        cout<<"Lista este vida"<<endl;
}
NOD*p;                      //pointerul p strabate lista
p=inceput;                 //acum p are aces la lista pentru ca inceput ia dat adresa primul nod din lista
while(p!=NULL){            //pana cand nu ajunge la finalul listei (pana cand intalneste pointerul null)
    cout<<p->info<<" ";   //afisaez elementele listei
    p=p->leaga;           //traversez lista
}
}

//FUNCTIA DE ADAUGARE LA FINALUL LISTEI
void AdaugareFinal(NOD*inceput ,int num){
NOD*p ;                         //pointerul p traverseaza lista
NOD*temp=new NOD;               //am alocat memorie pentru nodul pe care il voi adauga la finalul listei
p=inceput;                      //pt ca p sa poate parcurge lista avem nevoi de adresa primului element din lista
while(p->leaga!=NULL){
    p=p->leaga;                 //traversam lista
}
temp->info=num;                 //umplem nodul cu un tip de data
temp->leaga=NULL;               //pointeaza catre null pentru ca este ultimul nod al listei
p->leaga=temp;                  //legam ultimul nod de penultimul
}

//FUNCTIA DE STERGERE A NODURILOR DIN LISTA
NOD*Stergere(NOD*inceput,int num){
    NOD*temp,*p;                     //pointerul temp se utilizeaza pentru a salva elementul care va fi sters
                                    //pointerul p traverseaa lista
   if(inceput->info==num){         //numarul care trebuie sters este exact primul
    temp=inceput;
    inceput=temp->leaga;
    delete temp;
    return inceput;
   }
   else{                               //numarul care trebuie stars este oricare altul exceptand primul
    p=inceput;
    while(p->leaga!=NULL){
        if(p->leaga->info==num){       //daca urmatorul nod este nodul care trebuie sters
          temp=p->leaga;               //in temp se salveaza adresa elementului care trebuie sters
          p->leaga=temp->leaga;        //se reface legatura dintre noduri
          delete temp;                 //se elibereaza memoria
          return inceput;              //se returneza lista fara elementul sters
        }
        p=p->leaga;                    //traverseaza lista
    }
   }
 cout<<"Elementul pe care vrei sa il stergi nu se alfa in lista"<<endl;
 return inceput;
}

//FUNCTIE DE CAUTARE

void Cautare(NOD*inceput,int num){
NOD*p;
p=inceput;
while(p!=NULL){
    if(p->info==num){
       cout<<num<<" este elementul cautat";
       return;
    }
    p=p->leaga;
}
cout<<"Elementul cautat nu se afla in lista"<<endl;
return;
}

//FUNCTIA DE ADAUGARE INAINTEA UNUI NOD
NOD*AdaugareInainte(NOD*inceput,int num,int num1){
NOD* temp,*p;
                                //cand adaugam un nod inaintea primului nod
if(inceput->info==num1){
   temp=new NOD;                //se formeaza un nod nou
   temp->info=num;                 //se umple cu un tip de data
   temp->leaga=inceput;          //se face lagatura dintre noul inceput si vechiul inceput
   inceput=temp;                 //in inceput se stocheaza adresa noului nod care este acum primul
   return inceput;                   //returnam lista cu noul nod adaugat care este acum primul
}
else{                                //cand nodul pe care vrem sa il adugam se adauga inaintea oricarui nod din lista
     p=inceput;                      //acum p are acces la lista
     while(p->leaga!=NULL){
      if(p->leaga->info==num1){      //ne oprim inaintea nodululi inaintea caruia vrem sa adaugam nodul nou
         temp=new NOD;                //alocam memorie pentru nodul nou
         temp->info=num;               //umplem nodul cu o valoare
         temp->leaga=p->leaga;          //acum se face lagatura dintre nodul din fata si nodul nou
         p->leaga=temp;                  //acum se face lagatura dintre nodul din spata si nodul nou
         return inceput;
      }
      p=p->leaga;                       //se parcurge lista
     }
}
cout<<num1<<" nu se afla in lista"<<endl;
return inceput;
}
//FUNCTIA DE ADAUGRE DUPA UN NOD

void AdaugareDupa(NOD*inceput,int num,int num1){
NOD*temp,*p;
p=inceput;
while(p!=NULL){
    if(p->info==num1){
     temp=new NOD;
     temp->info=num;
     temp->leaga=p->leaga;
     p->leaga=temp;
     return;
    }
    p=p->leaga;
}
cout<<num1<<" nu se afla in lista"<<endl;
return;
}
//FUNCTIA CARE ARATA NUMARUL DE NODURI DIN LISTA
unsigned NumarNoduri(NOD*inceput){
unsigned contor=0;
NOD*p;
p=inceput;
while(p!=NULL){
  contor=contor+1;
  p=p->leaga;
}
return contor;
}
int main()
{NOD*inceput=NULL;
 int alegere,num,num1;
 while(1){
   cout<<"\n1.Adaugare la inceputul listei"<<endl;
   cout<<"2.Adaugare la finalul listei"<<endl;
   cout<<"3.Afisarea listei"<<endl;
   cout<<"4.Stergerea unui element din lista"<<endl;
   cout<<"5.Cautare"<<endl;
   cout<<"6.Adaugare dupa un nod"<<endl;
   cout<<"7.Adaugare inaintea unui nod"<<endl;
   cout<<"8.Numarul total de noduri din lista"<<endl;
   cout<<"9.Iesire"<<endl;
   cout<<"Introduce-ti optiunea"<<" ";
   cin>>alegere;
   switch(alegere){
   case 1:{
           cout<<"Dati un numar sa fie adaugat"<<endl;
           cin>>num;
           inceput=AdaugareInceput(inceput,num);
           break;
          }
   case 2:{cout<<"Dati numarul pe care vreti sa il adugati la finalul listei"<<endl;
           cin>>num;
           AdaugareFinal(inceput,num);
           break;
          }
   case 3:{
           Afisare(inceput);
           break;
          }
   case 4:{cout<<"Introduce-ti elementul pe care vreti sa il stergeti din lista"<<endl;
           cin>>num;
           inceput=Stergere(inceput,num);
           break;
          }
   case 5:{cout<<"Dati numarul pe care vreti sa il cautati"<<endl;
           cin>>num;
           Cautare(inceput,num);
           break;
          }
   case 6:{
           cout<<"Introduce-ti elementul pe care vreti sa il adaugati"<<endl;
           cin>>num;
           cout<<"Introduce-ti elementul dupa care se va adauga"<<endl;
           cin>>num1;
           AdaugareDupa(inceput,num,num1);
           break;
           }
   case 7:{
           cout<<"Introduce-ti elementul pe care vreti sa il adaugati"<<endl;
           cin>>num;
           cout<<"Introduce-ti elementul inaintea caruia se va adauga"<<endl;
           cin>>num1;
           inceput=AdaugareInainte(inceput,num,num1);
           break;
           }

   case 8:{
           cout<<"Avem "<<NumarNoduri(inceput)<<" noduri in lista"<<endl;
           break;
          }
   case 9:{
           exit(1);
          }
   default :{
             cout<<"Alegere gresita ,incearca din nou"<<endl;
            }
   }
 }

    return 0;
}
