#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define inf 2147480000
#define linf 9223372036800000000
#define PI 3.1415926535897932384626433832795
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define contains(c,x) ((c).find(x) != (c).end())
#define acontains(c,x) (find(all(c),x) != (c).end())
#define watch(x) cout << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
const double pi = acos(-1.0);

vector<ll> *scoreMap;
class Library {
public:
    static ll curr_id;
    ll id, nBooks, nSignupDays, nBookPerDay, scoreSum;
    vector<ll> booksId; // v3 hash this(change to unordered_set)
    double tDays, scorePerDay;
    Library() : id(curr_id) {
        curr_id += 1;
    }
    void sumScores() {
        scoreSum = 0;
        for(auto &id : booksId)
            scoreSum += scoreMap->at(id);
    }
    void computeFactors() {
        sumScores();
        tDays = ((double)nBooks / (double)nBookPerDay) + nSignupDays;
        scorePerDay = (double)scoreSum / tDays;
    }
};
bool scorePerDay(const Library &lib1, const Library &lib2) {
    return lib1.scorePerDay > lib2.scorePerDay;
}
bool compBook(const ll &id1, const ll &id2) {
    return scoreMap->at(id1) > scoreMap->at(id2);
}
ll Library::curr_id = 0;
int main() {
    fastio;
    ll nBooks, nLibraries, nDays;
    cin >> nBooks >> nLibraries >> nDays;
    vector<ll> bookScores(nBooks);
    for(ll &score : bookScores)
        cin >> score;
    scoreMap = &bookScores;
    deque<Library> libInfo(nLibraries);
    for(auto &lib : libInfo) {
        cin >> lib.nBooks >> lib.nSignupDays >> lib.nBookPerDay;
        lib.booksId.resize(lib.nBooks);
        for(auto &id : lib.booksId)
            cin >> id;
    }
    ll currDay = 0, bCount;
    cout << nLibraries << endl;
    while(!libInfo.empty()) {
        for(auto &lib : libInfo)
            lib.computeFactors();
        sort(libInfo.begin(), libInfo.end(), scorePerDay);
        auto &lib = libInfo.front();
        currDay += lib.nSignupDays;
        bCount = min((nDays - currDay) * lib.nBookPerDay, lib.nBooks);
        if(bCount < 1) bCount = 1;
        cout << lib.id << " " << bCount << endl;
        sort(lib.booksId.begin(), lib.booksId.end(), compBook);
        for(int i = 0; i < bCount; i++) {
            cout << lib.booksId[i] << " ";
            bookScores[lib.booksId[i]] = 0;
        } cout << endl;
        libInfo.pop_front();
    }
    return 0;
}