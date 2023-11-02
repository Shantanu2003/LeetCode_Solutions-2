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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;

        int count=0;

        while(temp!=NULL){

            count++;

            temp=temp->next;

        }

        int l=count-n,p=0;

        ListNode* temp1=head;

        if(l==0){

            head=head->next;

            return head;

        }

        while(temp1!= NULL){

            p++;

            if(p==l){

                temp1->next=temp1->next->next;

            }

            temp1=temp1->next;

        }

        return head;
    }
};