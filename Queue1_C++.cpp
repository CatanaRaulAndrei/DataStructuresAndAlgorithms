#include <iostream>
#include <stdlib.h>
#define MAX 5
//concept FIFO
using namespace std;
int Queue[MAX];
int Front,rear;

void Insert(int element){
if(rear==MAX-1){
    cout<<"The queue is full/overflow "<<endl;
    return;
}
if(Front==-1){
    Front=0;
}
rear++;
Queue[rear]=element;
}

int del(){
int data;
if(Front==-1||Front==rear+1){
    cout <<"The queue is empty/underflow"<<endl;
}
data=Queue[Front];
Front++;
cout<<"The element what is deleted is:"<<data<<endl;
return data;
}
void display(){
int i;
if(Front==-1||Front==rear+1){
    cout<<"The queue is empty"<<endl;
}
for(i=Front;i<=rear;i++){
    cout<<Queue[i]<<endl;
}

}

int main()
{Front=-1;
rear=-1;
int option,num;
while(1){
    cout<<"1.Add  an element in queue"<<endl;
    cout<<"2.Delete an element from the queue"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter an option"<<flush<<":";
    cin>>option;
    switch(option){
    case 1:{cout<<"Enter an element to be added:"<<flush;
            cin>>num;
            Insert(num);
            break;}
    case 2:{num=del();
           break;}

    case 3:{display();break;}
    case 4:{exit(1);}
    default:{
        cout<<"you entered a wrong option"<<endl;
    }
    }
}
return 0;
}



