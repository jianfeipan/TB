class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        root->next=NULL;
        queue<TreeLinkNode*> q1;
        queue<TreeLinkNode*> q2;
        q1.push(root);
        bool q1IsRoot = true;
        TreeLinkNode * fromNode=root;
        while(q1IsRoot?(!q1.empty()):(!q2.empty())){
            TreeLinkNode* a = q1IsRoot?q1.front():q2.front();
            q1IsRoot?q1.pop():q2.pop();
            if(fromNode!=NULL)
                fromNode->next=a;
            fromNode=a;
            if(a->left!=NULL)
                q1IsRoot?q2.push(a->left):q1.push(a->left);
            if(a->right!=NULL)
                q1IsRoot?q2.push(a->right):q1.push(a->right);
            if(q1IsRoot?(q1.empty()):(q2.empty())){
                fromNode->next=NULL;
                fromNode = NULL;
                q1IsRoot=!q1IsRoot;
            }
            
        }
    }
};
