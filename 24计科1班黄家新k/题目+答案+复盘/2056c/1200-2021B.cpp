//��Ŀ���������飬�������������Բ��ã�����һ��a[i]+x��������mex�Ƕ���
//mex��ָ��ǰ������ģ�δ���ֹ�����С���֣�����0 2 3��mex���� 1������0 1 2 3��mex���� 4 

#include<bits/stdc++.h>
using namespace std;
int T,n,a[200001],x,ans;
map<int,int> m;//m ͳ�����ֵĳ��ִ��� 
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
			if(!m[i]){//δ���֣��ҵ� mex ��ֹѭ�� 
				ans = i;
				break;
			}
			if(m[i] > 1){//���ֳ���һ�Σ�ִ�в��� 
				m[i + x] += m[i] - 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



//���˴��룬��ʱ��ʵ����ֻ��Ҫ����һ�顣
//��a[i]���ִ���-1��ֵ��a[i]+x���У����� �� 


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


