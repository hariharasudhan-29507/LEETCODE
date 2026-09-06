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
        int minDistance = INT_MAX;
        int firstCritical = -1;
        int lastCritical = -1;
        int prevCritical = -1;
        int index = 2;
        
        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        
        while (currNode != nullptr && currNode->next != nullptr) {
            int prevVal = prevNode->val;
            int currVal = currNode->val;
            int nextVal = currNode->next->val;
            
            if ((currVal > prevVal && currVal > nextVal) || (currVal < prevVal && currVal < nextVal)) {
                if (firstCritical == -1) {
                    firstCritical = index;
                }
                if (prevCritical != -1) {
                    minDistance = min(minDistance, index - prevCritical);
                }
                prevCritical = index;
                lastCritical = index;
            }
            
            prevNode = currNode;
            currNode = currNode->next;
            ++index;
        }
        
        if (firstCritical == -1 || firstCritical == lastCritical) {
            return {-1, -1};
        }
        
        return {minDistance, lastCritical - firstCritical};
    }
};
