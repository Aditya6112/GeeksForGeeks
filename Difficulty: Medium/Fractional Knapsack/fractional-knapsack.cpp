//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Comparator function to sort items by value-to-weight ratio
    static bool cmp(pair<int, int> A, pair<int, int> B) {
        return (double)A.first / A.second > (double)B.first / B.second;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int, int>> p;

        // Store value and weight pairs
        for (int i = 0; i < n; i++) {
            p.push_back({val[i], wt[i]});
        }

        // Sort items based on value-to-weight ratio
        sort(p.begin(), p.end(), cmp);

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            if (p[i].second <= capacity) {
                ans += p[i].first;
                capacity -= p[i].second;
            } else {
                // Taking fraction of the item
                ans += capacity * ((double)p[i].first / p[i].second);
                break; // Knapsack is full
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends