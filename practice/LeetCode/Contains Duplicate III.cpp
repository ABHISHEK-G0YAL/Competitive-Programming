https://leetcode.com/problems/contains-duplicate-iii/

// O(N Log N)
class SolutionNLogN {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> window;
        for (int i = 0; i < n; i += 1) {
            if(i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            // first num >= (nums[i] - valueDiff)
            auto it = window.lower_bound(nums[i] - valueDiff);

            // check if num exists and (num <= nums[i] + valueDiff)
            if (it != window.end() && *it <= nums[i] + valueDiff) {
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};

// O(N)
class SolutionOld {
    int bucket_size;
public:
    int getBucketId(int num) {
        return num < 0
            ? (num + 1) / bucket_size - 1
            : num / bucket_size;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // first -> number, second -> index
        unordered_map<int, pair<int, int>> buckets;
        bucket_size = valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove the number that is now outside the sliding window.
            if (i > indexDiff) {
                int old_bucket_id = getBucketId(nums[i - indexDiff - 1]);
                if (buckets[old_bucket_id].second <=  i - indexDiff - 1) {
                    buckets.erase(old_bucket_id);
                }
            }

            int bucket_id = getBucketId(nums[i]);

            // If bucket already has a number, it's close enough in value (<= valueDiff) and index (in window)
            if (buckets.count(bucket_id)) {
                return true;
            }
            // Check left bucket — it may hold a close value near current's lower bound
            if (buckets.count(bucket_id - 1)) {
                if (abs(nums[i] - buckets[bucket_id - 1].first) <= valueDiff) {
                    return true;
                }
            }
            // Check right bucket — it may have a close value near current's upper bound
            if (buckets.count(bucket_id + 1)) {
                if (abs(nums[i] - buckets[bucket_id + 1].first) <= valueDiff) {
                    return true;
                }
            }
            // Add the current number to its bucket.
            buckets[bucket_id] = { nums[i], i };
        }
        return false;
    }
};

// O(N)
class Solution {
    int bucket_size;
public:
    int getBucketId(int num) {
        return num < 0
            ? (num + 1) / bucket_size - 1
            : num / bucket_size;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> buckets;
        bucket_size = valueDiff + 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                int old_bucket_id = getBucketId(nums[i - indexDiff - 1]);
                buckets.erase(old_bucket_id);
            }
            int bucket_id = getBucketId(nums[i]);
            
            // no need to store orginal index since we never overwrite if same bucke exists
            if (buckets.count(bucket_id)) {
                return true;
            }
            if (buckets.count(bucket_id - 1)) {
                if (abs(nums[i] - buckets[bucket_id - 1]) <= valueDiff) {
                    return true;
                }
            }
            if (buckets.count(bucket_id + 1)) {
                if (abs(nums[i] - buckets[bucket_id + 1]) <= valueDiff) {
                    return true;
                }
            }
            buckets[bucket_id] = nums[i];
        }
        return false;
    }
};