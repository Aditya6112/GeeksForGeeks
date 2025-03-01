//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(vector<int>& length,vector<int>& price,int n,int len,vector<vector<int>>& dp){
        if(n==0)return 0;
        if(len==0)return 0;
        if(dp[n][len]!=-1)return dp[n][len];
        if(length[n-1]<=len){
            return dp[n][len]=max(price[n-1]+solve(length,price,n,len-length[n-1],dp),solve(length,price,n-1,len,dp));
        }
        return dp[n][len]=solve(length,price,n-1,len,dp);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>length(n);
        iota(length.begin(),length.end(),1);
        int len=n;
        vector<vector<int>>dp(n+1,vector<int>(len+1,-1));
        return solve(length,price,n,len,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends