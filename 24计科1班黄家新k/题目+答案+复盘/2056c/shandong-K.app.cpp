/*
	
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#define N 400005//注意离散化数组范围 
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin>>n;
	vector< vector<ll> > a(n+1,vector<ll> (n+1) );
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(i<=n-2) a[i][j]=i;
			else{
				if(j<=n-2) {
					a[i][j]=i-1+j;
					a[i+1][j]=i-1+j;
				}
				else {
					a[i][j]=2*n;
					a[i][j+1]=a[i][j]-1;
					a[i+1][j]=a[i][j+1]-1;
					a[i+1][j+1]=a[i+1][j]-1;
					break;
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}

