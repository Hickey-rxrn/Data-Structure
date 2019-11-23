//
//  main.cpp
//  test_10_27(Vector)
//
//  Created by 张辉 on 2019/10/22.
//  Copyright © 2019 张辉. All rights reserved.
//
//
//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}


#include <iostream>
#include <vector>
#include "Vector.h"
using namespace std;

// vector的使用
void test_vector1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
// 1.
    for(size_t i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
// 2.
    vector<int>::iterator it1 = v1.begin();
    while(it1 != v1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
// 3.
    for(auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;
    vector<int> v2(10, 5);
    vector<int> v4(v1.begin(), v1.end());
    vector<int> v5(++v1.begin(), --v1.end());
}
void test_vector2()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::reverse_iterator rit = v.rbegin(); //逆置
    while(rit != v.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}
void test_vector3()
{
    vector<int> v;
    v.reserve(10);
    v.reserve(20);
    v.reserve(10);    //不会缩容
    v.resize(10);   // 10 10
    v.resize(20);   // 20 20
    v.resize(10);   // 10 20
    v.insert(v.begin(), -1);
}
void test_vector5()
{
    int a[] = { 1, 2, 3, 4 };
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    typedef int* iterator;
    iterator it = a;
    while (it != a + sizeof(a) / sizeof(int))
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    // find算法体现-泛型层面代码复用
    vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    v.insert(pos, 30);  //可能会失效，如果增容pos就会失效
    pos = find(v.begin(), v.end(), 3);
    v.erase(pos); //pos都失效了
    cout << *pos << endl; //vs下会报错（pj版自己j会检查），Linux下不报错
}

void test_vector6()
{
    vector<int> v1(10, 5);
    vector<int> v2(5, 10);
    swap(v1, v2);  //深拷贝，代价大
    v1.swap(v2);   //代价小，只是两个指针互换
}
int main()
{
    test_vector1();
    test_vector2();
    test_vector3();
    test_vector5();
    return 0;
}



