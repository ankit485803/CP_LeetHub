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
        int lenA = 0, lenB = 0;
        ListNode *a = headA, *b = headB;

        // calculate lengths
        while (a) {
            lenA++;
            a = a->next;
        }
        while (b) {
            lenB++;
            b = b->next;
        }

        a = headA;
        b = headB;

        // move longer list ahead
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) a = a->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) b = b->next;
        }

        // move both together
        while (a && b) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }

        return NULL;
    }
};
