#include<stdio.h>
#include<stdlib.h>

struct LinkNode {
    int val;
    struct LinkNode *next;
};

struct LinkNode* store(struct LinkNode* head, int value){
    struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
    newNode->val = value;
    newNode->next = head;
    return newNode;
};
//display
void printList(struct LinkNode* head){
    struct LinkNode* current = head;
    while(current!=NULL){
        printf("%d->", current->val);
        current = current->next;
    }
    printf("Null\n");
}

int main(){
    struct LinkNode* list = NULL;
    /*
    multiple list can be initiated by simply:
    struct LinkNode* list1 = NULL;
    struct LinkNode* list1 = Null;
    */
    list = store(list, 7);
    list = store(list, 2);
    list = store(list, 9);
    printf("Linked List: ");
    printList(list);
    return 0;
}