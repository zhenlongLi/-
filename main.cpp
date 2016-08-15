#include <iostream>
#include "binarysearchtree.h"

using namespace std;

int main(int argc, char *argv[])
{
    BSTree<int> tree;
    cout<<"input binary tree nodes to construct BSTree"<<endl;
    int init[11] = {15,6,18,3,7,17,20,2,4,13,9};

    tree.Create(init,11);
    tree.LevelOrder();

    BSTNode<int> *temp = tree.Maximum();
    cout<<"the maximum node is: "<<temp->key<<endl;

    temp = tree.Minimum();
    cout<<"the minimum node is: "<<temp->key<<endl;

    tree.Delete(13);
    cout<<"after delete the value 13: "<<endl;
    tree.LevelOrder();

    tree.Insert(8);
    cout<<"after insert the vlaue 8: "<<endl;
    tree.LevelOrder();

    tree.Delete(9);
    cout<<"after delete the value 13: "<<endl;
    tree.LevelOrder();

    temp = tree.Search(8);
    if(temp!=nullptr)
        cout<<"found the "<<temp->key<<endl;
    else
        cout<<"not found "<<endl;

    temp = tree.Predecessor(tree.Search(15));
    cout<<"the predecessor of the "<<tree.Search(15)->key<<" is: "<<endl;
    cout<<temp->key<<endl;

    temp = tree.Successor(tree.Search(15));
    cout<<"the successor of the "<<tree.Search(15)->key<<" is "<<endl;
    cout<<temp->key<<endl;


    tree.Destory();
    if(tree.Empty())
        cout<<"delete complete"<<endl;

    return 0;
}
