//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int s=0;
        int e=arr.size()-1;
        int ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(arr[m]==k){
                ans=m;
                e=m-1;
            }
            else if(arr[m]>k)e=m-1;
            else s=m+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends