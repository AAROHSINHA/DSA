// int printSubTreeHeight1(TreeNode* root){
//     if(root == NULL){
//         return 0;
//     }
//     int lh = printSubTreeHeight1(root->left);
//     int rh = printSubTreeHeight1(root->right);
//     cout << "Node : " << root->data << " ";
//     cout << "left : " << lh << " ";
//     cout << "right : " << rh << "\n";
//     return 1 + max(lh, rh);
// }

// IMPORTANT FUNCTION - DRY RUN KRKE SMJHO....Gives height of left and right subtrees recursively