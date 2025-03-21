//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        unordered_map<char,int>mp;
        int maxi=-1;
        int i=0,j=0;
        int n=s.size();
        while(j<n){
            //store in map
            mp[s[j]]++;
            //when map size is less than k then increase j
            if(mp.size()<k){
                j++;
            }
            //when map size is equal then store the length in the ans
            else if(mp.size()==k){
                maxi=max(maxi,j-i+1);
                j++;
            }
            //when map size is greater than k then shrink the window
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends