//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int i=0,j=0,count=0,ans=0,k=pat.size();
        unordered_map<char,int>mpp;
        for(auto ch:pat){
            mpp[ch]++;
        }
        for(auto it:mpp){
            count++;
        }
        while(j<txt.size()){
            if (mpp.find(txt[j]) != mpp.end()) {
                mpp[txt[j]]--;
                if (mpp[txt[j]] == 0) {
                    count--;
                }
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(count==0){
                    ans++;
                }
                if(mpp.count(txt[i])){
                    mpp[txt[i]]++;
                    if(mpp[txt[i]]==1)count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends