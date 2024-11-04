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
    if (position >= lenNode(&*head)){
        printf("Index out of range");
        return;
    }
    int count = 0;
    struct Node* temp = *head;
    while (count < position){
        if (count == position){
            printf("%d\n", temp -> data);
            return;
        }
        count += 1;
        temp = temp -> next;
    }
}
int* getData(struct Node* head, int* size){
    int* out = NULL;
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL){
        count ++;
        out = realloc(out, count * sizeof(int));
        out[count-1] = temp->data;
        temp = temp -> next;
    }
    *size = count;
    return out; 
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
    
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    int count = 0;
    while (temp != NULL && count < position - 1){
        temp = temp -> next;
        count++;
    }
    
    if (temp == NULL || temp -> next == NULL){
        printf("Index out of range");
        return;
    }
    struct Node* deleteNode = temp -> next;
    temp -> next = deleteNode -> next;
    free(deleteNode);
}
int main(){
    struct Node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    int size = 0;
    int* out = getData(head, &size);
    for (int i = 0; i < size; i++){
        printf("Cai nay la Data: %d \n", out[i]);
    }
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
    
    free(out);
    temp = head;
    while(temp != NULL){
        struct Node* deleteNode = temp;
        temp = temp -> next;
        free(deleteNode);
    }
    return 0;
}