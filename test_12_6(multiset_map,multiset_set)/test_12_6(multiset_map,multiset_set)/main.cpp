//
//  main.cpp
//  test_12_6(multiset_map,multiset_set)
//
//  Created by 张辉 on 2019/12/6.
//  Copyright © 2019 可乐. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

void Testmultimap1()
{
    multimap <string, string> m;
    m.insert(make_pair("apple", "苹果"));
    m.insert(make_pair("peach", "桃子"));
    m.insert(make_pair("banana", "香蕉"));
    m.insert(make_pair("apple", "梨"));
    cout << m.size() << endl;
    cout << m.count("apple") << endl;
    for(auto& e : m)
    {
        cout << e.first << " " << e.second << endl;
    }
    
}
void Testmultimap2()
{
    multimap<int, int> m;
    for(int i = 0; i < 10; ++i)
    {
        m.insert(pair<int, int>(i, i));
    }
    for(auto& e: m)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;
    //返回
    auto it = m.lower_bound(5);
    cout << it->first << "->" << it->second << endl;
    
    //
    it = m.upper_bound(5);
    cout << it->first << "->" << it->second << endl;
}
int main()
{
    //Testmultimap1();
    Testmultimap2();
    return 0;
}
