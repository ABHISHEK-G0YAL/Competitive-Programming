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
        // O(N^2 L)
        for (int i = 0; i < wordList.size(); i++) {
            // O(N L)
            for (int j = i + 1; j < wordList.size(); j++) {
                // O(L)
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

class Solution {
public:
    int bfs(unordered_map<string, vector<string>> &patternMap, string startWord, string endWord) {
        int count = 1;
        queue<vector<string>> q;
        unordered_set<string> visited;
        q.push({startWord});
        visited.insert(startWord);
        // O (N L^2)
        while (!q.empty()) {
            ++count;
            vector<string> level;
            for (auto &parentWord : q.front()) {
                // O(L^2)
                for (int i = 0; i < parentWord.length(); i++) {
                    string pattern(parentWord);  // O(L)
                    pattern[i] = '*';
                    for (string &childWord : patternMap[pattern]) {
                        if (childWord == endWord) {
                            return count;
                        }
                        if (visited.count(childWord) == 0) {
                            level.push_back(childWord);
                            visited.insert(childWord);
                        }
                    }
                }
            }
            if (!level.empty()) {
                q.push(level);
            }
            q.pop();
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> patternMap;
        // O(N L^2)
        for (string &word : wordList) {
            // O(L^2) (Can be optimised to O(L))
            for (int i = 0; i < word.length(); i++) {
                string pattern(word); // O(L)
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }
        return bfs(patternMap, beginWord, endWord);
    }
};
