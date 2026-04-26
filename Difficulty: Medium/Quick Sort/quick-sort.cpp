class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low>=high){
            return;
        }
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int pivotIdx=low;
        int pivot=arr[pivotIdx];
        
        int count=0;
        for(int i=low+1;i<high+1;i++){
            if(pivot>=arr[i]){
                count++;
            }
        }
        swap(arr[pivotIdx],arr[count+low]);
        pivotIdx=count+low;
        
        int i=low,j=high;
        while(i<pivotIdx && j>pivotIdx){
            while(arr[i]<=pivot){
                i++;
            }
            while(arr[j]>pivot){
                j--;
            }
            if(i<pivotIdx && j>pivotIdx){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        return pivotIdx;
    }
};