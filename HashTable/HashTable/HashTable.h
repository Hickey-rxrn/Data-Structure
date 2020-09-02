//
//  HashTable.h
//  HashTable
//
//  Created by 张辉 on 2020/5/30.
//  Copyright © 2020 可乐. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h


#pragma once
#include<vector>

namespace CLOSE_HASH
{
    enum State
    {
        EXITS,
        EMPTY,
        DELETE,
    };
    template<class T>
    struct HashData
    {
        T _data;
        State _state;  //状态
        
    };

    template<class K, class V>
    class HashTable
    {
        typedef HashData<pair<K, V>> HashData;
    public:
        // 线性探测
//        pair<HashData*, bool> Insert(const pair<K, V>& kv)
//        {
//            //  容量问题
//            if(_dataNum == _tables.size())
//            {
//                size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//                vector<HashData> newtables;
//                newtables.resize(newSize);
//
//                // 将旧表中的数据映射到新表
//                for(size_t i = 0; i < _tables.size(); ++i)
//                {
//                    if(_tables[i]._state == EXITS)
//                    {
//                        size_t index = _tables[i]._data.first % newtables.size();
//                        // 线性探测
//                        while(newtables[index]._state == EXITS)
//                        {
//                            ++index;
//                            if(index == _tables.size())
//                            {
//                                index = 0;
//                            }
//                        }
//
//                        newtables[index]._data = _tables[i]._data;
//                        newtables[index]._state = EXITS;
//                    }
//                }
//
//                _tables.swap(newtables);
//            }
//
//            size_t index = kv.first % _tables.size();
//            // 线性探测
//            while(_tables[index]._state == EXITS)
//            {
//                ++index;
//                if(index == _tables.size())
//                {
//                    index = 0;
//                }
//            }
//
//            _tables[index]._data = kv;
//            _tables[index]._state = EXITS;
//            ++_dataNum;
//
//            return make_pair(&_tables[index], true);
//        }
//    private:
////        HashTable* _tables;
////        size_t _size;
////        size_t _capacity;
//
//        vector<HashData> _tables;
//        size_t _dataNum = 0;  //有效的数据个数
        
