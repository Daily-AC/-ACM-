
//题目：给定数组，求所有 i<j 时，移除 i、j 元素后，剩余和在 [x,y] 范围内的数量。 


// 核心思路复盘：
// 1. 数学公式推导（关键转化）：
// 设数组总和为 sum，移除位置 i 和 j 的元素后，剩余和为 sum - a [i] - a [j]
// 根据条件 x ≤sum-a[i]-a[j] ≤ y，变形得到 a [j] 的取值范围：
// sum - y - a [i] ≤ a [j] ≤ sum - x - a [i]
// 由此将问题转化为：对每个 i，找到满足上述范围的 j 的数量（j > i）

// 2. 排序 + 二分优化（避免暴力枚举）：
// - 先对数组排序，使 a [j] 有序，为二分铺垫 
// - 对每个 i，使用 lower_bound 找到 a [j] 的左边界
// - 使用 upper_bound 找到 a [j] 的右边界，-1 
// - 计算区间长度（pos2 - pos1 + 1）即为当前 i 对应的合法 j 的数量
// 该方法将原本 O (n2) 的暴力枚举优化至 O (n log n)，避免了大数据量下的超时问题
// 总结：通过数学推导明确搜索范围，利用排序和二分查找实现高效计数，是解决本题的核心策略

#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
#include<unordered_map>
#define ll long long
const int N = 4e5 + 10;
int s[N]={ 0 };
int l[N], r[N];
using namespace std;
int main()
{
    ll t;
    cin >> t;

    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
    
        vector<int> a(n + 1);
        ll sum = 0;
        for (int i = 1;i <= n;i++) {
           cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(),a.end());
        ll ans = 0;
        for (int i = 1;i <= n;i++) {
            ll pos1=lower_bound(a.begin()+i+1,a.begin()+n+1,sum-y-a[i])-a.begin();
            ll pos2=upper_bound(a.begin()+i+1,a.begin()+n+1,sum-x-a[i])-a.begin()-1;
            if(a[pos1]>=sum-y-a[i] && a[pos2]<=sum-x-a[i]) ans+=pos2-pos1+1;
        }
        cout << ans << endl;


    }

    return 0;
}





