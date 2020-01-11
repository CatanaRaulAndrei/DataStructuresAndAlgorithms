
#include <iostream>
#define size 10
using namespace std;

class Stack{
  private:
    int element;
    int top;
    int stack[size];
  public:
    Stack(){
        top=-1;
    }
    void push(); // Insert in stack
    void pop(); //  Delete from the stack
    bool isEmpty(); // check if stack is empty
    void display(); // display the stack
    
};
// check if stack is empty
bool Stack::isEmpty(){
   return (top==-1)?true:false;
}
// Insert
void Stack::push(){
    //  check if the stack is full - Overflow
    if(top==size-1){
        cout<<"Stack is full-Overflow";
    }
    else{
        top=top+1;
        cin>>element;
        stack[top]=element;
        cout<<"Element: "<<element<<" was inserted in the stack"<<endl;
    }
}
// Delete
void Stack::pop(){
    // check if the stack is empty - Underflow
    if(isEmpty()==true){
        cout<<"Stack is empty - Underflow";
    }
    else{
        element = stack[top];
        cout<<"\nElement: "<<element<<" was deleted from the stack"<<endl;
        top = top-1;
    }
}
// display 
void Stack::display(){
    if(isEmpty()==true)
    {
        cout<<"Stack is empty!!!"<<endl;
    }
    else{
        cout<<"STACK: ";
    }
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    Stack s;
    
    for(int i=0;i<size;i++){
        s.push();
    }
    s.display();
    s.push(); // Overflow
    
    for(int i=0;i<size;i++){
        s.pop();
    }
    s.display();
    s.pop(); // Undeflow
    
    
	return 0;
}
