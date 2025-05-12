#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int a[6]={0};
	int x;
	
	for(int i=1;i<=4;i++){
		cin>>x;
		a[x]=1;
	//	cout<<x<<" "<<a[x]<<endl;	
	}
	for(int i=1;i<=5;i++){
		if(a[i]==0) cout<<i;
	}
	
	
	return 0;
} 
