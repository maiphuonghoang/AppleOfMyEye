#include <bits/stdc++.h>
using namespace std;
struct node {
    int data; 
    struct node *next;
};
typedef struct node node;

node* makeNode(int x){
    // node *newNode = (node*)malloc(sizeof(node));
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(node *head){//tham số là con trỏ kiểu node 
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int countNode(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head->next;
    }
    return dem;
}
//truyền con trỏ đến con trỏ 
//vì bản thân node trong dslk là con trỏ rồi 
void pushFront(node **head, int x){
    node *newNode = makeNode(x); //*newNode là 1 con trỏ 
    newNode->next = *head;//*head là toán tử dải tham chiếu 
    // * này k phải là con trỏ kiểu head mà là địa chỉ của node head 
    *head = newNode;

}
void pushFront2(node *&head, int x){//Truyền tham chiếu 
    node *newNode = makeNode(x);
    newNode->next = head;// nên k cần dải tham chiếu 
    head = newNode;
}
void pushBack(node **head, int x){
    node *temp = *head; 
    node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    } 
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void pushBack2(node *&head, int x){
    node *temp = head; 
    node* newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    } 
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void run1(){
    node *head = NULL;
    for (int i = 1; i<=5; i++) 
        pushFront(&head, i);
    duyet(head);
    cout << countNode(head) << endl;
    for (int i = 10; i<=20; i++) 
        pushFront2(head, i);
    duyet(head);

    for (int i = 1; i<=5; i++) 
        pushBack(&head, i);
    duyet(head);

    for (int i = 1; i<=5; i++) 
        pushBack2(head, i);
    duyet(head);
} 
void insert(node **head, int x, int pos){
    int n = countNode(*head);
    if(pos < 1 || pos > n + 1) return;
    if(pos == 1){
        pushFront(head, x);
        return;
    } 
    node *temp = *head;
    for (int i = 1; i<= pos-2; i++){
        temp = temp->next;
    }
    //temp là node ở pos -1
    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(node **head){
    if(*head == NULL) return;
    node *temp = *head;//giải phóng
    *head = (*head)->next;
    delete(temp);
}
void popFront2(node *&head){
    if(head == NULL) return;
    node *temp = head;//giải phóng
    head = head->next;
    delete(temp);

}
void popBack(node **head){
    if(*head == NULL) return;
    node *temp = *head;
    // dslk chỉ có 1 node
    if(temp->next == NULL){
        *head = NULL;
        delete(temp);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    delete(last);
}
void popBack2(node *&head){
    if(head == NULL) return;
    node *temp = head;
    // dslk chỉ có 1 node
    if(temp->next == NULL){
        head = NULL;
        delete(temp);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    delete(last);
}
void erase(node **head, int pos){
    int n = countNode(*head);
    if(pos < 1 || pos > n) return; 
    if(pos == 1) popFront(head);
    else{
        node *temp = *head;
        for (int i = 1; i <= pos-2; i++){
            temp = temp->next;
        }
        node *posth = temp->next;//node vị trí pos 
        temp->next = posth->next;//cho pos-1 kết nối pos+1
        delete posth;
    }
}
void erase2(node *&head, int pos){
    int n = countNode(head);
    if(pos < 1 || pos > n) return; 
    if(pos == 1) popFront2(head);
    else{
        node *temp = head;
        for (int i = 1; i <= pos-2; i++){
            temp = temp->next;
        }
        node *posth = temp->next;//node vị trí pos 
        temp->next = posth->next;//cho pos-1 kết nối pos+1
        delete posth;
    }
}
void run2(){
    node* head = NULL;
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
            pushFront(&head, x);
        }else if(lc == 2){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            pushBack(&head, x);
        }
        else if(lc == 3){
            int x; cout << "Nhap gia tri can chen : "; cin >> x;
            int pos; cout << "Nhap vi tri can chen : "; cin >> pos;
            insert(&head, x, pos);
        }
        else if(lc == 4){
            popFront(&head);
            // popFront2(head);
        }else if(lc == 5){
            popBack(&head);
            // popBack2(head);
        }
        else if(lc == 6){
            int pos; cout << "Nhap vi tri can xoa : "; cin >> pos;
            erase(&head, pos);
        }
        else if(lc == 7){
            duyet(head);
        }
        else if(lc = 0){
            break;
        }
    }
}

int main() {
    run2();
    return 0;
}