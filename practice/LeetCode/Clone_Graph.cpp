// https://leetcode.com/problems/clone-graph/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* newNode = !visited[node] ? new Node(node->val) : visited[node];
        visited[node] = newNode;
        for (Node* neighbor : node->neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = cloneGraph(neighbor);
            }
            newNode->neighbors.push_back(visited[neighbor]);
        }
        return newNode;
    }
};