#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwo(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    struct ListNode* head = newNode;
    int carry = 0;
    while (l1!=NULL || l2!=NULL || carry!=0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        newNode->val = sum % 10;

        if (l1 != NULL || l2 != NULL || carry != 0)
        {
            newNode->next = malloc(sizeof(struct ListNode));
            newNode = newNode->next;
        }
    }
    newNode->next = NULL;
    return head;
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
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
};

int main(){
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    l1 = insert(l1, 3);
    l1 = insert(l1, 4);
    l1 = insert(l1, 2);

    l2 = insert(l2, 4);
    l2 = insert(l2, 6);
    l2 = insert(l2, 5);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    struct ListNode* result = addTwo(l1, l2);
    printf("Result: ");
    printList(result);

    return 0;
};
