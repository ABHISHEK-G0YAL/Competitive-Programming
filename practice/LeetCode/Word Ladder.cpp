// https://leetcode.com/problems/word-ladder/

class SolutionTLE {
public:
    bool isOneCharDiff(string &word1, string &word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                ++count;
            }
        }
        return count == 1;
    }
    int bfs(unordered_map<string, vector<string>> &adj, string start, string end) {
        int count = 1;
        queue<vector<string>> q;
        unordered_set<string> visited;
        q.push({start});
        visited.insert(start);
        while (!q.empty()) {
            ++count;
            vector<string> level;
            for (auto &parent : q.front()) {
                for (string &child : adj[parent]) {
                    if (child == end) {
                        return count;
                    }
                    if (visited.count(child) == 0) {
                        level.push_back(child);
                        visited.insert(child);
                    }
                }
            }
            q.push(level);
            q.pop();
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (isOneCharDiff(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if (adj.count(beginWord) == 0) {
            for (int i = 0; i < wordList.size(); i++) {
                if (isOneCharDiff(wordList[i], beginWord)) {
                    adj[wordList[i]].push_back(beginWord);
                    adj[beginWord].push_back(wordList[i]);
                }
            }
        }
        if (adj.count(beginWord) == 0 || adj.count(endWord) == 0) {
            return 0;
        }
        return bfs(adj, beginWord, endWord);
    }
};
