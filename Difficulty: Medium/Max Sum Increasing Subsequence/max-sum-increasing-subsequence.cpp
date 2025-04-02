//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int static t[1001][1001];
class Solution {
  public:
    int solve(vector<int>& nums,int n,int prev){
        if(n==0)return 0;
        if(t[n][prev+1]!=-1)return t[n][prev+1];
        int include=0;
        if(prev==-1 || nums[n-1]<nums[prev]){
            include=nums[n-1]+solve(nums,n-1,n-1);
        }
        int exclude=solve(nums,n-1,prev);
        return t[n][prev+1]=max(include,exclude);
    }
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        memset(t,-1,sizeof(t));
        int n=arr.size();
        return solve(arr,n,-1);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends