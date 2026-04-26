class Solution {
  public:
    void merge(vector<int>& arr, int l, int r){
        int m=l+(r-l)/2;
        int i=l;
        int j=m+1;
        vector<int>ans;
        while(i<=m && j<=r){
            if(arr[i]<arr[j]){
                ans.push_back(arr[i]);
                i++;
            }else{
                ans.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=m){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            ans.push_back(arr[j]);
            j++;
        }
        
        for(int k=0;k<ans.size();k++){
            arr[k+l]=ans[k];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r){
            return;
        }
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,r);
    }
};