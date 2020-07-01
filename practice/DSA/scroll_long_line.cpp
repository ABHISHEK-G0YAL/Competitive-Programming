#include <iostream>
using namespace std;

void sleep() {
        for(int i=0;i<5000000;i++);
}

int main() {
        int window_size = 12;
        string s = "This is a very very long line. This is a very very long line. This is a very very long line.";
        while(s.length() >= window_size) {
                system("cls");
                cout << s.substr(0, window_size) << flush;
                s = s.substr(1);
                sleep();
        }
}