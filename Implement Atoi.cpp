Approach for myAtoi

The myAtoi function converts a string into a 32-bit signed integer following specific rules. Here's the step-by-step approach:

Initialize Variables
Define constants INT_MAX and INT_MIN to represent the upper (2^31 - 1) and lower (-2^31) bounds of a 32-bit signed integer.
Use a variable ans initialized to 0 to store the final result.

Initialize flags and helpers:

 flag to track if number parsing has started.
 negate to indicate if the number is negative.
 end to mark overflow conditions.
 Find the length of the input string, n.
 Iterate Through the String
 Loop through each character in the string.
 Skip Leading Whitespaces
 Ignore whitespace characters (' ') before starting parsing.
 Handle Signs

 If a '-' is encountered before parsing digits, set the negate flag to 1 to indicate the number is negative.
 Similarly, handle the '+' sign but take no additional action.
 Detect and Parse Digits

If a digit between '1' and '9' is encountered, parsing begins:
Convert the character to its integer value by subtracting '0' from it.
Multiply the current ans by 10 and add the converted digit to ans.
Set flag = 1 to indicate parsing has started.

Handle Leading Zeros
Ignore zeros ('0') before meaningful digits if parsing has not started.
Handle Invalid Characters

If parsing has not started and an invalid character (neither whitespace, sign, nor digit) is encountered, terminate parsing.
Stop Parsing on Non-Digit After Starting
Once parsing has started, terminate parsing if any non-digit character is encountered.

Check for Overflow
After adding a digit, check if the ans exceeds the maximum 32-bit integer (INT_MAX).
If ans exceeds INT_MAX:
Set end = 1 to mark overflow and break out of the loop.
Handle Overflow
If overflow is detected (end = 1):
Return INT_MIN if the number is negative (negate = 1).
Return INT_MAX otherwise.

Apply Sign
If the negate flag is set, multiply ans by -1 to make it a negative value.
Return Result
Return the final value of ans as the parsed integer.

Complexity Analysis
Time Complexity: O(n), where n is the length of the input string. We iterate through each character in the string once.
Space Complexity: O(1), as no additional space is used apart from a few variables.

Edge Cases

Empty String: Returns 0 as no number can be parsed.
String with Only Whitespaces: Returns 0 since no digits are found.
String Starting with Invalid Characters: Parsing stops, and 0 is returned.
Overflow: Returns INT_MAX or INT_MIN depending on the sign of the overflow.
Valid String with Mixed Content: Parses the number until a non-digit character is encountered, ignoring the rest of the string.
Leading Zeros: Correctly ignores leading zeros and parses the number normally.


int myAtoi(char *s) {
        // Your code here
        int maxi=INT_MAX;
        int mini=INT_MIN;
        long long ans=0;
        int flag=0;
        int negate=0;
        int end=0;
        int n=strlen(s);
        for(int i=0;i<n;i++){
            if(flag==0 && s[i]=='-'){
                negate=1;
            }
            if(flag==0 && s[i]>='1' && s[i]<='9'){
                flag=1;
                int a=s[i]-'0';
                ans=ans*10+a;
            }
            else if(flag==0 &&(s[i]!=' ' && s[i]!='+' && s[i]!='0' && s[i]!='-')){
                break;
            }
            else if(flag==1 && (s[i]<'0' || s[i]>'9')){
                break;
            }
            else if(flag==1){
                int b=s[i]-'0';
                ans=ans*10+b;
                if(ans>maxi){
                    ans=maxi;
                    end=1;
                    break;
                }
            }
        }
        if(end==1){
            if(negate==1){
                return mini;
            }
            else{
                return maxi;
            }
        }
        if(negate==1){
            ans=ans*-1;
        }
        return ans;
    }
