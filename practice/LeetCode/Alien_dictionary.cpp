// https://leetcode.com/problems/alien-dictionary/description/
// https://www.naukri.com/code360/problems/alien-dictionary_630423/

string getAlienLanguage(vector<string> &dictionary, int k) {
    unordered_map<char, unordered_set<char>> adj;
    set<char> alphabet(dictionary[0].begin(), dictionary[0].end());
    for (int i = 1; i < dictionary.size(); ++i) {
        alphabet.insert(dictionary[i].begin(), dictionary[i].end());
        int length = min(dictionary[i - 1].length(), dictionary[i].length());
        bool allCharSame = true;
        for (int j = 0; j < length; ++j) {
            if (dictionary[i - 1][j] != dictionary[i][j]) {
                adj[dictionary[i - 1][j]].insert(dictionary[i][j]);
                allCharSame = false;
                break;
            }
        }
        if (dictionary[i - 1].length() > dictionary[i].length() && allCharSame) {
            return "";
        }
    }
    unordered_map<char, int> indegree;
    for (auto &[c, v] : adj) {
        for (auto ch : v) {
            ++indegree[ch];
        }
    }
    queue<char> q;
    for (char ch : alphabet) {
        if (indegree[ch] == 0) {
            q.push(ch);
        }
    }
    string charOrder;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        for (auto ch : adj[c]) {
            --indegree[ch];
            if (indegree[ch] == 0) {
                q.push(ch);
            }
        }
        charOrder += c;
    }
    return charOrder.length() == alphabet.size() ? charOrder : "";
}