#include <iostream>
using namespace std;

long long combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k); // �Ż�Ϊ��С��kֵ
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i; // ÿһ�����������������������
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << combination(n, k) << endl;
    return 0;
}
