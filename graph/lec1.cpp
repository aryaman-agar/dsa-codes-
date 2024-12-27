#include <iostream>
using namespace std;
void print(int adj[][101], int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    cout << "hello world";
    cout<<endl;
    int n , m ;
    cin >> n >> m;
    //this is for matrix representation 
    int adj[101][101];
    
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
        
    }

    //for list representation

    vector<int>adj[n+1];

    for(int i =0 ; I < m ; i++){
        int u , v;
        in >> u >> v;

        //if it is undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        //if its directed grpah
        adj[u].push_back(v);
        
    }
    
    cout << "Adjacency Matrix:" << endl;
    print (adj, n, m);
    
    return 0;
}
