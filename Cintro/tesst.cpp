#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *pnext;
} node;

typedef struct _list{
    node *head;
    node *tail;
} list;

void Init(list *l);
node *makeNode(int value);
void addNodeTail(list *l, node *p);
void outputList(list l);
void inputList(list *l);
void freeList(list &l);
void deleteNode(list *l);

int main(){
    list l;
    inputList(&l);
    printf("\n");

    outputList(l);

    deleteNode(&l);

    freeList(l);
    return 0;
}

//Cac ham khoi tao
void Init(list *l){
    l->head = l->tail = NULL;
}

node *makeNode(int value){
    node *p = (node *)malloc(sizeof(node));
    p->value = value;
    p->pnext = NULL;
    return p;
}

//Them node vao Tail
void addNodeTail(list *l, node *p){
    if(l->head==NULL)
        l->head=l->tail=p;
    else{
        l->tail->pnext = p;
        l->tail = p;
    }
}

//in list 
void outputList(list l){
    for(node *p= l.head; p != NULL; p = p->pnext){
        printf("%d ", p->value);
        printf("%p ", p);
    }
    printf("\n");
}

//Nhap list
void inputList(list *l){
    int size;
    printf("Nhap so node: ");
    scanf("%d", &size);
    Init(l);
    for(int i = 0; i < size; i++){
        int data;
        printf("\nNhap data cho node %d: ", i+1);
        scanf("%d", &data);
        node *p = makeNode(data);
        addNodeTail(l, p);
    }
}

//Giai phong list
void freeList(list &l){
    node *p;
    while(l.head != NULL){
        p = l.head;
        l.head = l.head->pnext;
        free(p);
    }   
}


void deleteNode(list *l){
    if(l->head->value == 0){
        node *q;
        q = l->head->pnext;
        l->head = q;
    }
    node *p = l->head;
    for(node *k = p->pnext; k != NULL; k = k->pnext){
        if(k->value == 0){
            p->pnext = k->pnext;
        }
        p = k;
    }
}