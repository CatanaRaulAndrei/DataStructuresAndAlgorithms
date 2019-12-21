#include <iostream>
// :) Happy Coding
using namespace std;
struct NOD{
int info;
struct NOD* urm;
};
/*
        +--------+
head--> |info|urm|
adresa  +--------+
        adresa
*/
void AfisareElementeLista(NOD*head){
//daca lista este goala afisam un mesaj: lista este vida
if(head==NULL){
    cout<<"LISTA ESTE VIDA";
}

struct NOD *temp=head;
    while(temp!=NULL){
        cout<<temp->info<<" "; // 1 2 3
        temp=temp->urm; //urmatorul nod
}
}

int main()
{struct NOD* head=NULL;
 struct NOD* nod2=NULL;
 struct NOD* nod3=NULL;
//alocam memorie dinamic in heap
head=new NOD;
nod2=new NOD;
nod3=new NOD;
/*     head
    +--------+
    |info|urm|
    +--------+
        nod2
    +--------+
    |info|urm|
    +--------+
        nod3
    +--------+
    |info|urm|
    +--------+
*/
//am adaugat valoarea unu in primul nod
head->info=7;
head->urm=nod2;
//am adaugat valoarea doi in cel de al doilea nod
nod2->info=2;
nod2->urm=nod3;
//am adaugat valaorea 3 in cel de al treilea nod
nod3->info=9;
nod3->urm=NULL;
//apelam functia de afisarea a listei
AfisareElementeLista(head);// 1 2 3
    return 0;
}
