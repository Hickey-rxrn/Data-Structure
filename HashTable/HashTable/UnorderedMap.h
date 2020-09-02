//
//  UnorderedMap.h
//  HashTable
//
//  Created by 张辉 on 2020/6/27.
//  Copyright © 2020 可乐. All rights reserved.
//

#ifndef UnorderedMap_h
#define UnorderedMap_h

#pragma once
#include "HashTable.h"
namespace bit
{
      template<class K, class V, class Hash = BUCKET_HASH::_Hash<K>>
      class unordered_map
      {
            struct MapKeyOfT
            {
                  const K& operator()(const pair<K, V>& kv)
                  {
                        return kv.first;
                  }
            };
          
      public:
          typedef typename BUCKET_HASH:: HashTable<K, pair<K, V>, MapKeyOfT, Hash>::iterator iterator;
          
          iterator begin()
          {
              return _ht.begin();
          }
          
          iterator end()
          {
              return _ht.end();
          }
          
          pair<iterator, bool> insert(const pair<K, V>& kv)
          {
              return _ht.Insert(kv);
          }
          V& operator[](const K& key)
          {
              pair<iterator, bool> ret = insert(make_pair(key, V()));
              return ret.first->second;
          }
      private:
            BUCKET_HASH::HashTable<K, pair<K, V>, MapKeyOfT, Hash> _ht;
      };

      void test_unordered_map()
      {
          unordered_map<int, int> m;
          m.insert(make_pair(1,1));
          m.insert(make_pair(6,1));
          m.insert(make_pair(8,1));
          m.insert(make_pair(21,1));
          m.insert(make_pair(3,1));
          
          unordered_map<int, int>::iterator it = m.begin();
          while (it != m.end())
          {
              cout << it->first << ":" << it->second << " ";
              ++it;
          }
          cout << endl;
          
          for(auto& e : m)
          {
              cout << e.first << ":" << e.second << " ";
          }
          cout << endl;

          
          unordered_map<string, string> ms;
          ms.insert(make_pair("sort", "排序"));
       
      }
}


#endif /* UnorderedMap_h */
