void levelOrderTraversal(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        node* temp = q.front();
        
        q.pop();
        
        if (temp == NULL) {  // End of current level
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        
        else{
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        
    }
    cout << endl;
}

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildtree(node* root){
    cout<<"enter the data for node: "<<endl ;
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    
    root = new node(data);
    
    
    cout<<"enter data for inserting in left: "<<endl;
    
    root->left = buildtree(root->left);
    
    cout<<"enter data for inserting in right: "<<endl;
    
    root->right = buildtree(root->right);
    
    return root;
}
};


