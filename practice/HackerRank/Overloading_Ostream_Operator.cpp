// https://www.hackerrank.com/challenges/overloading-ostream-operator/problem
// Accepted



ostream& operator << (ostream& cout, Person p) {
    return cout << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
}
