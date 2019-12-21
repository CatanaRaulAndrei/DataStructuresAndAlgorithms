#include <iostream>

using namespace std;
//MUCHIILE
struct MUCHIE{
unsigned nod1,nod2;
void citire(unsigned numar);
void afisare();
};

//OPERATII IN GRAFUL NEORIENTAT
struct GrafNeorientat{
MUCHIE*muchii;
unsigned NrNoduri,NrMuchii;
void MatriceAdiacenta(unsigned A[][100]);
void AfisareMatriceAdiacenta(unsigned A[][100]);
unsigned GradNoduri(unsigned nod);
void AfisareGradNoduri();
bool Adiacente(unsigned n1,unsigned n2);
void afisare();
void citire();
};
//FUNCTIA DE CITIRE
void MUCHIE::citire(unsigned numar){
do{
    cout<<"Dati prima extremitate"<<endl;
    cin>>nod1;
  }while(nod1==0||nod1>numar);

do{
    cout<<"Dati a doua extremitate"<<endl;
    cin>>nod2;
  }while(nod2==0||nod2>numar||nod2==nod1);

return;
}
//FUNCTIA DE CITIRE
void GrafNeorientat::citire(){
cout<<"Dati numarul de noduri"<<endl;
cin>>NrNoduri;
cout<<"Dati numarul de muchii"<<endl;
cin>>NrMuchii;
muchii=new MUCHIE[NrMuchii];
for(unsigned i=0;i<NrMuchii;i++){
    (muchii+i)->citire(NrNoduri);
}
return;
}
//FUNCTIA DE AFISARE
void MUCHIE::afisare(){
cout<<" cu extremitatile "<<nod1<<" "<<nod2<<endl;
return;
}
//FUNCTIA DE AFISARE
void GrafNeorientat::afisare(){
cout<<"Avem "<<NrNoduri<<" noduri"<<endl;
cout<<"Avem "<<NrMuchii<<" muchii"<<endl;
cout<<"Lista muchii"<<endl;
for(unsigned i=0;i<NrMuchii;i++){
     cout<<"Muchia "<<i+1;
    (muchii+i)->afisare();
}
return;
}
//MATRICE DE ADIACENTA
void GrafNeorientat::MatriceAdiacenta(unsigned A[][100]){
for(unsigned i=0;i<NrNoduri;i++)
    for(unsigned j=0;j<NrNoduri;j++)
        A[i][j]=0;
for(unsigned i=0;i<NrMuchii;i++){
    A[(muchii+i)->nod1-1][(muchii+i)->nod2-1]=1;
    A[(muchii+i)->nod2-1][(muchii+i)->nod1-1]=1;
}
return;
}

//AFISARE MATRICE DE ADIACENTA

void GrafNeorientat::AfisareMatriceAdiacenta(unsigned A[][100]){
for(unsigned i=0;i<NrNoduri;i++){
    for(unsigned j=0;j<NrNoduri;j++)
         cout<<A[i][j]<<" ";
         cout<<"\n";
}
return;
}

//GRADUL NODURILOR

unsigned GrafNeorientat::GradNoduri(unsigned nod){
unsigned contor=0;
for(unsigned i=0;i<NrMuchii;i++){
    if((muchii+i)->nod1==nod||(muchii+i)->nod2==nod){
        contor++;
    }
}
return contor;
}

//AFISARE GRAD NODURI

void GrafNeorientat::AfisareGradNoduri(){
for(unsigned i=0;i<NrNoduri;i++){
   cout<<"Nodul "<<i+1<<" are gradul "<<GradNoduri(i+1)<<endl;
}
}

//NODURI ADIACENTE
bool GrafNeorientat::Adiacente(unsigned n1,unsigned n2){
bool adiacente=false;
unsigned i=0;
while(i<NrMuchii&&adiacente==0){
    if(((muchii+i)->nod1==n1&&(muchii+i)->nod2==n2)||((muchii+i)->nod1==n2&&(muchii+i)->nod2==n1)){
        adiacente=true;
    }
    else{
         i++;
    }
}
 return adiacente;
}

int main()
{ GrafNeorientat gn;
unsigned A[100][100];

cout<<"Citire"<<endl;
gn.citire();

cout<<"Afisare"<<endl;
gn.afisare();

cout<<"Matrice Adiacenta"<<endl;
gn.MatriceAdiacenta(A);
gn.AfisareMatriceAdiacenta(A);

cout<<"Grad Noduri"<<endl;
gn.AfisareGradNoduri();
cout<<"Noduri Adiacente"<<endl;
unsigned n1,n2;
cout<<"Dati doua noduri pentru a verifica adiacenta"<<endl;
cout<<"Dati primul nod"<<" ";cin>>n1;
cout<<"Dati doua noduri pentru a verifica adiacenta"<<endl;
cout<<"Dati al doilea nod"<<" ";cin>>n2;

if(gn.Adiacente(n1,n2)==1){
    cout<<"nodurile sunt adiacente"<<endl;
}
else{
    cout<<"nodurile nu sunt adiacente"<<endl;
}
    return 0;
}
