//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int i=0,j=0,sum=0,n=arr.size();
        int maxi=INT_MIN;
        while(j<n){
            sum+=arr[j];
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                maxi=max(sum,maxi);
                //remove the element not within the window
                sum-=arr[i];
                //maintain window size
                i++;
                j++;
            }
        }
        return maxi;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends