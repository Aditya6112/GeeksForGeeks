class Solution {
  public:
    void adjList(vector<vector<int>>& edges,unordered_map<int,list<int>>& adj_list,unordered_map<int,int>& inDegree){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj_list[u].push_back(v);
            inDegree[v]++;
        }
    }
    void topoSortDFS(int src,unordered_map<int,list<int>>& adj_list,stack<int>& st,vector<bool>& visited){
        visited[src]=true;
        for(auto nbr:adj_list[src]){
            if(!visited[nbr]){
                topoSortDFS(nbr,adj_list,st,visited);
            }
        }
        st.push(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,list<int>> adj_list;
        unordered_map<int,int> inDegree;
        vector<bool> visited(V,false);
        adjList(edges,adj_list,inDegree);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topoSortDFS(i,adj_list,st,visited);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};