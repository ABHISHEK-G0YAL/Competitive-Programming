#include <bits/stdc++.h>
using namespace std;

int main() {
    string command = "./paint_tiles_inp_gen >inp";
    for(int i = 0; i < 200; i++) {
        string new_command = command + to_string(i) + ".txt";
        cout << new_command << endl;
        system(new_command.c_str());
    }
}