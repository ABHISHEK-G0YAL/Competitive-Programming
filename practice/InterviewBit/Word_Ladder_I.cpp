// https://www.interviewbit.com/problems/word-ladder-i/

int Solution::solve(string A, string B, vector<string> &C) {
    if (A == B) {
        return 0;
    }
    unordered_set<string> dict(C.begin(), C.end());
    unordered_set<string> visited;
    queue<string> q;
    q.push(A);
    visited.insert(A);
    int tCount = 1;
    while (!q.empty()) {
        int qSize = q.size();
        while(qSize--) {
            string top = q.front();
            if (top == B) {
                return tCount;
            }
            q.pop();
            for (int i = 0; i < top.length(); i++) {
                string t = top;
                for (char c = 'a'; c <= 'z'; c++) {
                    t[i] = c;
                    if (visited.find(t) == visited.end() && dict.find(t) != dict.end()) {
                        q.push(t);
                        visited.insert(t);
                    }
                }
            }
        }
        ++tCount;
    }
    return 0;
}