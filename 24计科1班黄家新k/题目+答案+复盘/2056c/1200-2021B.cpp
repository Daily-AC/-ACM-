//题目：给个数组，给个操作（可以不用）：将一个a[i]+x，问最大的mex是多少
//mex是指当前数组里的，未出现过的最小数字，比如0 2 3，mex就是 1，比如0 1 2 3，mex就是 4 

#include<bits/stdc++.h>
using namespace std;
int T,n,a[200001],x,ans;
map<int,int> m;//m 统计数字的出现次数 
int main(){ 
	scanf("%d",&T);
	while(T--){
		m.clear();
		scanf("%d%d",&n,&x);
		ans = n;
		for(int i = 1;i <= n;i ++){
			scanf("%d",&a[i]);
			m[a[i]] ++;
		}
		for(int i = 0;i < n;i ++){
			if(!m[i]){//未出现，找到 mex 终止循环 
				ans = i;
				break;
			}
			if(m[i] > 1){//出现超过一次，执行操作 
				m[i + x] += m[i] - 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



//本人代码，超时，实际上只需要遍历一遍。
//将a[i]出现次数-1后赋值给a[i]+x就行，如上 ↑ 


//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//signed main()
//{
//    ios::sync_with_stdio(0);
//    cout.tie(0);
//    cin.tie(0);
//    int t;cin >> t;
//    while (t--) {
//        ll n, x;
//        cin >> n >> x;
//        vector<ll> a(n + 1);
//        unordered_map<ll, ll> visited;
//        visited.clear();
//        for (int i = 1;i <= n;i++) {
//            cin >> a[i];
//            visited[a[i]]++;
//            while(visited[a[i]] > 1) {
//                visited[a[i]]--;
//                a[i] += x;
//                visited[a[i]]++;
//            }
//        }
//    
////        sort(a.begin(), a.end()); 	
////		for (int i = 1;i <= n;i++) {
////            cout<<a[i]<<" ";
////          cout.flush(); 
////        }
//  		
//        for (int i = 0;i<=n;i++) {
//            if (!visited[i]) {
//            	cout.flush(); 
//                cout << i << endl;
//                break;
//            }
////            else if(i==n){
////            	cout.flush(); 
////            	cout<<a[i]+1<<endl;
////			}
//        }
//
//    }
//
//    return 0;
//}


