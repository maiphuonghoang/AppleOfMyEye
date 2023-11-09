#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name, id;
    double gpa;

    Student(){}

    Student(string id, string ten, double diem){
        name = ten;
        gpa = diem;
    }
};
struct SV{
    Student s; 
    SV *next;
};
typedef struct SV* sv;

// Cấp phát động 1 node mới với dữ liệu là Sinh Vien  
sv makeNode(){
    Student s;
    cout << "Nhap thong tin sinh vien";
    cout << "\nNhap ID : "; cin >> s.id;
    cout << "Nhap ten : "; cin.ignore();
    getline(cin, s.name);
    cout << "Nhap gpa : "; cin >> s.gpa;

    sv tmp = new SV();
    tmp->s = s; 
    tmp->next = NULL;
    return tmp;
}
// Kiểm tra rỗng
bool empty(sv a){
    return a == NULL;
}
int size(sv a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;
    }
    return cnt;
}
// Thêm 1 phần tử vào đầu danh sách liên kết 
void insertFirst(sv &a){//Sử dụng toán tử dải tham chiếu 
    sv tmp = makeNode();
    if(a == NULL)
        a = tmp;
    else{
        tmp->next = a;
        a = tmp;
    }
}

// Thêm 1 phần tử vào cuối
void insertLast(sv &a){
    sv tmp = makeNode();
    if(a == NULL)
        a = tmp;
    else{
        sv p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;    
    }
}
// Thêm 1 phần tử vào giữa 
void insertMiddle(sv &a, int pos){
    int n = size(a);
    if(pos <= 0 || pos > n+1)
        cout << "Vi tri chen khong hop le" << endl;
    if(pos == 1){
        insertFirst(a);
        return;
    }
    else if(pos == n + 1){
        insertLast(a);
        return;
    }
    else{
        sv p = a;
        // chạy đến vị ví pos - 1;
        for (int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        sv tmp = makeNode();
        tmp->next = p->next;
        p->next = tmp;
    } 
}

// Xóa phần tử ở đầu 
void deleteFirst(sv &a){
    if(a == NULL)
        return;
    a = a->next;
}
// Xóa phần tử 
void deleteLast(sv &a){
    if(a == NULL) return;
    // duyệt đến ptu trước phần tử cuối cùng 
    sv truoc = NULL, sau = a;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL)//DSLK chỉ có 1 phần tử 
        a = NULL;
    else
        truoc->next = NULL;
}
// Xóa ở giữa 
void deleteMiddle(sv &a, int pos){
    if(pos <= 0 || pos > size(a)){
        cout << "Vi tri chen khong hop le" << endl;
        return;
    }
    sv truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) a = a->next;
    // trước nằm ở vị trí pos - 1, sau nằm ở vị trí pos 
    else truoc->next = sau->next; 
}
void in(Student s){
    cout << "------------------------------\n";
    cout << "ID : " << s.id << endl;
    cout << "Name : " << s.name << endl;
    cout << "GPA : " << fixed << setprecision(2) << s.gpa << endl;
    cout << "------------------------------";
}

void print(sv a){
    cout << "Danh sach sinh vien" << endl;
    while(a!=NULL){
        in(a->s);
        a = a->next;
    }
    cout << endl;
}
void sapxep(sv &a){
    for (sv p = a; p->next != NULL; p = p->next){
        sv min = p;
        for (sv q = p->next; q != NULL; q = q->next){
            if(q->s.gpa < min->s.gpa)
                min = q;
        }
        // Chỉ hoán vị 2 giá trị của node 
        Student tmp = min->s;
        min->s = p->s;
        p->s = tmp;
    }
}
void run(){
    sv head = NULL;
    while(1){
        cout << "---------------------MENU----------------------\n";
        cout << "1. Chen sinh vien vao dau danh sach" << endl;
        cout << "2. Chen sinh vien vao cuoi danh sach" << endl;
        cout << "3. Chen sinh vien vao giua danh sach" << endl;
        cout << "4. Xoa sinh vien o dau danh sach" << endl;
        cout << "5. Xoa sinh vien o cuoi danh sach" << endl;
        cout << "6. Xoa sinh vien o giua danh sach" << endl;
        cout << "7. Duyet danh sach" << endl;
        cout << "8. Sap xep cac sinh vien trong danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------\n";
        cout << "Nhap lua chon : "; 
        int lc; cin >> lc;
        if(lc == 1){
            insertFirst(head);
        }else if(lc == 2){
            insertLast(head);
        }
        else if(lc == 3){
            int pos; cout << "Nhap vi tri can chen : "; cin >> pos;
            insertMiddle(head, pos);
        }
        else if(lc == 4){
            deleteFirst(head);
        }else if(lc == 5){
            deleteLast(head);
        }
        else if(lc == 6){
            int pos; cout << "Nhap vi tri can xoa : "; cin >> pos;
            deleteMiddle(head, pos);
        }
        else if(lc == 7){
            print(head);
        }
        else if(lc == 8){
            sapxep(head);
        }
        else if(lc = 0){
            break;
        }
    }
}
int main() {
    run();
    return 0;
}