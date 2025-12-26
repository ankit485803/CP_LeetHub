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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //tc=O(n+m) = sc 
        stack<int> s1, s2;

        // Push values of l1 into stack
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push values of l2 into stack
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            // Insert at front
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};
