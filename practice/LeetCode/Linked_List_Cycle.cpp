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
    bool hasCycleUsingHashMap(ListNode *head) {
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

    bool hasCycleUsingTwoPointer(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
            if (fast != nullptr && slow == fast) {
                return true;
            }
        }
        return false;
    }


    bool hasCycle(ListNode *head) {
        return hasCycleUsingTwoPointer(head);
    }
};