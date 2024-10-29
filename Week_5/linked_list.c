#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Not enough memories\n");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
int lenNode(struct Node** head){
    struct Node* temp = *head;
    int count = 0;
    while(temp != NULL){
        count += 1;
        temp = temp -> next;
    }
    return count;
}
void accessElement(struct Node** head, int position){
    if (position > lenNode(&*head) -1){
        printf("Index out of range");
        return;
    }
    int count = 0;
    struct Node* temp = *head;
    while (count <= position){
        if (count == position){
            printf("%d\n", temp -> data);
            return;
        }
        count += 1;
        temp = temp -> next;
    }
}
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL){
        temp = temp -> next;
    }
    temp->next = newNode;
}

void deleteElement(struct Node** head, int position){
    if (position > lenNode(&*head) -1){
        printf("Index out of range");
        return;
    }
    int count = 0;
    struct Node* temp = *head;
    while (count <= position){
        if (count == position-1){
            struct Node* deleteNode = temp -> next;
            temp -> next = deleteNode -> next;
            free(deleteNode);
            return;
        }
        count += 1;
        temp = temp -> next;
    }
}
int main(){
    struct Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    struct Node* temp = head;
    while (temp != NULL){
            printf("%d\n",temp->data);
            temp = temp -> next;
    }
    deleteElement(&head, 1);
    temp = head;
    while (temp != NULL){
            printf("%d\n",temp->data);
            temp = temp -> next;
    }
    printf("%d\n", lenNode(&head));
    accessElement(&head, 1);
    temp = head;
    while(temp != NULL){
        struct Node* deleteNode = temp;
        temp = temp -> next;
        free(deleteNode);
    }
    return 0;
}