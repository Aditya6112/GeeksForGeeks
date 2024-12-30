//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTabs(vector<string> &arr) {
        // Your Code goes here.
        unordered_map<string,bool>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(mpp.find(arr[i])!=mpp.end()){
                if(mpp[arr[i]]==true){
                    mpp[arr[i]]=false;
                }else{
                    mpp[arr[i]]=true;
                }
            }else if(arr[i]=="END"){
                for(auto &it:mpp){
                    if(it.second==true){
                        it.second=false;
                    }
                }
            }else{
                mpp[arr[i]]=true;
            }
        }
        int count=0;
        for(auto &it:mpp){
            if(it.second==true){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> arr;
        string str;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        int ans = ob.countTabs(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends