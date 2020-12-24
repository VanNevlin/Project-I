#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node {
  char username[255];//username
  Node *next; 
} *head, *tail;
//This is from the friends list
void printFriendsList(Node * friendss){
    printf("Friend List\n");
    printf("No.  Username\n");
    while(friendss){
        int i=1;
        printf("%d %s",i,friendss->username);
        friendss = friendss->next;
        i++;
    }
}
void remove_friend(Node **ref,char* friendusername){
     Node* temp= *ref,*prev;
    if(temp !=NULL && strcmp(temp->next->username,friendusername)==0){
        *ref=temp->next;
        return;
    }
    while(temp !=NULL && strcmp(temp->next->username,friendusername)!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
}

int main(){
    Node* A = NULL;
    char removeusername[255];
    printf("Which user do you want to remove?\n");
    printf(">>");
    scanf("%s",removeusername);
    printf("--You are no longer friends with %s--\n",removeusername);
    remove_friend(&A,removeusername);
    printf("Press enter to continue!\n");
}
