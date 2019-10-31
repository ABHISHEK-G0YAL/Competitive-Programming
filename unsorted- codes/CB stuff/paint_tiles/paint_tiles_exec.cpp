#include <bits/stdc++.h>
using namespace std;

int main() {
    string command = "./paint_tiles_2 <inp";
    for(int i = 150; i < 200; i++) {
        string new_command = command + to_string(i) + ".txt >out" + to_string(i) + ".txt";
        cout << new_command << endl;
        system(new_command.c_str());
    }
}