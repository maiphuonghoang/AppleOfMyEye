#include <bits/stdc++.h>
using namespace std;
// địa chỉ của a được gán cho con trỏ n
void thaydoi(int *n){
    cout << n << endl; //n chính là địa chỉ của biến a
    cout << *n << endl;
}

void pointer(){
    int a = 100;
    cout << "Dia chi cua a trong bo nho : " << &a << endl;//0x61fef8
    //toán tử địa chỉ &
    int *ptr; // * con trỏ 
    ptr = &a;//con trỏ lưu địa chỉ
    cout << ptr << endl;//0x61fef8
    cout << *ptr << endl;//toán tử dải tham chiếu * để lấy giá trị con trỏ trỏ vào 

    a = 1000;
    thaydoi(&a);
}
struct SinhVien{
    string name;
    string lop;
    double diem;
};
void pointer2(){
    SinhVien s;
    s.name = "Teo";
    s.lop = "CNTT";
    s.diem = 3.7;
    SinhVien *ptr = &s;
    cout << (*ptr).name << " " << (*ptr).lop << " " << (*ptr).diem << endl;
    cout << ptr->name << " " << ptr->lop << " " << ptr->diem << endl;

    SinhVien *ptrM = new SinhVien[100];
    SinhVien *ptrO = new SinhVien();
}

int main() {
    #ifndef ONLINE_JUDGE 
    freopen ("D:\\AppleOfMyEye\\CTDLGT\\input.txt", "r", stdin);
    #endif
    pointer();
    pointer2();
    return 0;
}