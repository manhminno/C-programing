#include<stdio.h>
#include<stdlib.h>

//Khoi tao Node va List;
typedef struct Node{
    int data;
    struct Node *pNext;
} Node;

typedef struct List{
    Node *pHead;
    Node *pTail;
} List;

//Cho List = NULL;
void InitList(List *l){
    l->pHead = l->pTail = NULL;
}

//Tao Node: p->next = NULL, p->date = x;
Node *MakeNode(int x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->pNext = NULL;
    return p;
}

//Them Node vao cuoi danh sach;
void AddTail(List *l, Node *p){
    if(l->pHead == NULL)
        l->pHead = l->pTail = p;

    else
        l->pTail->pNext = p;
        l->pTail = p;
}

void Input(List *l, int n){
    for(int i = 1; i <= n; i++){
        int x;
        printf("Nhap data = ");
        scanf("%d", &x);
        Node *p = MakeNode(x);
        AddTail(l, p);
    }
}

void Output(List *l){
    for(Node *p = l->pHead; p != NULL; p = p->pNext){
        printf("%d\t", p->data);
    }
}

void DelHead(List *l){
    Node *temp = l->pHead;
    l->pHead = l->pHead->pNext;
    free(temp);
}

void DelTail(List *l){
    Node *temp;
    for(Node *i = l->pHead; i; i = i->pNext){
        if(i == l->pTail){
            temp->pNext = NULL;
            l->pTail = temp;
            free(i);
            return;
        }
        temp = i;
    }
}

void DelAfterNode(List *l, Node *q){
    Node *p;
    Node *g;
    p = q->pNext;
    q->pNext = p->pNext;
    free(p);
}


void DelNode(List *l, int data){
    Node *j = l->pHead;
    while(1){
        if(l->pHead->data == data) DelHead(l);
        else{
            for( j; j; j = j->pNext){
            if((j->pNext)->data == data){
            break;
            }
        }
        DelAfterNode(l, j);
        if(j->pNext == l->pTail){
            DelTail(l);
            return;
        }

    }
    }

}

int main(){
    int x;
    List l;
    InitList(&l);
    int n;
    printf("Nhap vao so node:");
    scanf("%d", &n);
    Input(&l, n);
    Output(&l);
    printf("Nhap vao gia tri xoa:");
    scanf("%d", &x);
    DelNode(&l, x);
    Output(&l);
    return 0;
}





