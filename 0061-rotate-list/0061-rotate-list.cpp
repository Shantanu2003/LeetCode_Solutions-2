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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
        // The list has 0 or 1 node, so there's no middle node to delete.
        return head;
    }
        ListNode* current = head;
        ListNode* prev =NULL;
        int count = 0;
        while(current->next){
            current = current->next;
            count++;

        }

        k %= (count+1);// Calculate the effective number of rotations incase k is greater than count and optimize the solution.

        if(k == 0)
        return head;
        

        int j = 0;
        ListNode* temp = head;
        while(j < count -k){
            temp= temp->next;
            j++;
        }
        ListNode* newNode= temp->next;
        temp->next = nullptr;
        current->next = head;

        return newNode;

    }
};