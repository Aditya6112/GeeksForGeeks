//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    bool isPossible(vector<int>& stalls,int dist,int cows,int placed_cow){
        int prev_cow=stalls[0];
        int i=1;
        while(i<stalls.size()){
            if(stalls[i]-prev_cow>=dist){
                placed_cow++;
                prev_cow=stalls[i];
            }
            i++;
        }
        if(placed_cow>=cows){
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        
        int start=1;
        int end=stalls[n-1]-stalls[0];
        
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(stalls,mid,k,1)){
                ans=max(ans,mid);
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends