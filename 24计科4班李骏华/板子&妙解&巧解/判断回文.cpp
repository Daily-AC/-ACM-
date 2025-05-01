#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int cnt=0,cnt5=0,n;
	string s;
	cin >> s;
	string mid=s; 
	reverse(s.begin(),s.begin());
	if(s!=mid) cout << "NOT";
	else cout << "YES";
	return 0;	
} 
