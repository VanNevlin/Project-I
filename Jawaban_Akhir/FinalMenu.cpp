#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

struct user {
    char userName[255];
    char passWord[255];
    char notes[255][255];
    bool privat;
    int status;
    user* Friend;
    user* prev, * next;
}*head = NULL, * tail = NULL;


user* new_User(char* name, char* pass) {
    user* temp = (user*)malloc(sizeof(user));
    strcpy(temp->userName, name);
    strcpy(temp->passWord, pass);
    temp->prev = temp->next = temp->Friend = NULL;
    return temp;
}

void pushhead(char* name, char* pass) {
    user* temp = new_User(name, pass);
    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void pushtail(char* name, char* pass) {
    user* temp = new_User(name, pass);
    if (!tail) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void pushmid(char* name, char* pass) {
    user* temp = new_User(name, pass);
    user* temp2 = head;
    while (temp2) {
        if (strcmp(temp->userName, temp2->userName) == 0) {
            return;
        }
        temp2 = temp2->next;
    }
    if (!head) {
        head = tail = temp;
    }
    else {
        if (strcmp(head->userName, name) > 0) {
            pushhead(name, pass);
        }
        else if (strcmp(tail->userName, name) <= 0) {
            pushtail(name, pass);
        }
        else {
            user* curr = head;
            while (curr->next && strcmp(tail->next->userName, name) > 0) {
                curr = curr->next;
            }
            if (curr == NULL) {
                return;
            }
            curr->prev->next = temp;
            temp->prev = curr->prev;
            temp->next = curr;
        }
    }
}

void printTime(){
    time_t t;   
    time(&t);
    printf("Logged in: %s\n", ctime(&t));
}

void post(user* curr) {
    char kalimat[255];
    scanf("%[^\n]", kalimat);
    getchar();
    int i = 0;
    while (kalimat[i] != '\0') {
        if (kalimat[i] >= '0' && kalimat[i] <= '9') {
            puts("Cannot Contain numbers");
            getchar();
            return;
        }
        i++;
    }
    int index = 0;
    while (curr->notes[index][0] != '\0') {
        index++;
    }
    strcpy(curr->notes[index], kalimat);
    puts("Notes added succesfully");
    getchar();
}
void print_post(user* curr) {
    if (!curr) {
        return;
    }
    int index = 0;
    while (curr->notes[index][0] != '\0') {
        printf("%s\n", curr->notes[index]);
        index++;
    }
    puts("That is all your notes");
    getchar();
}
void see_Post(user* curr) {
    if (!curr->Friend) {
        return;
    }
    user* temp = curr;
    while (temp->Friend && temp->Friend->notes) {
        printf("%s", temp->Friend->userName);
        printf("%s", temp->notes);
    }
}

void make_Private(user* curr) {
    if (!curr) {
        return;
    }
    if (curr->privat == true) {
        curr->privat = false;
    }
    else {
        curr->privat = true;
    }
}

void print_AllData() {
    user* temp = head;
    while (temp) {
        if (temp->privat == false) {
            printf("%s's Notes\n", temp->userName);
            printf("%s\n", temp->notes);
        }
        temp = temp->next;
    }
}

void note_Type(user* curr) {
    int opt;
    puts("Choose Your category for your notes!");
    puts("1.Backlog");
    puts("2.In Progress");
    puts("3.Peer Review");
    puts("4.In Test");
    puts("5.Done");
    puts("6.Blocked");
    do {
        scanf("%d", &opt);
        getchar();
    } while (opt < 1 && opt>6);
    if (opt == 1) {
        curr->status = 1;
    }
    else if (opt == 2) {
        curr->status = 2;
    }
    else if (opt == 3) {
        curr->status = 3;
    }
    else if (opt == 4) {
        curr->status = 4;
    }
    else if (opt == 5) {
        curr->status = 5;
    }
    else if (opt == 6) {
        curr->status = 6;
    }
}

void editnote(user* curr, int index) {
    if (curr->notes[index - 1][0] == '\0') {
        return;
    }
    char kalimat[255];
    scanf("%[^\n]", kalimat);
    int len = strlen(kalimat);
    getchar();
    int i = 0;
    while (kalimat[i] >= 0 && kalimat[i] <= 9) {
        return;
        i++;
    }
    strcpy(curr->notes[index - 1], kalimat);
    curr->notes[index - 1][len] = '\0';
    puts("Note succesfully edited");
    getchar();
}


void reg() {
    char name[255], pass[255];
    system("cls||clear");
    printf("\n\n\t\tPLEASE INPUT USERNAME & PASSWORD");
    printf("\n\n\t\t\t\t  USERNAME: ");
    scanf("%[^\n]", name);
    getchar();
    printf("\n\n\t\t\t\t  PASSWORD: ");
    scanf("%[^\n]", pass);
    getchar();
    user* temp = head;
    while (temp) {
        if (strcmp(temp->userName, name) == 0) {
            puts("Name already Exist");
            getchar();
            return reg();
        }
        temp = temp->next;
    }
    pushmid(name, pass);
    puts("Created User");
    getchar();
}

void login_menu(user* curr) {
    system("cls||clear");
loginMenu:
    printTime();
    int login_menu_option;
    puts("***********************************");
    puts("             ~ MENU ~              ");
    puts("***********************************");
    printf("Hi %s\n", curr->userName);
    puts("1. Add Friend");
    puts("2. Remove Friend");
    puts("3. View Inbox");
    puts("4. View Sent Request");
    puts("5. Add, Edit, Announce, Delete Note");
    puts("6. Log Out");
    printf(">> ");
    scanf("%d", &login_menu_option); getchar();

    if (login_menu_option != 6) {
        if (login_menu_option == 1) {
            user* A = NULL;
            //  Node* USERS = NUll;    <-- users that login
            //  printUserList(userfromlogin);
            char friendusername[255];
            printf("Which user do you wanr to add?\n");
            printf(">>");
            scanf("%s", friendusername);
            printf("--Your request has been sent to %s--\n", friendusername);
            // pushHead(friendusername, &A);
            printf("Press enter to continue!\n");
            getchar();
            system("clear");
        }

        else if (login_menu_option == 2) {
            puts("Menu 2 - Remove Friend is coming soon!");
            puts("");
            puts("Notes: ");
            puts("Menu Creator: @Niclola03");
            puts("Press enter to continue..");
            getchar();
            system("clear");
        }

        else if (login_menu_option == 3) {
            puts("Menu 3 - View Inbox is coming soon!");
            puts("");
            puts("Notes: ");
            puts("Menu Creator: (will be announced)");
            puts("Press enter to continue..");
            getchar();
            system("clear");
        }

        else if (login_menu_option == 4) {
            puts("Menu 4 - View Sent Request is coming soon!");
            puts("");
            puts("Notes: ");
            puts("Menu Creator: (will be announced)");
            puts("Press enter to continue..");
            getchar();
            system("clear");
        }

        else if (login_menu_option == 5) {
            system("clear");
            int note_menu, index;
            puts("[1]Add Note");
            puts("[2]Edit Note");
            puts("[3]Announce Note");
            puts("[4]Delete Note");
            printf(">> ");
            scanf("%d", &note_menu); getchar();

            switch (note_menu)  // <-- LAST LEFT OFF
            {
            case 1:
                puts("Note lenght 1-255");
                post(curr);
                break;
            case 2:
                printf("Which index note that you want to edit:");
                scanf("%d", &index);
                getchar();
                editnote(curr, index);
                break;
            case 3:
                // note_Type(curr);
                print_post(curr);

            default:
                break;
            }
        }
        login_menu(curr);
    }
    else if (login_menu_option == 6) {
        system("clear");
        return;
    }
}

void login() {
    char name[255], pass[255];
    system("cls||clear");
    printf("\n\n\t\tPLEASE INPUT USERNAME & PASSWORD");
    printf("\n\n\t\t\t\t  USERNAME: ");
    scanf("%[^\n]", name);
    getchar();
    printf("\n\n\t\t\t\t  PASSWORD: ");
    scanf("%[^\n]", pass);
    getchar();
    user* temp = head;
    while (temp) {
        if (strcmp(temp->userName, name) == 0 && strcmp(temp->passWord, pass) == 0) {
            return login_menu(temp);
        }
        temp = temp->next;
    }
    puts("Wrong name or pass");
    getchar();
    return;
}



void main_menu() {
    int n;
    printf("Oo===============================oO\n");
    printf("           STUDY NETWORK           \n");
    printf("Oo===============================oO\n");
    printf("\n[All User]\n");
    // All users coming soon
    printf("------------------------\n");
    printf("[1]Register\n");
    printf("[2]Login\n");
    printf("[3]Exit\n");
    printf("------------------------\n");
    printf("Press 0 and enter to abort an operation\n");
    printf("------------------------\n");
    printf(">>");
    scanf("%d", &n);
    getchar();

    if (n != 3) {
        switch (n) {
        case 1:
            reg();
            break;

        case 2:
            login();
            break;
        }
        main_menu();
    }
    else if (n == 3) {
        system("cls||clear");
        return;
    }

    return;
}

int main() {
    main_menu();


    return 0;
}