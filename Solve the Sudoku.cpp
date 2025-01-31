### **Approach and Intuition: Sudoku Solver using Backtracking**  

1. **Recursive Backtracking**  
   - The function `solve()` attempts to fill empty cells (`0`) in the Sudoku grid recursively.  
   - It tries numbers from **1 to 9**, checking if they are valid before placing them.  

2. **Validation Function (`isvalid()`)**  
   - Ensures a number is not already present in the **same row**, **same column**, or **same 3×3 subgrid**.  
   - If a number violates any of these rules, it is not placed in that cell.  

3. **Backtracking Mechanism**  
   - If a number is placed and leads to a solution (`solve()` returns `true`), the recursion stops.  
   - If a placement doesn’t lead to a solution, it **backtracks** by resetting the cell to `0` and trying the next possible number.  

4. **Base Case for Recursion**  
   - If all cells are filled, the Sudoku is solved (`return true`).  

5. **Time Complexity Consideration**  
   - Worst-case scenario involves trying multiple possibilities, making it **O(9^(N*N))**, but efficient pruning significantly reduces computations.  

This approach effectively finds a solution by **exploring possibilities, pruning invalid choices, and backtracking when necessary**. 🚀


void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
    bool solve(vector<vector<int>> &mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(isvalid(mat,i,j,k)){
                            mat[i][j]=k;
                            if(solve(mat)==true){
                                return true;
                            }
                            else{
                                mat[i][j]=0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<int>>&mat, int row, int col, int num){
        for(int i=0;i<9;i++){
            if(mat[i][col]==num){
                return false;
            }
            if(mat[row][i]==num){
                return false;
            }
            if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==num){
                return false;
            }
        }
        return true;
    }
