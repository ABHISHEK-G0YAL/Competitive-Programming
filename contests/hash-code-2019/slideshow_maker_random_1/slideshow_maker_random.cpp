#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n_photos,n_tags;
    string ignore_line;
    char orientation;
    cin>>n_photos;
    vector<int> h_photos;
    vector<int> v_photos;
    for(int i=0;i<n_photos;i++) {
        cin>>orientation;
        getline(cin,ignore_line);
        if(orientation=='H')
            h_photos.pb(i);
        else
            v_photos.pb(i);
    }
    cout<<h_photos.size()+v_photos.size()/2<<endl;
    for(int i=0;i<h_photos.size();i++)
        cout<<h_photos[i]<<endl;
    for(int i=0;i<v_photos.size();i+=2)
        cout<<v_photos[i]<<" "<<v_photos[i+1]<<endl;
}


// ./slideshow_maker_random <a_example.txt >a_out.txt
// ./slideshow_maker_random <b_lovely_landscapes.txt >b_out.txt
// ./slideshow_maker_random <c_memorable_moments.txt >c_out.txt 
// ./slideshow_maker_random <d_pet_pictures.txt >d_out.txt 
// ./slideshow_maker_random <e_shiny_selfies.txt >e_out.txt 