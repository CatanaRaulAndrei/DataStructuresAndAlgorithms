#include <iostream>
#include <stdlib.h>
using namespace std;
struct NOD{
int info;
NOD*urm;
NOD*ant;
};
//FUNCTIA DE AFISARE
void Afisare(NOD*inceput){
NOD*p;
if(inceput==NULL){
    cout<<"Lista este vida"<<endl;
    return;
}
p=inceput;
while(p!=NULL){
    cout<<p->info<<" ";
    p=p->urm;
}
return;
}

//FUNCTIA DE ADAUGARE AL INCEPUT
NOD*AdaugareInceput(NOD*inceput,int num){
if(inceput==NULL){
  NOD*temp=new NOD;
  temp->info=num;
  temp->urm=NULL;
  temp->ant=NULL;
  inceput=temp;
  return inceput;
}
 else{NOD*temp=new NOD;
      temp->info=num;
      temp->ant=NULL;
      temp->urm=inceput;
      inceput->ant=temp;
      inceput=temp;
      return inceput;

 }
return inceput;
}
//FUNCTIA DE ADAUGARE AL FINAL
void AdaugareFinal(NOD*inceput,int num){
NOD*p;
p=inceput;
if(inceput==NULL){
    cout<<"Nu putem adauga un element la finalul unei liste vide"<<endl;
    return;
}
while(p->urm!=NULL){
    p=p->urm;
}
 NOD*temp=new NOD;
 temp->info=num;
 temp->urm=NULL;
 p->urm=temp;
 temp->ant=p;
 return;
}

//FUNCTIA DE ADUGARE DUPA UN NOD
void AdaugareDupa(NOD*inceput,int num,int num1){
NOD*temp,*p;
p=inceput;
while(p!=NULL){
    if(p->info==num1){
        temp=new NOD;
        temp->info=num;
        p->urm->ant=temp;
        temp->urm=p->urm;
        p->urm=temp;
    }
    p=p->urm;
}
cout<<num1<<" nu este prezent in lista"<<endl;
}

//FUNCTIA DE ADAUGARE INAINTEA UNUI NOD
 NOD*AdaugareInainte(NOD*inceput,int num,int num1){
 NOD*temp,*p;
 if(inceput->info==num1){
    NOD*temp=new NOD;
      temp->info=num;
      temp->ant=NULL;
      temp->urm=inceput;
      inceput->ant=temp;
      inceput=temp;
      return inceput;
 }
 else{p=inceput;
      while(p->urm!=NULL){
       if(p->urm->info==num1){
          temp=new NOD;
          temp->info=num;
          p->urm->ant=temp;
          temp->urm=p->urm;
          p->urm=temp;
          return inceput;
       }
       p=p->urm;
      }
 }
 cout<<num1<<" nu este prezent in lista"<<endl;
 return inceput;
 }

//FUNCTIA DE CAUTARE
 void Cautare(NOD*inceput,int num){
 NOD*p;
 p=inceput;
 while(p!=NULL){
    if(p->info==num){
       cout<<"Numarul "<<num<<" se afla in lista"<<endl;
       return;
    }
    p=p->urm;
 }
 cout<<"Numarul "<<num<<" nu se afla in lista"<<endl;
 return;
 }

//NUMARUL TOTAL DE NODURI DIN LISTA
 unsigned NumarNoduri(NOD*inceput){
 unsigned contor=0;
 NOD*p;
 p=inceput;
 while(p!=NULL){
    contor++;
    p=p->urm;
 }
 return contor;
 }

 //FUNCTIA DE STERGERE
 NOD*Stergere(NOD*inceput,int num){
 NOD*temp,*p;
 if(inceput==NULL){
    cout<<"Nu putem sterge elemente dintr-o lista vida"<<endl;
    return inceput;
 }
 if(inceput->info==num){
    temp=inceput;
    inceput=temp->urm;
    delete temp;
    return inceput;
 }
 else{p=inceput;
      while(p->urm!=NULL){
       if(p->urm->info==num){
        temp=p->urm;
        p->urm=temp->urm;
        delete temp;
        return inceput;
       }
       p=p->urm;
      }
 }
 cout<<"Numarul pe care vrei sa-l stergi nu se afla in lista"<<endl;
return inceput;
 }

int main()
{NOD*inceput=NULL;
 int alegere,num,num1;
 while(1){
           cout<<"\n1.Afisare"<<endl;
           cout<<"2.Adaugare la inceput"<<endl;
           cout<<"3.Adaugare la final"<<endl;
           cout<<"4.Adaugare dupa un nod"<<endl;
           cout<<"5.Adaugare inaintea unui nod"<<endl;
           cout<<"6.Cautare"<<endl;
           cout<<"7.Numarul total de noduri din lista"<<endl;
           cout<<"8.Stergere"<<endl;
           cout<<"9.Iesire"<<endl;
           cout<<"Introduce-ti alegerea"<<" ";
           cin>>alegere;
           switch(alegere){
           case 1:{Afisare(inceput);
                   break;
           }
           case 2:{cout<<"Dati un numar sa fie adaugat  la inceputul listei"<<endl;
                   cin>>num;
                   inceput=AdaugareInceput(inceput,num);
                   break;
           }
           case 3:{cout<<"Dati un numar sa fie adaugat  la finalul listei"<<endl;
                   cin>>num;
                   AdaugareFinal(inceput,num);
                   break;
           }
            case 4:{cout<<"Dati un numar sa fie adaugat"<<endl;
                    cin>>num;
                    cout<<"Dati numarul dupa care sa fie adaugat"<<endl;
                    cin>>num1;
                    AdaugareDupa(inceput,num,num1);
                    break;
           }
           case 5:{cout<<"Dati un numar sa fie adaugat"<<endl;
                    cin>>num;
                    cout<<"Dati numarul inainte caruia sa fie adaugat"<<endl;
                    cin>>num1;
                    inceput=AdaugareInainte(inceput,num,num1);
                    break;
                  }

           case 6:{cout<<"Dati un numar sa fie cautat in lista"<<endl;
                   cin>>num;
                   Cautare(inceput,num);
                   break;
            }
           case 7:{cout<<"Numarul total de noduri din lista este "<<NumarNoduri(inceput);
                   break;
           }
           case 8:{cout<<"Dati un nod sa fie sters"<<endl;
                   cin>>num;
                   inceput=Stergere(inceput,num);
                   break;
                   }

           case 9:{exit(1);

           }
           default:{cout<<"Alegere gresita,incearca din nou"<<endl;
           }
           }
 }
return 0;
}


