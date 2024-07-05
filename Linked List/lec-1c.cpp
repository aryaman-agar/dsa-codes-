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
    node* next;
    
    node( int d){
        this->data = d;
        this->next = NULL;
    }
    
    ~node(){
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free now! "<< value <<endl;
    }

};

void insertnode( node* & tail , int element , int d){
    //assuming element  hai tail mei wwoowoafena
    //empty list
    if(tail==NULL){
        node* temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //non empty list
        node* current = tail;
        while(current->data != element){
            current = current->next;
        }
        
        node* temp = new node(d);
        temp->next = current->next;
        current->next = temp;
    }
}

void print(node* tail){
    node* temp = tail;
    
    do {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=temp);
    
    cout<<endl<<endl;
}

void deletee(node* tail , int value){
    
    if(tail == NULL){
        cout<<" List is empty "<<endl;
        return;
    }
    
    else{
        node* prev = tail;
        node* curr = prev->next;
        
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}



int main(){
        
    node* tail = NULL;
    
    insertnode(tail , 5 ,3);
    insertnode(tail , 3 ,10);
    insertnode(tail , 3 ,5);
    insertnode(tail , 10 ,15);
    print(tail);
    
    deletee(tail, 10);
    print(tail);
}
