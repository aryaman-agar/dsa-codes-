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
    
    int adj[101][101];
    
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        
        adj[u][v] = 1;
        adj[v][u] = 1;
        
    }
    
    cout << "Adjacency Matrix:" << endl;
    print (adj, n, m);
    
    return 0;
}
