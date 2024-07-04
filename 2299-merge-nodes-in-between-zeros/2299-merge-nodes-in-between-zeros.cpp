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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr= head;
        ListNode* newNode = new ListNode(0);
        curr = curr->next;
        ListNode* dummy = newNode;
        while(curr != NULL){
          int sum = 0;
          while(curr != NULL && curr->val != 0){
            sum += curr->val;
            curr = curr->next;
          }

          newNode->next = new ListNode(sum);
          newNode = newNode->next;

            if(curr != NULL) {
                curr = curr->next; 
            }
        }

        return dummy->next;
    }
};