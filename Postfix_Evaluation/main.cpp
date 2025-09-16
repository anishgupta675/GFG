#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int evaluatePostfix(vector<string>& arr) {
        // Initialize a stack to store operands
        stack<int> st;
        // String containing all valid operators for easy lookup
        string operand = "+-*/^";
        
        // Iterate through each token in the expression
        for(string &s: arr){
            // Check if the token is NOT an operator (i.e., it's a number)
            if(operand.find(s)==string::npos){
                // Convert string to integer and push onto stack
                int tt = stoi(s);
                st.push(tt);
            }else{
                // Token is an operator - pop the top two operands
                // Note: The first popped is num2, the second is num1
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                
                int result = -1;
                // Perform the appropriate operation based on the operator
                if(s == "+"){
                    result = num1 + num2;
                }else if(s == "-"){
                    result = num1 - num2;
                }else if(s == "*"){
                    result = num1 * num2;
                }else if(s == "/"){
                    // Regular integer division
                    result = num1 / num2;
                    // Special handling for negative division:
                    // If operands have different signs AND there's a remainder,
                    // we need to adjust the result to ensure proper floor behavior
                    if ((num1 ^ num2) < 0 && num1 % num2 != 0) result--;
                }else if(s == "^"){
                    // Power operation using standard library
                    result = pow(num1,num2);
                }
                
                // Push the result back onto the stack
                st.push(result);
            }
        }
        
        // The final result is the only element left in the stack
        return st.top();
    }
};

int main() {}