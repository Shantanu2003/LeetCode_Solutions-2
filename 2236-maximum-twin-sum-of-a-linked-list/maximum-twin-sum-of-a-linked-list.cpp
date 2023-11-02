/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
       vector<int> v;
       ListNode* current = head;
       while(current!= NULL){
           v.push_back(current->val);
           current= current->next;
       }
       int sum = 0;
       int max= 0;
       for(int i = 0; i<v.size()/2; i++){
           sum = v[i] + v[v.size()-1-i];
       if(max<sum){
           max= sum;
           sum = 0;
       }
       }
       return max;
    }
};