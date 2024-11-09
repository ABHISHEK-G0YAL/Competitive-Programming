https://www.naukri.com/code360/problems/implement-trie_1387095

#include <bits/stdc++.h>

class Trie{
    int prefixCount = 0;
    int wordCount = 0;
    unordered_map<char, Trie*> children;

public:
    void insert(string &word){
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
            node->prefixCount += 1;
        }
        node->wordCount += 1;
    }

    int countWordsEqualTo(string &word){
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) != node->children.end()) {
                node = node->children[c];
            } else {
                return 0;
            }
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string &word){
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) != node->children.end()) {
                node = node->children[c];
            } else {
                return 0;
            }
        }
        return node->prefixCount;
    }

    void erase(string &word){
        Trie* node = this;
        for (char c : word) {
            node = node->children[c];
            node->prefixCount -= 1;
        }
        node->wordCount -= 1;
    }
};