//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleBFS(vector<vector<int>>& adj,int src,unordered_map<int,bool>& visited,unordered_map<int,int>& parent){
        parent[src]=-1;
        visited[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto nbr:adj[front]){
                if(visited[nbr]==true && nbr!=parent[front]){
                    return true;
                }
                else if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=front;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code 
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycleBFS(adj,i,visited,parent)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends