class Solution {
  public:
    void adjList(vector<vector<int>>& edges, unordered_map<int,list<int>>& adj_list) {
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
    }
    
    bool isCyclicBFS(int src, unordered_map<int,list<int>>& adj_list, vector<bool>& visited, vector<int>& parent) {
        visited[src] = true;
        parent[src] = -1;
        queue<int> q;
        q.push(src);
        
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            for (auto& nbr : adj_list[frontNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                } else if (nbr != parent[frontNode]) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCyclicDFS(int node, unordered_map<int,list<int>>& adj_list, vector<bool>& visited, int parent) {
        visited[node] = true;
        
        for (auto& nbr : adj_list[node]) {
            if (!visited[nbr]) {
                if (isCyclicDFS(nbr, adj_list, visited, node)) return true;
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj_list;
        adjList(edges, adj_list);
        vector<bool> visited(V, false);

        // BFS approach (uncomment if needed)
        /*
        vector<int> parent(V, -1);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicBFS(i, adj_list, visited, parent)) return true;
            }
        }
        */

        // DFS approach
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicDFS(i, adj_list, visited, -1)) return true;
            }
        }
        return false;
    }
};
