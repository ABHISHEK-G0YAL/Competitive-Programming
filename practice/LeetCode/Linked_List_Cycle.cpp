// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        while(head) {
            if (visited.find(head) != visited.end()) {
                return true;
            } else {
                visited[head] = true;
            }
            head = head->next;
        }
        return false;
    }
};