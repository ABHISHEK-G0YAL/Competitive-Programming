// https://leetcode.com/problems/maximum-gap/

class SolutionNLogN {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
};

class Bucket {
public:
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    bool empty = true;

    void push(int &num) {
        maxVal = max(maxVal, num);
        minVal = min(minVal, num);
        empty = false;
    }
};

// O(n)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());
        // Ceiling is very important here or number of bucket required can be very greater than n (n + 1 or n + 5 won't work). Use integer ceiling or use double for precision float will fail for large integers.
        int smallestPossibleMaxGap = ceil((maxElement - minElement) / double(n - 1));
        int bucketSize = max(1, smallestPossibleMaxGap);
        vector<Bucket> buckets(n);
        for (int &num : nums) {
            int bucketIndex = (num - minElement) / bucketSize;
            buckets[bucketIndex].push(num);
        }

        int maxGap = 0, lastBucket = 0;
        for (int i = 1; i < buckets.size(); i++) {
            if (!buckets[i].empty) {
                maxGap = max(maxGap, buckets[i].minVal - buckets[lastBucket].maxVal);
                lastBucket = i;
            }
        }
        return maxGap;
    }
};