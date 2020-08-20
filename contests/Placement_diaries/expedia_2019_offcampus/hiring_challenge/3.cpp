
unordered_map<int,unordered_map<int,int>> dp;

int find(vector<int> &v,int i,int last) {
    if(i>=v.size())return 0;
    if(dp.count(i)==1 && dp[j].count(last)==1){
        return dp[i][last];
    }
    int x=0,y=0;
    if(v[i]%last==0){
        x=1+find(v,i+1,v[i]);
    }
    y=find(v,i+1,last);

    dp[i][last]=max(x,y);
    return max(x,y);
}
int main(){
    dp.clear();
    sort(v.begin(),v.end());
    return find(v,0,1);
}