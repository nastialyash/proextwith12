

#include <iostream>
using namespace std;
class Stack {
private:
    char stackArray[100];  
    int topIndex;          
public:
    Stack() : topIndex(-1) {}  
    
    void push(char ch) {
        if (topIndex < 99) {
            topIndex++;
            stackArray[topIndex] = ch;
        }
    }

    
    void delete1() {
        if (topIndex >= 0) {
            topIndex--;
        }
    }

  
    char top() const {
        if (topIndex >= 0) {
            return stackArray[topIndex];
        }
        return 0;  
    }

   
    bool isEmpty() const {
        return topIndex == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}


void checkBrackets(const string& expression) {
    Stack bracketsStack; 
    int errorIndex = -1; 
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

      
        if (ch == '(' || ch == '{' || ch == '[') {
            bracketsStack.push(ch);
        }
      
        else if (ch == ')' || ch == '}' || ch == ']') {
           
            if (bracketsStack.isEmpty()) {
                errorIndex = i;
                break;
            }

            char topChar = bracketsStack.top();
           
            if (isMatchingPair(topChar, ch)) {
                bracketsStack.delete1();
            }
            else {
                errorIndex = i;
                break;
            }
        }
        
        else if (ch == ';') {
            break;
        }
    }

    if (errorIndex == -1 && bracketsStack.isEmpty()) {
        cout << "The string is correct." << endl;
    }
    else {
        cout << "Error in the string at position " << errorIndex << ": ";
        for (size_t i = 0; i <= errorIndex; ++i) {
            cout << expression[i];
        }
        cout << endl;
    }
}

int main() {
    string expression;
    cout << "Enter an expression ending with : ";
   

    checkBrackets(expression);

 
}