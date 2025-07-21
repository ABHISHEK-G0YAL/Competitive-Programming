// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class SolutionSort {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());
        vector<string> filteredFolders;
        for (auto &folder : folders) {
            if (filteredFolders.empty()
            || !folder.starts_with(filteredFolders.back() + '/')) {
                filteredFolders.push_back(folder);
            }
        }
        return filteredFolders;
    }
};


class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isPathEnd = false;
};

class SolutionTrie {
public:
    TrieNode* root = new TrieNode();
    vector<string> filteredFolders;

    vector<string> removeSubfolders(vector<string>& folders) {
        for (const string& folder : folders) {
            insert(folder);
        }
        vector<string> path;
        dfs(root, path);
        return filteredFolders;
    }

    void insert(const string& folder) {
        TrieNode* node = root;
        stringstream ss(folder);
        string part;
        getline(ss, part, '/'); // skip empty

        while (getline(ss, part, '/')) {
            if (!node->children.count(part)) {
                node->children[part] = new TrieNode();
            }
            node = node->children[part];
        }
        node->isPathEnd = true;
    }

    void dfs(TrieNode* node, vector<string>& path) {
        if (node->isPathEnd) {
            string folder = "";
            for (string& dir : path) {
                folder += "/" + dir;
            }
            filteredFolders.push_back(folder);
            return; // don't go deeper into subfolders
        }

        for (auto& [name, child] : node->children) {
            path.push_back(name);
            dfs(child, path);
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        SolutionSort *solution = new SolutionSort();
        // SolutionTrie *solution = new SolutionTrie();
        return solution->removeSubfolders(folders);
    }
};