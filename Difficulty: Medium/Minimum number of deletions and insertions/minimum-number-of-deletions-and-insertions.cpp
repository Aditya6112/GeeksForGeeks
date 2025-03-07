//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int static t[1001][1001];
class Solution {
  public:
    int solve(string &s1,string& s2,int n,int m){
        if(n*m==0)return 0;
        if(t[n][m]!=-1)return t[n][m];
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1+solve(s1,s2,n-1,m-1);
        }else{
            return t[n][m]=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
        }
    }    
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        memset(t,-1,sizeof(t));
        int n=s1.size();
        int m=s2.size();
        int lcs=solve(s1,s2,n,m);
        return (n-lcs)+(m-lcs);
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
        cout << ob.minOperations(s1, s2) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends