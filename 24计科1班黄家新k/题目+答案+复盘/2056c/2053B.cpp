//��Ҫ���Ż���

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
        for (int i = 1; i <= 2 * n; i++) { //�ǵ���������
            s[i] = a[i] = 0;
        }
        for (int i = 1;i <= n;i++) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                a[l[i]]++;  //a��������ʵ���ǹ�ϣ��
                s[l[i]] = 1;//l�Ǽ�¼ǰ׺�͵�
            }
        }

        for (int i = 1;i <= 2*n;i++) {
            s[i] += s[i - 1];
        }
        
        for (int i = 1;i <= n;i++) {
            if (l[i] == r[i]) {
                if (a[l[i]] == 1) cout << 1;  //�����ϣ��Ϊ1��˵�����Ԫ��ֻ������һ�Σ�����
                else cout << 0;
            }
            else {  //����˴�ǰ׺�����ǵ�����=��ǰ������˵��ûλ�����Ѿ���
                    //���統ǰ��3 5����ô����ǰ��ǰ׺�ͼ�¼�Ĵ�3��5Ϊ3��������5-3��3����3,4,5��������
                   //������˵�����λ���Ѿ����ˣ�ǰ׺�͵�ǿ����Ǳ������ÿ�ζ�Ҫ����
                if (s[r[i]] - s[l[i]-1] == r[i] - l[i]+1) cout << 0;  
                else cout << 1;
            }
        }
        cout << endl;

    }
    return 0;
}



//��������Ż�������������е��Ż��㷨��ǰ׺�������Ƿǳ�������