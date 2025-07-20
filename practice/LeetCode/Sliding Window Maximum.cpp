// https://leetcode.com/problems/sliding-window-maximum/

class SolutionBST {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mset;
        vector<int> maxOfWindow;
        maxOfWindow.reserve(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                // // This erases all instance of num
                // mset.erase(nums[i - k]);

                mset.erase(mset.find(nums[i - k]));
            }
            mset.insert(nums[i]);
            if (mset.size() == k) {
                maxOfWindow.push_back(*mset.rbegin());
            }
        }
        return maxOfWindow;
    }
};

class SolutionHeap {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> maxOfWindow;
        maxOfWindow.reserve(nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            heap.push({nums[i], i});

            if (i >= k - 1) {
                // Remove elements outside the window
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                maxOfWindow.push_back(heap.top().first);
            }
        }
        return maxOfWindow;
    }
};

class SolutionDeque {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // (val, index) -> can be optimised to just index
        deque<pair<int, int>> deque;
        vector<int> maxOfWindow;
        maxOfWindow.reserve(nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            while (!deque.empty() && deque.back().first < nums[i]) {
                deque.pop_back();
            }
            while (!deque.empty() && deque.front().second <= i - k) {
                deque.pop_front();
            }
            deque.push_back({nums[i], i});
            if (i >= k - 1) {
                maxOfWindow.push_back(deque.front().first);
            }
        }
        return maxOfWindow;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // SolutionBST *solution = new SolutionBST();
        // SolutionHeap *solution = new SolutionHeap();
        SolutionDeque *solution = new SolutionDeque();
        return solution->maxSlidingWindow(nums, k);
    }
};