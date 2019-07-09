#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

typedef struct _node{
    char c;
    struct _node *pNext;
} node;

typedef struct _stack{
    node *top;
} stack;

void initStack(stack *arr){
    arr->top = NULL;
}

node *makeNode(char c){
    node *p = (node *)malloc(sizeof(node));
    p->c = c;
    p->pNext = NULL;
    return p;
}

void pushStack(stack *arr, node *p){
    if(arr->top == NULL)
        arr->top = p;
    else{
        p->pNext = arr->top;
        arr->top = p;
    }
}

int popStack(stack *arr){
    if(arr->top == NULL){
        return 0;
    }
    else{
        int x = arr->top->c - '0';
        node *p = arr->top;
        arr->top = arr->top->pNext;
        return x;
    }
}

void printStack(stack arr){
    for(node *p = arr.top; p; p = p->pNext){
        printf("%c", p->c);
    }
}

void calculateStack(stack *arr1, char mang[]){
    int temp;
    char c;
    for(int i = 0; i < strlen(mang); i++){
        if(mang[i] >= '0' && mang[i] <= '9'){
            pushStack(arr1, makeNode(mang[i]));
        }
        else{
            if(mang[i] == '+'){
                temp = popStack(arr1) + popStack(arr1);
                if(temp >= 10){
                    c = temp%10 + '0';
                    pushStack(arr1, makeNode(c));
                    c = temp/10 + '0';
                    pushStack(arr1, makeNode(c));
                }else{
                    c = temp + '0';
                    pushStack(arr1, makeNode(c));
                }
            }
            if(mang[i] == '*'){
                temp = popStack(arr1) * popStack(arr1);
                if(temp >= 10){
                    c = temp%10 + '0';
                    pushStack(arr1, makeNode(c));
                    c = temp/10 + '0';
                    pushStack(arr1, makeNode(c));
                }else{
                    c = temp + '0';
                    pushStack(arr1, makeNode(c));
                }
            }
        }
    }
}
int main(){
    char temp[MAX];
    stack arr1;  initStack(&arr1);
    printf("Nhap xau: ");
    scanf("%[^\n]%*c", &temp);
    calculateStack(&arr1, temp);
    printStack(arr1);
    return 0;

}

