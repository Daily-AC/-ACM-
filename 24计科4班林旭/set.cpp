#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5}; // �Զ�����ȥ�أ�1, 2, 3, 4, 5, 6, 9
    int i = 3; // ���磬��ȡ��4��Ԫ�أ�ע��������0��ʼ��
    if (i < mySet.size()) {
        auto it = mySet.begin();
        advance(it, i); // ����������ǰ�ƶ�i��λ��
        int x = *it;    // ��ȡ������ָ���ֵ
        cout << "��" << i+1 << "��Ԫ���ǣ�" << x << endl;
    } else {
        cout << "����������Χ��" << endl;//���Ϊ��4��Ԫ�أ�4 
    }
    return 0;
}
