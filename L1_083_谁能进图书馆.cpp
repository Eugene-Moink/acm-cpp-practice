#include<bits/stdc++.h>
using namespace std;

int main()
{
    int not_age, with_age, age_1, age_2;
    cin >> not_age >> with_age >> age_1 >> age_2;

    // --- 1. 判断谁能进 ---
    bool can_enter_1 = false;
    bool can_enter_2 = false;

    // 判断 1 号能否进入
    if(age_1 >= not_age) {
        // 1号自己就能进
        can_enter_1 = true;
    } else {
        // 1号是小孩，需要2号陪同
        if(age_2 >= with_age) {
            can_enter_1 = true; // 2号可以陪同，所以1号能进
        }
    }

    // 判断 2 号能否进入
    if(age_2 >= not_age) {
        // 2号自己就能进
        can_enter_2 = true;
    } else {
        // 2号是小孩，需要1号陪同
        if(age_1 >= with_age) {
            can_enter_2 = true; // 1号可以陪同，所以2号能进
        }
    }

    // --- 2. 输出第一行 ---
    if(can_enter_1) {
        cout << age_1 << "-Y ";
    } else {
        cout << age_1 << "-N ";
    }

    if(can_enter_2) {
        cout << age_2 << "-Y" << endl;
    } else {
        cout << age_2 << "-N" << endl;
    }

    // --- 3. 分析情况并输出第二行 ---
    if(can_enter_1 && can_enter_2) {
        // 两人都能进
        // 检查是否是“必须一起进”的情况 (一人是小孩，一人是成人)
        bool is_child_1 = age_1 < not_age;
        bool is_adult_2 = age_2 >= with_age;
        bool is_child_2 = age_2 < not_age;
        bool is_adult_1 = age_1 >= with_age;

        if( (is_child_1 && is_adult_2) || (is_child_2 && is_adult_1) ) {
            // 是“必须一起进”的情况
            if(is_adult_1) {
                cout << "qing 1 zhao gu hao 2" << endl;
            } else { // is_adult_2
                cout << "qing 2 zhao gu hao 1" << endl;
            }
        } else {
            // 不是“必须一起进”，只是普通都能进
            cout << "huan ying ru guan" << endl;
        }
    } else if (!can_enter_1 && !can_enter_2) {
        // 两人都进不去
        cout << "zhang da zai lai ba" << endl;
    } else {
        // 一人能进，一人不能进
        if(can_enter_1) {
            cout << "1: huan ying ru guan" << endl;
        } else { // can_enter_2
            cout << "2: huan ying ru guan" << endl;
        }
    }

    return 0;
}