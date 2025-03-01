//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int n,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            //for sum is 0 we can do it using empty subset
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(arr[i-1]<=j)dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total_sum=accumulate(arr.begin(),arr.end(),0);
        if((total_sum+d)%2!=0)return 0;
        int sum1=(total_sum+d)/2;
        //this sum1 becomes a target for the arr to achieve
        //if this is achieved then abs(sum1-sum2) is d.
        int n=arr.size();
        return solve(arr,n,sum1);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends