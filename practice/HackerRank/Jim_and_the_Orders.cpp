// https://www.hackerrank.com/challenges/jim-and-the-orders/problem

#include <bits/stdc++.h>
using namespace std;

class customer {
public:
    static int totalCustomer;
    int customerNumber;
    int orderNumber;
    int prepTime;
    customer() : customerNumber(totalCustomer++) {}
};
bool servedBefore(const customer &first, const customer &second) {
    if(first.orderNumber + first.prepTime == second.orderNumber + second.prepTime)
        return first.customerNumber < second.customerNumber;
    return first.orderNumber + first.prepTime < second.orderNumber + second.prepTime;
}
int customer::totalCustomer = 1;
int main() {
    int n;
    cin >> n;
    vector<customer> line(n);
    for(auto &customer : line)
        cin >> customer.orderNumber >> customer.prepTime;
    sort(line.begin(), line.end(), servedBefore);
    for(auto &customer : line)
        cout << customer.customerNumber << " ";
    cout << endl;
}
