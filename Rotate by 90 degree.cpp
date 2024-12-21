Approach

When you carefully see the pattern you will notice that the answer matrix is nothing but the transpose of the original matrix when we reverse each row of the original matrix already.

void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
       
    }
