#include <iostream>
#include <string>
using namespace std;

// 基类
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {} // 基类带参构造
};

// 派生类 【考点】必须写 public 继承！
class Student : public Person {
private:
    string studentID;
    double score;
public:
    // 【考点】冒号后面必须显式给父类传参！
    Student(string n, int a, string id, double s) 
        : Person(n, a), studentID(id), score(s) {} 
    
    void display() {
        // 输出全部信息
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << "岁" << endl;
        cout << "学号:" << studentID << endl;
        cout << "成绩:" << score << "分" << endl;
    }
};

int main() {
    Student stu("李四", 20, "2024001", 85.5);
    stu.display();
    return 0;
}