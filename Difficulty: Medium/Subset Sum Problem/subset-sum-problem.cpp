//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool solve(vector<int>& arr,int n,int t,vector<vector<int>>& dp){
        if(t==0){
            return true;
        }
        if(n==0 && t!=0){
            return false;
        }
        if(dp[n][t]!=-1){
            return dp[n][t];
        }
        if(arr[n-1]<=t){
            return dp[n][t]=solve(arr,n-1,t-arr[n-1],dp) || 
            solve(arr,n-1,t,dp);
        }else{
            return dp[n][t]=solve(arr,n-1,t,dp);
        }
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(arr,n,target,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends