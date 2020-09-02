//
//  UnorderedSet.h
//  HashTable
//
//  Created by 张辉 on 2020/6/27.
//  Copyright © 2020 可乐. All rights reserved.
//

#ifndef UnorderedSet_h
#define UnorderedSet_h


#pragma once
#include "HashTable.h"
namespace bit
{
    template<class K, class Hash = BUCKET_HASH::_Hash<K>>
    class unordered_set
    {
        struct SetKeyOfT
        {
            const K& operator()(const K& k)
            {
                return k;
            }
        };
         
    public:
        typedef typename BUCKET_HASH:: HashTable<K, K, SetKeyOfT, Hash>::iterator iterator;
        
        iterator begin()
        {
            return _ht.begin();
        }
        
        iterator end()
        {
            return _ht.end();
        }
        
        void insert(const K& k)
        {
            _ht.Insert(k);
        }
    private:
        BUCKET_HASH::HashTable<K, K, SetKeyOfT, Hash> _ht;
     
    };

    void test_unordered_set()
    {
        unordered_set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(6);
        s.insert(21);
        
        unordered_set<int>::iterator it = s.begin();
        while (it != s.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        
        for(auto& e : s)
        {
            cout << e << " ";
        }
        cout << endl;
        unordered_set<string> strs;
        strs.insert("sort");
         
        //unordered_set<Date, DateHash> dataSet;
    }
}


#endif /* UnorderedSet_h */
   
