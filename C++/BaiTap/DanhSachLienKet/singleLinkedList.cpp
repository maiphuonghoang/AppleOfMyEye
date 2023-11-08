#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    Node *next;
};
typedef struct Node* node;

// Cấp phát động 1 node mới với dữ liệu là số nguyên x 
node makeNode(int x){
    node tmp = new Node();
    // Vì temp là con trỏ nên để truy cập vào data thì dùng -> chứ k .
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
// Kiểm tra rỗng
bool empty(node a){
    return a == NULL;
}
int size(node a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;//gán địa chỉ của node tiếp theo cho node hiện tại 
        //cho node hiện tại nhảy sang node tiếp theo 
    }
    return cnt;
}
// Thêm 1 phần tử vào đầu danh sách liên kết 
void insertFirst(node &a, int x){//Sử dụng toán tử dải tham chiếu 
    node tmp = makeNode(x);
    if(a == NULL)
        a = tmp;
    else{
        tmp->next = a;
        a = tmp;
    }
}
void insertFirst2(node *a, int x){//Sử dụng con trỏ <Con trỏ kiểu node>
    node tmp = makeNode(x);
    if(*a == NULL)
        *a = tmp;//<Giá trị của con trỏ kiểu node>
    else{
        tmp->next = *a;
        *a = tmp;
    }
}
// Thêm 1 phần tử vào cuối
void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL)
        a = tmp;
    else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;    
    }
}
// Thêm 1 phần tử vào giữa 
void insertMiddle(node &a, int x, int pos){
    // Chèn x vào vị trí pos của dslk 
    int n = size(a);
    if(pos <= 0 || pos > n+1)
        cout << "Vi tri chen khong hop le" << endl;
    if(n == 1){
        insertFirst(a, x);
        return;
    }
    else if(n == pos + 1){
        insertLast(a, x);
        return;
    }
    else{
        node p = a;
        // chạy đến vị ví pos - 1;
        for (int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        node tmp = makeNode(x);
        tmp->next = p->next;
        p->next = tmp;
    } 
}

// Xóa phần tử ở đầu 
void deleteFirst(node &a){
    if(a == NULL)
        return;
    a = a->next;
}
// Xóa phần tử 
void deleteLast(node &a){
    if(a == NULL) return;
    // duyệt đến ptu trước phần tử cuối cùng 
    node truoc = NULL, sau = a;
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
void deleteMiddle(node &a, int pos){
    if(pos <= 0 || pos > size(a))
        return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) a = a->next;
    // trước nằm ở vị trí pos - 1, sau nằm ở vị trí pos 
    else truoc->next = sau->next; 
}
void print(node a){
    while(a!=NULL){
        cout << a->data << " ";
        a = a->next;
    }
}
void sapxep(node &a){
    for (node p = a; p->next != NULL; p = p->next){
        node min = p;
        for (node q = p->next; q != NULL; q = q->next){
            if(q->data < min->data)
                min = q;
        }
        // Chỉ hoán vị 2 giá trị của node 
        int tmp = min->data;
        min->data = p->data;
        p->data = tmp;
    }
}
void run(){
    cout << sizeof(Node) << endl;
    node head = NULL;
    while(1){
        cout << "---------------------MENU----------------------\n";
        cout << "1. Chen phan tu vao dau danh sach" << endl;
        cout << "2. Chen phan tu vao cuoi danh sach" << endl;
        cout << "3. Chen phan tu vao giua danh sach" << endl;
        cout << "4. Xoa phan tu o dau danh sach" << endl;
        cout << "5. Xoa phan tu o cuoi danh sach" << endl;
        cout << "6. Xoa phan tu o giua danh sach" << endl;
        cout << "7. Duyet danh sach" << endl;
        cout << "8. Sap xep cac phan tu trong danh sach" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------\n";
        cout << "Nhap lua chon : "; 
        int lc; cin >> lc;
        if(lc == 1){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertFirst(head, x);
        }else if(lc == 2){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertLast(head, x);
        }
        else if(lc == 3){
            int x; cout << "Nhap gia tri can chen : "; cin >> x;
            int pos; cout << "Nhap vi tri can chen : "; cin >> pos;
            insertMiddle(head, x, pos);
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