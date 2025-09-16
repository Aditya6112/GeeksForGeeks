class Solution {
  public:
    void adjList(vector<vector<int>>& edges,unordered_map<int,list<int>>& adj_list){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
    }
    
    bool isCyclic(int src,vector<vector<int>>& edges,unordered_map<int,list<int>>& adj_list,vector<bool>& visited,vector<int>& parent){
        visited[src]=true;
        parent[src]=-1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto& nbr:adj_list[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }else{
                    if(nbr!=parent[frontNode]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,list<int>> adj_list;
        adjList(edges,adj_list);
        vector<bool>visited(V,false);
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCyclic(i,edges,adj_list,visited,parent))return true;
            }
        }
        return false;
    }
};