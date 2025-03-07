//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
int static t[501][501];
class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int lcs(string &s1, string &s2,int n,int m){
        if(n==0 || m==0)return 0;
        if(t[n][m]!=-1)return t[n][m];
        if(s1[n-1]==s2[m-1]){
            return t[n][m]=1+lcs(s1,s2,n-1,m-1);
        }else{
            return t[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
        }
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        memset(t,-1,sizeof(t));
        int n=s1.size();
        int m=s2.size();
        return (n+m)-lcs(s1,s2,n,m);
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends