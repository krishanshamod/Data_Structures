//Array Implementation of Stack

#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct{
    int top;
    char entry[maxsize];
}stack;

void CreateStack(stack *s){
    s->top=-1;
}

void IsStackEmpty(stack *s){
    if(s->top == -1){
        printf("TRUE \n");
    }
    else{
        printf("FALSE \n");
    }
}

void IsStackFull(stack *s){
    if(s->top == maxsize-1){
        printf("TRUE \n");
    }
    else{
        printf("FALSE \n");
    }
}

void Push(char item, stack *s){
    if(s->top == maxsize-1){
        printf("Stack is full \n");
        exit(1);
    }
    else{
        s->entry[++s->top] = item;
    }
}

void Pop(char *item, stack *s){
    if(s->top == -1){
        printf("Stack is empty \n");
        exit(1);
    }
    else{
        *item=s->entry[s->top--];
    }
}




int main(){

char item;
stack s;

CreateStack(&s);
IsStackEmpty(&s);
IsStackFull(&s);

Push('k',&s);
Pop(&item,&s);
printf("%c",item);

return 0;
}