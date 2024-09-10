#include<iostream>
using namespace std;

int main(){
    long a, b, c;
    cin >> a >> b >> c;
    long Alice = a * a;
    long Bob = b * c;
    if(Alice > Bob){
        cout << "Alice";
    } else {
        cout << "Bob";
    }
}

// int: -32767 ~ 32767