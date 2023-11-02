/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *f = headA;

    ListNode *s = headB;

    unordered_set<ListNode *>st;

     while(f)

     {

         st.insert(f);

         f=f->next;

 

     }

     while(s)

     {

         if(st.find(s)!=st.end())

         {

             return s;

         }

         s=s->next;

     }
      return NULL;
    }
};