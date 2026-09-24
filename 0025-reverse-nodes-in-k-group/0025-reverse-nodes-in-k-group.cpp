
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if (kth == nullptr) {
                break;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {

                ListNode* temp = curr->next;

                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            ListNode* groupTail = groupPrev->next;

            groupPrev->next = kth;

            groupPrev = groupTail;
        }

        return dummy->next;
    }
};