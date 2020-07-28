// https://leetcode.com/problems/ugly-number-ii/
// TLE

#define N 1000000
class Solution {
public:
    int nthUglyNumber(int n) {
        bool arr[N] = {0, 1};
        for(int i = 2; i < N / 2; i++) {
            if(!arr[i]) {
                for(int j = i; j < N; j += i) {
                    if(i <= 5)
                        arr[j] = true;
                    else
                        arr[j] = false;
                }
            }
        }
        for(int i = 0; i < N; i++) {
            if(arr[i])
                un.push_back(i);
        }
        cout << un.size();
        return un[n - 1];
    }
};
vector<int> Solution::un;