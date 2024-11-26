#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** p_head, struct Node* position, int data);
void pushBack(struct Node** p_head, int data);
void deleteNode(struct Node** p_head, struct Node* position);
void deleteList(struct Node** p_head);
int sizeOfList(struct Node* head);
void displayList(struct Node* head);
void displayListToString(struct Node* head, char* output);
void insertNode(struct Node** p_head, struct Node* position, int data) 
{
    // your implementation
    if(*p_head == NULL){
        pushBack(p_head, data);
        return;
    }
    if(*p_head == position){
        struct Node* data1 = (struct Node*)malloc(sizeof(struct Node));
        data1 -> data = data;
        struct Node* temp = *p_head;
        *p_head = data1;
        (*p_head)->next = temp;
        return;
    }
    struct Node* prev = *p_head;
    struct Node* current = (*p_head)->next;
    struct Node* data1 = (struct Node*)malloc(sizeof(struct Node));
    data1 -> data = data;
    while(current != position){
        current = current -> next;
        prev = prev -> next;
    }
    prev -> next = data1;
    prev -> next -> next = current;
    return;
}

void pushBack(struct Node** p_head, int data)
{
    // your implementation
    if(*p_head == NULL){
        struct Node* data1 = (struct Node*)malloc(sizeof(struct Node));
        data1 -> data = data;
        *p_head = data1;
        return;
    }
    struct Node* current = (*p_head) -> next;
    while(current != NULL){
        current = current -> next;
    }
    struct Node* data1 = (struct Node*)malloc(sizeof(struct Node));
    data1 -> data = data;
    current = data1;
    return;
}

void deleteNode(struct Node** p_head, struct Node* position) 
{
    // your implementation
    if((*p_head) == NULL){
        return;
    }
    if(position == *p_head){
        struct Node * temp = *p_head;
        *p_head = (*p_head) -> next;
        free(temp);
        return;
    }
    struct Node* current = (*p_head)->next;
    while(current != NULL && current -> next != NULL){
        // prev = prev -> next;
        if (current->next == position){
            struct Node *temp = current->next;
            current = temp -> next;
            free(temp);
        }
        current = current -> next;
    }
    // if(prev-> next -> next == NULL){
    //     prev->next = NULL;
    //     return;
    // }
    // prev -> next = prev -> next -> next;
    // free(current);
    return;
}

int sizeOfList(struct Node* head) 
{
    if(head == NULL){
        return 0;
    }
    int count = 0;
    // your implementation
    struct Node* current = head;
    while(current != NULL){
        count++;
        current = current -> next;
    }
    return count;
}

void deleteList(struct Node **p_head)
{
    // your implementation
    if(*p_head == NULL){
        return;
    }
    while(*p_head != NULL){
        struct Node* current = *p_head;
        *p_head = (*p_head) -> next;
        free(current);
    }
    return;
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

// display the linked list to a string output
void displayListToString(struct Node* head, char* output) {
    sprintf(output, "%s", "");
    struct Node* temp = head;
    while (temp != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%d -> ", temp->data);
        strcat(output, temp_str);
        temp = temp->next;
    }
    // concatenate NULL to the output string
    sprintf(output, "%sNULL", output);
    return;
}
int main() {
    struct Node* head = NULL;
    pushBack(&head, 25);
    insertNode(&head, head, 20);
    insertNode(&head, head, 15);
    insertNode(&head, head, 10);
    deleteNode(&head, head);
    char output[100];
    displayListToString(head, output);
    assert(strcmp(output, "25 -> 20 -> 15 -> NULL") == 0);
    deleteList(&head);
    return 0;
}