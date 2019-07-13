
//清北学堂 NOIP
//第一天 第一课
//广度查询与深度查询，枚举
//以及那几道练习题
#include "binarySearch.h"
#include <iostream>

//int all = {1,3,4,5};
//
//int choose = {1,3,4};


//待解决的两个题 迷宫 和 直接·枚举 以及 二分答案












//n个整数种选k个整数相加，分别得到一系列的和
//求出素数
//    n      k
// 假如4个数 选3个，那么1 1 1 0
//
// 1                     0
// 1 1 1 0 找4个路径 n    1
//1110 1110 1110        2




int vis[6][6];

int dx[4]{-1,1,0,0};

int dy[4]{0,0,-1,1};


int a[6][6]{
    {0,0,0,0,0,0},
    {0,0,0,1,1,1},
    {0,0,1,0,0,1},
    {0,0,1,0,0,1},
    {0,0,1,1,1,1},
    {0,0,0,0,0,0}
};


bool notIs[6][6];

void dfs(int,int);
void migongDfsDo();

void enumThat();



int vis2[6][6];

int migong[6][6]={
    {0,0,1,0,0,1},
    {0,0,0,1,0,0},
    {0,0,1,0,0,1},
    {0,0,0,0,1,0},
    {0,0,1,0,0,1},
    {0,0,1,1,0,0}
};

int endx = 5;
int endy = 5;

int startx = 0;

int starty = 0;

int answer;
void dfs2(int,int);
void migongDfsDo(){
        //给定一个迷宫，迷宫有T处障碍
        //障碍处不可通过
        //求有多少种通过迷宫的方案，上下左右四种方式
        //此处玄学出没，带解决
    dfs2(startx, starty);
    
    printf("%d",answer);
}



void dfs2(int x,int y){
    //优化
    if(x == endx && y == endy){//到达
        answer++;
        return;
    }
    
    vis[x][y] = true;
    for(int i = 0;i<3;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx<0||xx>5)continue;
        if(yy<0||yy>5)continue;
        //1,0 2,0 0,0 0,-1 1,1
        std::cout<< vis[xx][yy] << std::endl;
        if(!vis[xx][yy])dfs(xx, yy);
    }
    vis[x][y] = false;
}

int main(){
    migongDfsDo();
    return 0;
}

void enumThat(){
    
    int i = 12345;
    int sub1  = i%1000;//345
    int sub2 = i%10000/10;//234
    int sub3 = i/100;//123
    
    int sum = sub1+sub2+sub3;
    printf("%d",sum);
}

void dfsDo(){
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(i == 0||j==0||i==5||j==5){
                notIs[i][j] = true;
                dfs(i, j);
            }
        }
    }
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(!notIs[i][j]&&a[i][j]!=1){
                a[i][j] = 2;
            }
        }
    }
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            std::cout<<a[i][j];
        }
        printf("\n");
    }
}
void dfs(int x,int y){
    vis[x][y] = true;
    for(int i = 1;i<=4;i++){
        int xx = x + dx[i-1];
        int yy = y + dy[i-1];
        if(xx<1||xx>6)continue;
        if(yy <1||yy>6)continue;
        if(a[xx][yy])return;
        if(!vis[xx][yy]){
            
            notIs[xx][yy] = true;
            dfs(xx,yy);
        }
    }
}
// 找出图中被 1 围住的 0，并将他们都变成 2，保证只有一块被围住的 1 。
// 使用深度查询
//例子
// 0 0 0 0 0 0
// 0 0 1 1 1 1
// 0 1 1 0 0 1 ->
// 1 1 0 0 0 1
// 1 0 0 0 0 1
// 1 1 1 1 1 1

// 0 0 0 0 0 0
// 0 0 1 1 1 1
// 0 1 1 2 2 1
// 1 1 2 2 2 1
// 1 2 2 2 2 1
// 1 1 1 1 1 1
