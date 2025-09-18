class Solution {
  public:
    bool isCycle(int src,vector<bool>& visited,vector<bool>& dfsVisited,unordered_map<int,list<int>>& adj_list){
        visited[src]=true;
        dfsVisited[src]=true;
        for(auto nbr:adj_list[src]){
            if(!visited[nbr]){
                if(isCycle(nbr,visited,dfsVisited,adj_list))return true;
            }else{
                if(dfsVisited[nbr]){
                    return true;  // back edge → cycle
                }
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    
    void adjList(vector<vector<int>>& edges,unordered_map<int,list<int>>& adj_list){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj_list[u].push_back(v);
        }
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        unordered_map<int,list<int>> adj_list;
        adjList(edges,adj_list);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCycle(i,visited,dfsVisited,adj_list)){
                    return true;
                }
            }
        }
        return false;
    }
};