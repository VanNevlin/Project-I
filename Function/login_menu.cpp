/*
o @Shadow Prince  The logged-on user’s menu should display his/her friends and the 
management feature: Add Friend, Remove Friend, View Inbox, View Sent
Request, and Logout.
o @Shadow Prince  Selecting one of the choices should give easiness of use.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct user {
    char userName[255];
    char passWord[255];
    char notes[255];
    bool privat;
    user* Friend;
    user* prev, * next;
}*head = NULL, * tail = NULL;

void login_menu()
{
    int login_menu;
    puts("***********************************");
    puts("             ~ MENU ~              ");
    puts("***********************************");
    puts("");
    puts("1. Add Friend");
    puts("2. Remove Friend");
    puts("3. View Inbox");
    puts("4. View Sent Request");
    puts("5. Add, Edit, Announce, Delete Note");
    puts("6. Log Out");
    printf(">> ");
    scanf("%d", &login_menu); getchar();

    if (login_menu == 1)
    {
        puts("Menu 1 - Add Friend is coming soon!");
        puts("");
        puts("Notes: ");
        puts("Menu Creator: @Niclola03");
    }

    else if (login_menu == 2)
    {
        puts("Menu 2 - Remove Friend is coming soon!");
        puts("");
        puts("Notes: ");
        puts("Menu Creator: @Niclola03");
    }

    else if (login_menu == 3)
    {
        puts("Menu 3 - View Inbox is coming soon!");
        puts("");
        puts("Notes: ");
        puts("Menu Creator: (will be announced)");
    }

    else if (login_menu == 4)
    {
        puts("Menu 3 - View Sent Request is coming soon!");
        puts("");
        puts("Notes: ");
        puts("Menu Creator: (will be announced)"); 
    }

    else if (login_menu == 5)
    {
        puts("Menu 4 - Add, Edit, Announce, Delete Note is coming soon!");
        puts("");
        puts("Notes: ");
        puts("Menu Creator: @KFC, (other creators will be announced");
    }

    else
    {
        // main_menu(); // untuk balik ke Main Menu yang dibuat oleh creator @VanNevlin. Sesampai di main menu, akan di-exit untuk keluar dari network.
    }
    
}

