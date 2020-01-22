#include <iostream>

using namespace std;
class Stack{
private:
    int data,elem;
    Stack*next,*top;
public:
    Stack(){
        top=nullptr;
        }
    void push();
    void pop();
    void display();
};
// Insert
void Stack::push(){
    Stack*newNode = new Stack;
    cin>>elem;
    if(top==NULL){
        newNode->data=elem;
        newNode->next=NULL;
        top=newNode;
    }else{
        newNode->data=elem;
        newNode->next=top;
        top=newNode;
    }
}
// Delete
void Stack::pop(){
    if(top==nullptr){
        cout<<"Stack is empty-- Underflow"<<endl;
    }
    else{
        Stack*temp;

        temp=top;
        top=temp->next;
        temp->next=nullptr;
        cout<<temp->data<<" will be deleted!"<<endl;
        delete(temp);
    }
}

// Display
void Stack::display(){
    if (top==nullptr){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        Stack* temp;
        temp=top;
        while(temp!=nullptr){
             cout<<temp->data<<" ";
             temp=temp->next;
            }
        cout<<endl;
    }
}

int main(){
    Stack stackObject;
    // Insert - Push
    stackObject.push();
    stackObject.push();
    stackObject.push();
    // Display
    stackObject.display();
    // Delete
    stackObject.pop();
    //display
    stackObject.display();

    return 0;
}
