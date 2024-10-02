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

    // ~ O(N) time
    void reorderList2(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        // reverse list 2
        ListNode *last = nullptr, *curr;
        while(head2) {
            curr = head2;
            head2 = head2->next;
            curr->next = last;
            last = curr;
        }
        head2 = last;

        // merge 2 list alternate
        ListNode *mergedList = head, *retHead = head;
        head = head->next;
        bool listTwoTurn = true;
        while (head || head2) {
            if (listTwoTurn && head2) {
                mergedList->next = head2;
                head2 = head2->next;
            } else {
                mergedList->next = head;
                head = head->next;
            }
            mergedList = mergedList->next;
            listTwoTurn = !listTwoTurn;
        }
        // return retHead;
    }

    void reorderList(ListNode* head) {
        reorderList2(head);
    }
};