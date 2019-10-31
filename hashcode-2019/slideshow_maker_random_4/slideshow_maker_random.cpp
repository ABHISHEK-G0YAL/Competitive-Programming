#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

class photo {
    public:
        int identity;
        int n_tags;
        char orient;
};

bool cmpNtags(photo p1,photo p2) {
    return p1.n_tags<p2.n_tags;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n_photos;
    cin>>n_photos;
    photo p;
    string ignore_line;
    vector<photo> photos;
    for(int i=0;i<n_photos;i++) {
        p.identity=i;
        cin>>p.orient;
        cin>>p.n_tags;
        getline(cin,ignore_line);
        photos.pb(p);
    }
    sort(photos.begin(),photos.end(),cmpNtags);
    int count_slides=0;
    for(int i=0;i<photos.size();) {
        if(photos[i].orient=='H') {
            count_slides++;
            i++;
        }
        else if(photos[i+1].orient=='V') {
            count_slides++;
            i+=2;
        }
        else i++;
    } cout<<count_slides<<endl;
    for(int i=0;i<photos.size();) {
        if(photos[i].orient=='H') {
            cout<<photos[i].identity<<endl;
            i++;
        }
        else if(photos[i+1].orient=='V') {
            cout<<photos[i].identity<<" "<<photos[i+1].identity<<endl;
            i+=2;
        }
        else i++;
    }
}


// ./slideshow_maker_random <a_example.txt >a_out.txt
// ./slideshow_maker_random <b_lovely_landscapes.txt >b_out.txt
// ./slideshow_maker_random <c_memorable_moments.txt >c_out.txt 
// ./slideshow_maker_random <d_pet_pictures.txt >d_out.txt 
// ./slideshow_maker_random <e_shiny_selfies.txt >e_out.txt 