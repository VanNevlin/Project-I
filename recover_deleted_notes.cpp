#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// o User can recover their deleted notes. Please validate the recycle bin is not
// empty and the note is in there.

struct user {
    char userName[255];
    char passWord[255];
    char notes[255][255];
    bool privat;
    user *Friend;
    user *prev, *next;
    char deleted_notes[255];
}*head = NULL, *tail = NULL;

void delete_notes(user* current)
{
    int index_del;
    // post(); // untuk memanggil fungsi post notes dari @KFC
    
    // DEBUG
    // printf("%d", &index); // untuk memastikan indeks dari fungsi KFC

    // Ini untuk scan indeks yang ingin di-delete di file
    scanf("%d", &index_del);
    
    for (int i = 0; i < index; i++)
    {
        for (int j = i; j < index; j++)  
        {
            if (strcmp(current -> notes[i][j], current -> notes[i][index_del]) == 0)
            {
                strcpy(current -> notes[i][index_del], current -> deleted_notes);
                current -> notes[i][index_del] = NULL; // untuk menghapus notes
            }
        }
    }
}

void recover_deleted_notes(user *current)
{
    int index_recover;

    // post(); // untuk memanggil fungsi post notes dari @KFC
    
    // DEBUG
    // printf("%d", &index); // untuk memastikan indeks dari fungsi KFC

    scanf("%d", &index_recover);

    for (int i = 0; i < index; i++)
    {
        for (int j = i; j < index; j++)  
        {
            if (strcmp(current -> deleted_notes, current -> notes[i][index_recover]) == 0)
            {
                strcpy(current -> notes[i][index_recover], current -> deleted_notes);
            }
        }
    }
}