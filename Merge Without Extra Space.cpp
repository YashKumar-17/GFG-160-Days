APPROACH

Two Pointers Setup:
Start with two pointers:
l, pointing to the last element of array a.
r, pointing to the first element of array b.
The idea is to compare elements from the end of a and the beginning of b to identify misplaced elements that violate the overall sorted order.

Element Swap for Correction:
If the current element in a (pointed by l) is greater than the current element in b (pointed by r), swap them. This ensures the largest elements move toward the end of the combined sequence and the smallest elements move toward the beginning.

Break Condition:
If the element in a[l] is already smaller or equal to b[r], it means that all elements in a are smaller than or equal to those in b. No further swaps are needed, so the loop can terminate early.

Sorting After Adjustments:
Once the pointers have adjusted the positions of misplaced elements, sort both arrays individually. This guarantees that both arrays are fully sorted.

While sorting may seem less efficient, the number of swaps performed during the pointer phase significantly reduces disorder, making the final sorting step more optimized.

void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size();
        int m=b.size();
        int l=n-1;
        int r=0;
        while(l>=0 && r<m){
            if(a[l]>b[r]){
                swap(a[l],b[r]);
                l--;
                r++;
            }
            else {
                break;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }
