class Solution {
private:
int first(vector<int>& arr, int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
 
        int mid = (low + high) / 2;
 
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
int last(vector<int>& arr, int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
 
    
        int mid = (low + high) / 2;
 
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
 
        else {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
 
 
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ans;
      int n = nums.size();

      int first1 = first(nums, target, n);
      int last1 = last(nums, target, n);
      ans.push_back(first1);
      ans.push_back(last1);

      return ans;
    }
};