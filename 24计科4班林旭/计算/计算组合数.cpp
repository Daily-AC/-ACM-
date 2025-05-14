#include <iostream>
using namespace std;

long long combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k); // 优化为较小的k值
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i; // 每一步都能整除，结果保持整数
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << combination(n, k) << endl;
    return 0;
}
