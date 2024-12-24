//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        if(s.size()<=1)return false;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(s[i]==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends