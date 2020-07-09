// https://www.hackerrank.com/challenges/inherited-code/problem
// Accepted


class BadLengthException {
    int len;
    public:
    BadLengthException(int n) {
        len=n;
    }
    int what() {
        return len;
    }
};
