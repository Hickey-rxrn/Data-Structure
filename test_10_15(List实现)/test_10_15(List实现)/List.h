//
//  List.h
//  test_10_15(list实现)
//
//  Created by 张辉 on 2019/10/25.
//  Copyright © 2019 张辉. All rights reserved.
//

#ifndef List_h
#define List_h
#pragma once
namespace bit
    {
    template <class T>
    struct _list_node
    {
        _list_node* _prev;
        _list_node* _next;
        T _data;
        _list_node(const T& x = T())
        {
            _data = x;
            _prev = nullptr;
            _next = nullptr;
        }
    };
    template<class T,class Ref, class Ptr>
    struct _list_iterator
    {
        typedef _list_node<T> node;
        typedef _list_iterator<T,Ref,Ptr> Self;
        node* _node;
        _list_iterator(node* node)
        {
            _node = node;
        }
        Ref operator*() //内置类型
        {
            return _node->_data;
        }
        Ptr operator->()  //自定义类型
        {
            return &_node->_data;
        }
        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }
        Self& operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp(*this);
            _node = _node->_next;
            return tmp;
        }
        Self operator--(int)
        {
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }
        // it1 != it2
        bool operator!=(const Self& it)
        {
            return _node != it._node;
        }
        // it1 == it2
        bool operator==(const Self& it)
        {
            return _node == it._node;
        }
    };
    template <class T>
    class list
    {
        typedef _list_node<T> node;
    public:
        typedef _list_iterator<T,T&, T*> iterator;
        typedef _list_iterator<T,const T&,const T*> const_iterator;
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }
        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        //深拷贝  copy(list)
        list(const list<T>& l)
        {
            _head = new node;
            _head->_next = _head;
            _head->_prev = _head;
            
            //const_iterator it = l.begin();
            auto it = l.begin();
            while(it != l.end())
            {
                push_back(*it);
                ++it;
            }
        }
        //赋值（传统写法）
//        list<T>& operator=(const list<T>& l)
//        {
//            this->clear();
//        //将this中的数据先清除掉，然后再将l中的数据插入到this中
//            auto it = l.begin();
//            while(it != l.end())
//            {
//                push_back(*it);
//                ++it;
//            }
//        }
        //现代写法
        //l2 = l1
        list<T>& operator=(const list<T>& l)
        {
            swap(_head, l._head);
            //将l2与l1交换，然后析构掉l2
            return *this;
        }
        list()
        {
            _head = new node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }
        ~list()
        {
            clear();
            
            delete _head;
            _head = nullptr;
        }
        void clear() //只清除节点中的数据
        {
            iterator it = begin();
            while(it != end())
            {
                it = erase(it);
            }
        }
        // 任意位置插入
        void insert(iterator pos, const T& x)
        {
            node* cur = pos._node;
            node* prev = cur->_prev;
            node* newnode = new node(x);
            
            // prev newnode cur
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            
        }
    //任意位置删除 （会导致迭代器失效，因为释放cur,cur成为野指针）
        iterator erase(iterator pos)
        {
            node* cur = pos._node;
            assert(cur != _head);
            
            node* prev = cur->_prev;
            node* next = cur->_next;
            
            prev->_next = next;
            next->_prev = prev;
            
            delete cur;
            
            return iterator(next);
        }
//        void push_back(const T& x)
//        {
//            node* tail = _head->_prev;
//            node* newnode = new node(x);
//
//            // head  tail  newnode
//            tail->_next = newnode;
//            newnode->_prev = tail;
//            newnode->_next = _head;
//            _head->_prev = newnode;
//        }
        // 复用
        void push_back(const T& x)  //尾插
        {
            insert(end(),x);
        }
        void push_front(const T&x)  //头插
        {
            insert(begin(), x);
        }
        void pop_back()  //尾删
        {
            erase(--end());
        }
        void pop_front()   //头删
        {
            erase(begin());
        }
    private:
        node* _head;
    };
    void print_list(const list<int>& l)
    {
        list<int>::const_iterator it = l.begin();
        while(it != l.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
    void test_list1()
    {
        list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        print_list(l);
        list<int>::iterator it = l.begin();
        while(it != l.end())
        {
            if(*it %2 == 0)  //如果it此时是2，则会导致迭代器失效
            {
                it = l.erase(it);
            }
            else
            {
                ++it;
            }
        }
        print_list(l);
    }
    struct Date
    {
        int _year = 1900;
        int _month = 1;
        int _day = 1;
    };
    void test_list2()
    {
        list<Date> l;
        l.push_back(Date());
        l.push_back(Date());
        //list<Date>::iterator it = l.begin();
        auto it = l.begin();
        while(it != l.end())
        {
            //cout << *it << " ";
            //自定义类型要输出必须重载operator->
            cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
            ++it;
        }
        cout << endl;
    }
    void test_list3()
    {
        list<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        //print_list(l);
        
        list<int> copy = l;
        //l.push_back(5);
        print_list(copy);
        print_list(l);
    }
    }

#endif /* List_h */
