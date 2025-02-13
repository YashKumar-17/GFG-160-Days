### **Intuition**  
The code checks whether there exist two nodes in a binary tree whose sum equals a given target. It does this by keeping track of visited node values in an unordered map (hashmap) to enable quick lookups.

### **Approach**  
1. **Recursive Traversal**: The `check` function traverses the binary tree in a depth-first manner.  
2. **Hashmap Storage**: Each node’s value is stored in an unordered map (`ump`) along with its frequency.  
3. **Checking for Pair**: For each node, the code computes `req = target - node->data` and checks:  
   - If `req` is equal to `node->data`, it ensures that this value appears at least twice in the map.  
   - Otherwise, it simply checks if `req` is already present in the map.  
4. **Return Result**: If a valid pair is found, it returns `true`; otherwise, it continues traversing left and right subtrees.  
5. **Final Check**: The function `findTarget` initializes the hashmap and calls `check` to determine the answer.

bool check(Node* node, int &target, unordered_map<int,int>&ump){
        if(node==NULL){
            return false;
        }
        ump[node->data]++;
        int req=target-node->data;
        if(req==node->data){
            if(ump[req]>1){
                return true;
            }
        }
        else if(ump.find(req)!=ump.end()){
            return true;
        }
        return (check(node->left,target,ump) || check(node->right,target,ump));
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        unordered_map<int,int>ump;
        return check(root,target,ump);
        
    }
