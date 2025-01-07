//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<string,int> solve(vector<int>& arr,int i,int j,vector<vector<pair<string,int>>>& dp){
        if(i==j){
            string st="";
            st+='A'+i-1;
            return {st,0};
        }
        if(dp[i][j].second!=-1)return dp[i][j];
        int mini=INT_MAX;
        string sr="";
        for(int k=i;k<j;k++){
            auto pr1=solve(arr,i,k,dp);
            auto pr2=solve(arr,k+1,j,dp);
            int x=pr1.second+pr2.second+arr[i-1]*arr[k]*arr[j];
            string s="";
            s="("+pr1.first+pr2.first+")";
            if(mini>x){
                mini=x;
                sr=s;
            }
        }
        dp[i][j]={sr,mini};
        return dp[i][j];
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n,{"",-1}));
        auto ans=solve(arr,1,n-1,dp);
        return ans.first;
    }
};

//{ Driver Code Starts.

int get(vector<int> &p, int n) {
    int m[n][n], ans = 1e9;
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            m[i][i + L - 1] = INT_MAX;
            for (int k = i; k <= i + L - 2; k++) {
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i - 1] * p[k] * p[i + L - 1];
                if (q < m[i][i + L - 1]) {
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int find(string s, vector<int> &p) {
    vector<pair<int, int>> arr;
    int ans = 0;
    for (auto t : s) {
        if (t == '(') {
            arr.push_back({-1, -1});
        } else if (t == ')') {
            pair<int, int> b = arr.back();
            arr.pop_back();
            pair<int, int> a = arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first, b.second});
            ans += a.first * a.second * b.second;
        } else {
            arr.push_back({p[int(t - 'A')], p[int(t - 'A') + 1]});
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> p;
        int x;
        while (ss >> x) {
            p.push_back(x);
        }
        Solution ob;
        string result = ob.matrixChainOrder(p);
        if (find(result, p) == get(p, p.size())) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
// } Driver Code Ends