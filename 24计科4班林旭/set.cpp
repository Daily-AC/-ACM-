#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // 自动排序并去重：1, 2, 3, 4, 5, 6, 9
    int i = 3; // 例如，获取第4个元素（注意索引从0开始）
    if (i < mySet.size()) {
        auto it = mySet.begin();
        advance(it, i); // 将迭代器向前移动i个位置
        int x = *it;    // 获取迭代器指向的值
        cout << "第" << i+1 << "个元素是：" << x << endl;
    } else {
        cout << "索引超出范围！" << endl;//输出为第4个元素：4 
    }
    return 0;
}
