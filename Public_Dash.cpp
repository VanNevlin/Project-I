#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void printall() {
    if (!head) {
        return;
    }
    user* temp = head;
    while (temp) {
        printf("Username: %s\n", temp->userName);
        printf("Password: %s\n", temp->passWord);
        temp = temp->next;
    }
}

void post(user* curr) {
    char kalimat[255];
    scanf("%[^\n]", kalimat);
    getchar();
    int i = 0;
    while (kalimat[i] != '\0') {
        if (kalimat[i] >= '0' && kalimat[i] <= '9') {
            return;
        }
        i++;
    }
    int index = 0;
    while (curr->notes[index][0] != '\0') {
        index++;
    }
    strcpy(curr->notes[index], kalimat);
}
void print_post(user* curr) {
    if (!curr) {
        return;
    }
    int index = 0;
    while (curr->notes[index + 1][0] != '\0') {
        printf("%s\n", curr->notes[index]);
        index++;
    }
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
    int i = 0;
    while (kalimat[i] >= 0 && kalimat[i] <= 9) {
        return;
        i++;
    }
    curr->notes[index - 1][0] = '\0';
    strcpy(curr->notes[index - 1], kalimat);
}

void deletenote(user* curr, int index) {
    if (curr->notes[index - 1][0] == '\0') {
        return;
    }
    //Pindahin ke recyle binnya ??
    //Belinda I need your Help WKWK
}

int main() {
    pushmid((char*)"bili", (char*)"oass");
    pushmid((char*)"bili", (char*)"oass");
    pushmid((char*)"aili", (char*)"pass");
    post(head);
    post(head->next);
    editnote(head->next, 1);
    // make_Private(head);
    // note_Type(head);
    // print_post(head->next);
    print_AllData();
    // printall();


    return 0;
}