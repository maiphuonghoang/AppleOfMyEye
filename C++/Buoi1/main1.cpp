#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    cout << "Xin chao\n"; // << là extraction operator 
    cout << "Ngon ngu C++" << endl;
    
    cout << INT_MIN << " " << INT_MAX << endl;
    cout << LLONG_MIN << " " << LLONG_MAX << endl;

    float x = 3.141592653589793;
    cout << fixed << setprecision(3) << x << endl;//in ra số với 3 số đằng sau dấu thập phân 

    bool check = false;
    cout << true << " " << check << endl;

    int a,b,c;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << endl;

    return 0;
}