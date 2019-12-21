#include <iostream>
#include <stdlib.h>
using namespace std;
//Arbore Binar(Binary tree);
struct Nod{
int info;
Nod* s;
Nod* d;
};

Nod* NodNou(int num){
Nod*temp=new Nod;
temp->info=num;
temp->s=NULL;
temp->d=NULL;
return temp;
}

Nod*inserare(Nod*radacina,int num){
if(radacina==NULL){
    radacina=NodNou(num);
    return radacina;
}
else if(radacina->info>=num){
     cout<<"Nodul este adaugat la stanga"<<endl;
     radacina->s=inserare(radacina->s,num);
}
else{
     cout<<"Nodul este adaugat la dreapta"<<endl;
     radacina->d=inserare(radacina->d,num);
    }
return radacina;
}

bool Cautare(Nod*radacina,int num){
if(radacina==NULL){return false;}
else if(radacina->info==num){return true;}
else if(radacina->info>=num){return Cautare(radacina->s,num);}
else{return Cautare(radacina->d,num);}
}

void PreOrdine(Nod* nod){
if(nod!=NULL){
    cout<<nod->info<<" ";
    PreOrdine(nod->s);
    PreOrdine(nod->d);
}
}

void PostOrdine(Nod*nod){
if(nod!=NULL){
    PostOrdine(nod->s);
    PostOrdine(nod->d);
    cout<<nod->info<<" ";
}
}

void InOrdine(Nod*nod){
if(nod!=NULL){
    InOrdine(nod->s);
    cout<<nod->info<<" ";
    InOrdine(nod->d);
}
}


void Afisare(Nod*radacina){
if(radacina==NULL){cout<<"arboarele este gol"<<endl;}
else{
    cout<<"\nParcurgerea in PreOrdine"<<endl;
    PreOrdine(radacina);
    cout<<"\nParcurgerea in PostOrdine"<<endl;
    PostOrdine(radacina);
    cout<<"\nParcurgerea in InOrdine"<<endl;
    InOrdine(radacina);

}
}

unsigned NrNoduri(Nod* nod){
unsigned num;
if(nod==NULL){num=0;return num;}
else{num=NrNoduri(nod->s)+NrNoduri(nod->d)+1;return num;}
return num;
}
unsigned NrNoduriFrunza(Nod*nod){
unsigned num;
if(nod==NULL){num=0;return num;}
else if(nod->s==NULL&&nod->d==NULL){num=1;return num;}
else{
    num=NrNoduriFrunza(nod->s)+NrNoduriFrunza(nod->d);
    return num;
}
return num;
}

unsigned InaltimeArbore(Nod*nod){
unsigned num;
if(nod==NULL){num=0;return num;}
else if(nod->s==NULL&&nod->d==NULL){num=0;return num;}
else if(nod->s>=nod->d){num=InaltimeArbore(nod->s)+1;return num;}
else{num=InaltimeArbore(nod->d)+1;return num;}
return num;
}

int main()
{Nod*radacina=NULL;
int alegere,num;
while(1){
      cout<<"\n1.Adauga un element in arbore"<<endl;
      cout<<"2.Cauta un element in arbore"<<endl;
      cout<<"3.Afisare"<<endl;
      cout<<"4.Numar noduri"<<endl;
      cout<<"5.Numar noduri frunza"<<endl;
      cout<<"6.Inaltime arbore"<<endl;
      cout<<"7.Iesire"<<endl;
      cout<<"Introduce-ti alegerea"<<" ";
      cin>>alegere;
      switch(alegere){
      case 1:{cout<<"Introduce-ti un element pentru a fi adaugat"<<endl;
              cin>>num;
              radacina=inserare(radacina,num);
              break;
             }
       case 2:{cout<<"Introduce-ti un element pentru a fi cautat"<<endl;
                cin>>num;
                if(Cautare(radacina,num)==true){cout<<"Nodul "<<num<<" este prezent in arbore"<<endl;}
                else{cout<<"Nodul "<<num<<" nu este prezent in arbore"<<endl;}
                break;
       }
      case 3:{Afisare(radacina);
              break;
             }
      case 4:{cout<<"Noi avem "<<NrNoduri(radacina)<<" noduri"<<endl;break;}
      case 5:{cout<<"Avem "<<NrNoduriFrunza(radacina)<<" noduri frunza"<<endl;break;}
      case 6:{cout<<"Arborele este de inaltime "<<InaltimeArbore(radacina)<<endl;break;}
      case 7:{exit(1);}
      default:{cout<<"Alegere gresita,incearca din nou"<<endl;}
      }
}


    return 0;
}
