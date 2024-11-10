// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = new ListNode();
        ListNode* temp = mergedList;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1 ->next;
            } else {
                temp->next = l2;
                l2 = l2 ->next;
            }
            temp = temp->next;
        }
        if (l1) {
            temp->next = l1;
        }
        if (l2) {
            temp->next = l2;
        }
        return mergedList->next;
    }

    ListNode* mergeKListsRange(vector<ListNode*>& lists, int l, int r) {
        // Just safety check (Never encountered)
        if (l > r) {
            return NULL;
        }
        if (r == l) {
            return lists[r];
        } else {
            int mid = l + ((r - l) / 2);
            ListNode* l1 = mergeKListsRange(lists, l, mid);
            ListNode* l2 = mergeKListsRange(lists, mid + 1, r);
            return merge2Lists(l1, l2);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return mergeKListsRange(lists, 0, lists.size() - 1);
    }
};