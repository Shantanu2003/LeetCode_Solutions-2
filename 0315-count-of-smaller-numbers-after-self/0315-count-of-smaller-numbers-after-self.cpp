// class Solution {
// public:
//     void merge(vector<int>& arr, vector<int>& indices, vector<int>& count, int left, int mid, int right) {

//         int n = right - left + 1;
//         vector<int> newIndices(n);
//         int i = left, j = mid + 1, k = 0, rightCounter = 0;

//         while (i <= mid && j <= right) {
//             if (arr[indices[i]] <= arr[indices[j]]) {
//                 newIndices[k] = indices[i];
//                 count[indices[i]] += rightCounter;
//                 i++;
//             } else {
//                 newIndices[k] = indices[j];
//                 rightCounter++;
//                 j++;
//             }
//             k++;
//         }

//         while (i <= mid) {
//             newIndices[k] = indices[i];
//             count[indices[i]] += rightCounter;
//             i++;
//             k++;
//         }

//         while (j <= right) {
//             newIndices[k] = indices[j];
//             j++;
//             k++;
//         }

//         for (int p = 0; p < n; p++) {
//             indices[left + p] = newIndices[p];
//         }
//     }

//     void mergeSort(vector<int>& arr, vector<int>& indices, vector<int>& count, int left, int right) {
//         if (left < right) {
//             int mid = left + (right - left) / 2;
//             mergeSort(arr, indices, count, left, mid);
//             mergeSort(arr, indices, count, mid + 1, right);
//             merge(arr, indices, count, left, mid, right);
//         }
//     }

//     vector<int> countSmaller(vector<int>& arr) {
//     //     vector<pair<int,int>>nums(arr.size());
//     //     for(int  i = 0 ; i < arr.size() ; i++){
//     //         nums[i] = make_pair(arr[i], i);
//     //     }
        
//     //     sort(nums.begin(), nums.end());
//     //     vector<int>res(arr.size());
//     //     for(auto i : nums){
//     //         int index = i.second;
//     //         int count = 0;
//     //         for(int j = index+1; j < arr.size() ; j++){
//     //             if(arr[j] < i.first)
//     //             count++;
//     //         }
//     //         res[i.second] = count;
//     //     }
        
//     // return res;

//            int n = arr.size();
//         vector<int> indices(n), count(n, 0);

//         for (int i = 0; i < n; i++) {
//             indices[i] = i;
//         }

//         mergeSort(arr, indices, count, 0, n - 1);

//         return count;
//     }
// };

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset<int> st;
        vector<int> ans;
        int n = nums.size();
        for(int i=n-1; i>=0; --i){
            ans.push_back(st.order_of_key(nums[i]));
            st.insert(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};