                  // 线性探测改进
//                pair<HashData*, bool> Insert(const pair<K, V>& kv)
//                {
//                    //  容量问题
//                    if(_dataNum == _tables.size())
//                    {
//                        size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//                        HashTable<K, V> newht;
//                        newht._tables.resize(newSize);
//
//                        // 将旧表中的数据映射到新表
//                        for(size_t i = 0; i < _tables.size(); ++i)
//                        {
//                            if(_tables[i]._state == EXITS)
//                            {
//                                newht.Insert(_tables[i]._data);
//                            }
//                        }
//
//                        _tables.swap(newht._tables);
//                    }
//
//                    size_t index = kv.first % _tables.size();
//                    // 不能 % capacity，因为会导致越界
//                    // 线性探测
//                    while(_tables[index]._state == EXITS)
//                    {
//                        if(_tables[index]._data.first == kv.first)
//                            return make_pair(&_tables[index], false);
//                        ++index;
//
//                        if(index == _tables.size())
//                        {
//                            index = 0;
//                        }
//                    }
//
//                    _tables[index]._data = kv;
//                    _tables[index]._state = EXITS;
//                    ++_dataNum;
//
//                    return make_pair(&_tables[index], true);
//                }
//        HashTable* Find(const K& key)
//        {
//            size_t index = key % _tables.size();
//            while (_tables[index]._state != EMPTY)
//            {
//                if(_tables[index]._state == EXITS && _tables[index]._data.first == key)
//                {
//                    return &_tables[index];
//                }
//                else
//                {
//                    ++index;
//                    if(index == _tables.size())
//                    {
//                        index = 0;
//                    }
//                }
//            }
//            return nullptr;
//        }
//
        // 二次探测
//                 pair<HashData*, bool> Insert(const pair<K, V>& kv)
//                 {
//                      //  容量问题
//                     if(_dataNum == _tables.size())
//                     {
//                         size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//                         HashTable<K, V> newht;
//                         newht._tables.resize(newSize);
//
//                        // 将旧表中的数据映射到新表
//                         for(size_t i = 0; i < _tables.size(); ++i)
//                         {
//                             if(_tables[i]._state == EXITS)
//                             {
//                                 newht.Insert(_tables[i]._data);
//                             }
//                         }
//
//                         _tables.swap(newht._tables);
//                       }
//
//                      size_t start = kv.first % _tables.size();
//                      size_t index = start;
//                      size_t i = 1;
//                      // 不能 % capacity，因为会导致越界
//                       while(_tables[index]._state == EXITS)
//                       {
//                          if(_tables[index]._data.first == kv.first)
//                           {
//                               return make_pair(&_tables[index], false);
//                           }
//                               index = start + i * i;
//                               index %= _tables.size();  //防止越界
//                               ++i;
//                        }
//                            _tables[index]._data = kv;
//                            _tables[index]._state = EXITS;
//                            ++_dataNum;
//
//                            return make_pair(&_tables[index], true);
////                }
//                HashTable* Find(const K& key)
//                {
//                    size_t start = key.first % _tables.size();
//                    size_t index = start;
//                    size_t i = 1;
//                    while (_tables[index]._state != EMPTY)
//                    {
//                        if(_tables[index]._state == EXITS && _tables[index]._data.first == key)
//                        {
//                            return &_tables[index];
//                        }
//                        else
//                        {
//                            index = start + i^2;
//                            index %= _tables.size();  //防止越界
//                            ++i;
//                        }
//                    }
//                    return nullptr;
//                }
        
        
//        pair<HashData*, bool> Insert(const pair<K, V>& kv)
//        {
//            // 负载因子控制在0.7
//            if(_tables.size() == 0 || _dataNum * 10 / _tables.size() == 7)
//            {
//                size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//
//                HashTable<K,V> newht;
//                newht._tables.resize(newSize);
//
//                // 遍历旧表，映射到新表
//                for(size_t i = 0; i < _tables.size(); ++i)
//                {
//                    if(_tables[i]._state == EXITS)
//                     {
//                         newht.Insert(_tables[i]._data);
//                     }
//                }
//
//                     _tables.swap(newht._tables);
//            }
//                    size_t start = kv.first % _tables.size();
//                    size_t index = start;
//                    size_t i = 1;
//                // 不能 % capacity，因为会导致越界
//                while(_tables[index]._state == EXITS)
//                {
//                    if(_tables[index]._data.first == kv.first)
//                    {
//                        return make_pair(&_tables[index], false);
//                    }
//                        index = start + i * i;
//                        index %= _tables.size();  //防止越界
//                        ++i;
//                }
//                        _tables[index]._data = kv;
//                        _tables[index]._state = EXITS;
//                        ++_dataNum;
//
//                return make_pair(&_tables[index], true);
//        }
//
//
//        void Erase(const K& key)
//        {
//            HashData* ret = Find(key);
//            if(ret)
//            {
//                ret->_state = DELETE;
//            }
//        }
//
//        V& operator[](const K& key)
//        {
//            pair<HashData*, bool> ret = Insert(make_pair(key, V()));
//            return ret.first->_data.second;
//        }
            private:
        //        HashTable* _tables;
        //        size_t _size;
        //        size_t _capacity;

                vector<HashData> _tables;
                size_t _dataNum = 0;  //有效的数据个数
    };
//
//    void Test()
//    {
//        HashTable<int, int> ht;
//        ht.Insert(make_pair(1, 1));
//        ht.Insert(make_pair(3, 1));
//        ht.Insert(make_pair(5, 1));
//    }
}



