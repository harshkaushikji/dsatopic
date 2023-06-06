#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};

    void insertathead(Node* &head, int d){
        //new node create 
        Node* temp=new Node(d);
        temp->next=head;
        head=temp;
    }
    
    void insertattail(Node* &tail, int d){
        //new node create 
        Node* temp=new Node(d);
        tail->next=temp;
        tail=tail->next;

    }

    void print(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

int main(){
    //create a new node
    Node* node1= new Node(10);
   // cout<<node1->data<<endl;
   // cout<<node1->next<<endl;

   //head pointed to node1
   Node* head=node1;
   Node* tail=node1;
   print(head);

  insertathead(head,12);
   print(head);

   insertathead(head,17);
   print(head);

  /* insertattail(tail,15);
   print(head);

   insertattail(tail,22);
   print(head);*/
   cout<<"head"<<head->data<<endl;
   cout<<"tail"<<tail->data<<endl;
    deleteNode(2,head);
    print(head);
    return 0;
}