// DÃY CON TĂNG DÀI NHẤT
#include <bits/stdc++.h>
using namespace std;
/**
14
128 104 53 576 668 961 754 775 290 231 335 915 392 994 
=> 6   
*/
void dayConTangDaiNhat(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector <int> L(n, 1); //khởi tại tất cả ptu trong vector có giá trị là 1

    for (int i = 0; i<n; i++){
        //L[i]: độ dài của dãy con tăng dài nhất kết thức ở chỉ số i 
        //L[i] = max[L[i], L[j] + 1]; j là những ptu đứng trước i
        //duyệt qua từng phần tử đứng trước chỉ số i
        for (int j = 0; j < i; j++){
            //đưa a[i] vào được dãy con tăng dần kết thúc ở chỉ số 
            if(a[i] > a[j])
                L[i] = max(L[i], L[j]+1);
        }
    }
    //in ra phần tử lớn nhất trong L 
    cout << *max_element(L.begin(), L.end()) << endl;


}
//----------------------------------------------------------------
/**
 * Given an integer array nums, return the number of longest increasing subsequences.
 * Notice that the sequence has to be strictly increasing.
5
1 3 5 4 7
=>
L[i]     = 1 2 3 3 4
count[i] = 1 1 1 1 2
5
2 2 2 2 2
=> 5
L[i]     = 1 1 1 1 1
count[i] = 1 1 1 1 1
*/
void SoLuongDayConTangDaiNhat(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
        vector<int> L(n, 1);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if(a[i] > a[j]){
                    if (L[j] + 1 > L[i]) {
                        L[i] = L[j] + 1;
                        count[i] = count[j];
                    } else if (L[j] + 1 == L[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            cout << L[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++){
            cout << count[i] << " ";
        }
        int max_length =  *max_element(L.begin(), L.end());
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] == max_length) {
                result += count[i];
            }
        }

        cout << result << endl;
}

void InDayConTangDaiNhat(){//hiện tại chỉ in ra được 1 case 
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int Ljmax, jmax;
    vector<int> L(n, 1);
    vector<int> T(n, -1);
    T[0] = 0;
    for (int i = 1; i < n; i++){
        Ljmax = 0; jmax = i;
        for (int j = 0; j < i; j++){
            if(a[j] <= a[i] && Ljmax<L[j]){
                Ljmax = L[j];
                jmax = j;
            }
        }
        L[i] = Ljmax + 1;
        T[i] = jmax;
    }
    for (int i = 0; i < n; i++){
        cout << T[i] << " ";
    }

}
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    dayConTangDaiNhat();
    return 0;
}