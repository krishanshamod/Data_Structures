//Dynamic Allocation Implementation of Stack

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct{
    int no_ele;
    struct node *top;
}stack;

void CreateStack(stack *s){
    s->top = NULL;
    s->no_ele = 0;
}

void IsStackEmpty(stack *s){
    if(s->top==NULL){
        printf("TRUE \n");
    }
    else{
        printf("FALSE \n");
    }
}

void Push(int item, stack *s){
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = item;
    new->next = s->top;
    s->top = new;
    s->no_ele++;
}

void Pop(int *item, stack *s){
    node *new;
    *item = s->top->data;
    new = s->top;
    s->top = new->next;
    s->no_ele--;
    free(new);
}



int main(){
stack s;
int n;
CreateStack(&s);
IsStackEmpty(&s);

Push(5,&s);
Pop(&n,&s);
IsStackEmpty(&s);


return 0;
}