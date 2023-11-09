#include <bits/stdc++.h>
using namespace std;

struct SinhVien{
    string name;
    double gpa;

    SinhVien(){}

    SinhVien(string ten, double diem){
        name = ten;
        gpa = diem;
    }
};

struct node {
    SinhVien data; 
    struct node *next;
};
node* makeNode(SinhVien s){
    node *newNode = new node();
    newNode->data = s;
    newNode->next = NULL;
    return newNode;
}
void pushFront(node **head, SinhVien s){
    node *newNode = makeNode(s); 
    newNode->next = *head;
    *head = newNode;

}
void pushBack(node **head, SinhVien s){
    node *temp = *head; 
    node* newNode = makeNode(s);
    if(*head == NULL){
        *head = newNode;
        return;
    } 
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void duyet(node *head){//tham số là con trỏ kiểu node 
    while (head != NULL){
        cout << head->data.name << " " <<fixed << setprecision(2) << head->data.gpa << endl;
        head = head->next;
    }
    cout << endl;
}
void sapxepGpa(node **head){
    for (node *i = *head; i->next!=NULL; i=i->next){
        node *minNode = i;
        for (node *j = i->next; j!=NULL; j=j->next){
            if(minNode->data.gpa < j->data.gpa)
                minNode = j;       
        }
        SinhVien tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}
void sapxepSameGpa2Name(node **head){
    for (node *i = *head; i->next!=NULL; i=i->next){
        node *minNode = i;
        for (node *j = i->next; j!=NULL; j=j->next){
            if(minNode->data.gpa > j->data.gpa)
                minNode = j;   
            else if(minNode->data.gpa == j->data.gpa){
                if(minNode->data.name > j->data.name)
                    minNode = j; 
            }    
        }
        SinhVien tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}
void run(){
    node *head = NULL;
    SinhVien s("Teo", 3.5);
    SinhVien t("Ti", 3.8);
    SinhVien u("Long", 2.5);
    SinhVien v("Hai", 3.7);
    SinhVien w("Lan", 3.7);
    pushBack(&head, s);
    pushBack(&head, t);
    pushBack(&head, u);
    pushBack(&head, v);
    pushBack(&head, w);
    duyet(head);
    sapxepGpa(&head);
    duyet(head);
    sapxepSameGpa2Name(&head);
    duyet(head);
}
int main() {
    run();
    return 0;
}