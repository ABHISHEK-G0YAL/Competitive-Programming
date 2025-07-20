// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class SolutionLinearSpace {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        Node *COPY_HEAD = new Node(head->val);
        mp[head] = COPY_HEAD;
        Node *copyHead = COPY_HEAD;
        while (head) {
            if (head->next) {
                copyHead->next = mp[head->next]
                    ? mp[head->next]
                    : new Node(head->next->val);
                mp[head->next] = copyHead->next;
            }
            if (head->random) {
                copyHead->random = mp[head->random]
                    ? mp[head->random]
                    : new Node(head->random->val);
                mp[head->random] = copyHead->random;
            }
            head = head->next;
            copyHead = copyHead->next;
        }
        return COPY_HEAD;
    }
};

// O(1) Auxaliary Space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        // Interweave new copied Nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Set random of copied nodes
        curr = head;
        while(curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        Node* COPY_HEAD = head->next;
        curr = head;
        while(curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
        }
        return COPY_HEAD;
    }
};