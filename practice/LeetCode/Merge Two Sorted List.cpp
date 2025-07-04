// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        ListNode *list3, *list3Head;
        if (list1->val <= list2->val) {
            list3 = list1;
            list1 = list1->next;
        } else {
            list3 = list2;
            list2 = list2->next;
        }
        list3Head = list3;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                list3->next = list1;
                list1 = list1->next;
            } else {
                list3->next = list2;
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        if (list1) {
            list3->next = list1;
        }
        if (list2) {
            list3->next = list2;
        }
        return list3Head;
    }
};