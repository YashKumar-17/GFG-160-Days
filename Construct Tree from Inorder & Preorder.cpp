### **Approach & Intuition:**  
1. **Understanding the Tree Construction:**  
   - The given `preorder` and `inorder` traversals are used to reconstruct the binary tree.  
   - **Preorder** traversal gives the root first, followed by left and right subtrees.  
   - **Inorder** traversal provides the left subtree, then root, and finally the right subtree.  

2. **Mapping Inorder Indices for Quick Lookup:**  
   - A **hash map (`inMap`)** stores indices of elements from `inorder` for **O(1) lookup** of a node's position.  

3. **Recursive Tree Construction:**  
   - **Base Case:** If traversal indices become invalid (`preStart > preEnd` or `inStart > inEnd`), return `NULL`.  
   - **Root Selection:** The first element in the `preorder` segment is the root of the current subtree.  
   - **Finding Left & Right Subtrees:**  
     - Locate the root in `inorder` (`inRoot` from `inMap`).  
     - Compute the number of nodes in the left subtree (`numsLeft`).  
   - **Recursive Calls:**  
     - **Left Subtree:** Uses next `numsLeft` elements in `preorder`.  
     - **Right Subtree:** Uses remaining elements after left subtree.  

This approach efficiently reconstructs the binary tree in a top-down recursive manner. 🚀

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        Node* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
        
    }
    Node* buildTree(vector<int>& preorder, int preStart, int preEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
               
                if(preStart > preEnd || inStart > inEnd){
                    return NULL;
                }
                Node* root = new Node(preorder[preStart]);
                int inRoot = inMap[root->data];
                int numsLeft = inRoot - inStart;
                root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                                inorder, inStart, inRoot - 1, inMap);
                root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMap);
                return root;
            }
