// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

#include <bits/stdc++.h>

using namespace std;

int designerPdfViewer(vector <int> h, string word) {
    // Complete this function
    int max=0;
    for(int i =0;i<word.length();i++)
        if(h[word[i]-'a']>max)
            max=h[word[i]-'a'];
    return max*word.length();
}

int main() {
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    int result = designerPdfViewer(h, word);
    cout << result << endl;
    return 0;
}
