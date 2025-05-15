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
	ll t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(s[0]==s[s.size()-1]){
			cout<<0<<endl;
			continue;
		}
		else{
			bool check=0;
			for(int i=1;i<s.size();i++){
				if(s[i]==s[i-1]){
					cout<<i<<endl;
					check=1;
					break;
				}
				
			}
			if(check==0){
				cout<<-1<<endl;
			}
			
		}
	}
	return 0;
}

