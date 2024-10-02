// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ahead = head;
        while(n--) {
            ahead = ahead->next;
        }
        if (!ahead) {
            return head->next;
        }
        ListNode *behind = head;
        while(ahead && ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        behind->next = behind->next->next;
        return head;
    }
};