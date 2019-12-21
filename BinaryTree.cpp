#include <iostream>
#include <stdlib.h>
using namespace std;

struct NOD{
int info;
NOD*s;
NOD*d;
};

//ADAUGARE IN ARBORE

NOD* NodNou(int num){
NOD* temp=new NOD;
temp->info=num;
temp->s=NULL;
temp->d=NULL;
return temp;
}

NOD* Adaugare(NOD*radacina,int num){
if(radacina==NULL){
    radacina=NodNou(num);
    return radacina;
}
else if(radacina->info>=num){
    cout<<"Nodul se adauga in stanga"<<endl;
    radacina->s=Adaugare(radacina->s,num);
}
else{
    cout<<"Nodul se adauga la dreapta"<<endl;
    radacina->d=Adaugare(radacina->d,num);
}
return radacina;
}

//PARCURGERI ARBORE

void PreOrdine(NOD* radacina){
if(radacina!=NULL){
   cout<<radacina->info<<" ";
   PreOrdine(radacina->s);
   PreOrdine(radacina->d);
}
return;
}

void PostOrdine(NOD* radacina){
if(radacina!=NULL){
  PostOrdine(radacina->s);
  PostOrdine(radacina->d);
  cout<<radacina->info<<" ";
}
return;
}

void InOrdine(NOD* radacina){
if(radacina!=NULL){
  InOrdine(radacina->s);
  cout<<radacina->info<<" ";
  InOrdine(radacina->d);
}
return;
}

//NUMARUL DE NODURI DIN ARBORE

unsigned NumarNoduri(NOD*radacina){
unsigned num=0;
if(radacina==NULL){num=0; return num;}
else{num=NumarNoduri(radacina->s) + NumarNoduri(radacina->d)+1; return num;}
return num;
}

//NODURI FRUNZA DIN ARBORE

unsigned NumarNoduriFrunza(NOD*radacina){
unsigned num=0;
if(radacina==NULL){num=0; return num;}
else if(radacina->s==NULL&&radacina->d==NULL){num=1; return num;}
else{num=NumarNoduriFrunza(radacina->s)+NumarNoduriFrunza(radacina->d); return num;}
return num;
}

//INALTIME ARBORE

unsigned InaltimeArbore(NOD*radacina){
unsigned num;
if(radacina==NULL){num=0; return num;}
else if(radacina->s==NULL&&radacina->d==NULL){num=0; return num;}
else if(InaltimeArbore(radacina->s)>=InaltimeArbore(radacina->d)){num=InaltimeArbore(radacina->s)+1; return num;}
else{num=InaltimeArbore(radacina->d)+1; return num;}
return num;
}

//CAUTARE  IN ARBORE

bool Cautare(NOD*nod,int num){
if(nod==NULL)return false;
else if(nod->info==num)return true;
else if(nod->info>=num)return Cautare(nod->s,num);
else return Cautare(nod->d,num);
}

//AFISARE

void Afisare(NOD* radacina){

if(radacina==NULL){cout<<"Arborele este gol"<<endl;}
//parcurgeri
cout<<"\nParcurgerea PreOrdine"<<endl;
PreOrdine(radacina);

cout<<"\nParcurgerea PostOrdine"<<endl;
PostOrdine(radacina);

cout<<"\nParcurgerea InOrdine"<<endl;
InOrdine(radacina);

cout<<"\nIn arbore avem "<<NumarNoduri(radacina)<<" noduri"<<endl;

cout<<"\nIn arbore avem "<<NumarNoduriFrunza(radacina)<<" noduri frunza"<<endl;

cout<<"\nInaltimea arborelui este "<<InaltimeArbore(radacina)<<endl;

return;
}

int main()
{NOD* radacina=NULL;
 int alegere,num;
 while(1){
    cout<<"\n1.Adaugare elemente in arbore"<<endl;
    cout<<"2.Afisare "<<endl;
    cout<<"3.Cautare in arbore"<<endl;
    cout<<"4.Iesire"<<endl;
    cout<<"Introduce-ti optiunea dorita"<<endl;
    cin>>alegere;
    switch(alegere){
    case 1:{
            cout<<"Dati numarul pe care vreti sa il adaugati in arbore"<<endl;
            cin>>num;
            radacina=Adaugare(radacina,num);
            break;
           }
    case 2:{
            Afisare(radacina);
            break;
           }
    case 3:{cout<<"Introduce-ti numarul pentru a fi cautat"<<endl;
            cin>>num;
            if(Cautare(radacina,num)==true)cout<<"Nodul se afla in arbore"<<endl;
            else cout<<"Nodul nu se afla in arbore"<<endl;
            break;
           }
    case 4:{
            exit(1);
           }
    default:{cout<<"Alegere gresita,incearca din nou"<<endl;}
    }
 }
    return 0;
}
