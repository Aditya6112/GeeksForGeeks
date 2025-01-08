//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        vector<string> list;
    };
    
    TrieNode* root;
    TrieNode* p;
    
    void insert(string s){
        TrieNode* p = root;
        for (char c : s) {
            if (p->child[c] == NULL) p->child[c] = new TrieNode();
            p = p->child[c];
            p->list.push_back(s);
        }
    }   
    
    vector<string> query(char c){
        if (p == NULL || p->child[c] == NULL) {
            p = NULL;
            return {"0"};
        }
        
        p = p->child[c];
        return p->list;
    }
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new TrieNode();
        p = root;
        
        for (int i = 0; i < n; ++i){
            insert(contact[i]);
        }
        
        
        vector<vector<string>> ans;
        for (int i = 0; i < s.length(); ++i){
            vector<string> list = query(s[i]);
            sort(list.begin(), list.end());
            list.erase(unique(list.begin(), list.end()), list.end());
            ans.push_back(list);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends