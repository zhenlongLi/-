#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
using namespace std;

//tree node
template<typename T>
class BSTNode
{
public:
    T key;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
    //构造函数
    BSTNode(T value,BSTNode *lchild,BSTNode *rchild,BSTNode *parent):
        key(value),left(lchild),right(rchild),parent(parent){}
};

template<typename T>
class BSTree
{
private:
    BSTNode<T> *root;//root node
public:
    BSTree():root(nullptr){}
    ~BSTree(){};

    void Create(T* a,int size);

    void Insert(T key);
    void Delete(T key);
    BSTNode<T> *Search(T key);

    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();

    BSTNode<T>* Minimum();//find the minimun node
    BSTNode<T>* Maximum();//find the maximum node

    void Print();//print the BSTree

    BSTNode<T>* Predecessor(BSTNode<T>* x);//find the predecessor of node x
    BSTNode<T>* Successor(BSTNode<T>* x);//find the successor of node x

    void Destory();
    bool Empty();
private:
    void Insert(BSTNode<T>* &tree,BSTNode<T>* z);
    BSTNode<T>* Search(BSTNode<T>* &tree,T value) const;
    void PreOrder(BSTNode<T>* &tree) const;
    void InOrder(BSTNode<T>* &tree) const;
    void PostOrder(BSTNode<T>* &tree) const;
    void LevelOrder(BSTNode<T>* &tree) const;
    BSTNode<T>* Minimum(BSTNode<T>* &tree);
    BSTNode<T>* Maximum(BSTNode<T>* &tree);
    void Print(BSTNode<T>* &tree);
    BSTNode<T>* Delete(BSTNode<T>* &tree,BSTNode<T> *z);
    void Destory(BSTNode<T>* &tree);
};
/**
 *插入操作
 * 非递归实现
 * 内部使用函数
 */
template<typename T>
void BSTree<T>::Insert(BSTNode<T> *&tree, BSTNode<T> *z)
{
    BSTNode<T> *parent = nullptr;
    BSTNode<T> *temp = tree;
    //寻找插入点
    while(temp!=nullptr)
    {
        parent = temp;
        if(z->key>temp->key)
            temp = temp->right;
        else
            temp = temp->left;
    }
    z->parent=parent;
    if(parent==nullptr)
        tree = z;
    else if(z->key>parent->key)
        parent->right = z;
    else
        parent->left = z;
}
/**
* 接口
*/
template<typename T>
void BSTree<T>::Insert(T key)
{
    //创建一个新的节点，使用构造函数初始化
    BSTNode<T>* z = new BSTNode<T>(key,nullptr,nullptr,nullptr);
    if(!z)//如果创建失败，则返回
        return;
    //调用内部函数进行插入
    Insert(root,z);
}
/**
 * 查找操作
 * 非递归实现
 * 内部使用函数
 * */
