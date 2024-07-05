//
//  main.cpp
//  Aryaman's code5

//
//  Created by Aryaman Agarwal on 19/12/23.
//
//
//

#include <iostream>
using namespace std;

class node{
    
public:
    int data;
    node* prev;
    node* next;
    
    //constructor
    
    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
        
    }
    
    ~node() {
         int val = this -> data;
         if(next != NULL) {
             delete next;
             next = NULL;
         }
         cout << "memory free for node with data "<< val << endl;
     }
    
    
    
    void print(node* head){
        node* temp = head;
        while( temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
    int getLength(node* head) {
        int len = 0;
        node* temp  = head ;

        while(temp != NULL) {
            len++;
            temp  = temp -> next;
        }

        return len;
    }
    
    void insertAthead(node* &head , int d){
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
    void insertAtend( node* &tail , int d){
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
    void insertAtpos( node* &head , node* &tail, int pos , int d){
        
        node* temp = head;
        if(pos==1){
            insertAthead(head, d);
            return;
        }
        int cnt = 1 ;
        while(cnt<pos-1){
            temp = temp->next;
            cnt++;
        }
        if(temp->next == NULL){
            insertAtend(tail, d);
            return;
        }
        
        node* newnode = new node(d);
        
        newnode->next = temp->next;
        temp->next = newnode;
        
    }
    
    void delette (node* &head , int pos){
        if(pos == 1) {
            node* temp = head;
            temp -> next -> prev = NULL;
            head = temp ->next;
            temp -> next = NULL;
            delete temp;
        }
        
        else{
            //middle hogi ya to last wali hogi simple si baaat hai bhaiya
            
            node* curr = head;
            node* prev = NULL;

                   int cnt = 1;
                   while(cnt < pos) {
                       prev = curr;
                       curr = curr -> next;
                       cnt++;
                   }

                   curr -> prev = NULL;
                   prev -> next = curr -> next;
                   curr -> next = NULL;

                   delete curr;
            
        }
        
            
    }
    
};



int main(){
    
    node* node1 = new node(15);
    node* head = node1;
    node* tail = node1;
    
    node1->print(head);
    cout<<node1->getLength(head)<<endl;
    
    node1->insertAthead(head, 10);
    node1->insertAtend(tail, 20);
    node1->insertAtpos(head, tail, 2, 13);
    node1->insertAtpos(head, tail, 1, 3);
    node1->insertAtpos(head, tail, 6, 23);
    
    node1->delette(head, 3);
    
    node1->print(head);
    
   
}
        
     
        
