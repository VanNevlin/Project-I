#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node {
  char username[255];//username
  Node *next; 
} *head, *tail; 
Node *createNode(const char *username) {
  Node *newNode = (Node*)malloc(sizeof(Node)); 
  strcpy(newNode->username, username);
  return newNode;
}
void pushHead(const char *username, Node** curr) {
  Node *temp = createNode(username);
    temp->next = *curr; 
    *curr = temp; 
}
void printUserList(Node * bingung){
    printf("No.  Username\n");
    while(bingung){
        int i=1;
        printf("%d %s",i,bingung->username);
        bingung = bingung->next;
        i++;
    }
}
int main(){
    Node* A = NULL;
  //  Node* USERS = NUll;    <-- users that login
  //  printUserList(userfromlogin);
    char friendusername[255];
    printf("Which user do you wanr to add?\n");
    printf(">>");
    scanf("%s",friendusername);
    printf("--Your request has been sent to %s--\n",friendusername);
    pushHead(friendusername, &A);
    printf("Press enter to continue!\n");
}
