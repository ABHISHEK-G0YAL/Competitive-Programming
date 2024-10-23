// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
    bool isWord = false;
    vector<Trie*> children = vector<Trie*>(26, NULL);
public:
    void insert(string word) {
        Trie *temp = this;
        for (char c : word) {
            c = c - 'a';
            if (!temp->children[c]) {
                temp->children[c] = new Trie();
            }
            temp = temp->children[c];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        Trie *temp = this;
        for (char c : word) {
            c = c - 'a';
            if (!temp->children[c]) {
                return false;
            }
            temp = temp->children[c];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie *temp = this;
        for (char c : prefix) {
            c = c - 'a';
            if (!temp->children[c]) {
                return false;
            }
            temp = temp->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */