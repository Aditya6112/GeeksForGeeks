class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long total_sum=1LL*n*(n+1)/2;
        long long current_sum=accumulate(arr.begin(),arr.end(),0);
        unordered_map<int,int>mpp;
        for(auto a:arr){
            mpp[a]++;
        }
        int r_n=-1;
        for(auto it:mpp){
            if(it.second>1){
                r_n=it.first;
                break;
            }
        }
        vector<int>ans;
        ans.push_back(r_n);
        int m_n=total_sum-(current_sum-r_n);
        ans.push_back(m_n);
        return ans;
    }
};