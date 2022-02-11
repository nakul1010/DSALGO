class Solution {
public:
    bool isValid(string s) {
                // the string cant be of uneven length because each paranthesis has to be closed again
        if (s.length() % 2 == 1) {
            return false;
        }
        // fill up the stack with opening parenthesis and pop from the stack when closing paranthesis is read 
        stack<char> stk;
        for(int i = 0; i < s.length(); i++) {
           switch (s[i]) {
               case '(':
               case '[':
               case '{':
                   stk.push(s[i]);
                   break;
               case ')':
                   if (stk.empty()) {
                       return false;
                   }
                   if (stk.top() != '(') {
                       return false;
                   }
                   stk.pop();
                   break;
               case ']':
                   if (stk.empty()) {
                       return false;
                   }
                   if (stk.top() != '[') {
                       return false;
                   }
                   stk.pop();
                   break;
               case '}':
                   if (stk.empty()) {
                       return false;
                   }
                   if (stk.top() != '{') {
                       return false;
                   }
                   stk.pop();
           }
        }
        return stk.empty();
    }
};