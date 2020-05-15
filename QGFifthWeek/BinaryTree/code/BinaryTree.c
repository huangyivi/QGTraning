#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"
#include"AQueue.c"
// 初始化二叉树
Status InitBiTree(BiTree *T){
    *T = (BiTree)malloc(sizeof(BiTNode));
    if(*T == NULL){
        printf("构造失败！\n");
        return ERROR;
    }else{
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->data = NULL;
        printf("初始化成功\n");
        return SUCCESS;
    }
}

// 摧毁二叉树
Status DestroyBiTree(BiTree *T){
    if((*T) != NULL){
        DestroyBiTree((*T)->lchild);
        DestroyBiTree((*T)->rchild);
        free(*T);
        printf("摧毁二叉树成功！\n");
        return SUCCESS;
    }else{
        printf("树未初始化！请先初始化！\n");
        return ERROR;
    }
    
}

// 构建二叉树
Status CreateBiTree(BiTree *T, char* definition){
    definition = (char*)malloc(sizeof(char));
    (*definition) = getchar();
    if((*definition) == '#'){
        *T = NULL;
        return ERROR;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = *definition;
        CreateBiTree(&((*T)->lchild),definition);
        CreateBiTree(&((*T)->rchild),definition);
        return SUCCESS;
    }
}

// 先序遍历
Status PreOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        visit((*T)->data);
        PreOrderTraverse(&((*T)->lchild),visit);
        PreOrderTraverse(&((*T)->rchild),visit);
    }else{
        return SUCCESS;
    }

}

// 中序遍历
Status InOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        PreOrderTraverse(&((*T)->lchild),visit);
        visit((*T)->data);
        PreOrderTraverse(&((*T)->rchild),visit);
    }else{
        return SUCCESS;
    }

}

// 后序遍历
Status PostOrderTraverse(BiTree *T, Status (*visit)(TElemType e)){
    if(*T){
        PreOrderTraverse(&((*T)->lchild),visit);
        PreOrderTraverse(&((*T)->rchild),visit);
        visit((*T)->data);
    }else{
        return SUCCESS;
    }

}

// 打印
Status print(TElemType e){
    printf("\t%c",e);
    return SUCCESS;
}

// 是否存在
int isExist(int flag){
    if(flag){
        return 1;
    }else{
        return 0;
    }
}


void menu(){
    printf("----------------------------------------\n\
-----------*欢迎进入二叉树ADT*-----------\n\
----------------------------------------\n\
--------------*请选择以下功能*--------------\n\
----------------------------------------\n\
||     1      ||-------->||初始化树    ||\n\
||     2      ||-------->||构造树      ||\n\
||     3      ||-------->||销毁树      ||\n\
||     4      ||-------->||先序遍历    ||\n\
||     5      ||-------->||中序遍历    ||\n\
||     6      ||-------->||后续遍历    ||\n\
||     7      ||-------->||退出系统    ||\n\
----------------------------------------\n\
请选择功能(以第一个字符为标准):\
");
}
