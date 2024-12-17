#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


class node {
public:
    node* left;
    node* right;
    int data;

    node(int d) {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
    }
};

node* insertBST(node* root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }

    if (data > root->data) {
        // Right part mei insert karna hai
        root->right = insertBST(root->right, data);
    } else {
        // Left part mei insert karna hai
        root->left = insertBST(root->left, data);
    }
    return root;
}

void takeinput(node*& root) { // Pass root by reference
    int data;
    cin >> data;

    while (data != -1) {  // Terminate input when -1 is entered
        root = insertBST(root, data);
        cin >> data;
    }
}

void levelorder(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}
void minVal(node*& temp) {
    if (temp == NULL) {
        return;
    }
    while (temp->left != NULL) {
        temp = temp->left;
    }
}
void maxVal(node*& temp) {
    if (temp == NULL) {
        return;
    }
    while (temp->right != NULL) {
        temp = temp->right;
    }
}

int main() {
    // Pehle ek node create karna hai
    node* root = NULL;

    cout << "Enter data to create BST (end with -1): " << endl;
    takeinput(root);

    cout << "Level Order Traversal of BST:" << endl;
    levelorder(root);
    
    node* temp = root;
    cout<<"min"<<endl;
    minVal(temp);
    cout<<temp->data<<endl;
    
    cout<<"max"<<endl;
    node* temp2 = root;
    maxVal(temp2);
    cout<<temp2->data<<endl;
    return 0;
    
}
