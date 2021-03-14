#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct list{
    int count;
    int full;
    node *head;
}list;

void CreateList(list *l){
    l->count = 0;
    l->full = 0;
    l->head = NULL;
}

int IsListEmpty(list *l){
    return (l->head == NULL);
}

int IsListFull(list *l){
    return (l->full);
}

int ListSize(list *l){
    return (l->count);
}

void InsertBeginning(int x, list *l){
    node *new = (node *) malloc(sizeof(node));

    if(new == NULL){
        l->full = 1;
        printf("List is full\n");
    }
    else{
        new->data = x;
        if(IsListEmpty(l)){
            new->next = NULL;
        }
        else{
            new->next = l->head;
        }
        l->count++;
        l->head = new;
    }
}

void InsertEnd(int x, list *l){
    node *new = (node *) malloc(sizeof(node));

    if(new == NULL){
        l->full = 1;
        printf("List is full\n");
    }
    else{
        new->data = x;
        new->next = NULL;

        if(IsListEmpty(l)){
            l->head = new;
        }
        else{
            node *temp = l->head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = new;
        }
        l->count++;
    }
}

void InsertList(int position, int x, list *l){
    node *new = (node *) malloc(sizeof(node));

    if(new == NULL){
        l->full = 1;
        printf("List is full\n");
    }
    else if(position < 1 || position > ListSize(l)){
        printf("Try to insert a position in the list\n");
    }
    else if(position == 1){
        InsertBeginning(x,l);
    }
    else{
        new->data = x;
        node *temp = l->head;
        int j = 1;

        while(j < position-1){
            temp = temp->next;
            j++;
        }

        new->next = temp->next;
        temp->next = new;
        l->count++;
    }
}

void DeleteBeginning(int *x, list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
    }
    else{
        *x = l->head->data;

        node *temp = l->head;

        l->head = l->head->next;
        l->count--;

        free(temp);
    }
}

void DeleteEnd(int *x, list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
    }
    else{
        node *temp = l->head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        *x = temp->next->data;
        free(temp->next);
        temp->next = NULL;
        l->count--;
    }
}

void DeleteList(int position, int *x, list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
    }
    else if(position < 1 || position > ListSize(l)){
        printf("Try to delete a position in the list\n");
    }
    else if(position == 1){
        DeleteBeginning(x,l);
    }
    else{
        node *temp = l->head;
        int j = 1;

        while(j < position-1){
            temp = temp->next;
            j++;
        }

        *x = temp->next->data;

        node *del = temp->next;

        temp->next = temp->next->next;
        l->count--;

        free(del);
    }
}

void RetrieveList(list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
    }
    else{
        node *temp = l->head;

        for(int i=1 ; i<=l->count ; i++){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){


return 0;
}