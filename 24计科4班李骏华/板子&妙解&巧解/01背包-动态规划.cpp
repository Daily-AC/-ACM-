#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, bagweight;// bagweight����������ռ�

    cin >> n >> bagweight;

    vector<int> weight(n, 0); // �洢ÿ����Ʒ��ռ�ռ�
    vector<int> value(n, 0);  // �洢ÿ����Ʒ��ֵ

    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for(int j = 0; j < n; ++j) {
        cin >> value[j];
    }
    // dp����, dp[i][j]����������ռ�Ϊj�������,���±�Ϊ[0, i]����Ʒ��������ȡ,�ܴﵽ������ֵ
    vector< vector<int> > dp(weight.size(), vector<int>(bagweight + 1, 0));

    // ��ʼ��, ��Ϊ��Ҫ�õ�dp[i - 1]��ֵ
    // j < weight[0]�����Ϸ�����ʼ��Ϊ0
    // j >= weight[0]��ֵ�ͳ�ʼ��Ϊvalue[0]
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); i++) { // ����������Ʒ
        for(int j = 0; j <= bagweight; j++) { // ��������������
            if (j < weight[i]) dp[i][j] = dp[i - 1][j]; // ���װ���������Ʒ,��ô�ͼ̳�dp[i - 1][j]��ֵ
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);//���ƹ�ʽ 
            }
        }
    }
    cout << dp[n - 1][bagweight] << endl;

    return 0;
}
