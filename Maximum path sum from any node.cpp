 ### **Intuition & Approach**  

This code finds the **maximum path sum** in a binary tree, where a path can start and end at any node.  

### **Step-by-Step Execution**  
1. **Recursive DFS Traversal (`maxpathsum`)**:  
   - Compute the maximum path sum for the left and right subtrees.  
   - If a subtree's sum is negative, we ignore it (`max(0, sum)`).  

2. **Update the Global Maximum (`maxi`)**:  
   - The max sum **through the current node** is `left + right + root->data`.  
   - Update `maxi` if this sum is the largest encountered so far.  

3. **Return the Best Path Upwards**:  
   - The function returns `max(left, right) + root->data`, ensuring the **best single path** extending upwards.  

### **Why This Works?**  
✅ Avoids negative contributions.  
✅ Ensures `maxi` stores the **best overall path sum**.  
✅ Runs in **O(N) time complexity** using postorder traversal.  

🚀 **Key Takeaway**: This problem is a common **tree DP** question and a great example of **postorder traversal + global optimization**.

int maxpathsum(Node* root, int &maxi){
        if(root==NULL){
            return 0;
        }
        int left=max(0,maxpathsum(root->left,maxi));
        int right=max(0,maxpathsum(root->right,maxi));
        maxi=max(maxi,left+right+root->data);
        return (max(left,right)+root->data);
     }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxi=INT_MIN;
        maxpathsum(root,maxi);
        return maxi;
    }
