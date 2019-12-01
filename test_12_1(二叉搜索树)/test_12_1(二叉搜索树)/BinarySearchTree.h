//
//  BinarySearchTree.h
//  test_12_1(二叉搜索树)
//
//  Created by 张辉 on 2019/12/1.
//  Copyright © 2019 可乐. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
using namespace  std;
template <class K>
struct BSTreeNode
{
    BSTreeNode<K>* _left;
    BSTreeNode<K>* _right;
    K _key;
    
    BSTreeNode(const K& key)
    :_key(key)
    ,_right(nullptr)
    ,_left(nullptr)
    {}
};

template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;
public:
    BSTree()
    :_root(nullptr)
    {}
    
    ~BSTree()
    {
        
    }
    
    bool Insert(const K& key)
    {
        if(_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        
        cur = new Node(key);
        if(parent->_key < key)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        return true;
    }
    
    Node* Find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }
    bool Erase(const K& key)
    {
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            if(cur->_key < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_key > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                //删除
                //1.左为空
                //2.右为空
                //3.左右都不为空
                Node* del = cur;
                //左为空
                if(cur->_left == nullptr)
                {
                    if(parent == nullptr)
                    {
                        _root = cur->_right;
                    }
                    else
                    {
                        if(parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                    }
                    
                }
                //右为空
                else if(cur->_right == nullptr)
                {
                    if(parent == nullptr)
                    {
                        _root = cur->_left;
                    }
                    else
                    {
                        if(parent->_left == cur)
                        {
                            parent->_left = cur->_left;
                        }
                        else
                        {
                            parent->_right = cur->_left;
                        }
                    }
                    
                }
                //左右都不为空
                else
                {
                    Node* lessParent = cur;
                    Node* lessRight = cur->_right;
                    while(lessRight->_left)
                    {
                        lessParent = lessRight;
                        lessRight = lessRight->_left;
                    }
                    cur->_key = lessRight->_key;
                    del = lessRight;
                    if(lessParent->_left == lessRight)
                    {
                        lessParent->_left = lessRight->_right;
                    }
                    else
                    {
                        lessParent->_right = lessRight->_right;
                    }
                }
                delete del;
                return true;
            }
        }
        return false;
    }
    //递归版本
    bool _InsertR(Node*& root, const K& key)
    {
        if(root == nullptr)
        {
            root = new Node(key);
        }
        if(root->_key < key)
        {
            return _InsertR(root->_right, key);
        }
        else if(root->_key > key)
        {
            return _InsertR(root->_left, key);
        }
        else
            return  false;
    }
    bool InsertR(const K& key)
    {
        return _InsertR(_root, key);
    }
    Node* _FindR(Node* root, const K& key)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->_key == key)
        {
            return root;
        }
        else if(root->_key < key)
        {
            return _FindR(root->_right, key);
        }
        else if(root->_key > key)
        {
            return _FindR(root->_left, key);
        }
        
    }
    Node* FindR(const K& key)
    {
        return _FindR(_root, key);
    }
    bool EraseR(const K& key)
    {
        
    }
    void InOrder()  //中序遍历
    {
        _InOrder(_root);
        cout << endl;
    }
    
    void _InOrder(Node* root)
    {
        if(root == nullptr)
        {
            return;
        }
        
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }
    
    
private:
    Node* _root;
};

void TestBSTree()
{
    int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9};
    BSTree<int> t;
    for(auto e : a)
    {
        t.Insert(e);
    }
    t.InOrder();
    
//// 测试顺序根据代码逻辑设置->白盒测试
//    t.Erase(2);
//    t.Erase(8);
//    t.Erase(1);
//    t.Erase(7);
//    t.Erase(5);
//
//    t.InOrder();
}

#endif /* BinarySearchTree_h */
