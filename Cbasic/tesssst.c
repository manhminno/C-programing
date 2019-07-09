#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef struct {
    Node *root;
} Tree;

void Init(Tree *Tree){
    Tree-> root = NULL;
}

Node *makeNode(int data){
    Node *tmp = (Node*) malloc (sizeof(Node));
    tmp -> data = data;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

void insert(Node *t, Node *p){
    if( p->data < t->data ){
        if( t->left == NULL ){
            t->left = p;
        } else insert(t->left,p);
    }
    else{
        if( p->data > t->data ){
            if( t->right == NULL ){
                t->right = p;
            }else insert(t->right,p);
        }
    }
}

void insertNode(Tree *t, Node *p){
    if (t->root == NULL ) t->root = p;
    else{
        insert(t->root,p);
    }
}

void Input(Tree *t, int n, int *a){
    for (int i=0; i<n; i++){
        Node *p = makeNode(a[i]);
        insertNode(t,p);
    }
}
/*
Node *search(Node *root,int key){
    if ( root !=NULL ){
        if (key == root->data) return root;
        else if (key > root->data) search(root->right,key);
        else search(root->left,key);
    }
    else return NULL;
}

int searchMin(Node *root){
    if(root->left == NULL) return root->data;
    else searchMin(root->left);
}

int searchMax(Node *root){
    if(root->right == NULL) return root->data;
    else searchMin(root->right);
}

int Successor(Node *root,int key){
    Node *k = search(root,key) ;
    if (k->right != NULL){
        searchMin(k->right);
    }
}
*/

Out(Node *root, int data1, Node *result){
    if ( root != NULL ){
        Out(root->left, data1, result);
        if(root->data > data1){
            if(result ==  NULL){
                result = root;
                result->left = result->right = NULL;
            }
        }
        Out(root->right, data1, result);
    }
}

Node *Searchchild(Tree root1){
    Node *tmp;
    while(root1.root->left != NULL){
        tmp = root1.root;
        root1.root = root1.root->left;
    }
    return tmp;
}

void PrintfTree(Node *root){
    if(root != NULL){
        PrintfTree(root->left);
        printf("%d ", root->data);
        PrintfTree(root->right);
    }
}

int a;

int main(){
    int arr[13]={50, 30, 25, 10, 20, 23, 35, 31, 37, 55, 53, 60, 62};
    Tree Tree;
    Init(&Tree);
    // Node *temp = NULL;
    Input(&Tree, 13,arr);
    PrintfTree(Tree.root);
    Out(Tree.root, 23, temp);
    printf("\n%d\n",temp->data);
    return 0;
}
