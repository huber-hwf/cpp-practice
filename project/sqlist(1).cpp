#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct SqList{
    ElemType data[MAXSIZE];
    int length;
}SqList, *Sqptr;

Sqptr CreateList(){
    Sqptr p=(Sqptr)malloc(sizeof(SqList));
    if(!p) return NULL;
    return p;
}

Status InitList(Sqptr L){
    L->length=0;
    return OK;
}

Status ListEmpty(Sqptr L){
    return L->length==0;
}

Status ClearList(Sqptr L){
    L->length=0;
    return OK;
}

int ListLength(Sqptr L){
    return L->length;
}

Status GetElem(Sqptr L, int i, int *e){
    if(i<1||i>L->length) return ERROR;
    *e=L->data[i-1];
    return OK;
}

int LocateElem(Sqptr L, int e){
    for(int i=0; i<L->length; i++)
    if(L->data[i]==e) return i+1;
    return 0;
}

Status ListInsert(Sqptr L, int i, int e){
    if(L->length==MAXSIZE) return ERROR;
    if(i<1||i>L->length+1) return ERROR;
    for(int k=L->length; k>=i; k--){
        L->data[k]=L->data[k-1];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

Status ListDelete(Sqptr L, int i, int *e){
    if(L->length==0) return ERROR;
    if(i<1||i>L->length) return ERROR;
    *e=L->data[i-1];
    for(int k=i-1; k<L->length-1; k++){
        L->data[k]=L->data[k+1];
    }
    L->length--;
    return OK;
}

void DestroyList(Sqptr L){
    free(L);
}