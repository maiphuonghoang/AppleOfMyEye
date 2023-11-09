#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};
node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void themdau1(node **head, int x){//Con trỏ đến con trỏ 
    node *newNode = makeNode(x);
    newNode->next = (*head);//cho next node mới trỏ vào node đầu hiện tại
    if(*head != NULL) 
        (*head)->prev = newNode;
    (*head) = newNode;
}
void themdau2(node *&head, int x){//tham chiếu 
    node *newNode = makeNode(x);
    newNode->next = head;//cho next node mới trỏ vào node đầu hiện tại
    if(head != NULL) 
        (head)->prev = newNode;
    head = newNode;
}
void themcuoi1(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *tmp = *head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
void themcuoi2(node *&head, int x){
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}
int size(node *head){
    int cnt = 0;
    while (head != NULL){
        ++cnt;
        head = head->next;
    }
    return cnt;
}
void themgiua1(node **head, int x, int pos){
    int n = size(*head);
    if(pos < 1 || pos > n + 1) return;
    if(pos == 1){
        themdau1(head, x);
        return;
    } 
    node *temp = *head;
    for (int i = 1; i <= pos -1; i++){
        temp = temp->next;
    }
    node* newNode = makeNode(x);
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode->next;
}
void themgiua2(node *&head, int x, int pos){
    int n = size(head);
    if(pos < 1 || pos > n + 1) return;
    if(pos == 1){
        themdau2(head, x);
        return;
    } 
    node *temp = head;
    for (int i = 1; i <= pos -1; i++){
        temp = temp->next;
    }
    node* newNode = makeNode(x);
    newNode->next = temp;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode->next;
}
void run(){
    node *head = NULL;
	while(1){
		cout << "---------------DSLK---------------\n";
		cout << "1. Them node vao dau\n";
		cout << "2. Them node vao cuoi\n";
		cout << "3. Them node vao giua\n";
		cout << "4. Duyet\n";
		cout << "5. Thoat !\n";
		cout << "----------------------------------\n";
		cout << "Nhap lua chon :"; int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x : ";
			cin >> x;
			themdau1(&head, x); 
            // themdau2(head, x);
		}
		else if(lc == 2){
			int x; cout << "Nhap x : ";
			cin >> x;
			themcuoi1(&head, x); 
            // themcuoi2(head, x);
		}
		else if(lc == 3){
			int x; cout << "Nhap x : ";
			cin >> x;
			int k; cout << "Nhap vi tri chen :";
			cin >> k;
			themgiua1(&head, x, k); 
            // themgiua2(head, x, k);
		}
		else if(lc == 4){
			duyet(head);
		}
		else{
			break;
		}
 
	}
}
int main() {
    run();
    return 0;
}