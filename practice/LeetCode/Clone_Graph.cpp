// https://leetcode.com/problems/clone-graph/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (!visited[node]) {
            Node* newNode = new Node(node->val);
            visited[node] = newNode;
            for (Node* neighbor : node->neighbors) {
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return visited[node];
    }
};