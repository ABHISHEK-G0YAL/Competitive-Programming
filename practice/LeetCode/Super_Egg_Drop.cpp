// https://leetcode.com/problems/super-egg-drop/

// TC - O(KN^2) | Time Limit Exceeded 74 / 121 testcases passed
class Solution1 {
public:
    static int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        for (int k = 1; k <= K; ++k) {
            for (int n = 0; n <= N; ++n) {
                if (k == 1 || n == 1 || n == 0) {
                    dp[k][n] = n;
                    continue;
                }
                // check by droping egg on all floors and minimise to find optimum floor for minimum moves
                for (int i = 1; i <= n; i++) {
                    // take max for the worst of egg break / no break case
                    dp[k][n] = min(long(dp[k][n]), 1L + max(dp[k - 1][i - 1], dp[k][n - i]));
                }
            }
        }
        return dp[K][N];
    }
};

// In Solution 1 in inner loop dp[k - 1][i - 1] is increasing and dp[k][n - i] is decreasing,
// ergo dp[k - 1][i - 1] > dp[k][n - i] is a monotonous step function i.e. false at first then true
// So we can use binary search to optimise inner loop

// TC - O(KNlog(N)) | 327 ms Beats 5.12%
class Solution2 {
public:
    static int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        for (int k = 1; k <= K; ++k) {
            for (int n = 0; n <= N; ++n) {
                if (k == 1 || n == 1 || n == 0) {
                    dp[k][n] = n;
                    continue;
                }
                int low = 1, high = n;
                while (low <= high) {
                    int mid = low + ((high - low) / 2);
                    int breakCase = dp[k - 1][mid - 1];
                    int noBreakCase = dp[k][n - mid];
                    dp[k][n] = min(dp[k][n], 1 + max(breakCase, noBreakCase));
                    if (breakCase > noBreakCase) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return dp[K][N];
    }
};

// This is a recursive take on solution 2
// This is more optimal as there are sub-problems that we do not need
// to calculate at all. In solution 2 while optimised with binary search
// we still calculate all sub-problems in 1...K 1...N loop
// TC - O(KNlog(N)) | 95 ms Beats 31.71%
class Solution3 {
    inline static unordered_map<int, unordered_map<int, int>> mem;
public:
    static int superEggDrop(int k, int n) {
        if (n == 0 || n == 1 || k == 1) {
            return n;
        }
        if (mem[k].find(n) != mem[k].end()) {
            return mem[k][n];
        }
        int minMoves = INT_MAX;
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int breakCount, noBreakCount;

            breakCount = superEggDrop(k - 1, mid - 1);
            noBreakCount = superEggDrop(k, n - mid);

            // key insight (breakCount > noBreakCount) is a monotonus step function
            if (breakCount > noBreakCount) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            minMoves = min(minMoves, 1 + max(breakCount, noBreakCount));
        }

        return mem[k][n] = minMoves;
    }
};


// The idea dp[K][N] = 1 + max(dp[K - 1][i - 1], dp[K][N - i]) for i in 1...N.
// is very brute force, for the reason that you check all possiblity.

// So lets consider this problem in a different way:

// dp[M][K] means that, given K eggs and M moves,
// what is the maximum number of floor that we can check.

// The dp equation is:
// dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1,
// which means we take 1 move to a floor,
// if egg breaks, then we can check dp[m - 1][k - 1] floors.
// if egg doesn't breaks, then we can check dp[m - 1][k] floors.

// dp[m][k] is the number of combinations and it increase exponentially to N

// TC - O(Klog(N)) | 0 ms Beats 100%
class Solution4 {
public:
    static int superEggDrop(int k, int n) {
        vector<int> drop1(k + 1);
        vector<int> drop2(k + 1);
        int moves = 0;
        while (drop2[k] < n) {
            for (int i = 1; i <= k; i++) {
                drop2[i] = drop1[i] + drop1[i - 1] + 1;
            }
            drop1 = drop2;
            ++moves;
        }
        return moves;
    }
};


class Solution {
public:
    int superEggDrop(int K, int N) {
        // return Solution1::superEggDrop(K, N); // TC - O(KN^2)
        // return Solution2::superEggDrop(K, N); // TC - O(KNlog(N))
        // return Solution3::superEggDrop(K, N); // TC - O(KNlog(N))
        return Solution4::superEggDrop(K, N); // TC - O(Klog(N))
    }
};