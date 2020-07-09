// https://www.hackerrank.com/challenges/operator-overloading/problem
// Accepted


class Matrix {
public:
    vector<vector<int> > a;
    Matrix operator+ (Matrix b) {
        for(int i = 0; i < b.a.size(); i++)
            for(auto j = 0; j < b.a[0].size(); j++)
                b.a[i][j] += a[i][j];
        return b;
    }
};
