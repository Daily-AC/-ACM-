#include<stdio.h>
#define N 50
int BinSearch(long a[] ,long x,int n);
/*  BinSearch（）函数功能：在含有n个元素的数组a中查找非负整数x的最小下标。
   函数参数：
   参数a[],表示一维数组。
   参数n，为一维数组a的元素个数。
   参数x，要查找的非负整数。
   函数返回值： 为查找到的元素的最小下标。
*/
int Read(long a[]);
/* Read（）函数功能：输入负整数赋给数组a的元素输入负数结束。
   函数参数：
   参数a[],表示一维数组
   函数返回值：输入的元素的个数 
*/
void Print(long a[],int n);
/* Print（）函数功能：输出中的n个元素 
   参数a[],表示一维数组
   参数n，为一维数组a的元素个数。
   函数返回值：无
   */ 
void SortASC(long a[],int n);
/* SortASC（）函数功能：将n个整数升序排列 
   参数a[],表示一维数组
   参数n，为一维数组a的元素个数。
   函数返回值：无
   */ 


int main(void)
{
    /*********Begin*********/
    long a[N],x; int n,mid;
 	n=Read(a);
	scanf("%d",&x);
	SortASC(a,n);
	Print(a,n);	
	mid=BinSearch(a,x,n);
	if(mid==-1) printf("None");
	else printf("%d",mid);
    /*********End**********/
    return 0;
}
void SortASC(long a[],int n)
{ /*********Begin**********/
	 int i,j,mid;
  	for(i=0;i<n-1;i++){
  		for(j=0;j<n-1-i;j++){
    	 	if(a[j]>a[j+1]){
      		mid=a[j];
      		a[j]=a[j+1];
      		a[j+1]=mid;
    	}
   	}
}
 /*********End**********/
 }
 

int Read(long a[])
{int i=-1;
/*********Begin**********/
 int b;
 for(b=0;b>=0;b++)
 {
 	scanf("%d",&a[b]);
 	i++;
 	if(a[b]==-1) break;
 }
 /*********End**********/
return i;
}
void Print(long a[],int n)
{/*********Begin**********/
	int i;
	for(i=0;i<=n;i++)
	{
	if(a[i]>0) printf("%d ",a[i]);
	}
 /*********End**********/
} 
int BinSearch(long a[] ,long x,int n)
{int low=0,high=n-1,mid;
 while(low<=high)
 { mid=(low+high)/2;
   if(x>a[mid]) low=mid+1;
   else if(x<a[mid]) high=mid-1;
   else 
  { 
    do 
    { if(mid!=0&&a[mid-1]==x) mid--; 
      else return mid;
     }while(1);
	 
  }
    
   }
   return -1;   
}   
 


