#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50


typedef struct _info{
    char name[MAX];
    char phone[MAX];
    char email[MAX];
} info;

typedef struct _node{
    info member;
    struct _node *left;
    struct _node *right;
} node;

node *makeNode(info mem){
    node *p = (node *)malloc(sizeof(node));
    p->member = mem;
    p->left = p->right = NULL;
    return p;
}

//Ham them vao theo thu tu sap xep ten
node *addTree(node *root, info mem){
    if(root == NULL)
        return makeNode(mem);
    else{
        if(strcmp(root->member.name, mem.name) > 0) root->left = addTree(root->left, mem);
        else if(strcmp(root->member.name, mem.name) < 0) root->right = addTree(root->right, mem);
    }
    return root;
}

//Ham them vao theo thu tu sap xep email
// node *addTree(node *root, info mem){
//     if(root == NULL)
//         return makeNode(mem);
//     else{
//         if(strcmp(root->member.email, mem.email) > 0) root->left = addTree(root->left, mem);
//         else if(strcmp(root->member.email, mem.email) < 0) root->right = addTree(root->right, mem);
//     }
//     return root;
// }

void printTree(node *root){
    if(root != NULL){
        printTree(root->left);
        printf("Name: %s\n", root->member.name);
        printf("Phone: %s\n", root->member.phone);
        printf("Email: %s\n\n", root->member.email);
        printTree(root->right);
    }
}

node *readFile(node *root){
   FILE *fin = fopen("PhoneBook.txt", "r");
   if(fin == NULL) printf("Can't read file!\n");
   else{
       char tempInfo[256];
       info temp;
       while(!feof(fin)){
           fgets(tempInfo, 256, fin);
           sscanf(tempInfo,"%s %s %s", temp.name, temp.phone, temp.email);
           root = addTree(root, temp);
       }
       printf("Read file successfully!\n");
   }
   fclose(fin);
   return root;
}

node *searchEmail(node *root, char key[]){
    if(root == NULL) return NULL;
    else if(strcmp(root->member.email, key) == 0) return root;
    else{
        if(strcmp(root->member.email, key) > 0) searchEmail(root->left, key);
        else if(strcmp(root->member.email, key) < 0) searchEmail(root->right, key);
    }
}

void writeFile(node *root){
    char key[MAX];
    printf("Nhap vao email muon tim: ");
    gets(key);
    node *find = searchEmail(root, key);
    if(find){
        printf("Da tim thay email ban muon tim, luu thanh cong vao file SearchMem.txt !");
        FILE *fout = fopen("SearchMem.txt", "w");
        fprintf(fout, "Name: %s\n", find->member.name);
        fprintf(fout, "Phone: %s\n", find->member.phone);
        fprintf(fout, "Email: %s\n", find->member.email);
        fclose(fout);
    }
    else printf("Khong tim thay email ban muon tim !\n");
}



int main(){
    node *root = NULL;
    root = readFile(root);
    printf("Danh ba sap xep theo email la:\n");
    printTree(root);
    writeFile(root);
    return 0;
}