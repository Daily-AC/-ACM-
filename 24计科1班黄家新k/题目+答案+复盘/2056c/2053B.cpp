//主要是优化难

#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<unordered_map>
#define ll long long
const int N = 4e5 + 10;
int a[N] = { 0 };
int s[N]={ 0 };
int l[N], r[N];
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) { //记得重置数组
            s[i] = a[i] = 0;
        }
        for (int i = 1;i <= n;i++) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                a[l[i]]++;  //a在这里其实就是哈希表
                s[l[i]] = 1;//l是记录前缀和的
            }
        }

        for (int i = 1;i <= 2*n;i++) {
            s[i] += s[i - 1];
        }
        
        for (int i = 1;i <= n;i++) {
            if (l[i] == r[i]) {
                if (a[l[i]] == 1) cout << 1;  //如果哈希表为1，说明这个元素只出现了一次，独立
                else cout << 0;
            }
            else {  //如果此处前缀和里标记的数量=当前数量，说明没位子了已经，
                    //比如当前是3 5，那么假设前面前缀和记录的从3到5为3个，这里5-3是3个（3,4,5），都是
                   //则足以说明这个位子已经满了，前缀和的强大就是避免后续每次都要遍历
                if (s[r[i]] - s[l[i]-1] == r[i] - l[i]+1) cout << 0;  
                else cout << 1;
            }
        }
        cout << endl;

    }
    return 0;
}



//如果不会优化，可以穷举所有的优化算法，前缀和这种是非常常见的