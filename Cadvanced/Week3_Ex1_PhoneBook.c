#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define INCREMENTAL_SIZE 5

typedef struct {
    char name[80];
    long number;
} PhoneEntry;

typedef struct {
    PhoneEntry *entries;
    int total;
    int size;
} PhoneBook;

PhoneBook createPhoneBook(){
    PhoneBook temp;
    temp.total = 0;
    temp.size = INITIAL_SIZE;
    temp.entries = (PhoneEntry *)malloc(INITIAL_SIZE*sizeof(PhoneEntry));
    return temp;
}

void dropPhoneBook(PhoneBook *book){
    free(book->entries);
}

int binarySearch(PhoneEntry *entries, int l, int r, char name[], int *index){
    int Mid;
    if(l > r){
        *index = 0;
        return l+1;
    }
    else{
        Mid = (l + r)/2;
        if(strcmp(entries[Mid].name, name) == 0){
            *index = 1;
            return Mid;
        }
        else if(strcmp(entries[Mid].name, name) > 0) return binarySearch(entries, l, Mid - 1, name, index);
        else if(strcmp(entries[Mid].name, name) < 0) return binarySearch(entries, Mid + 1, r, name, index);
    }
}

void addPhoneNumber(char name[], long number, PhoneBook *book){
    int check;
    int index;
    if(book->total > 0){
        check = binarySearch(book->entries, 0, book->total-1, name, &index);
        if(index == 1){
            book->entries[check].number = number;
        }
        else{
            if(book->total >= book->size){
                PhoneEntry *temp;
                int newsize = book->size + INCREMENTAL_SIZE;
                temp = (PhoneEntry *)malloc(newsize*sizeof(PhoneEntry));
                memcpy(temp, book->entries, book->total*sizeof(PhoneEntry));
                memcpy(&book->entries[check+1], &book->entries[check], (book->total - check)*sizeof(PhoneEntry));
                strcpy(book->entries[check].name, name);
                book->entries[check].number = number;
                book->total++;
            }
            else{
                memcpy(&book->entries[check], &book->entries[check-1], (book->total - check + 1)*sizeof(PhoneEntry));
                strcpy(book->entries[check-1].name, name);
                book->entries[check-1].number = number;
                book->total++;
            }

        }
    }
    else{
        strcpy(book->entries[0].name, name);
        book->entries[0].number = number;
        book->total++;
    }
}

void printBook(PhoneBook book){
    for(int i = 0; i < book.total; i++){
        printf("%s\n", book.entries[i].name);
        printf("%ld\n\n", book.entries[i].number);
    }
}

int main(){
    PhoneBook book;
    book = createPhoneBook();

    addPhoneNumber("Manh", 93774, &book);
    addPhoneNumber("Khanh", 93314, &book);
    addPhoneNumber("Dung", 33774, &book);
    addPhoneNumber("Chinh", 33774, &book);
    addPhoneNumber("An", 33774, &book);
    addPhoneNumber("Manh", 11111, &book);


    printBook(book);
    return 0;
}
