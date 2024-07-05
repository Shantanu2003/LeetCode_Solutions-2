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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        while(head != NULL){
            ans.push_back(head->val);
            head= head->next;
        }
        
        vector<int> criticalPoints;
        
        for (int i = 1; i < ans.size() - 1; i++) {
            if ((ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) || 
                (ans[i] > ans[i - 1] && ans[i] > ans[i + 1])) {
                criticalPoints.push_back(i+1);
            }
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int maxDistance = criticalPoints.back() - criticalPoints.front();
        int minDistance = criticalPoints.back() - criticalPoints[criticalPoints.size() - 2];
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }


        return {minDistance, maxDistance};
    }
};
