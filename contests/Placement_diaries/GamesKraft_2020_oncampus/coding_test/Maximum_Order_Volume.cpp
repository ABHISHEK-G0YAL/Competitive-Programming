// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/practice/Misc/Maximum_Order_Volume.md

bool cmp_customer_by_end(customer c1, customer c2) {
    return c1.end <= c2.end;
}

class customer {
public:
    int start, duration, end, order_s;
    customer() {}
    customer(int s, int d, int o) {
        start = s;
        duration = d;
        end = s + d;
        order_s = o;
    }
};

unordered_map<int, unordered_map<int, int>> mem;
int solve(vector<customer> &cs, int i = 0, int last = 0) {
    if(i == int(cs.size()))
        return 0;
    if(mem.find(i) != mem.end() and mem[i].find(last) != mem[i].end())
        return mem[i][last];
    int a1 = 0, a2 = 0;
    if(last < cs[i].start)
        a1 = cs[i].order_s + solve(cs, i + 1, cs[i].end);
    a2 = solve(cs, i + 1, last);
    return mem[i][last] = max(a1, a2);
}

int order(vector<int> s, vector<int> d, vector<int> o) {
    mem.clear();
    int n = s.size();
    vector<customer> cs(n);
    for(int i = 0; i < n; ++i)
        cs[i] = customer(s[i], d[i], o[i]);
    sort(cs.begin(), cs.end(), cmp_customer_by_end);
    return solve(cs);
}