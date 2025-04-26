//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(vector<int> arr,int i,int j,vector<vector<int>>&t)
    {
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int cost = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int ans = solve(arr,i,k,t) + solve(arr,k+1,j,t) + arr[i-1]*arr[k] * arr[j];
            
            cost = min(cost,ans);
        }
        return t[i][j] = cost;
    } 
     
    int matrixMultiplication(vector<int> &arr) {
    vector<vector<int>>t (arr.size()+1,vector<int>(arr.size()+1, - 1));
    return solve(arr,1,arr.size()-1,t);
        
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