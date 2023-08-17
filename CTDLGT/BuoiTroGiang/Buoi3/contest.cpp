#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


/**
2352
2*1000 + 3*100+ 50 + 2
Số lượng = số tiền / mệnh giá 
2*1000 => 2352/1000=2 => thừa = 2352%1000 = 352  
*/

void doiTienThamLam(){
    int tien[] = {1000,500,200,100,50,20,10,5,2,1};
    long long n; cin >> n;
    long long cnt = 0;
    int i = 0;
    while (n!=0){
        cnt += n / tien[i];
        n = n % tien[i];
        i++;
    }
    cout << cnt << endl;
} 
//----------------------------------------------------------------
/**
888 289 123
321 54 888
=> 
888 2
123 1
289 1
*/
int checkKhongGiam(int n){
    while (n>=10){//chừng nào còn 2 chữ số thì mới check 
        int r = n%10;
        int l = n/10%10;
        if(r < l) return 0;
        n = n/10;
    }
    return 1;
}
bool cmplietKeVaDem(pair<int, int> a, pair<int, int> b){
    //In ra theo số lần xuất hiện giảm dần, trong trường hợp 
    //cùng số lần xuất hiện thì số nhỏ hơn sẽ xếp trước 
    if(a.second != b.second) 
        return a.second > b.second;
    return a.first < b.first;
}
//Nếu đề bài yêu cầu tiêu chí phụ: số nào xuất hiện trước in ra trước 
//thì trong cmp chỉ có tiêu chí chính, tiêu chí phụ thì dùng stable_sort 
bool cmplietKeVaDemXh(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) 
        return a.second > b.second;
}

void lietKeVaDem(){
    map<int, int> mp;
    int n; 
    //Dùng khi cho đầu vào không có số lượng phần tử  
    while (cin >> n){//cứ lặp đi đến chừng nào còn cin được 
        if(checkKhongGiam(n))
            mp[n]++;
    }
    //in ra biến map
    for (auto it : mp) cout << it.first << '-' << it.second <<' ';
    //đổ dữ liệu từ trong map vào vector 
    vector <pair<int, int>> v;
    for (auto it : mp) 
        v.push_back(it);
    sort(v.begin(), v.end(), cmplietKeVaDem);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
    stable_sort(v.begin(), v.end(), cmplietKeVaDemXh);
    for (auto it : v) cout << it.first << '-' << it.second <<' ';
}
//----------------------------------------------------------------
//chinh: sx theo trị tuyệt đối tăng dần
//phụ: sx trước in ra trước  
//2 -3 3 3 -5 5 -5
bool cmpthuTuSort(int a, int b) {
    // if(abs(a) != abs(b))
        return abs(a) < abs(b);
}
void thuTuSort(){
    int a[7] = {-5,5,2,-3,3,3,-5};
    stable_sort(a, a+7, cmpthuTuSort);
    for (int x: a) cout << x << ' ';
}
//----------------------------------------------------------------
int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    thuTuSort();
    lietKeVaDem();
    return 0;
}