template<typename T>
BSTNode<T>* BSTree<T>::Search(BSTNode<T> *&tree, T value) const
{
    BSTNode<T>* temp = tree;
    while(temp)
    {
        if(temp->key == value)
            return temp;
        else if(temp->key>value)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return nullptr;
}
/**
* 接口
*/
template<typename T>
BSTNode<T>* BSTree<T>::Search(T key)
{
    return Search(root,key);
}

/**
*
* 遍历算法，外部使用接口
*/
template<typename T>
void BSTree<T>::PreOrder(BSTNode<T>* &tree) const
{
    if(tree)
    {
        cout<<tree->key<<" ";
        PreOrder(tree->left);
        PreOrder(tree->right);
    }
}
template<typename T>
void BSTree<T>::InOrder(BSTNode<T>* &tree) const
{
    if(tree)
    {
        InOrder(tree->left);
        cout<<tree->key<<" ";
        InOrder(tree->right);
    }
}
template<typename T>
void BSTree<T>::PostOrder(BSTNode<T>* &tree) const
{
    if(tree)
    {
        PostOrder(tree->left);
        PostOrder(tree->right);
        cout<<tree->key<<" ";
    }
}

template<typename T>
void BSTree<T>::Create(T* a, int size)
{
    for(int i=0;i<size;i++)
        Insert(a[i]);
}

template<typename T>
void BSTree<T>::LevelOrder(BSTNode<T>* &tree) const
{
    queue<BSTNode<T> *> nodeQueue;
    if(tree)
        nodeQueue.push(tree);
    int current = 1;
    int next = 0;
    while(!nodeQueue.empty())
    {
        BSTNode<T> *temp = nodeQueue.front();
        cout<<temp->key<<" ";
        if(temp->left)
        {
            nodeQueue.push(temp->left);
            next++;
        }
        if(temp->right)
        {
            nodeQueue.push(temp->right);
            next++;
        }
        nodeQueue.pop();
        current--;
        if(current==0)
        {
            cout<<endl;
            current = next;
            next=0;
        }
    }
}
/**
*
*遍历算法
* 分别为前序、中序、后序
* BSTree类外部接口函数
*/
template<typename T>
void BSTree<T>::PreOrder()
{
    PreOrder(root);
}
template<typename T>
void BSTree<T>::InOrder()
{
    InOrder(root);
}
template<typename T>
void BSTree<T>::PostOrder()
{
    PostOrder(root);
}

template<typename T>
void BSTree<T>::LevelOrder()
{
    LevelOrder(root);
}

/**
*查找最小的结点
* 内部调用函数
*/
template<typename T>
BSTNode<T>* BSTree<T>::Minimum(BSTNode<T>* &tree)
{
    BSTNode<T> *temp = tree;
    while(temp->left)
        temp = temp->left;
    return temp;
}
/**
*接口
*/
template<typename T>
BSTNode<T>* BSTree<T>::Minimum()
{
    return Minimum(root);
}
/**
*查找键值最大的结点
* 内部调用函数
* 非递归实现
*/
template<typename T>
BSTNode<T>* BSTree<T>::Maximum(BSTNode<T> *&tree)
{
    BSTNode<T> *temp = tree;
    while(temp->right)
        temp = temp->right;
    return temp;
}
/**
*接口
*/
template<typename T>
BSTNode<T>* BSTree<T>::Maximum()
{
    return Maximum(root);
}
/**
*打印函数
* 打印出平衡二叉树
* BSTree内部函数
*/
template<typename T>
void BSTree<T>::Print(BSTNode<T>* &tree)
{
    if(tree)
    {
        if(tree->left)
            cout<<"node: "<<tree->key<<"left child"<<tree->left->key<<endl;
        else
            cout<<"node: "<<tree->key<<"has no left child"<<endl;
        if(tree->right)
            cout<<"node: "<<tree->key<<"right child"<<tree->right->key<<endl;
        else
            cout<<"node: "<<tree->key<<"has no right child"<<endl;
        Print(tree->left);
        Print(tree->right);
    }
}

/**
*接口
*/
template<typename T>
void BSTree<T>::Print()
{
    Print(root);
}
/**
*查找某个结点的前驱结点
*/
template<typename T>
BSTNode<T>* BSTree<T>::Predecessor(BSTNode<T> *x)
{
    //如果x是最最小的结点，他没有前驱
    if(x->key == Minimum(root)->key)
        return nullptr;
    //否则
    //先获取二叉树中键值与x的键值相同的结点
    BSTNode<T> *y = nullptr;
    y = Search(root,x->key);
    if(y==nullptr)
        return nullptr;
    //如果y有左孩子，则x的前驱为"以x的左孩子为根的子树的最大值"
    if(y->left)
        return Maximum(y->left);
    //如果y没有左孩子，则x有两种可能
    //1.y是一个右孩子，此时x的前驱为其双亲结点
    BSTNode<T>* _parent = y->parent;
    if(_parent->right == y)
        return _parent;
    //2.y是一个左孩子，则其前驱为其双亲结点中“第一个拥有右孩子结点”的结点
    while(_parent!=nullptr&&_parent->right==nullptr)
        _parent = _parent->parent;
    return _parent;
}
/**
*查找某个结点的后继结点
* 外部调用接口
*/
template<typename T>
BSTNode<T>* BSTree<T>::Successor(BSTNode<T> *x)
{
    //如果x是键值最大的则没有后继结点
    if(x->key == Maximum(root)->key)
        return nullptr;
    //获取x在二叉树的结点y
    BSTNode<T> *y = nullptr;
    y = Search(root,x->key);
    if(!y)  //如果二叉树没有此结点
        return nullptr;
    //如果y有右孩子，则y的后继为其右孩子的最小节点
    if(y->right)
        return Minimum(y->right);
    //如果y没有右孩子，则分为两种情况
    //1.y是左孩子，此时y的后继结点为y的双亲结点
    BSTNode<T> *_parent = y->parent;
    if(y->parent->left == y)
        return _parent;
    //2.y是一个右孩子，此时y的后继结点为“第一个拥有左孩子且不是y的直接双亲”的结点
    while(_parent)
    {
        if(_parent->left&&_parent!=y->parent)
            return _parent;
    }
    return nullptr;
}
/**
*删除节点
* BSTree类内部调用函数
*
*/
template<typename T>
BSTNode<T>* BSTree<T>::Delete(BSTNode<T> *&tree, BSTNode<T> *z)
{
    BSTNode<T> *x = nullptr;
    BSTNode<T> *y = nullptr;
    if(z->left==nullptr||z->right==nullptr)
        y=z;
    else
        y=Successor(z);
    if(y->left)
        x=y->left;
    else
        x=y->right;
    if(x)
        x->parent = y->parent;
    if(y->parent==nullptr)
        tree=x;
    else if(y==y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    if(y!=z)
        z->key = y->key;
    return y;
}
/**
*接口
*/
template<typename T>
void BSTree<T>::Delete(T key)
{
    BSTNode<T> *z,*node;
    if((z=Search(root,key))!=nullptr)
        if((node=Delete(root,z))!=nullptr)
            delete node;
}
/**
*销毁查找二叉树
* 内部调用函数
*/
template<typename T>
void BSTree<T>::Destory(BSTNode<T>* &tree)
{
    if(tree->left)
        Destory(tree->left);
    if(tree->right)
        Destory(tree->right);
    if(tree->left==nullptr&&tree->right==nullptr)
    {
        delete tree;
        tree=nullptr;
    }
}
/**
*接口
*/
template<typename T>
void BSTree<T>::Destory()
{
    Destory(root);
}

template<typename T>
bool BSTree<T>::Empty()
{
    if(root == nullptr)
        return true;
    else
        return false;
}

#endif // BINARYSEARCHTREE_H
