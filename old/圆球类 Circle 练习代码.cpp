#include <iostream>
using namespace std;

class Circle {
private:
    double radius;          // 私有成员
public:
    void get_value();       // 类内声明
    void volume();          // 类内声明
};  // 【考点】结尾必须写分号 !

// 【考点】类外定义必须加上 类名::
void Circle::get_value() {
    cin >> radius; 
}

void Circle::volume() {
    // 【考点】浮点数除法，必须写 4.0/3.0，绝不能写 4/3！
    double v = 4.0 / 3.0 * 3.14 * radius * radius * radius;
    cout << v << endl;
}

int main() {
    Circle c1;
    cout << "请输入圆半径: ";
    c1.get_value();
    cout << "圆体积为: ";
    c1.volume();
    return 0;
}