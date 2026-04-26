#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // 排序，确保 a <= b <= c，方便后续判断
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    // 1. 判断是否能构成三角形
    if (a + b <= c) {
        cout << "Not triangle" << endl;
        return 0;
    }

    // 2. 判断角的类型 (只能是其中一个)
    if (a * a + b * b == c * c) {
        cout << "Right triangle" << endl;
    }
    else if (a * a + b * b > c * c) {
        cout << "Acute triangle" << endl;
    }
    else { // a*a + b*b < c*c
        cout << "Obtuse triangle" << endl;
    }

    // 3. 判断边的类型 (可以和角的类型一起输出)
    if (a == b || b == c || a == c) {
        cout << "Isosceles triangle" << endl;
    }
    if (a == b && b == c) {
        cout << "Equilateral triangle" << endl;
    }

    return 0;
}