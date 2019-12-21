#include <iostream>

using namespace std;
//ARCUL
struct ARC{
unsigned nod1,nod2;
void afisare();
void citire(unsigned numar);
};
//OPERATII ASUPRA GRAFURLUI
struct GrafOrientat{
ARC *arcuri;
unsigned NrNoduri,NrArce;
void MatriceAdiacenta(unsigned A[][100]);
void AfisareMatriceAdiacetna(unsigned A[][100]);
unsigned GradExt(unsigned nod);
void AfisareGradExt();
unsigned GradInt(unsigned nod);
void AfisareGradInt();
void MatriceVarfuriArce(int V[][100]);
void AfisareMatriceVarfuriArce(int v[][100]);
bool Adiacente(unsigned n1,unsigned n2);
void afisare();
void citire();
};
//CITIRE
void ARC::citire(unsigned numar){
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
//CITIRE
void GrafOrientat::citire(){
cout<<"Dati numarul de noduri"<<endl;
cin>>NrNoduri;
cout<<"DAti numarul de arce"<<endl;
cin>>NrArce;
arcuri=new ARC[NrArce];
for(unsigned i=0;i<NrArce;i++){
    (arcuri+i)->citire(NrNoduri);
}
return;
}
//AFISARE
void ARC::afisare(){
cout<<" cu extremitatile "<<nod1<<" "<<nod2<<endl;
return;
}
//AFIASRE
void GrafOrientat::afisare(){
cout<<"Avem "<<NrNoduri<<" noduri"<<endl;
cout<<"Avem "<<NrArce<<" arce"<<endl;
cout<<"Lista Arcelor"<<endl;
for(unsigned i=0;i<NrArce;i++){
    cout<<"Arcul "<<i+1;
    (arcuri+i)->afisare();
}
return;
}

//MATRICE DE ADIACENTA
void GrafOrientat::MatriceAdiacenta(unsigned A[][100]){
for(unsigned i=0;i<NrNoduri;i++)
    for(unsigned j=0;j<NrNoduri;j++)
        A[i][j]=0;
unsigned m=0;
for(unsigned i=0;i<NrArce;i++){
    if((arcuri+i)->nod1!=(arcuri+i)->nod2){
    A[(arcuri+i)->nod1-1][(arcuri+i)->nod2-1]=1;
    m++;
    }
}
return;
}
//AFISARE MATRICE ADAICENTA
void GrafOrientat::AfisareMatriceAdiacetna(unsigned A[][100]){
for(unsigned i=0;i<NrNoduri;i++){
    for(unsigned j=0;j<NrNoduri;j++)
        cout<<A[i][j]<<" ";
        cout<<"\n";
        }
return;
}
//GRAD NODURI
unsigned GrafOrientat::GradExt(unsigned nod){
unsigned contor=0;
for(unsigned i=0;i<NrArce;i++){
    if((arcuri+i)->nod1==nod){
        contor++;
    }
}
return contor;
}
unsigned GrafOrientat::GradInt(unsigned nod){
unsigned contor=0;
for(unsigned i=0;i<NrArce;i++){
    if((arcuri+i)->nod2==nod){
        contor++;
    }
}
return contor;
}
//AFISARE GRAD NODURI
void GrafOrientat::AfisareGradExt(){
for(unsigned i=0;i<NrNoduri;i++){
    cout<<"Nodul "<<i+1<<" are gradul exterior "<<GradExt(i+1)<<endl;
}
return;
}
void GrafOrientat::AfisareGradInt(){
for(unsigned i=0;i<NrNoduri;i++){
    cout<<"Nodul "<<i+1<<" are gradul interior "<<GradInt(i+1)<<endl;
}
return;
}
//MATRICE VARFURI ARCE
void GrafOrientat::MatriceVarfuriArce(int V[][100]){
for(unsigned i=0;i<NrNoduri;i++)
    for(unsigned j=0;j<NrArce;j++)
        V[i][j]=0;
unsigned k=0;
for(unsigned i=0;i<NrArce;i++){
    V[(arcuri+i)->nod1-1][k]=1;
    V[(arcuri+i)->nod2-1][k]=-1;
    k++;
    }
return;
}

//AFISARE MATRICE VARFURI ARCE
void GrafOrientat::AfisareMatriceVarfuriArce(int V[][100]){
for(unsigned i=0;i<NrNoduri;i++){
    for(unsigned j=0;j<NrArce;j++)
        cout<<V[i][j]<<" ";
        cout<<"\n";
        }
return;
}

//ADIACENTE
bool GrafOrientat::Adiacente(unsigned n1,unsigned n2){
bool adiacente=false;
unsigned i=0;
while(i<NrArce&&adiacente==0){
    if(((arcuri+i)->nod1==n1&&(arcuri+i)->nod2==n2)||((arcuri+i)->nod1==n2&&(arcuri+i)->nod2==n1))
    adiacente=true;
    else i++;
}
 return adiacente;
}

int main()
{GrafOrientat go;
unsigned A[100][100];
int V[100][100];
cout<<"Citire"<<endl;
go.citire();

cout<<"Afisare"<<endl;
go.afisare();

cout<<"Matrice de adiacenta"<<endl;
go.MatriceAdiacenta(A);
go.AfisareMatriceAdiacetna(A);

cout<<"Grad Noduri"<<endl;

cout<<"Gradul exterior"<<endl;
go.AfisareGradExt();

cout<<"Gradul interior"<<endl;
go.AfisareGradInt();

cout<<"Matrice Varfuri Arce"<<endl;
go.MatriceVarfuriArce(V);
go.AfisareMatriceVarfuriArce(V);
unsigned n1,n2;
cout<<"Noduri Adiacente"<<endl;
cout<<"Dati doua noduri pentru a verifica adiacenta"<<endl;
cout<<"Dati primul nod"<<endl;cin>>n1;
cout<<"Dati al doilea nod"<<endl;cin>>n2;
if(go.Adiacente(n1,n2)==1){
    cout<<"Nodurile "<<n1<<" "<<n2<<" sunt adiacente"<<endl;
}
else{
      cout<<"Nodurile "<<n1<<" "<<n2<<" nu sunt adiacente"<<endl;
}
    return 0;
}
