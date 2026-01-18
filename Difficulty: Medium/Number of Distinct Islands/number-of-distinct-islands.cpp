// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int n,int m,int dirx[],int diry[],vector<pair<int,int>>& vec,int row0,int col0){
        visited[i][j]=1;
        vec.push_back({i-row0,j-col0});
        for(int d=0;d<4;d++){
            int r=i+dirx[d];
            int c=j+diry[d];
            if(r>=0 && r<n && c>=0 && c<m){
                if(grid[r][c]==1 && !visited[r][c]){
                    dfs(grid,visited,r,c,n,m,dirx,diry,vec,row0,col0);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        set<vector<int>>mp;
        int dirx[]={-1,0,1,0};
        int diry[]={0,1,0,-1};
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(grid,visited,i,j,n,m,dirx,diry,vec,i,j); 
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
