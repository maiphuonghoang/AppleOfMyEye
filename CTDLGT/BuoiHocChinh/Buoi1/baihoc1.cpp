#include <bits/stdc++.h>

using namespace std;
void duyet(){
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x; 
    for (int x : a) cout << x ; cout << endl;

    //để làm thay đổi giá trị của các phần tử trong mảng 
    for (int x : a) x = 100 ; //k thay đổi 
    for (int i=0; i<n; i++) a[i] = 100; //thay đổi 
    for (int &x : a) x = 10; //thay đổi 
    for (int x : a) cout << x ; cout << endl;
}

int cnt[1000001];//khai báo thế này thì 0 
void bt1(){//liệt kê các giá trị khác nhau trong mảng theo thứ tự xuất hiện 
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x; 

    for (int i = 0; i < n; i++){
        bool check = true; 
        for (int j = i - 1; j >= 0 ; j--){
            if(a[i] == a[j]){
                check = false;
                break;
            } 
        }
        if(check) cout << a[i] << " ";
    }    

    //C2: Mảng đánh dấu
    // thằng nào xuất hiện thì cho cnt[1] = 1, cnt[8]=1, cnt[12]= 1
    int max_val = -1e9;
    for (int i = 0; i < n; i++){
        //đánh dấu sự xuất hiện của a[i]
        cnt[a[i]] = 1;//O(1)
        max_val = max(max_val, a[i]); //tìm phần tử lớn nhất 
    }
    for (int i = 0; i <= max_val; i++)
        if (cnt[i] == 1) cout << " " << i ;
    
}
//cnt[-3] => segmentation fault 
int cnt2[1000001];
void bt2(){ //liệt kê các giá trị xuất hiện trong mảng theo thứ tự từ nhỏ đến lớn kèm theo tần xuất của nó 
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x; 

    for (int i = 0; i < n; i++){
        cnt2[a[i]]++;
    }
    for (int i = 0; i < 1000000; i++){
        if(cnt2[a[i]]>0){
            cout << a[i]<< " "<< cnt2[a[i]] << endl;
            cnt2[a[i]] = 0;
        }
    }

}
void bt3(){
    //Dịch các phần tử trong mảng sang trái K vị trí,
    //khi dịch trái thì phần tử đầu tiên của dãy số quay vòng trở lại thành phần tử cuối cùng 
    // 1 2 3 4 5 sau 2 lần xoay 3 4 5 1 2 
    //sau k lần xoay k phần tử đầu tiên về cuối 
    //=> in ra n-k thằng cuối, in ra k thằng cuối 
    //lấy k % n cho số lần xoay (vì sau n lần nó lại về vị trí ban đầu)
    int n, t; cin >> n >> t;
    int a[n];
    for (int &x : a) cin >> x; 
    int k = t%n;
    for (int i= k; i<n; i++)
        cout << a[i] << " ";
    for (int i=0; i< k; i++)
        cout << a[i] << " ";
}
void basicVector(){
    vector<int> v;//vector rỗng 
    int n; cin >> n;
    for (int i=0; i< n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> vc(n);//khai báo số lượng phần tử để lấy v[i]
    for (int i=0; i< n; i++){
        cin >> vc[i];
    }

    v.push_back(100);
    v.push_back(200);
    v.push_back(300);
    cout << v.size() << endl;
    for (int i=0; i<v.size(); i++) 
        cout << v[i] << ' ';
    for (int x: v) 
        cout<< x << ' ';
}
void basicIterator(){
    vector<int> v = {1,2,3,4,5};
    vector<int>::iterator it = v.begin();//con trỏ templace 
    //hoặc auto it = v.begin();//tự động hiểu kiểu 
    cout << *it << endl;//toán tử giải tham chiếu - dereference 
    it++; 
    it = v.begin() + 3;//trỏ đến phần tử có chỉ số x trong mảng 
    for (it = v.begin(); it != v.end();it++){
        cout << *it << " ";
    }

    //Hàm insert: Thêm 1 phần tử vào vị trí bất kì trong vector thông qua iterator
    //insert(Vị trí iterator, val)
    v.insert(v.begin() + 2, 10);
    for (auto x: v)
        cout << x << " ";
    v.erase(v.begin()+3);//xóa phần tử chỉ số x 
    v.pop_back();//xóa phần tử cuối cùng trong vector 

}
void basicPair(){
    pair<int, int> p;
    p.first = 100;
    p.second = 200;
    pair<int, int> p2 = make_pair(100, 200);
    pair<int, int> p3 = {100, 200};

    int n; cin >> n;
    pair<int, int> a[n]; //mảng pair 
    for (int i =0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
}
int main(){
    //int cnt[1000001];// khai báo thế này thì biến rác, có thể tràn stack của main 
    basicIterator();
}
