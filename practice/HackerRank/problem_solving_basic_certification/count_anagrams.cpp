vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    unordered_map<string, int> anagramCount;
    for(string &s : dictionary) {
        sort(s.begin(), s.end());
        ++anagramCount[s];
    }
    vector<int> queryAnagramCount;
    for(string &s : query) {
        sort(s.begin(), s.end());
        queryAnagramCount.push_back(anagramCount[s]);
    }
    return queryAnagramCount;
}