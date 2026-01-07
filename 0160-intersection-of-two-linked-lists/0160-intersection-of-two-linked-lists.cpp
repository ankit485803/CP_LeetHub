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
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode* h1 = headA;
        ListNode* h2 = headB;

        while (h1 != h2) {
            h1 = (h1 == nullptr) ? headB : h1->next;
            h2 = (h2 == nullptr) ? headA : h2->next;
        }

        return h1;  // intersection node or nullptr
    }
};
