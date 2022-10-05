#include <iostream>
using namespace std;

class Node{
    public:
    int data;     //stores the data 
    Node*next;    //stores address of next node

};

void PrintList(Node* n){        // used to print the Linked list data
    while (n!=NULL)
    {
        cout<<n->data<<"->";
        n=n->next;
    };
    
    
};

int main(){
                //giving memory to nodes
Node* head;
Node* second;
Node* third;

              //initializing objects of nodes
head=new Node();
second=new Node();
third=new Node();
      
                //giving data to nodes
head->data=1;
head->next=second;
second->data=2;
second->next=third;
third->data=3;
third->next=NULL;
                //calling print function
PrintList(head);

    return 0;
}
