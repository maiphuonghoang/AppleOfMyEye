#include <bits/stdc++.h>
using namespace std;

//lower_bound(iter1, iter2, key) [iter1, iter2)
//Trả về vị trí của phần tử đầu tiên >= key 

//upper_bound(iter1, iter2, key) [iter1, iter2)
//Trả về vị trí của phần tử đầu tiên > key 
void bound(){
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; cout << a[i] << " ";
    }cout << endl;

    auto it = lower_bound(a, a+n, x);
    cout << *it << endl;//giá trị của iterator 
    cout << it - a << endl;//chỉ số của iterator 
    if(it == (a + n))
        cout << "Khong co phan tu nao trong mang"<<endl;

    vector<int> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }cout << endl;
    auto inter = upper_bound(v.begin(), v.end(),x);
    cout << *inter << endl;//giá trị của iterator 
    cout << inter - v.begin() << endl;//vị trí phần tử 
    if(inter == (v.end()))
        cout << "Khong co phan tu nao trong mang"<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    bound();
    return 0;
}