
//��Ŀ���������飬������ i<j ʱ���Ƴ� i��j Ԫ�غ�ʣ����� [x,y] ��Χ�ڵ������� 


// ����˼·���̣�
// 1. ��ѧ��ʽ�Ƶ����ؼ�ת������
// �������ܺ�Ϊ sum���Ƴ�λ�� i �� j ��Ԫ�غ�ʣ���Ϊ sum - a [i] - a [j]
// �������� x ��sum-a[i]-a[j] �� y�����εõ� a [j] ��ȡֵ��Χ��
// sum - y - a [i] �� a [j] �� sum - x - a [i]
// �ɴ˽�����ת��Ϊ����ÿ�� i���ҵ�����������Χ�� j ��������j > i��

// 2. ���� + �����Ż������Ⱪ��ö�٣���
// - �ȶ���������ʹ a [j] ����Ϊ�����̵� 
// - ��ÿ�� i��ʹ�� lower_bound �ҵ� a [j] ����߽�
// - ʹ�� upper_bound �ҵ� a [j] ���ұ߽磬-1 
// - �������䳤�ȣ�pos2 - pos1 + 1����Ϊ��ǰ i ��Ӧ�ĺϷ� j ������
// �÷�����ԭ�� O (n2) �ı���ö���Ż��� O (n log n)�������˴��������µĳ�ʱ����
// �ܽ᣺ͨ����ѧ�Ƶ���ȷ������Χ����������Ͷ��ֲ���ʵ�ָ�Ч�������ǽ������ĺ��Ĳ���

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





