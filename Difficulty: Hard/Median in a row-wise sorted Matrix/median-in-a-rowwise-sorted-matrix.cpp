//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int upperbound(vector<int>& mat, int n, int num) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mat[mid] > num) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>> &mat, int r, int c, int mid) {
        int count = 0;
        for (int i = 0; i < r; i++) {
            count += upperbound(mat[i], c, mid);
        }
        return count;
    }

    int median(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        int low = mat[0][0];
        int high = mat[0][0];
        
        for (int i = 0; i < row; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][col - 1]);
        }
    
        int desired = (row * col + 1) / 2;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            int smallerNo = countSmallEqual(mat, row, col, mid);
            if (smallerNo < desired) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends