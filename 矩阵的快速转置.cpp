#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 12500
typedef struct{
	int i,j ;         
    int e;     
}Triple;

typedef struct{
    Triple data[MAXSIZE + 1];
    int mu,nu,tu;
}TSMatrix;

void  FastTransMatrix(TSMatrix M, TSMatrix &T)
{  
	int col,t,p,q,num[100],cpot[100]; 
	T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
	if(T.tu){
		for(col = 0;col<M.nu;++col) 
	  		num[col]=0;
		for(t=0; t<M.tu; ++t) 
	  		++num[M.data[t].j];
      	cpot[0] = 1;
    	for(col = 1;col<M.nu;++col) 
        	cpot[col] = cpot[col-1] + num[col-1];
    	for(p=0;p<M.tu;++p){
       		col=M.data[p].j; 
			q=cpot[col];
    		T.data[q].i = M.data[p].j; 
			T.data[q].j = M.data[p].i;
        	T.data[q].e = M.data[p].e; 
			++cpot[col];
     }
  }
}
void put(TSMatrix &T){
	int i=0;
	T.tu=0;
	printf("行列数分别为"); 
	scanf("%d%d",&T.mu,&T.nu);
	printf("行数 列数 元素 输入一组数据后输入0结束\n"); 
	while(1){
		scanf("%d",&T.data[i].i);
		if(T.data[i].i==0) break;
		scanf("%d%d",&T.data[i].j,&T.data[i].e);
		if(T.data[i].i>T.mu || T.data[i].j>T.nu || T.data[i].i<1 || T.data[i].j<1) {
			printf("输入错误\n");
			break; 
		}
		T.tu++;
		i++;
	}
}

void out(TSMatrix &T){
	int a;
	for(a=0;a<T.tu;a++)
		printf("%d %d %d\n",T.data[a].i,T.data[a].j,T.data[a].e);
}

int main(){
	TSMatrix T,M;
	put(T);
	FastTransMatrix(T,M);
	out(M);
}


	
	
