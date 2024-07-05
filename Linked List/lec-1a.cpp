#include <iostream>
using namespace std;

//SINGLY LINKED LIST 

class node {
public:
    int data;
    node* next;
    
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
    
    void insertAtHead(node* &head, int d) {
        // new node create
        node* temp = new node(d);
        temp->next = head;
        head = temp;
    }
    
    void insertAtNull(node* &tail, int d) {
        node* temp = new node(d);
        tail->next = temp;
        tail = temp;
    }
    
    void insertAtPosition(node* &head, node* &tail, int pos, int d) {
        if (pos == 1) {
            insertAtHead(head, d);
            return;
        }
        
        node* temp = head;
        int cnt = 1;
        while (cnt < pos - 1) {
            temp = temp->next;
            cnt++;
        }
        
        if (temp->next == NULL) {
            insertAtNull(tail, d);
            return;
        }
        
        node* newnode = new node(d);
        newnode->next = temp->next;
        temp->next = newnode;
}
        void deleteAtposition(int pos , node* &head){
        node* temp = head;
        if(pos ==1){
            head = temp->next;
            delete temp;
            return;
            
        }
        
        int cnt = 1;
        while(cnt<pos-1){
            temp = temp->next;
            cnt++;
        }
        
        temp->next = temp->next->next;
      
       
        
    }
    
    void print(node* head) {
        node* temp = head;
        
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // created a new node
    node* node1 = new node(1);
    cout << node1->data << endl;
    cout << node1->next << endl;
    
    node* head = node1;
    node* tail = node1;
    
    cout << head << endl;
    cout << tail << endl;
    
    node1->print(head);
    
    // insert nodes
    node1->insertAtNull(tail, 3);
    node1->insertAtNull(tail, 5);
    node1->insertAtNull(tail, 6);
    
    node1->insertAtPosition(head, tail, 2, 2);
    node1->insertAtPosition(head, tail, 4, 4);
    node1->insertAtPosition(head, tail, 1, 0);
    node1->insertAtPosition(head, tail, 8, 7);

    node1->deleteAtposition(1, head);
    node1->deleteAtposition(7, head);
    
    node1->print(head);
}

