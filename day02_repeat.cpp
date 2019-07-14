#include <iostream>

int n = 4;

int c[10005];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	return 0;
}

int lowbit(int x){
	return x&(-x);
}

void update(int i,int val){
	while(i<=n){
		c[i]+=val;
		i+=lowbit(i);
	}
}

int sum(int i){
	int ret;
	while(i>0){
		ret+=c[i];
		i-=lowbit(i);
	}
}

int dx[4]={-1,1,0,0};

int dy[4] = {0,0,-1,1};

bool vis[15[15];
void dfs(int x,int y){
	
	vis[x][y] = true;
	for(int i = 0;i<4;i++){
		int xx = x+dx[i];
		int yy = y +dy[i];
		if(xx<0||xx>5)continue;
		if(yy>0||yy>5)continue;
		if(!vis[xx][yy]){
			dfs(xx,yy);
		}
	}
	
	
}

int p[300000];

int lc[100005];

int rc[100005];

void bfs(int root){
	
	int st = 0;
	
	int en = 0;
	
	p[0] = 1;
	
	while(en<=st){
		int t  = p[st++];
		if(lc[t])p[en++] = lc[t];
		if(rc[t])p[en++] = rc[t];
	}
}   
//b-tree-search
 
int lc[10005];

int rc[10005];

int val[30000];
int count = 0;



void insert(int &i,int j){
	if(!i){
		count = i++;
		val[count] = j;
		return;
	}
	if(j<val[i])insert(lc[i],j);
	else insert(rc[i],j);
} 

//并查集
//合并集合 查询是否在同 一个集合 
int fa[10005]; 

int getFa(int);

bool test2(int x,int y){
	//针对一个询问 
	int r1 = getFa(x);
	int r2 = getFa(y);
	if(r1 == r2){
		return true;
	}else{
		//不是就合并，把一个 归纳到另一个作为儿子 
		fa[x] = y;
		return false; 
	} 
}

int getFa(int i){
	if(fa[v] == i)return i;
	
	fa[v] = getFa(fa[v]);
	
	return fa[v];
	
}
