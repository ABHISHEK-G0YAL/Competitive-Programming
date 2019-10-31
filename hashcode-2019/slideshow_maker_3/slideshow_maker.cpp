#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class photo {
    public:
        int n_tags;
        int identity;
        vector<string> tags;
};

bool cmpNtags(photo p1,photo p2) {
    return p1.n_tags<p2.n_tags;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n_photos;
    char orientation;
    cin>>n_photos;
    photo p;
    vector<photo> h_photos;
    vector<photo> v_photos;
    for(int i=0;i<n_photos;i++) {
        cin>>orientation;
        p.identity=i;
        cin>>p.n_tags;
        p.tags.resize(p.n_tags);
        for(int j=0;j<p.n_tags;j++)
            cin>>p.tags[j];
        sort(p.tags.begin(),p.tags.end());
        if(orientation=='H')
            h_photos.pb(p);
        else
            v_photos.pb(p);
    }
    sort(h_photos.begin(),h_photos.end(),cmpNtags);
    sort(v_photos.begin(),v_photos.end(),cmpNtags);
    cout<<h_photos.size()+v_photos.size()/2<<endl;
    for(int i=0;i<v_photos.size();i+=2)
        cout<<v_photos[i].identity<<" "<<v_photos[i+1].identity<<endl;
    for(int i=0;i<h_photos.size();i++)
        cout<<h_photos[i].identity<<endl;
}


// ./slideshow_maker <a_example.txt >a_out.txt
// ./slideshow_maker <b_lovely_landscapes.txt >b_out.txt
// ./slideshow_maker <c_memorable_moments.txt >c_out.txt 
// ./slideshow_maker <d_pet_pictures.txt >d_out.txt 
// ./slideshow_maker <e_shiny_selfies.txt >e_out.txt 
