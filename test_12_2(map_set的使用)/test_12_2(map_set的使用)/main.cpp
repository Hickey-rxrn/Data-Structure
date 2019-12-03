//
//  main.cpp
//  test_12_2(map_set的使用)
//
//  Created by 张辉 on 2019/12/2.
//  Copyright © 2019 可乐. All rights reserved.
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

#include <map>
#include <string>
using namespace  std;
void TestMap1()
{
    map <string, string> m1;
    map <string, string> m2 =
    {
        { "apple", "苹果" },
        { "banana", "香蕉" },
        { "organge", "橘子"},
        { "peach", "桃子"},
        { "waterme", "水蜜桃"}
    };
    cout << m2["apple"] << endl;
    cout << m2["waterme"] << endl;
    map<string, string> m3(m2);
}

//遍历
void TestMap2()
{
    map <string, string> m3 =
    {
        { "apple", "苹果" },
        { "banana", "香蕉" },
        { "organge", "橘子"},
        { "peach", "桃子"},
        { "waterme", "水蜜桃"}
    };
    for(auto it = m3.begin(); it != m3.end(); ++it)
    {
       cout << (*it).first << "--->" << it->second << endl;
    }
    cout << endl;
}

void TestMap3()
{
    map <string, string> m;
    m.insert(make_pair("apple", " "));
    //m.insert(make_pair("apple", "苹果"));
    m["apple"] = "苹果";
    //m.at("banana");  抛异常，key值没有被发现
    cout << m["apple"] << endl;
    cout << m.size() << endl;
}
int main()
{
    //TestMap1();
    //TestMap2();
    TestMap3();
    return 0;
}



