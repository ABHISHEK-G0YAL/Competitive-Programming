// https://leetcode.com/problems/reorder-list/

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
    // ~ O(N^2) time
    void reorderList1(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode *last = head, *secondLast;
        while(last && last->next) {
            secondLast = last;
            last = last->next;
        }
        secondLast->next = nullptr;
        reorderList(head->next);
        last->next = head->next;
        head->next = last;
    }

    void reorderList(ListNode* head) {
        reorderList1(head);
    }
};