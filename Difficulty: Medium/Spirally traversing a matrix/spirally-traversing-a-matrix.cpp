//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int total_ele = m * n;
        vector<int> ans;
    
        int startingRow = 0;
        int endingRow = m - 1;
        int startingCol = 0;
        int endingCol = n - 1;
    
        int count = 0;
    
        while (count < total_ele) {
            // Print starting row
            for (int i = startingCol; i <= endingCol && count < total_ele; i++) {
                ans.push_back(mat[startingRow][i]);
                count++;
            }
            startingRow++;
    
            // Print ending column
            for (int i = startingRow; i <= endingRow && count < total_ele; i++) {
                ans.push_back(mat[i][endingCol]);
                count++;
            }
            endingCol--;
    
            // Print ending row
            for (int i = endingCol; i >= startingCol && count < total_ele; i--) {
                ans.push_back(mat[endingRow][i]);
                count++;
            }
            endingRow--;
    
            // Print starting column
            for (int i = endingRow; i >= startingRow && count < total_ele; i--) {
                ans.push_back(mat[i][startingCol]);
                count++;
            }
            startingCol++;
        }
    
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends