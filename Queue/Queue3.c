// Linked Implementation of Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct{
    node *front;
    node *rear;
    int full;
    int count;
}queue;

void CreateQueue(queue *s){
    s->count = 0;
    s->full = 0;
    s->front = s->rear = NULL;
}

int IsQueueEmpty(queue *s){
    return (s->front == NULL && s->rear == NULL);
}

int IsQueueFull(queue *s){
    return (s->full);
}

void Insert(int item, queue *s){
    node *new;
    new = (node *) malloc(sizeof(node));

    if(new == NULL){
        s->full = 1;
        printf("Not enough memory.\n");
    }
    else{
        new->data = item;
        new->next = NULL;

        if(IsQueueEmpty(s)){
            s->front = s->rear = new;
        }
        else{
            s->rear->next = new;
            s->rear = new;
        }
        s->count++;
    }
}

void Remove(int *item, queue *s){
   

    if(IsQueueEmpty(s)){
        printf("Queue is empty.\n");
    }
    else{
        s->count--;
        *item = s->front->data;
        s->front = s->front->next;

        if(s->front == NULL){
            s->rear =NULL;
        }
    }
}


int main(){

int i;
queue s;

CreateQueue(&s);

Insert(5,&s);
Insert(1,&s);
Remove(&i,&s);

printf("Count = %d\n",s.count);

return 0;
}