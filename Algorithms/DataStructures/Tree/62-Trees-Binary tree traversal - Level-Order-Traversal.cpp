#include <stdio.h>
#include <iostream>
#include<queue>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
    
};

BstNode* GetNewNode( int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

BstNode* Insert( BstNode* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if( data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data)
{
    if(root == NULL) return false;
    if(data == root->data)
    {
        return true;
        
    }
    else if(data <= root->data)
    {
        return Search(root->left, data);
        
    }
    else
    {
        return Search(root->right, data);
        
    }
    
}

int FindMin(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMin(root->left);
    }
}

int FindMax(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMax(root->right);
    }
}

int FindHeight(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    return max( FindHeight(root->left), FindHeight(root->right)  ) +1;
}

void LevelOrder(BstNode* root)
{
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    //while there is atleast one discovered node
    while(!Q.empty())
    {
        BstNode* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();  //removing the element at front
        
    }
}

int main()
{
    BstNode * root = NULL;
    
    root = Insert(root, 500);
    root = Insert(root, 50);
    root = Insert(root, 5);
    root = Insert(root, 55);
    root = Insert(root, 10);
    root = Insert(root, 8000);
    root = Insert(root, 60);
    root = Insert(root, 160);
    root = Insert(root, 760);
    root = Insert(root, 260);
    
    
     int number;
     cout << "Enter the Number to be searched: \n";
     cin >> number;
     
    if(Search(root, number) == true)
        cout << "found\n";
    else
        cout << "False\n";
    
    int min = FindMin(root);
    cout << "Minimum: " << min << "\n";
    
    int max = FindMax(root);
    cout << "Maximum: " << max << "\n";
    
    int height = FindHeight(root);
    cout << "Height: " << height << "\n";
    
    LevelOrder(root);
    
    return 0;
}

/*
#include <stdio.h>
#include<iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode * left;
    BstNode* right;
};

BstNode* GetNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert( BstNode* root, int data)
{
    if(root == NULL)  //empty node
    {
        root = GetNode(data);
    }
    else if( data <= root-> data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data )
{
    if( root == NULL) return false;
    if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
    
}

int main()
{
    BstNode* root = NULL;
    
     root = Insert(root,15);     root = Insert(root,10);     root = Insert(root,20);
     root = Insert(root,25);     root = Insert(root,8);     root = Insert(root,12);
     
     int number;
     cout << "Enter the Number to be searched: \n";
     cin >> number;
     
    if(Search(root, number) == true)
        cout << "found\n";
    else
        cout << "False\n";
        
     
    
    printf("Hello World");

    return 0;
}
*/


