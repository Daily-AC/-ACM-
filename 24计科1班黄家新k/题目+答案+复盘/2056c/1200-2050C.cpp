//��Ŀ���ж��ܷ�ͨ���޸��ַ������磺2344123�������2��3��ʹ�ã����յ���%9==0

#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    int t;cin >> t;
    while (t--) {
        //˼·�ǿ�����λ�ӵĺͣ��Ƿ���9�ı���������333��3+3+3=9���ǾͿ�������9
   
        string strn ;  //תΪ�ַ��������Ҹ���λ��
        cin >> strn;
        ll sum = 0;
        ll a = 0;
        ll b = 0;
        for (int i = 0;i < strn.size();i++) {
            int mid = strn[i] - '0';
            sum += mid;  //�����
            if (strn[i] == '2') a++;
            if (strn[i] == '3') b++;
        }
        if (sum % 9 == 0) {  //�����9�ı�����ֱ�ӷ���
            cout << "YES" << endl;
            continue;
        }
        bool check = 0;                 //ֻ��2��3�������⣬ƽ����<10
        ll m = 9 - sum % 9;
        for (int i = 0;i <= a;i++) {
            //����sumҪô+6Ҫô+2 ��3->9��6     2->4��2
            for (int j = 0;j <= b;j++) {
                if ((i * 2 + j * 6) % 9 == m) {   //�����˼·������˼
                    cout << "YES" << endl;         //����ͨ��ֱ�������9�ı����������
                    check = 1;            //��󵥶���������㣬����������Ҫ���ٸ�2��3
                    break;                //�ҵ�ʱҲ������ôȥ����2��3����Ҫ���ٸ�
                }                       //����ĺ������%�����ⳬ��9��ֻҪһֱ%9���ܻ��ҵ�
            }               //���õ����Ҳ�������Ϊ�����Ƕ����е�i��jȫ������һ�飬���п���
            if (check == 1) break; 
        }
        if (check == 0) {
            cout << "NO" << endl;
            continue;
        }

    }

    return 0;
}