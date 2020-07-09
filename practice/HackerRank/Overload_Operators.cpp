// https://www.hackerrank.com/challenges/overload-operators/problem
// Accepted


Complex operator + (Complex &x, Complex &y) {
    return {x.a + y.a, x.b + y.b};
}
ostream& operator << (ostream& cout, Complex &x) {
    return cout << x.a << "+i" << x.b;
}
