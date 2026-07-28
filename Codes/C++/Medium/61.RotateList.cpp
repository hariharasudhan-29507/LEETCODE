class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head; 

        ListNode *ptr1, *ptr2, *newhead, *tail, *curr;
        int len = 1; 

        
        curr = head;
        while (curr->next != nullptr) {
            len++;
            curr = curr->next;
        }
        tail = curr; 

        k = k % len;
        if (k == 0) return head; 
        curr = head;
        ptr1 = head;
        for (int i = 0; i < k; i++) {
            ptr1 = ptr1->next;
        }

        ptr2 = head;
        while (ptr1 != tail) { 
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        newhead = ptr2->next;
        ptr2->next = nullptr;
        ptr1->next = head;
        head = newhead;

        return head;
    }
};