// 开散列->哈希桶
namespace BUCKET_HASH
{
    template<class T>
    struct HashNode
    {
        HashNode<T>* _next;
        T _data;
        
        HashNode(const T& data)
        :_data(data)
        ,_next(nullptr)
        {}
    };
    
    template<class K>
    struct _Hash   //针对int类型
    {
        const K& operator()(const K& key)
        {
            return key;
        }
    };

    template<>
    struct _Hash<string>  //模版特化
    {
        size_t operator()(const string& key)
        {
            //return key[0];
            size_t hash = 0;
            for(size_t i = 0; i < key.size(); ++i)
            {
                hash = hash * 131 + key[i];
            }
            return hash;
        }
    };

    struct _HashString   // 针对string类型
    {
        size_t operator()(const string& key)
        {
            //return key[0];
            size_t hash = 0;
            for(size_t i = 0; i < key.size(); ++i)
            {
                hash = hash * 131 + key[i];
            }
            return hash;
        }
    };

    // 前置声明
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable;


    // 迭代器
    template<class K, class T, class KeyOfT, class Hash>

    struct HashTableIterator
    {
        
        typedef HashNode<T> Node;
        Node* _node;
        HashTable<K, T, KeyOfT, Hash>* _ht;
        
        typedef HashTableIterator<K, T, KeyOfT, Hash> Self;
        
        HashTableIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* ht)
        :_node(node)
        ,_ht(ht)
        {}
        
        T& operator*()
        {
            return _node->_data;
        }
        
        T* operator->()
        {
            return &_node->_data;
        }
        
        Self operator++()
        {
            if(_node->_next)  //当前桶还没走完
            {
                _node = _node->_next;
            }
            else  //当前桶已经走完，寻找下一个桶
            {
                KeyOfT kot;
                size_t index = _ht->HashFunc(kot(_node->_data), _ht->_tables.size());
                ++index;
                for(; index < _ht->_tables.size(); ++index)
                {
                    Node* bucket = _ht->_tables[index];
                    if(bucket)
                    {
                        _node = bucket;
                        return *this;
                    }
                }
                _node = nullptr;
            }
            return *this;
        }
        
