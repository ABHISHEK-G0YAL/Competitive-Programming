// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    long n = arr.size();
    
    long sum_expected = (n * (n + 1)) / 2;
    long sum_squares_expected = (n * (n + 1) * (2 * n + 1)) / 6;
    
    long sum = 0;
    long sum_squares = 0;
    
    for (const int &i : arr) {
        sum += i;
        sum_squares += (long long)i * i;
    }
    
    // Difference between the actual and expected sums
    long diff_sum = sum - sum_expected;  // A - B
    long diff_squares = sum_squares - sum_squares_expected;  // A^2 - B^2
    
    // A^2 - B^2 = (A - B)(A + B)
    // diff_squares = diff_sum * (A + B)
    
    long sum_ab = diff_squares / diff_sum;  // A + B
    
    // Solving for A and B:
    long A = (diff_sum + sum_ab) / 2;
    long B = sum_ab - A;
    
    // Return the repeated number (A) and the missing number (B)
    return {(int)A, (int)B};
}