### Approach & Intuition:  
1. **Handle Negative Exponent:**  
   - If `e` is negative, compute `power(b, -e)` and take the reciprocal (`1 / result`).  

2. **Base Case:**  
   - If `e == 0`, return `1.0` for nonzero `b` (anything raised to power `0` is `1`).  
   - If `b == 0`, return `0.0` (edge case for `0^0`).  

3. **Recursive Approach (Exponentiation by Squaring):**  
   - Compute `power(b, e/2)` recursively and store it in `ans`.  
   - If `e` is even: return `ans * ans`.  
   - If `e` is odd: return `b * ans * ans`.  

### Efficiency:  
- Reduces exponent size by half in each step → **O(log e) complexity**.

double power(double b, int e) {
        // code here
        if(e<0){
            return 1/power(b,-e);
        }
        if(e==0){
            if(b<0 || b>0){
                return 1.0;
            }
            else if(b==0){
                return 0.0;
            }
        }
        
        double ans = power(b, e/2);
        
        if(e%2==0){
            return ans*ans;
        }
        else {
            return b*ans*ans;
        }
    }
