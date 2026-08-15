#include <iostream>
using namespace std;

// 1. 两个 int 最大值
int max(int a, int b) {
    return (a > b) ? a : b;
}
// 2. 三个 int 最大值（参数个数不同，构成重载）
int max(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}
// 3. 三个 double 最大值（参数类型不同，构成重载）
double max(double a, double b, double c) {
    double m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

int main() {
    // 测试
    cout << "两个 int 最大值: " << max(5, 8) << endl;
    cout << "三个 int 最大值: " << max(5, 8, 3) << endl;
    cout << "三个 double 最大值: " << max(1.2, 3.4, 2.0) << endl;
    return 0;
}