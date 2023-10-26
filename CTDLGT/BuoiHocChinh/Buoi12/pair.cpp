#include <bits/stdc++.h>
using namespace std;
void basicPair(){
    pair<int, int> p1 = make_pair(100, 200);
    pair<int, int> p2 = {100, 200};
    pair<int, int> p3 {300, 200};
    cout << p1.first << " " << p2.second << " " << p3.first<<endl;
}
void basicTuple(){
    tuple<int, int, int> t1 {1,2,3};
    tuple<int, int, int> t2 =  {1,2,3};
    tuple<string, string, int, int > t3 = make_tuple("java", "c++", 100, 2);
    cout << get<0>(t1) << " " << get<2>(t2) << " " << get<1>(t3)<< endl;
}
int main() {
    basicTuple();
    return 0;
}