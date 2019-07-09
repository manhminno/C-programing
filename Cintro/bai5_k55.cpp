#include<iostream>
using namespace std;

#define MAX_ID 10
#define MAX_NAME 50

struct book{
    char *id;
    char *name;
    int tatalPages;
};

struct DS_book{
    struct book key;
    struct DS_book *next;
};

struct DS_book *New_book(struct book key){
    struct DS_book *node = new DS_book();
    node->key = key;
    node->next = NULL;
}

struct book Create_book(){
    struct book new_book;
    new_book.id = new char[MAX_ID+1];
    cout<<"inport id: "<<endl;
    fflush(stdin);
    gets(new_book.id);
    new_book.name = new char [MAX_NAME+1];
    cout<<"inport name: "<<endl;
    gets(new_book.name);
    cout<<"import totalPages: "<<endl;
    cin>>new_book.tatalPages;
    return new_book;
}

struct DS_book *import_book(struct DS_book *head){

    struct DS_book *node = New_book(Create_book());
    if(head == NULL) return node;
    struct DS_book *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    return head;

}

void Print(struct DS_book *head){
    while(head != NULL){
        cout<<head->key.id<<"     "<<head->key.name<<"                       "<<head->key.tatalPages<<endl;
        head = head->next;
    }
}

int main(){
    
    struct DS_book *head = NULL;
    head = import_book(head);
    head = import_book(head);
    head = import_book(head);
    cout<<"Print list"<<endl;
    Print(head);
    
    return 0;
}