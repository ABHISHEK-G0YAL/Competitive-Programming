// https://leetcode.com/problems/query-kth-smallest-trimmed-number/

// Number of queries: Q
// Number of numbers: N
// Length of each number: D

// O (N X D + Q) - 693 ms
class SolutionOld {
public:
    vector<pair<string, int>> sortByDigit(vector<pair<string, int>>& numsIdx, int place) {
        vector<vector<pair<string, int>>> buckets(10);
        for (auto &[num, idx] : numsIdx) {
            buckets[num[place] - '0'].emplace_back(num, idx);
        }
        vector<pair<string, int>> ans;
        ans.reserve(numsIdx.size());
        for (auto &bucket : buckets) {
            // 1052 ms
            // ans.insert(ans.end(), bucket.begin(), bucket.end());

            // move -> 693 ms
            for (auto &entry : bucket) {
                ans.emplace_back(move(entry));
            }
        }
        return ans;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> queryBuckets(nums[0].size());

        for (int i = 0; i < queries.size(); i++) {
            int &trim = queries[i][1];
            queryBuckets[trim - 1].push_back(i);
        }

        vector<pair<string, int>> numsIdx;
        numsIdx.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numsIdx.emplace_back(nums[i], i);
        }

        vector<int> ans(queries.size());
        int place = nums[0].size() - 1;
        for (auto &queryBucket : queryBuckets) {
            numsIdx = sortByDigit(numsIdx, place);
            for (int &qIdx : queryBucket) {
                int &kSmallest = queries[qIdx][0];
                ans[qIdx] = numsIdx[kSmallest - 1].second;
            }
            --place;
        }
        return ans;
    }
};


// O (N X D + Q) - 175 ms
class Solution {
public:
    vector<int> sortByDigit(vector<string>& nums, vector<int>& numsIdx, int place) {
        vector<vector<int>> buckets(10);
        for (auto &idx : numsIdx) {
            buckets[nums[idx][place] - '0'].emplace_back(idx);
        }
        vector<int> ans;
        ans.reserve(numsIdx.size());
        for (auto &bucket : buckets) {
            // 175 ms
            ans.insert(ans.end(), bucket.begin(), bucket.end());
        }
        return ans;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> queryBuckets(nums[0].size());

        for (int i = 0; i < queries.size(); i++) {
            int &trim = queries[i][1];
            queryBuckets[trim - 1].push_back(i);
        }

        vector<int> numsIdx(nums.size());
        iota(numsIdx.begin(), numsIdx.end(), 0);

        vector<int> ans(queries.size());
        int place = nums[0].size() - 1;
        for (auto &queryBucket : queryBuckets) {
            numsIdx = sortByDigit(nums, numsIdx, place);
            for (int &qIdx : queryBucket) {
                int &kSmallest = queries[qIdx][0];
                ans[qIdx] = numsIdx[kSmallest - 1];
            }
            --place;
        }
        return ans;
    }
};