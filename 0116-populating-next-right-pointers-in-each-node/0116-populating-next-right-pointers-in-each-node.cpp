/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL)
        return root;
        q.push(root);
        while(!q.empty()){
            int s = (int)q.size();
            Node* first = q.front();
            q.pop();
            if(first->left != NULL)
            q.push(first->left);
            if(first->right != NULL)
            q.push(first->right);
            cout<<s<<" ";
            for(int i=0;i<s-1;i++){
                // cout<<first->val;
                first->next = q.front();
                q.pop();
                if(first->next->left != NULL)
                q.push(first->next->left);
                if(first->next->right != NULL)
                q.push(first->next->right);
                first = first->next;
            }
            first->next = NULL;
        }
        return root;
    }
};