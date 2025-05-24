
// int height(Node* root) {
//     if (!root) return 0;
//     return 1 + max(height(root->left), height(root->right));
// }

// bool isBalanced(Node* root) {
//     if (!root) return true; // An empty tree is balanced
    
//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
    
//     // Check if current node is balanced, then check subtrees
//     return (abs(leftHeight - rightHeight) <= 1) &&
//            isBalanced(root->left) &&
//            isBalanced(root->right);
// }