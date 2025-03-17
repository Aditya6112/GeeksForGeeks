//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
int static dp[101][101];
class Solution {
  public:
    int solve(vector<int>& arr,int i,int j){
        int mini=INT_MAX;
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j-1;k++){
            int tempAns=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            mini=min(tempAns,mini);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,arr.size()-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends