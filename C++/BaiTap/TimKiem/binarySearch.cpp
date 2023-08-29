#include <bits/stdc++.h>
using namespace std;

//Linear search O(n)
bool ls(int a[], int n, int x){
    for (int i = 0; i < n; i++)
        if(a[i] == x) return true;
    return false;
}

//Binary search O(logn)
//Các phần tử phải được sắp xếp tăng dần, giảm dần 
bool bs(int a[], int n, int x){
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) 
            return true;
        //Thằng đứng giữa nhỏ hơn X, thì phải tìm ở bên phải, l = m + 1
        else if(a[m] > x)
            l = m + 1;
        //Thằng đứng giữa lớn hơn X, thì phải tìm ở bên trái 
        else 
            r = m - 1;
    }
}
bool binarySearchDQ(int a[], int l, int r, int x){
    if(l > r) return false;
    int m = (l + r)/2;
    if(a[m] == x)
        return true;
    else if(a[m] < x) 
        return binarySearchDQ(a, m + 1, r, x);
    else 
        return binarySearchDQ(a, l, m - 1, x);
}
void run(){
    int n, x; cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if(ls(a, n, x)) cout << "Found";
    else cout << "Not Found";
    
    if(bs(a, n, x)) cout << "Found";
    else cout << "Not Found";

    if(binarySearchDQ(a, 0, n-1, x)) cout << "Found";
    else cout << "Not Found";

    //hàm có sẵn 
    if(binary_search(a, a + n, x)) cout << "Found";
    // binary_search(a+x, a+y, key) => tìm kiếm từ a[x] đến a[y-1] 
    else cout << "Not Found";

    vector<int> v(n);
    if(binary_search(v.begin(), v.end(), x)) cout << "Found";
    else cout << "Not Found";  
    //tìm kiếm từ chỉ số 0 đến chỉ số 2 (3 ptu)
    if(binary_search(v.begin(), v.begin() + 3, x)) cout << "Found";
    else cout << "Not Found";    
}
//----------------------------------------------------------------
// Vị trí phần tử đầu tiên = x xuất hiện trong mảng 
int first_pos(int a[], int n, int x){
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;//cập nhật kết quả
            r = m - 1;//tìm thêm ở bên trái xem còn ko?
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
// Vị trí phần tử cuối cùng = x xuất hiện trong mảng 
int last_pos(int a[], int n, int x){
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;//cập nhật kết quả
            l = m + 1;//tìm thêm ở bên phải xem còn ko?
        }
        else if(a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}
//***Vị trí đầu tiên của phần tử lớn hơn hoặc bằng X 
int greaterFirstVIP(int a[], int n, int x){
    int res = -1;
    int l = 0, r = n-1;
    while (l <= r){
        int m = (l + r)/2;
        if(a[m] >= x){
            res = m;//cập nhật 
            r = m - 1;//Tìm thêm đáp án tốt hơn
        }
        else
            l = m + 1;
    }
    return res;
}
//Vị trí cuối cùng của phần tử lớn hơn hoặc bằng X 
int greaterLast(int a[], int n, int x){
    int l = 0, r = n-1;
    while (l <= r){
        int m = (l + r)/2;
        if(a[m] >= x){
            return n - 1;
        }
        else
            l = m + 1;
    }
    return -1;
}
//***Vị trí cuối cùng của phần tử nhỏ hơn hoặc bằng X 
int lessLastVIP(int a[], int n, int x){
    int res = -1;
    int l = 0, r = n-1;
    while (l <= r){
        int m = (l + r)/2;
        if(a[m] <= x){
            res = m;//cập nhật 
            l = m + 1;//Tìm thêm đáp án tốt hơn
        }
        else
            r = m - 1;
    }
    return res;
}
//Vị trí đầu tiên của phần tử nhỏ hơn hoặc bằng X 
int lessFirst(int a[], int n, int x){
    int l = 0, r = n-1;
    while (l <= r){
        int m = (l + r)/2;
        if(a[m] <= x){
            return 0;
        }
        else
            r = m - 1;
    }
    return -1;
}
void runViTri(){
    int n, x; cin >> n >> x;
    int a[n];
    for (int &x : a) cin >> x;
    cout << first_pos(a, n, x) << " " << last_pos(a, n, x) << endl;

    // Tìm số lượng phần tử = x trong mảng tăng dần 
    // số lần xh của x = chỉ số xh cuối - chỉ số xh đầu + 1 (2Ologn)
    int l = first_pos(a, n, x);
    int r = last_pos(a, n, x);
    if(l != -1)
        cout << r - l + 1 << endl; 
    else //k tìm thấy ptu nào 
        cout << 0 << endl;

    for (int x : a) cout << x <<" ";
    cout << endl;
    cout << "Vi tri dau tien cua phan tu lon hon hoac bang X: " << greaterFirstVIP(a,n,x)<< endl;
    cout << "Vi tri cuoi cung cua phan tu lon hon hoac bang X: " << greaterLast(a,n,x) << endl;
    cout << "Vi tri dau tien cua phan tu nho hon hoac bang X: " << lessFirst(a,n,x) << endl;
    cout << "Vi tri cuoi cung cua phan tu nho hon hoac bang X: " << lessLastVIP(a,n,x) << endl;

}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\C++\\input.txt", "r", stdin);
    #endif
    runViTri();
    return 0;
}