#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char value;
    struct _node *pNext;
} node;

typedef struct _stack{
    node *top;
} stack;

void initStack(stack *num){
    num->top = NULL;
}

node *makeNode(char value){
    node *p = (node *)malloc(sizeof(node));
    p->value = value;
    p->pNext = NULL;
    return p;
}

void pushStack(stack *num, node *p){
    if(num->top == NULL){
        num->top = p;
    }
    else{
        p->pNext = num->top;
        num->top = p;
    }
}

int popStack(stack *num){
    if(num->top == NULL){
        return 0;
    }
    else{
        int x = num->top->value - '0';
        node *p = num->top;
        num->top = num->top->pNext;
        free(p);
        return x;
    }
}

void printStack(stack num){
    for(node *p = num.top; p != NULL; p = p->pNext){
        printf("%c", p->value);
    }
    printf("\n");
}

void inputStack(stack *num){
	char c;
	printf("Nhap so: ");
	c = getchar();
	while(c != '\n'){
        pushStack(num, makeNode(c));
		c = getchar();
	}
}

int coutStack(stack num){
    int cout = 0;
    for(node *p = num.top; p; p = p->pNext){
        cout++;
    }
    return cout;
}

void addStack(stack *num1, stack *num2, stack *num3){
    int temp, memory = 0;
    char c;
    while(coutStack(*num1) || coutStack(*num2)){
        temp = popStack(num1) + popStack(num2);
        c = (temp + memory)%10 + '0';
        pushStack(num3, makeNode(c));
        memory = (temp + memory)/10;
    }
    if(memory != 0){
        c = memory + '0';
        pushStack(num3, makeNode(c));
    }
}

int main(){
    stack num1, num2, num3;
    initStack(&num1); initStack(&num2); initStack(&num3);
    printf("So thu nhat:\n");
    inputStack(&num1);
    printf("So thu hai:\n");
    inputStack(&num2);
    addStack(&num1, &num2, &num3);
    printf("Ket qua cua phep cong hai so la: ");
    printStack(num3);
    return 0;
}


