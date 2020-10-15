vector<string> mostActive(vector<string> customers) {
    float totalTrades = customers.size();
    map<string, int> countTrade;
    for(string &s : customers)
        ++countTrade[s];
    vector<string> activeCustomers;
    for(auto &p : countTrade)
        if(float(p.second) / totalTrades >= 0.05)
            activeCustomers.push_back(p.first);
    return activeCustomers;
}