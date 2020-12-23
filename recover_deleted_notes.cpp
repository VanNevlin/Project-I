#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// o User can recover their deleted notes. Please validate the recycle bin is not
// empty and the note is in there.

struct user {
    char userName[255];
    char passWord[255];
    char notes[255];
    bool privat;
    user *Friend;
    user *prev, *next;
    char deleted_notes;
}*head = NULL, *tail = NULL, User;

void delete_notes()
{
    struct user User;
    char delete_note[255];
    struct user User[1000];
    scanf("%s", delete_note);
    puts("Coming Soon!");

}

void recover_deleted_notes()
{
    puts("Coming Soon!");        
}