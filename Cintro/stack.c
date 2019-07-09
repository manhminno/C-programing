#include <stdio.h>
#include <stdlib.h>
struct NODE{
    int data;
    struct NODE *next;
};
typedef struct NODE Node;

struct STACK{
    Node *top;
};
typedef struct STACK Stack;
void InitStack(Stack *l){
    l->top = NULL;
}
Node *MakeNode(int x){

    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}
void Push(Stack *l, Node *p){
    if(l->top == NULL) l->top = p;
    else{
        p->next = l->top;
        l->top = p;
    }
}
int Pop(Stack *l){
    int x;
    if(l->top == NULL){
        printf("Eror\n");
        return 0;
    }
    else{
        Node *p = l->top;
        l->top = l->top->next;
        x = p->data;
        free(p);
    }
    return x;
}
void Input(Stack *l){
    int size;
    printf("Nhap vao so Node:");
    scanf("%d", &size);
    int x;
    for(int i = 0; i < size; i++){
        printf("Nhap du lieu cho Node:");
        scanf("%d", &x);
        Node *p = MakeNode(x);
        Push(l, p);
    }
    printf("\n");
}
void Output(Stack l){
    Node *p = l.top;
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    Stack l;
    InitStack(&l);
    Input(&l);
    Output(l);
    printf("%d", Pop(&l));
    printf("\n");
    Output(l);
}


