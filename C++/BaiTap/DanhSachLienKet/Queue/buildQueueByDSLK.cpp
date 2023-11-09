#include <bits/stdc++.h>
using namespace std;
/*
PUSH = INSERT LAST : thêm node vào cuối DSLK 
POP = DELETE FIRST: xóa node ở đầu DSLK
*/
struct  node {
    int data;
    struct node *next;
};

node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void push(node **queue, int x){
    node *newNode = makeNode(x);
    if(*queue==NULL){
        *queue = newNode;
        return;
    } 
    node *temp = *queue;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void pop(node **queue){
    if(*queue==NULL) return;
    node *temp = *queue;
    *queue = (*queue)->next;
    delete temp;
}
int size(node *queue){
    int ans = 0;
    while (queue != NULL){
        ++ans;
        queue = queue->next;
    }
    return ans;
}
bool empty(node *queue){
    return queue == NULL;
}
int front(node *queue){
    return queue->data;
}
void duyet(node *queue){
    while(queue != NULL){
        cout << queue->data << " ";
        queue = queue->next;
    }
    cout << endl;
}
void run(){
    node *queue = NULL;
    while(1){
        cout << "---------------------MENU----------------------\n";
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. front" << endl;
        cout << "4. size" << endl;
        cout << "5. empty" << endl;
        cout << "6. duyet" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------\n";
        cout << "Nhap lua chon : "; 
        int lc; cin >> lc;
        if(lc == 1){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            push(&queue, x);
        }else if(lc == 2){
            pop(&queue);
        }
        else if(lc == 3){
            if(queue==NULL) cout << "EMPTY" << endl;
            cout << front(queue) << endl;
        }
        else if(lc == 4){
            cout << size(queue) << endl;
        }
        else if(lc == 5){
            if(empty(queue))
                cout << "EMPTY" << endl;
            else cout << "NOT EMPTY" << endl;
        }
        else if(lc == 6){
            duyet(queue);
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