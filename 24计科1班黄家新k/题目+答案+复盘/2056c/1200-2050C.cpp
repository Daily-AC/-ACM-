//题目：判断能否通过修改字符串（如：2344123）里面的2和3，使得：最终的数%9==0

#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    int t;cin >> t;
    while (t--) {
        //思路是看各个位子的和，是否是9的倍数，比如333，3+3+3=9，那就可以整除9
   
        string strn ;  //转为字符串，好找各个位子
        cin >> strn;
        ll sum = 0;
        ll a = 0;
        ll b = 0;
        for (int i = 0;i < strn.size();i++) {
            int mid = strn[i] - '0';
            sum += mid;  //先求和
            if (strn[i] == '2') a++;
            if (strn[i] == '3') b++;
        }
        if (sum % 9 == 0) {  //如果是9的倍数，直接返回
            cout << "YES" << endl;
            continue;
        }
        bool check = 0;                 //只有2和3符合题意，平方后<10
        ll m = 9 - sum % 9;
        for (int i = 0;i <= a;i++) {
            //这里sum要么+6要么+2 ，3->9是6     2->4是2
            for (int j = 0;j <= b;j++) {
                if ((i * 2 + j * 6) % 9 == m) {   //这里的思路很有意思
                    cout << "YES" << endl;         //它是通过直接算出离9的倍数还差多少
                    check = 1;            //随后单独拎出来计算，看看具体需要多少个2和3
                    break;                //我当时也在想怎么去计算2和3具体要多少个
                }                       //这里的很巧妙，用%来避免超出9，只要一直%9，总会找到
            }               //不用担心找不到，因为这里是对所有的i和j全部找了一遍，所有可能
            if (check == 1) break; 
        }
        if (check == 0) {
            cout << "NO" << endl;
            continue;
        }

    }

    return 0;
}