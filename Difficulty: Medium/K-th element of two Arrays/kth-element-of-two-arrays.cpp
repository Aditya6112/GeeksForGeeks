//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        // code here
        int n1 = arr1.size(), n2 = arr2.size();
        int i = 0, j = 0, count = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                count++;
                if (count == k) return arr1[i];
                i++;
            } else {
                count++;
                if (count == k) return arr2[j];
                j++;
            }
        }
        // Handle remaining elements in arr1
        while (i < n1) {
            count++;
            if (count == k) return arr1[i];
            i++;
        }
        // Handle remaining elements in arr2
        while (j < n2) {
            count++;
            if (count == k) return arr2[j];
            j++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(arr1, arr2, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends