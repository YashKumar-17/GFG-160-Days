### Approach and Intuition for `addBinary`

The function `addBinary` performs binary addition on two binary strings (`s1` and `s2`). Here’s the breakdown of the approach and intuition:

---

#### **1. Equalizing String Lengths**
- **Intuition**: Binary addition operates from the least significant bit (rightmost bit) to the most significant bit (leftmost bit). To simplify processing, both strings must have the same length, so padding with leading zeros ensures this.
- **Implementation**: 
  - If the length of `s1` is less than `s2`, pad `s1` with leading zeros until both strings have equal length.
  - Similarly, pad `s2` with leading zeros if it is shorter than `s1`.

---

#### **2. Initialize Variables**
- **Carry**: Used to store the carry-over value during binary addition.
- **Result String (`ans`)**: Stores the result of the binary addition.

---

#### **3. Binary Addition Logic**
- Traverse both strings from right to left (starting from the least significant bit).
- For each pair of bits from `s1` and `s2` and the current carry:
  - Consider all possible combinations of `0` and `1` for `s1[i]`, `s2[i]`, and `carry`. Update the `ans` string and the `carry` accordingly.
    - Example: 
      - If `s1[i] = '1', s2[i] = '1', carry = 0`: Result is `0` (with carry `1`).
      - If `s1[i] = '0', s2[i] = '1', carry = 1`: Result is `0` (with carry `1`).
- Add the computed bit to the **front** of the result string (`ans`).

---

#### **4. Handle Remaining Carry**
- After processing all bits, if a carry remains, prepend it to the result string (`ans`).

---

#### **5. Remove Leading Zeros**
- **Intuition**: The result string may contain unnecessary leading zeros, which are not significant in binary representation.
- **Implementation**: Iterate through the result string and count leading zeros. Erase these leading zeros from the string.

---

#### **6. Return the Result**
- Return the final binary sum stored in the `ans` string.

---

### **Key Observations**
1. **Bitwise Processing**: The algorithm mimics manual binary addition, combining bits one-by-one while keeping track of the carry.
2. **Edge Cases Handled**:
   - Unequal input lengths (via padding).
   - Strings with only zeros (leading zeros are removed).
   - Cases where the result requires an additional bit due to carry overflow (e.g., `1 + 1`).

---

### **Time Complexity**
- **Padding**: \(O(\max(s1.length, s2.length))\).
- **Addition**: \(O(n)\), where \(n = \max(s1.length, s2.length)\).
- **Total**: \(O(n)\).

### **Space Complexity**
- **Result String**: \(O(n+1)\) (to store the result, including carry).
- **Total**: \(O(n)\).


string addBinary(string& s1, string& s2) {
        // your code here
        int s1len=s1.length();
        int s2len=s2.length();
        if(s1len<s2len){
            while(s1.length()!=s2.length()){
                char c='0';
                s1=c+s1;
            }
        }
        else if(s2len<s1len){
            while(s2.length()!=s1.length()){
                char z='0';
                s2=z+s2;
            }
        }
        int carry=0;
        string ans;
        for(int i=s1.length()-1;i>=0;i--){
            if(s1[i]=='0' && s2[i]=='0' && carry==0){
                ans='0'+ans;
            }
            else if(s1[i]=='0' && s2[i]=='0' && carry==1){
                ans='1'+ans;
                carry=0;
            }
            else if(s1[i]=='0' && s2[i]=='1' && carry==0){
                ans='1'+ans;
            }
            else if(s1[i]=='0' && s2[i]=='1' && carry==1){
                ans='0'+ans;
                carry=1;
            }
            else if(s1[i]=='1' && s2[i]=='0' && carry==0){
                ans='1'+ans;
            }
            else if(s1[i]=='1' && s2[i]=='0' && carry==1){
                ans='0'+ans;
                carry=1;
            }
            else if(s1[i]=='1' && s2[i]=='1' && carry==0){
                ans='0'+ans;
                carry=1;
            }
            else if(s1[i]=='1' && s2[i]=='1' && carry==1){
                ans='1'+ans;
                carry=1;
            }
            
        }
        if(carry!=0){
            ans='1'+ans;
        }
        int flag=0;
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0' && flag==0){
                count++;
            }
            else{
                break;
            }
        }
        ans.erase(0,count);
        return ans;
    }
