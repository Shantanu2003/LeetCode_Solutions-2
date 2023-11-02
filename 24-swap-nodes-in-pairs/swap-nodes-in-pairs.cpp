class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* firstN = head;
        if(firstN==NULL || firstN->next==NULL)
            return head;
        while(firstN != NULL && firstN->next !=NULL){
            swap(firstN->val,firstN->next->val);
            firstN = firstN->next->next;          
        }
        return head;
   }
};