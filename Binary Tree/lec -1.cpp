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

void buildFromLevelOrder(node*& root){
    queue<node*> q;

       cout << "Enter data for root" << endl;
       int data ;
       cin >> data;
       root = new node(data);
       
       q.push(root);

       while(!q.empty()) {
           node* temp = q.front();
           q.pop();

           cout << "Enter left node for: " << temp->data << endl;
           int leftData;
           cin >> leftData;

           if(leftData != -1) {
               temp -> left = new node(leftData);
               q.push(temp->left);
           }

           cout << "Enter right node for: " << temp->data << endl;
           int rightData;
           cin >> rightData;

           if(rightData != -1) {
               temp -> right = new node(rightData);
               q.push(temp->right);
           }
       }
    
}

void inorderHelper(TreeNode* root , vector<int>&ans){
        if(root == NULL) return;

        inorderHelper(root->left , ans);
        ans.push_back(root->val);
        inorderHelper(root->right , ans);

}
vector<int> inorderTraversal(TreeNode* root) {
        //base case likhna hai
    vector<int> ans;
    inorderHelper(root, ans);
    return ans;
}

//same aise he postorder and preorder ke liye hai 
    

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


