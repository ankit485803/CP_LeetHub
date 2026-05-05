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
    ListNode* rotateRight(ListNode* head, int k) {  //TC=O(n), SC=O(1)

        if (!head || !head->next || k == 0) return head; // Edge cases
        
        //step1: find lengthLL
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        //step2: Reduce k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) return head;  // If k is a multiple of length, no rotation needed
        

        //step3: Find the new tail (n-k-1) and new head (n-k)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        //step4: rotateList
        newTail->next = nullptr; // Break the list
        temp->next = head; // Connect the old tail to the old head
        
        return newHead;
    }
};
