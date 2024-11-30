//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        int start=0, end=n-1;
        int mid = (start+end)/2;
        int index = n+1;
        int cnt = 0;
        while(cnt<=n/2){
            
            if(mid<0 || mid>=n) break;
            
            if(arr[mid]>k){
                end = mid-1;
            }else if(arr[mid]<k){
                start = mid+1;
            }else{
                index = min(index, mid);
                end = mid-1;
            }
            
            mid = (start+end)/2;
            
            cnt++;
        }
        
        return index==n+1 ? -1 : index;
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