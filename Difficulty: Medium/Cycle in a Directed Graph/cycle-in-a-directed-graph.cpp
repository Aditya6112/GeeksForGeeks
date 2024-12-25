//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycleDFS(vector<vector<int>>& adj, int src, unordered_map<int, bool>& visited, unordered_map<int, int>& dfsVisited) {
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                if(isCycleDFS(adj,nbr,visited,dfsVisited)){
                    return true;
                }
            }else if(dfsVisited[nbr]){
                return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> adj) {
        unordered_map<int, bool> visited;
        unordered_map<int, int> dfsVisited;
    
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleDFS(adj, i, visited,dfsVisited)) {
                    return true;
                }
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