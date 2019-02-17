#include <bits/stdc++.h>
using namespace std;

bool chkb(pair<char,char> card)
{
    if(card.first=='b' || card.second=='b')
        return true;
    else
        return false;
}

bool chko(pair<char,char> card)
{
    if(card.first=='o' || card.second=='o')
        return true;
    else
        return false;
}

bool chkbob(vector<pair<char,char> > cards)
{
    if(chkb(cards[0]) && chko(cards[1]) && chkb(cards[2]))
        return true;
    else if(chko(cards[0]) && chkb(cards[1]) && chkb(cards[2]))
        return true;
    else if(chkb(cards[0]) && chkb(cards[1]) && chko(cards[2]))
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<char,char> > cards(3);
        for(int i=0;i<3;i++)
            cin>>cards[i].first;
        for(int i=0;i<3;i++)
            cin>>cards[i].second;
        if(chkbob(cards))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
