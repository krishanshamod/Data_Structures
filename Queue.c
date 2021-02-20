//Array Implementation of Queue

#include <stdio.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0

typedef struct Queue{
    int count;
    int front;
    int rear;
    int item[MAXSIZE];
}queue;

void CreateQueue(queue *s){
    s->count = 0;
    s->front = -1;
    s->rear = -1;
}

int IsQueueEmpty(queue *s){
    if(s->count == 0){
        return (TRUE);
    }
    else{
        return (FALSE);
    }
}

int IsQueueFull(queue *s){
    if(s->rear == MAXSIZE-1){
        return (TRUE);
    }
    else{
        return (FALSE);
    }
}

void Remove(queue *s, int *x){
    if(s->count == 0){
        printf("Queue is empty.\n");
        exit(1);
    }
    else{
        *x = s->item[s->front];
        s->front++;
        s->count--;
    }
}

void Insert(queue *s, int x){
    if(s->front == -1){
        s->front++;
    } 
    
    if(s->rear == MAXSIZE-1){
        printf("Queue is full.\n");
        exit(1);
    }
    else{
        s->rear++;
        s->item[s->rear] = x;
        s->count++;
    }
}

int QueueSize(queue *s){
    return (s->count);
}


int main(){


return 0;
}