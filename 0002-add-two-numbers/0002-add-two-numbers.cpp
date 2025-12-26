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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // dummy node to simplify code
        ListNode* current = dummy;          // pointer to construct the result list
        int carry = 0;                      // to keep track of carry-over
        

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // start with carry from previous operation
            

            // If l1 is not null, add its value to sum
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // move to the next node in l1
            }
            
            // If l2 is not null, add its value to sum
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // move to the next node in l2
            }
            
            // Update carry for the next addition (sum / 10 gives the carry)
            carry = sum / 10;
            
            // Create a new node with the digit (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;  // move to the new node
        }
        
        return dummy->next;  // the result starts from dummy->next
    }
};


//TC=(max(n, m)) = sc