class Solution {
private:
int findPeak(vector<int>arr, int low, 
                 int high, int n) 
{ 

    int mid = low + (high - low) / 2; 
  
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&  
        (mid == n - 1 || arr[mid + 1] <= arr[mid])) 
        return mid; 
  
    else if (mid > 0 && arr[mid - 1] > arr[mid]) 
        return findPeak(arr, low, (mid - 1), n); 
  
    
    else
        return findPeak(arr, (mid + 1), high, n); 
}
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0;
    int high = arr.size()-1;
    return findPeak(arr, low, high, arr.size()) ;
    }
};