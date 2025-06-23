// https://leetcode.com/problems/longest-consecutive-sequence/

class UnionFind {
public:
    unordered_map <int, int> parent;
    unordered_map <int, int> size;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }

    void add(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            size[x] = 1;
        }
    }
};

// Using Union find
class SolutionA {
public:
    static int longestConsecutive(vector<int>& nums) {
        UnionFind uf;
        for(int num : nums) {
            uf.add(num);
        }

        // Union consecutive elements
        for (int num : nums) {
            if (uf.parent.find(num + 1) != uf.parent.end()) {
                uf.join(num, num + 1);
            }
        }

        // Get largest set
        int largest = 0;
        for (int num : nums) {
            largest = max(largest, uf.size[num]);
        }
        return largest;
    }
};

// Using hashmap
class SolutionB {
public:
    static int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums) {
            // start of sequence
            if (s.find(num - 1) == s.end()) {
                int current = 1;
                while (s.find(num + current) != s.end()) {
                    ++current;
                }
                longest = max(longest, current);
            }
        }
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return SolutionA::longestConsecutive(nums);
        // return SolutionB::longestConsecutive(nums);
    }
};