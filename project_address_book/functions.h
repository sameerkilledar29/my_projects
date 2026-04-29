#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct student
{
 char name[100];
 char gmail[100];
 char add[50];
 char mob[15];
};
struct AddressBook {
    struct student arr[100];
    int size;
};


int digit(char * mob);
void add_contact(struct AddressBook *addressBook);
int search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contact(struct AddressBook *addressBook);
void edit_all(struct AddressBook *addressBook,int ind);
void edit_name(struct AddressBook *addressBook,int ind);
void edit_number(struct AddressBook *addressBook,int ind);
void edit_mail(struct AddressBook *addressBook,int ind);
void edit_location(struct AddressBook *addressBook,int ind);  
void sort(struct AddressBook *addressBook);



#endif
