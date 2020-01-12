#include <iostream>
#include <stdlib.h>
#define MAX 5
//Stack other variant concept LIFO
using namespace std;
int top;
int Stack[MAX];
void push(){
if(top==MAX-1){
   cout<<"The stack is full/overflow"<<endl;
}
else{
    int e;
    cout<<"Enter an element on the stack"<<endl;
    cin>>e;
    top++;
    Stack[top]=e;
}
}

void pop(){
if(top==-1){
    cout<<"The stack is empty/underflow"<<endl;
}
else{
    int data;
    data=Stack[top];
    top--;
    cout<<"The element what is deleted is: "<<data<<endl;
}
}

void display(){
int i;
if(top==-1){
    cout<<"The stack is empty you can not delete another element"<<endl;
}
for(i=top;i>=0;i--){
    cout<<Stack[i]<<endl;
}
}

int main()
{top=-1;
    int option;
while(1){
    cout<<"1.Add an element on the stack"<<endl;
    cout<<"2.Display the stack"<<endl;
    cout<<"3.Delete an element on the stack"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Chose an option: "<<flush;
    cin>>option;
    switch(option){
        case 1 :{
                push();
                break;
                }
        case 2 :{
                display();
                break;
                }
        case 3 :{
                pop();
                break;
                }
        case 4 :{
                 exit(1);
                 break;
                }
         default:
             cout<<"Wrong option try again"<<endl;
    }
}

    return 0;
}
