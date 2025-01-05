//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<vector<int>>& adj,int src,vector<bool>& visited,vector<bool>& inRecursion){
        visited[src]=true;
        inRecursion[src]=true;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                visited[nbr]=true;
                if(dfs(adj,nbr,visited,inRecursion))return true;
            }else if(inRecursion[nbr]){
                return true;
            }
        }
        inRecursion[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,inRecursion))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends