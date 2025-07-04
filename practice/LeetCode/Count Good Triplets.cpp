// https://leetcode.com/problems/count-good-triplets/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < n; k++) {
                        if (abs(arr[j] - arr[k]) <= b
                            && abs(arr[k] - arr[i]) <= c
                        ) {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};