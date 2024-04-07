#include <iostream>
using namespace std;
// Stack implementation
class Stack {
private:
    int top;
    int *arr;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = data;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
};
int evaluatePostfix(char* expression) {
    Stack operandStack(100);
    for (int i = 0; expression[i]; ++i) {
        if (isdigit(expression[i])) {
            operandStack.push(expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
            int operand2 = operandStack.pop();
            int operand1 = operandStack.pop();
            switch(expression[i]) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    exit(1);
            }
        }
    }
    return operandStack.peek();
}
int main() {
    char postfixExpression[100];
    cout << "Enter postfix expression: ";
    cin.getline(postfixExpression, 100);
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
    return 0;
}
