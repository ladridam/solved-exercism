#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* twoList(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    
    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;

    if(l1->val < l2->val){
        result = l1;
        l1 = l1->next;
    }else{
        result = l2;
        l2 = l2->next;
    }
    tail = result;

    while (l1!=NULL && l2!=NULL){
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL)
    {
        tail->next = l1;
    }
    if (l2 != NULL)
    {
        tail->next = l2;
    }
    return result;
};

struct ListNode* insert(struct ListNode* head, int value){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = head;
    return newNode;
};

void printList(struct ListNode* head){
    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d->", current->val);
        current = current->next;
    }
    printf("Null\n");
};

int main(){
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    list1 = insert(list1, 7);
    list1 = insert(list1, 4);
    list1 = insert(list1, 2);

    list2 = insert(list2, 3);
    list2 = insert(list2, 5);
    list2 = insert(list2, 1);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = twoList(list1, list2);
    printf("Merged: ");
    printList(merged);
    
    return 0;
}