#include<iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType data;
    int cur;
} component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space){
    for(int i=0; i<MAXSIZE-1; i++){
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
    return OK;
}

int Malloc_SLL(StaticLinkList space){
    int i=space[0].cur;
    if(i) space[0].cur=space[i].cur;
    return i;
}

Status Add_To_Head(StaticLinkList L, ElemType e){
    int i=MAXSIZE-1;
    L[1].data=e;
    L[1].cur=L[i].cur;
    L[i].cur=1;
    return OK;
}

int ListLength(StaticLinkList L){
    int i=L[MAXSIZE-1].cur;
    int j=0;
    while(i!=0){
        i=L[i].cur;
        j++;
    }
    return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e){
    int j, k, l;
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)
    return ERROR;
    j=Malloc_SLL(L);
    L[j].data=e;
    for(l=1; l<=i-1; l++){
        k=L[k].cur;
    }
    L[j].cur=L[k].cur;
    L[k].cur=j;
    return OK;
}

void free_SLL(StaticLinkList L, int j){
    L[j].cur=L[0].cur;
    L[0].cur=j;
}

Status ListDelete(StaticLinkList L, int i, ElemType *e){
    int j, k;
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L))
    return ERROR;
    for(j=1; j<=i-1; j++){
        k=L[k].cur;
    }
    j=L[k].cur;
    *e=L[j].data;
    L[k].cur=L[j].cur;
    free_SLL(L, j);
    return OK;
}