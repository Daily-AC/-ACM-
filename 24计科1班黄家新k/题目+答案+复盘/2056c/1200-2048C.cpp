//请务必去死，根本不会写 ，太可怕了 



#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5007;
ll T,n,fl;
char s[N],t[N];
vector<ll> ans,tmp[2];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>(s+1);n=strlen(s+1);
		fl=0;
		for (int i=1;i<=n;++i){
			t[i]=s[i];
			if (s[i]=='0'&&fl==0) fl=i;
		}
		if (!fl) cout<<"1 1 1 "<<n<<endl;
		else{
			ans.clear();
			for (int i=1;i<=fl;++i) if (s[i]=='1') ans.emplace_back(i);
			for (int i=fl+1;i<=n;++i){
				tmp[0].clear();tmp[1].clear();
				for (auto x:ans) tmp[s[i]^s[x+i-fl]].emplace_back(x);
				if (tmp[1].size()) ans.swap(tmp[1]);
			}
			cout<<1<<' '<<n<<' '<<ans[0]<<' '<<ans[0]+n-fl<<endl;
		}
	}
	return 0;
}
