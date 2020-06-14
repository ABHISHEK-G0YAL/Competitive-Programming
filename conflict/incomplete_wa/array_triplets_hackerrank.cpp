#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void allSubsets(int n,vector<int> &a,ll &sm,vector<pair<ll,vector<int> > > &powerset,vector<int> set={}){
    if(n==0) {
        if(!set.empty()) {
            ll sum=0;
            for(auto it=set.begin();it!=set.end();it++)
                sum+=a[*it];
            if(sum == sm)
                powerset.pb(mp(sum,set));
        }
        return;
    }
    allSubsets(n-1,a,sm,powerset,set);
    set.pb(n-1);
    allSubsets(n-1,a,sm,powerset,set);
}

// Complete the solve function below.
int solve(vector<int> a){
    ll n=a.size(),sm=0,triplets=0;
    bool dp[n];
    for(int i=0;i<n;i++)
        sm+=a[i];
    if(sm % 3 == 0)
        sm/=3;
    else
        return 0;
    vector<pair<ll,vector<int> > > powerset;
    allSubsets(n,a,sm,powerset);
    // sort(powerset.begin(),powerset.end());
    // cout<<powerset.size()<<endl;
    // for(auto it=powerset.begin();it!=powerset.end();it++){
    //     cout<<"sum = "<<(*it).first<<"\tindices = ";
    //     for(auto it2=((*it).second).begin();it2!=((*it).second).end();it2++)
    //         cout<<*it2<<" ";
    //     cout<<endl;
    // }
    for(auto i=powerset.begin();i!=powerset.end();i++){
        memset(dp,0,n);
        for(auto x=((*i).second).begin();x!=((*i).second).end();x++)
            dp[*x]=true;
        for(auto j=i+1;j!=powerset.end();j++){
            for(auto y=((*j).second).begin();y!=((*j).second).end();y++)
                if(dp[*y]==true)
                    break;
            if(y==((*j).second).end())
                triplets+=2;
        }
    }
    return triplets;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = solve(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
