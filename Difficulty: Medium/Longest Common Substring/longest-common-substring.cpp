//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int ans=0;
    int solve(string& s1, string& s2, int n, int m,vector<vector<int>>& dp) {
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        int same=0;
        if(s1[n-1]==s2[m-1]){
            same=1+solve(s1,s2,n-1,m-1,dp);
        }
        int not_same=max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
        ans=max({ans,same,not_same});
        return dp[n][m]=same;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        solve(s1,s2,n,m,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends