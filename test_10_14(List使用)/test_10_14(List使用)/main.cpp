//
//  main.cpp
//  test_10_14(list)
//
//  Created by 张辉 on 2019/10/15.
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
//
//
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void test_list1()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(0);
    l.sort();   // 排序
    l.unique();  // 去重（必须有序）
    // 插入
    list<int>::iterator pos = find(l.begin(), l.end(), 3);
    l.insert(pos, 30);
    for(auto e : l)
    {
        cout << e << " ";
    }
    cout << endl;
    
    list<int>::iterator it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main()
{
    test_list1();
    return 0;
}
