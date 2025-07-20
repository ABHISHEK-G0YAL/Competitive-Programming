// https://leetcode.com/problems/search-suggestions-system/

class SolutionMap {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string &searchWord) {
        sort(products.begin(), products.end());
        unordered_map<string, vector<int>> mp;
        for (int idx = 0; idx < products.size(); ++idx) {
            string &product = products[idx];
            for (int i = 1; i <= product.length(); i++) {
                vector<int> &vList = mp[product.substr(0, i)];
                if (vList.size() < 3) {
                    mp[product.substr(0, i)].push_back(idx);
                }
            }
        }
        vector<vector<string>> suggestedProducts;
        for (int i = 1; i <= searchWord.length(); ++i) {
            vector<string> temp;
            for (int j : mp[searchWord.substr(0, i)]) {
                temp.push_back(products[j]);
            }
            suggestedProducts.push_back(temp);
        }
        return suggestedProducts;
    }
};

class SolutionBS {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0, n = products.size();
        string prefix;
        for (char &c : searchWord) {
            prefix += c;
            start = lower_bound(
                products.begin() + bsStart,
                products.end(),
                prefix
            ) - products.begin();

            result.push_back({});

            for (int i = start; i < min(start + 3, n); i++) {
                if (products[i].compare(0, prefix.length(), prefix) == 0) {
                    result.back().push_back(products[i]);
                }
            }

            // Reduce the size of elements to binary search on since we know
            bsStart = start;
        }
        return result;
    }
};

struct TrieNode {
    TrieNode* children[26] = {};  // 26 lowercase letters
    bool isEnd = false;
    vector<string*> top3;
};

class SolutionTrie {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        sort(products.begin(), products.end());
        TrieNode* root = new TrieNode();
        for (auto &product : products) {
            TrieNode* lastNode = root;
            for (char c : product) {
                if (!lastNode->children[c - 'a']) {
                    lastNode->children[c - 'a'] = new TrieNode();
                }
                lastNode = lastNode->children[c - 'a'];
                if (lastNode->top3.size() < 3) {
                    lastNode->top3.emplace_back(&product);
                }
            }
            lastNode->isEnd = true;
        }
        vector<vector<string>> result;
        TrieNode* lastNode = root;
        for (char &c : searchWord) {
            result.push_back({});
            if (lastNode) {
                lastNode = lastNode->children[c - 'a'];
            }
            if (lastNode) {
                for (auto &s : lastNode->top3) {
                    result.back().push_back(*s);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        // SolutionMap *solution = new SolutionMap();
        // SolutionTrie *solution = new SolutionTrie();
        SolutionBS *solution = new SolutionBS();
        return solution->suggestedProducts(products, searchWord);
    }
};