// https://www.interviewbit.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (!node)
        return nullptr;
    
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> clones;
    queue<UndirectedGraphNode*> q;
    
    UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
    clones[node] = clone;
    q.push(node);
    
    while (!q.empty()) {
        UndirectedGraphNode *curr = q.front();
        q.pop();
        
        for (auto neighbor : curr->neighbors) {
            if (clones.find(neighbor) == clones.end()) {
                clones[neighbor] = new UndirectedGraphNode(neighbor->label);
                q.push(neighbor);
            }
            clones[curr]->neighbors.push_back(clones[neighbor]);
        }
    }
    
    return clone;
}