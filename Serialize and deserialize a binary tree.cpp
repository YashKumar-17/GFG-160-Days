### **Intuition & Approach**
This code **serializes and deserializes a binary tree** using **preorder traversal**.

#### **Serialization (Preorder Traversal)**
1. Traverse the tree in **preorder** (Root → Left → Right).
2. Store node values in a list.
3. Use `-1` as a marker for `NULL` (missing children).

#### **Deserialization (Rebuilding Tree)**
1. Read values from the list **sequentially**.
2. If the value is `-1`, return `NULL`.
3. Otherwise, create a new node and **recursively** build its left and right subtrees.

This ensures that the **original tree structure is preserved** when reconstructing from the serialized data.

🔹 **Time Complexity:** `O(n)` (both serialization & deserialization).  
🔹 **Space Complexity:** `O(n)` (for storing serialized data & recursion stack).

void preorder(Node *root,vector<int>&ans){
        if(!root){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
    int i=0;
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        int val=arr[i];
        i++;
        if(val==-1) return NULL;
        Node *nn=new Node(val);
        nn->left=deSerialize(arr);
        nn->right=deSerialize(arr);
        return nn;
    }
