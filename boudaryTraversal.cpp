//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int>v2;
    void mid(Node* root){
        if(root==NULL) return;
        mid(root->left);
        mid(root->right);
        if(root->left==NULL and root->right==NULL){
            v2.push_back(root->data);
        }
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>v;
        //inserting root data
        v.push_back(root->data);
        //if left child and right child of root id null
        if(root->left==NULL and root->right==NULL) return v;
        
        Node *temp=root;
        
        //insert val into vector if it leftmost node in tree means;
        /*
        
            1
           / \
          2   2
         / \  /\
        N  3 1  N
          / \    
         6  7
         
        1--rootnode
        2--leftmost
        3--leftmost   
        6--leafode
        7--leafnode
        1--leafnode
        2--rightmost

        */
        if(temp->left!=NULL){
            temp=temp->left;
            while(temp->left!=NULL or temp->right!=NULL){
                v.push_back(temp->data);
                if(temp->left!=NULL){
                    temp=temp->left;
                }
                else if(temp->right!=NULL){
                    temp=temp->right;
                }
            }
        }
        
        
        mid(root);
        //insertin leaf nodes
        for(auto e:v2){
            v.push_back(e);
        }
        
        temp=root;
        vector<int>vv;
        
        //insert val into vector if it righttmost node in tree 
        if(temp->right!=NULL){
            temp=temp->right;
            while(temp->left!=NULL or temp->right!=NULL){
                vv.push_back(temp->data);
                if(temp->right!=NULL){
                    temp=temp->right;
                }
                else if(temp->left!=NULL){
                    temp=temp->left;
                }
            }
        }
        //reverse the vector becuase we are adding from top-bottom 
        reverse(vv.begin(),vv.end());
        for(auto e:vv){
            v.push_back(e);
        }
        return v;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
