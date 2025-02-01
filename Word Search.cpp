### **Approach and Intuition**  

1. **Iterate Over the Matrix:**  
   - Traverse each cell in the matrix to find the starting character of the given word.

2. **Recursive Backtracking Search:**  
   - If a match is found, call the `search` function recursively in all four directions (up, down, left, right) to find the next character.
   - Mark the current cell as visited (`'*'`) to avoid revisiting it during the same path.

3. **Base Conditions:**  
   - If `k` (current index in the word) reaches the word’s length, return `true` (word found).
   - If out of bounds or character mismatch occurs, return `false`.

4. **Backtracking:**  
   - After exploring a path, restore the original character of the matrix cell to allow further searches.

5. **Return Result:**  
   - If any path successfully finds the word, return `true`, otherwise return `false`.

bool search(int i, int j, int n, int m, vector<vector<char>>& mat, string& word,int k){
        if(k==word.length()){
            return true;
        }
        if(i<0 || j<0 || i==n || j==m || mat[i][j]!=word[k]){
            return false;
        }
        mat[i][j]='*';
        bool up=search(i-1,j,n,m,mat,word,k+1);
        bool down=search(i+1,j,n,m,mat,word,k+1);
        bool left=search(i,j-1,n,m,mat,word,k+1);
        bool right=search(i,j+1,n,m,mat,word,k+1);
        mat[i][j]=word[k];
        return up || down || left || right;
    }
    
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
               if(mat[i][j]==word[0]){
                   if(search(i,j,n,m,mat,word,0)){
                       return true;
                   }
               }
            }
        }
        return false;
    }
