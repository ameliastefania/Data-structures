#include <stdio.h>
#include <stdlib.h>

typedef struct content {
    int an;
} content;

typedef struct node {
    content *data;
    struct node *next;
} node;


void addNodeFront(node **head, content *contentParam) {
    node *temp = *head;
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = contentParam;

    newNode->next = temp;
    *head = newNode;
}

void addNodeBack(node **head, content *contentParam) {
    node *temp = *head;
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = contentParam;
    
    if (temp!=NULL) {
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    } 
}

void printList(node *head) {
    while (head!=NULL) {
        printf("An: %d", head->data->an);
        printf("\n");
        head = head->next;
    }
}

/*delete last node*/
void deleteLastNode(node **head) {
    node *temp1 = *head;
    node *temp2 = *head;

    if (temp1!=NULL) {
        while (temp1->next!=NULL) {
            temp1 = temp1->next;
        }
        while (temp2->next!=NULL) {
            if (temp2->next == temp1) {
                temp2->next = NULL;
                break;
            }
            temp2 = temp2->next;
        }
        free(temp1);
    }
}

void deleteNodeAn(node **head, int an) {
    node *temp = *head;
    node *previous = temp;
    if (temp!=NULL) {
        while (temp->next != NULL) {
            if (temp->data->an == an) {
                previous->next = temp->next;
                free(temp);
                break;
            }
            previous = temp;
            temp = temp->next;
        }
    }
}

int main() {
    node *head = NULL;
    content testContent;
    testContent.an = 4;

    content testContent2;
    testContent2.an = 3;

    content testContent3;
    testContent3.an = 6;

    addNodeFront(&head, &testContent);
    addNodeFront(&head, &testContent2);
    addNodeBack(&head, &testContent3);
    printList(head);

    //deleteLastNode(&head);
    deleteNodeAn(&head,4);
    printList(head);
    return 0;
}