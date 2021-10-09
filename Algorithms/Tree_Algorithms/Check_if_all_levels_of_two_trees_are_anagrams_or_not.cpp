/*
Problem Statement:
------------------
Given two binary trees, we have to check if each of their levels are anagrams of each other or not. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool areAnagrams(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while (1)
    {

        int n1 = q1.size(), n2 = q2.size();

        // If n1 and n2 are different
        if (n1 != n2)
            return false;

        // If level order traversal is over
        if (n1 == 0)
            break;

        // Vector to store nodes at each level.
        vector<int> v1, v2;

        // Now performing level order traversal while size (i.e. n1 or n2 > 0)
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left)
                q1.push(node1->left);
            if (node1->right)
                q1.push(node1->right);

            n1--;

            Node *node2 = q2.front();
            q2.pop();
            if (node2->left)
                q2.push(node2->left);
            if (node2->right)
                q2.push(node2->right);

            // Finally pushing the data of the current node into the vector.
            v1.push_back(node1->data);
            v2.push_back(node2->data);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if (v1 != v2)
            return false;
    }

    return true;
}

int main()
{
    Node *root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    areAnagrams(root1, root2) ? cout << "Yes" : cout << "No";
    return 0;
}
