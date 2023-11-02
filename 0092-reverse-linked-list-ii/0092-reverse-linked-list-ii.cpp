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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     ListNode* curr =head, *prev  = NULL; 
     int i;
     for(i = 1;i<left; i++){
       prev = curr;
       curr = curr->next;
     }
     ListNode* tail = curr;
     ListNode* head1  = NULL;
     
     //i=1;
     while(i <= right){
       ListNode* next = curr->next;
       curr->next = head1;
       head1 = curr;
       curr= next;
       i++;
     }
     if(prev != NULL)
     prev->next = head1;
     else{
       head= head1;
     }

     tail->next = curr;

     return head;
    }
};