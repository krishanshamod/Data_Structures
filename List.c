#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct list{
    int count;
    int arr[MAXSIZE];
}list;

void CreateList(list *l){
    l->count = -1;
}

int IsListEmpty(list *l){
    return (l->count == -1);
}

int IsListFull(list *l){
    return (l->count == MAXSIZE-1);
}

void InsertLast(int item, list *l){
    if(IsListFull(l)){
        printf("List is full\n");
        exit(1);
    }
    else{
        l->count++;
        l->arr[l->count] = item;
    }
}

void InsertList(int position, int item, list *l){
    if(IsListFull(l)){
        printf("List is full\n");
        exit(1);
    }
    else if(position < 0 || position > l->count){
        printf("Try to insert a position in the list");
    }
    else{
        for(int i = l->count ; i>=position ; i--){
            l->arr[i+1] = l->arr[i];
        }

        l->arr[position] = item;
        l->count++;
    }
}

void ReplaceList(int position, int item, list *l){
    if(position < 0 || position > l->count){
        printf("Try to replace a position in the list");
    }
    else{
        l->arr[position] = item;
    }
}

void DeleteList(int position, int *item, list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
        exit(1);
    }
    else if(position < 0 || position > l->count){
        printf("Try to delete a position in the list");
    }
    else{
        *item = l->arr[position];

        for(int i = position ; i < l->count ; i++){
            l->arr[i] = l->arr[i+1];
        }

        l->count--;
    }
}

void RetrieveList(int position, int *item, list *l){
    if(IsListEmpty(l)){
        printf("List is empty\n");
        exit(1);
    }
    else if(position < 0 || position > l->count){
        printf("Try to retrieve a position in the list");
    }
    else{
        *item = l->arr[position];
    }
}



int main(){

list l;
int i;

CreateList(&l);
InsertLast(5,&l);
InsertLast(10,&l);
DeleteList(0,&i,&l);
printf("%d\n",i);
printf("%d",IsListEmpty(&l));


return 0;
}