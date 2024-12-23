APPROACH:

 Understand the Input:

mat is a 2D matrix (vector of vectors) with n rows and m columns.
Each row is sorted in ascending order.
x is the number we want to search for in the matrix.

Initialize Variables:

n is the total number of rows.
m is the total number of columns.
Start searching from the first row (row = 0).

Iterate Through Rows:

Check each row one by one.
If the target x is smaller than the first element of the row or larger than the last element of the row, skip to the next row because x cannot exist in the current row.
Binary Search in the Valid Row:

If x lies within the range of the current row (between the first and last elements of that row):
Perform a binary search on the row.
Use two pointers low and high to search within the row:
Calculate the middle index (mid).
If x matches the middle element, return true.
If x is less than the middle element, search in the left half (adjust high).
If x is greater, search in the right half (adjust low).
Continue to the Next Row:

If binary search fails in the current row, move to the next row.
Return the Result:

If all rows are checked and x is not found, return false.


bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int row=0;
        while(row<n){
            int low=0;
            int high=m-1;
            if(x<mat[row][0] || x>mat[row][high]){
                row++;
                continue;
            }
            else{
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(mat[row][mid]==x){
                        return true;
                    }
                    else if(mat[row][mid]<x){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                row++;
            }
        }
        return false;
    }
