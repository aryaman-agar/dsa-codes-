bool detectcycle(int i , vector<int>&  vis , vector<vector<int>>& adjl){
        vis[i] = 1;
        queue<pair<int,int>> q;
        
        q.push({i , -1});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int old = q.front().second;
            q.pop();
            
            for(auto it : adjl[node]){
                if(!vis[it]){
                    q.push({it , node});
                    vis[it] = 1;
                }
                else if(old != it){
                    return true;
                }
            }
        }
        return false;
    }
    

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adjl) {
        
        int V = adjl.size();
        vector<int> vis(V, 0);
        
        for(int i =0 ; i < V ; i++){
            if(!vis[i]){
                if(detectcycle(i , vis , adjl)) return true;
            }
        }
        return false;
    }
