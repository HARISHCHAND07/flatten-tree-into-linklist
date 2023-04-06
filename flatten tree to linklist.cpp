
public:void flatten(TreeNode* root) {
       if(root==NULL){return;}
       TreeNode* Rright=root->right;
       TreeNode* Rleft=root->left;
       root->left=NULL;
       flatten(Rleft);
       flatten(Rright);
       root->right=Rleft;
       TreeNode* curr=root;
       while(curr->right!=NULL){
           curr=curr->right;
       }curr->right=Rleft;
    }
};
// udated morris traversal
void flatten(TreeNode* root) {
        TreeNode *curr = root;
        
        while(curr != NULL){
            if(curr->left){
                TreeNode *pred = curr->left;
                while(pred->right)
                    pred = pred->right;
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            curr = curr->right;// ye else condition ka hn 
        }
    }