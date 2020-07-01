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

class Library {
public:
    static ll curr_id;
    ll id, nBooks, nSignupDays, nBookPerDay, scoreSum;
    vector<ll> booksId;
    double tDays, scorePerDay;
    Library() : id(curr_id), scoreSum(0) {
        curr_id += 1;
    }
    void computeFactors() {
        tDays = ((double)nBooks / (double)nBookPerDay) + nSignupDays;
        scorePerDay = (double)scoreSum / tDays;
    }
};
vector<ll> *scoreMap;
bool scorePerDay(const Library &lib1, const Library &lib2) {
    return lib1.scorePerDay > lib2.scorePerDay;
}
bool compBook(ll s1, ll s2) {
    return scoreMap->at(s1) > scoreMap->at(s2);
}
ll Library::curr_id = 0;
int main() {
    fastio;
    ll nBooks, nLibraries, nDays;
    cin >> nBooks >> nLibraries >> nDays;
    vector<ll> bookScores(nBooks);
    priority_queue<pair<ll, ll> > maxBScore;
    for(int id = 0; id < nBooks; id++) {
        cin >> bookScores[id];
        maxBScore.push({bookScores[id], id});
    }
    scoreMap = &bookScores;
    vector<Library> libInfo(nLibraries);
    for(auto &lib : libInfo) {
        cin >> lib.nBooks >> lib.nSignupDays >> lib.nBookPerDay;
        lib.booksId.resize(lib.nBooks);
        for(auto &id : lib.booksId) {
            cin >> id;
            lib.scoreSum += bookScores[id];
        }
        lib.computeFactors();
        sort(lib.booksId.begin(), lib.booksId.end(), compBook);
    }
    sort(libInfo.begin(), libInfo.end(), scorePerDay);
    cout << nLibraries << endl;
    for(auto &lib : libInfo) {
        cout << lib.id << " " << lib.nBooks << endl;
        for(auto &id : lib.booksId)
            cout << id << " ";
        cout << endl;
    }
    return 0;
}