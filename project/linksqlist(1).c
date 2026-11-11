#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

LinkList CreateList(){
    LinkList L=(LinkList)malloc(sizeof(Node));
    if(!L) return NULL;
    L->data=0;
    L->next=NULL;
    return L;
}

int ListEmpty(LinkList L){
    return L->data==0;
}

int ListLength(LinkList L){
    return L->data;
}

int ListLocate(LinkList L, ElemType e){
    int j;
    LinkList p=L->next;
    j=1;
    while(p&&p->data!=e){
        p=p->next;
        j++;
    }
    if(!p) return 0;
    return j;
}

Status GetElem(LinkList L, int i, int *e){
    int j;
    LinkList p=L->next;
    j=1;
    while(j<i&&p){
        p=p->next;
        j++;
    }
    if(!p||j>i) return ERROR;
    *e=p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e){
    int j;
    LinkList p, s;
    p=*L;
    j=1;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i) return ERROR;
    s=(LinkList)malloc(sizeof(Node));
    if(!s) return ERROR;
    s->data=e;
    s->next=p->next;
    p->next=s;
    (*L)->data++;
    return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e){
    int j;
    LinkList p=*L;
    j=1;
    while(p->next&&j<i){
        p=p->next;
        j++;
    }
    if(!p->next||j>i) return ERROR;
    LinkList q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    (*L)->data--;
    return OK;
}

void ClearList(LinkList *L){
    LinkList p=(*L)->next;
    while(p){
        LinkList q=p;
        p=p->next;
        free(q);
    }
    (*L)->next=NULL;
    (*L)->data=0;
}