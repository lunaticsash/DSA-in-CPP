#include <bits/stdc++.h>
using namespace std;

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to reverse a string and swap '(' with ')' and vice versa
string reverseAndSwap(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    return s;
}

// Function to convert Infix to Prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse and swap brackets
    string revInfix = reverseAndSwap(infix);

    stack<char> st;
    string result = "";

    // Step 2: Convert reversed infix to postfix
    for (int i = 0; i < (int)revInfix.length(); i++) {
        char c = revInfix[i];

        // If operand, add to result
        if (isalnum(c)) {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(c) < precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            // For right-associative operator (^)
            while (!st.empty() && precedence(c) == precedence(st.top()) && c != '^') {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Step 3: Reverse postfix result → prefix
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
