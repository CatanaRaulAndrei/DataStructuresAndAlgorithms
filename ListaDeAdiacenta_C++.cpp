#include <iostream>
#include<bits/stdc++.h>
//Lista de adiacenta - Graf neordonat
using namespace std;
//adauga nod
void AdaugaNod(vector<int> adj[],int nod1,int nod2){
    adj[nod1].push_back(nod2);//nod1-------nod2
    adj[nod2].push_back(nod1);//nod2-------nod1
    return;
}

//afiseaza adj
void AfisareGraf(vector<int> adj[],int dimensiune){
    for(int i=0;i<dimensiune;++i){
        cout<<"Lista de adiacenta a nodului "<< i <<endl<<"inceput ";
        for(int j:adj[i]){ //foreach
            cout<<"->"<<j;
        }
        cout<<endl;
    }

    return;
}
int main()
{   int dimensiune = 5; //graf cu cinci noduri
    vector<int>adj[dimensiune];
    //nod 0
    AdaugaNod(adj,0,1);
    AdaugaNod(adj,0,4);
    //nod 1
    AdaugaNod(adj,1,2);
    AdaugaNod(adj,1,3);
    AdaugaNod(adj,1,4);
    //nod 2
    //AdaugaNod(adj,2,1);
    AdaugaNod(adj,2,3);
    //nod 3
    //AdaugaNod(adj,3,1);
    //AdaugaNod(adj,3,2);
    AdaugaNod(adj,3,4);
    //nod4
    //AdaugaNod(adj,4,0);
    //AdaugaNod(adj,4,1);
    //AdaugaNod(adj,4,3);
    AfisareGraf(adj,dimensiune);


    return 0;
}
