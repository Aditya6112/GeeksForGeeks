//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    bool subsetSum(vector<int>& arr, int n, int target, vector<int>& v, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (n == 0) return false;
    
        if (dp[n][target] != -1) return dp[n][target];
    
        if (arr[n - 1] <= target) {
            return dp[n][target] = subsetSum(arr, n - 1, target - arr[n - 1], v, dp) ||
                                   subsetSum(arr, n - 1, target, v, dp);
        } else {
            return dp[n][target] = subsetSum(arr, n - 1, target, v, dp);
        }
    }
    
    int minDifference(vector<int>& arr) {
        int range = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(range + 1, -1));

        vector<int> v;
        for (int j = 0; j <= range / 2; j++) {
            if (subsetSum(arr, n, j, v, dp)) {
                v.push_back(j);
            }
        }
    
        int mini = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            mini = min(mini, (range - 2 * v[i]));
        }
    
        return mini;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends