//
//  binarySearch.cpp
//  day01
//
//  Created by 卢昶存 on 2019/7/13.
//  Copyright © 2019 noyark. All rights reserved.
//
#include <iostream>

//二分查找
int binarySearch(int arr[],int len,int target){
    
    int low = 0;
    int high = len;
    int middle = 0;
    while(low< high){
        middle = (low+high)<<2;
        if(target == arr[middle]){
            return target;
        }else if(target>arr[middle]){
            low = target + 1;
        }else if(target<arr[middle]){
            high = target;
        }
    }
    return -1;
}

//深度查询
int dx1[4]{0,0,1,-1};
int dy1[4]{1,-1,0,0};
bool vis1[6][6];
//m = 6;n=6
void dfs1(int x,int y){
    
    vis1[x][y] = true;
    
    for(int i = 0;i<4;i++){
        int xx = x + dx1[i];
        int yy = y + dy1[i];//上下左右查询
        if(xx<1||xx>6)continue;
        if(yy<1||yy>6)continue;
        if(!vis1[xx][yy])dfs1(x, y);//继续查询下去
    }
}

//广度查询 bfs
#define MAXN 1005
int q[MAXN];//队列

int lc[MAXN]{1,3,5,7,9};//左子树
// 0 1 2 3 4 5 6
// 1 3 5 7 9 11 13
// 0 1 2 3 4 5 6
// 2 4 6 8 10 12 14

int rc[MAXN]{2,4,6,8,10};//右子树

void bfs1(int root,int h){
    int count = 0;
    int left = root;
    int right = root;
    while(count <= h){
        q[count++] = lc[left++];
        q[count++] = rc[right++];
    }
    for(int i = 0;i<count;i++){
        std::cout<<q[i]<<std::endl;
    }
}

//广泛查询
void bfs(int root){
    int st = 1, en = 0;//en,st计数
    q[++en] = root;//存储查询到的节点
    while(st <= en){
        int t = q[st++];//获取节点b
        printf("bfs ---> %d\n",t);
        if(lc[t]) q[++en] = lc[t];//通过节点取出子节点
        if(rc[t]) q[++en] = rc[t];//通过节点取出子节点
    }
    for(int i =0;i<=en;i++){
        printf("%d",q[i]);
    }
}

//快速幂

int power(int a,int b){
    
    int ret = 1;
    while(b){
        if(b&1)ret*=a;
        b>>=1;a = a*a;
    }
    return ret;
}

//二分答案

//迷宫问题

//直接·枚举

//归并排序

//贪心算法的实现(那几道题，每天练一遍)
