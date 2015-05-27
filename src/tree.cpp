#include "tree.h"
BinaryTreeNode* Construct(int * preOrder, int* inOrder, int length)
{
//    if()
}
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode;
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == endPreorder)
            return root;
        else
            throw exception("Invalid input");
    }
    int* rootInorder = startInorder;
    while(rootInorder)


}
