### **Intuition & Approach:**

1. **Problem Understanding:** The goal is to find the number of paths in a binary tree whose sum equals `k`. The paths can start from any node but must follow parent-child connections.

2. **Using Prefix Sum & Hash Map:**  
   - A **prefix sum** stores the cumulative sum from the root to the current node.  
   - A **hash map (`ump`)** keeps track of how many times each prefix sum has appeared.

3. **Recursive Traversal:**  
   - We use **DFS (Depth-First Search)** to traverse the tree.  
   - At each node, update the current sum (`sum += node->data`).  
   - Check if `sum - k` exists in the hash map, meaning there’s a valid path that sums to `k`. If found, add its count to `total`.

4. **Backtracking:**  
   - Add `sum` to the map before moving to the left and right subtrees.  
   - After visiting both children, **remove** the current sum from the map to avoid affecting other paths.

5. **Modulo Operation:** Since the number of valid paths can be large, results are stored modulo `1e9+7`.

int sumK(Node *root, int k) {
        // code here
        unordered_map<int,int> ump;
        ump[0]=1;
        solve(root, k, ump, 0);
        return total;
    }
    private:
        int total = 0;
        const int mod=1e9+7;
        void solve(Node* node, int k, unordered_map<int,int> &ump, int sum){
            if(node==nullptr) return;
            sum+=node->data;
            if(ump.find(sum-k)!=ump.end()) total=(total+ump[sum-k])%mod;
            ump[sum]++;
            solve(node->left, k, ump, sum);
            solve(node->right, k, ump, sum);
            ump[sum]--;
            if(ump[sum]==0) ump.erase(sum);
        }
