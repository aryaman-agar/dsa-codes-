//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs (vector<vector<int>>& adj , vector<int>& fs , vector<int>& vis ,  int node ){
        
        vis[node] = 1;
        fs.push_back(node);
        
        for( auto it: adj[node] ){
            if (!vis[it]){
                dfs(adj , fs , vis , it);
            }
        }
        
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n , 0);
  
        vector<int> fs;
        
        dfs(adj, fs, vis, 0);
        
        return fs;
        
       
    }
};

