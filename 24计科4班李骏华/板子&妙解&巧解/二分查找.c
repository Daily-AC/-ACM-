#include<stdio.h>
#define N 50
int BinSearch(long a[] ,long x,int n);
/*  BinSearch�����������ܣ��ں���n��Ԫ�ص�����a�в��ҷǸ�����x����С�±ꡣ
   ����������
   ����a[],��ʾһά���顣
   ����n��Ϊһά����a��Ԫ�ظ�����
   ����x��Ҫ���ҵķǸ�������
   ��������ֵ�� Ϊ���ҵ���Ԫ�ص���С�±ꡣ
*/
int Read(long a[]);
/* Read�����������ܣ����븺������������a��Ԫ�����븺��������
   ����������
   ����a[],��ʾһά����
   ��������ֵ�������Ԫ�صĸ��� 
*/
void Print(long a[],int n);
/* Print�����������ܣ�����е�n��Ԫ�� 
   ����a[],��ʾһά����
   ����n��Ϊһά����a��Ԫ�ظ�����
   ��������ֵ����
   */ 
void SortASC(long a[],int n);
/* SortASC�����������ܣ���n�������������� 
   ����a[],��ʾһά����
   ����n��Ϊһά����a��Ԫ�ظ�����
   ��������ֵ����
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
 


