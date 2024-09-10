#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n = -1;
    int a ,b;
    cin >> a >> b;
    int c = pow(a, b);
    if (c < 0){
        cout << n;
    } else {
        cout << c;
    }
}