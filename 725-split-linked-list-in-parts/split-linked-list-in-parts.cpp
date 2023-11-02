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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int count = 0;
       if(k ==1){
           ans.push_back(head);
           return ans;
       }
       ListNode* temp = head;
       while(temp != NULL){
           count++;
           temp= temp->next;
       }
       ListNode* temp1 = NULL;
       ListNode* temp2 = head;
       for(int i =0 ; i< k ; i++){
        ans.push_back(temp2);
        int j = count / k + (i < count % k ? 1 : 0);
        while(head != NULL && j>0){
            temp1 = temp2;
            temp2= temp2->next;
            j--;
        }
        if(temp1 != NULL) temp1->next = NULL;

       }
       return ans;
    }
};