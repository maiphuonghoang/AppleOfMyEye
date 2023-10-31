// DANH SÁCH KỀ SANG DANH SÁCH CẠNH 
#include <bits/stdc++.h>
using namespace std;
/*
5
2 3 4 
1 3 4 5
1 2 4 5
1 2 3 5
2 3 4
=> 
1 2 
1 3
1 4 
2 3
2 4
2 5 
3 4 
3 5 
4 5 
*/
vector<pair<int, int>> edge;
void run(){
    int n; cin >> n;//số lượng đỉnh 
    cin.ignore();
    for (int i = 1; i <= n; i++){
        string s;//xâu s là các đỉnh kề của đỉnh thứ i 
        getline(cin, s);
        stringstream ss(s); string num;
        while(ss >> num){
            if(stoi(num) > i) //đỉnh kề phải > đỉnh hiện tại thì mới đẩy vào dsc 
                edge.push_back({i, stoi(num)});
        }
    }

    //liệt kê danh sách cạnh
    for (auto it: edge)
        cout << it.first << " " << it.second << endl;
}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    run();
    return 0;
}