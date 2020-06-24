#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n_photos,n_tags;
    string tag;
    char orientation;
    cin>>n_photos;
    vector<pair<int,int> > h_photos;
    vector<pair<int,int> > v_photos;
    for(int i=0;i<n_photos;i++) {
        cin>>orientation;
        cin>>n_tags;
        for(int j=0;j<n_tags;j++) cin>>tag;
        if(orientation=='H')
            h_photos.pb(mp(n_tags,i));
        else
            v_photos.pb(mp(n_tags,i));
    }
    sort(h_photos.begin(),h_photos.end());
    sort(v_photos.begin(),v_photos.end());
    cout<<h_photos.size()+v_photos.size()/2<<endl;
    for(int i=0;i<h_photos.size();i++)
        cout<<h_photos[i].second<<endl;
    for(int i=0;i<v_photos.size();i+=2)
        cout<<v_photos[i].second<<" "<<v_photos[i+1].second<<endl;
}


// ./slideshow_maker_random <a_example.txt >a_out.txt
// ./slideshow_maker_random <b_lovely_landscapes.txt >b_out.txt
// ./slideshow_maker_random <c_memorable_moments.txt >c_out.txt 
// ./slideshow_maker_random <d_pet_pictures.txt >d_out.txt 
// ./slideshow_maker_random <e_shiny_selfies.txt >e_out.txt 