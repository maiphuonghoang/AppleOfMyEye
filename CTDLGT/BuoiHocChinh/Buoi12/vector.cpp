#include <bits/stdc++.h>

using namespace std;
void basicVector(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    cout << v.back() << " " << v.size() << endl;
    cout << "Phan tu dau tien cua vector " << v[0] << endl;
    cout << "Phan tu cuoi cung cua vector " << v[v.size() - 1] <<" or "<< v.back() << endl;

    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    for (int x : v) 
        cout << x << " ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
        cout << *it << " ";
    // vector<int>::iterator  toán tử phạm vi - khai báo iterator cho vector 
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
        cout << *(v.begin() + 1);//v.begin + index = v[index]
    }
    
    //NHẬP 
    int n;
    vector<int> v1(n);//= int a[n] //khai báo vector đã có sẵn n ptu 
    vector<int> v2[n]; //khai báo 1 mảng các vector 
    for (int i = 0; i < n; i++)
        cin >> v1[i] ;
    //nếu chưa khai báo kích thước thì 
    vector<int> v3;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v3.push_back(x);
    } 
    //khai báo và khởi tạo luôn giá trị 
    vector<int> v4(n, 100);//tất cả ptu đều có gtri 100
    v4.push_back(50);//vẫn có thể nới rộng 
    
    string s = "ngon ngu  lap trinh    ";
    stringstream ss(s);
    string token;
    vector<string> vs; 
    while (ss >> token) 
        vs.push_back(token);
    for (string x : vs) cout << x;
    
}

int main() {
    basicVector();
    return 0;
}