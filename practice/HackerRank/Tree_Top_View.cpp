// https://www.hackerrank.com/challenges/tree-top-view/problem



/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    void topView(Node* root) {
        map<int, Node*> mp;
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        while(!q.empty()) {
            root = q.front().first;
            int hd = q.front().second;
            if(!mp[hd])
                mp[hd] = root;
            if(root->left)
                q.push({root->left, hd - 1});
            if(root->right)
                q.push({root->right, hd + 1});
            q.pop();
        }
        for(auto &p : mp)
            cout << p.second->data << " ";
        cout << endl;
    }