        bool operator!=(const Self& s)
        {
            return _node != s._node;
        }
    };

    template<class K, class T, class KeyOfT, class Hash>
    class HashTable
    {
        //typedef HashNode<K> Node;
        typedef HashNode<T> Node;
        // 友元

        friend HashTableIterator<K, T, KeyOfT, Hash>;
        
    public:
        typedef HashTableIterator<K, T, KeyOfT, Hash> iterator;
        
        iterator begin()
        {
            for(size_t i = 0; i < _tables.size(); ++i)
            {
                Node* bucket = _tables[i];
                if(bucket)
                {
                    return iterator(bucket, this);
                }
            }

            return end();
        }
        
        iterator end()
        {
            return  iterator(nullptr, this);
        }
        // 除留余数法
//        size_t GetNextPrime(size_t prime)
//        {
//            const int PRIMECOUNT = 28;
//            const size_t primeList[PRIMECOUNT] =
//            {
//                53ul,         97ul,         193ul,       389ul,       769ul,
//                1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
//                49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
//                1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
//                50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
//                1610612741ul, 3221225473ul, 4294967291ul
//            };
//        size_t i = 0;
//        for(; i < PRIMECOUNT; ++i) {
//                if(primeList[i] > prime)
//                    return primeList[i];
//        }
//            return primeList[i];
//        }
        
        pair<iterator, bool> Insert(const T& data)
        {
            KeyOfT kot;
            // 负载因子控制到1
            if(_dataNum == _tables.size())
            {
                size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
            //size_t newsize = GetNextPrime(_tables.size());
                vector<Node*> newtables;
                newtables.resize(newsize, nullptr);
                
                //将旧表中的数据取下来负载到新表中，并重新算在新表中的位置
                for(size_t i = 0; i < _tables.size(); ++i)
                {
                    Node* cur = _tables[i];
                    while(cur)
                    {
                        Node* next = cur->_next;
                         // 头插到新表
                        //size_t index = cur->_data.first & newtables.size();
                        size_t index = HashFunc(kot(cur->_data), newtables.size());
                        cur->_next = newtables[index];
                        newtables[index] = cur;
                        cur = next;
                    }
                    _tables[i] = nullptr; //旧表数据取完了就置空
                }
                _tables.swap(newtables);
            }
            //size_t index = kv.first % _tables.size();
            size_t index = HashFunc(kot(data), _tables.size());
            // 查找key是否存在，存在则不插入。如果是multi版本则不做冗余检查，直接插入
            Node* cur = _tables[index];
            while (cur)
            {
                if(kot(cur->_data) == kot(data))
                {
                    return make_pair(iterator(cur, this), false);
                }
                cur = cur->_next;
            }
            // 头插
            Node* newnode = new Node(data);
            //_tables[index]存放的是链表头节点的指针，不能让_tables[index]先指向newnode,因为如果这样做会找不到链表的头节点
            newnode->_next = _tables[index];
            _tables[index] = newnode;
            ++_dataNum;
            
            return make_pair(iterator(newnode, this), true);
        }
        
        Node* Find(const K& key)
        {
            //size_t index = key % _tables.size();
            size_t index = HashFunc(key, _tables.size());
            Node* cur = _tables[index];
            while (cur)
            {
                if(cur->_data.first == key)
                {
                    return cur;
                }
                else
                {
                    cur = cur->_next;
                }
            }
            return nullptr;
        }
        
        bool Erase(const K& key)
        {
            //size_t index = key % _tables.size();
            size_t index = HashFunc(key, _tables.size());
            Node* cur = _tables[index];
            Node* prev = nullptr;
            while(cur)
            {
                if(cur->_data.first == key)
                {
                    //if(prev == nullptr)
                    if(cur == _tables[index])
                    {
                        _tables[index] = cur->_next; //刚好cur是头节点，删除头节点
                    }
                    else  //cur不是头节点，prev不为空
                    {
                        prev->_next = cur->_next;
                    }
                    
                    delete cur;
                    _dataNum--;
                    //cur = nullptr;    置空防止野指针，不写也行，因为下面直接会return
                    return true;
                }
                else
                {
                    prev = cur;
                    cur = cur->_next;
                }
            }
            return false;
        }
        
        // 将key取模计算映射位置
        size_t HashFunc(const K& key, size_t size)
        {
            Hash hash;  // 哈希仿函数key转化为整形
            return hash(key) % size;
        }
    private:
        vector<Node*> _tables;
        size_t _dataNum = 0;
    };
}

//
//    void Test()
//    {
//        HashTable<int, int> ht;
//        ht.Insert(make_pair(1, 1));
//        ht.Insert(make_pair(3, 1));
//        ht.Insert(make_pair(5, 1));
//        ht.Insert(make_pair(7, 1));
//        ht.Insert(make_pair(9, 1));
//        ht.Insert(make_pair(11, 1));
//        ht.Insert(make_pair(13, 1));
//        ht.Insert(make_pair(15, 1));
//        ht.Insert(make_pair(17, 1));
//        ht.Insert(make_pair(19, 1));
//        ht.Insert(make_pair(21, 1));
//        ht.Insert(make_pair(23, 1));
//
//        ht.Erase(23);
//        ht.Erase(3);
//
//        //HashTable<string, string, _HashString> dict;
//        HashTable<string, string> dict;
//        dict.Insert(make_pair("sort", "排序"));
//        dict.Insert(make_pair("string", "字符串"));
//        dict.Insert(make_pair("left", "左边"));
//
//        _HashString hash;
//        cout << hash("abc") << endl;
//        cout << hash("aab") << endl;
//    }
//}
//


#endif /* HashTable_h */
