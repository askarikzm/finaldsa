#include<iostream>
using namespace std;
class node{
 public:
 int data;
 node * next;
 node  * prev;
node (int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}
};
class doublylinked{
    public:
    node * head;
    node * tail;
    doublylinked(){
        this->head=NULL;
        this->tail=NULL;
    }
    void insertion(int x){
        node * newnode=new node(x);
        node * temp=head;
         if(head==NULL){
            head=newnode;
            tail=newnode;
            return ;
        }
        if(head->next==NULL){
            head->next=newnode;
            newnode->prev=head;
            newnode=tail;
            return;
        }

        else{

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        tail=newnode;
        return ;
        }
    }
    void display(){
     node * temp=head;
     while(temp!=NULL){
        cout<<temp->data<<"\t<->\t";
        temp=temp->next;
     }
     cout<<"NULL"<<endl;
     return ;        
    }
    void insertion_at_pos(int pos,int value){
        int position=1;
        node * temp=head;
        node * newnnode=new node(value);
        while(position!=pos-1){
            temp=temp->next;
            position++;
        }
        newnnode->next=temp->next;
        newnnode->prev=temp;
        temp->next->next->prev=newnnode;
        temp->next=newnnode;
    }
    void delete_at_pos(int pos){
        node * temp=head;
        int counter=1;
        while(counter!=pos-1){
            temp=temp->next;
            counter++;
        }
        node * garbage=temp->next;
        temp->next->next->prev=temp;
        temp->next=temp->next->next;
        delete garbage;
    }
    void deletionhead(){
        node *temp =head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
};

int main()
{
    doublylinked l1;
    l1.insertion(10);
    l1.insertion(20);
    l1.insertion(30);
    l1.insertion(40);
    l1.display();
    l1.insertion_at_pos(3,-100);
    l1.display();
    l1.delete_at_pos(3);
    l1.display();
    l1.deletionhead();
    l1.display();

    
    return 0;
}