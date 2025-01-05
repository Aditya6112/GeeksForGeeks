//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<vector<int>>& adj,int src,vector<bool>& visited,vector<int>&ans){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto nbr:adj[u]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int v=adj.size();
        vector<bool>visited(v,false);
        vector<int>ans;
        bfs(adj,0,visited,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends