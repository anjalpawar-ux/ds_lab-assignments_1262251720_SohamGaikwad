#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100
int stack[MAXSIZE];
int top = -1;

void Push(int item) { if(top < MAXSIZE - 1) stack[++top] = item; }
int pop() { if(top >= 0) return stack[top--]; return 0; }

int Evaluate_Postfix(char expression[]) {
    top = -1; // Create an empty stack
    int l = strlen(expression);
    for(int i = 0; i < l; i++) {
        char symbol = expression[i];
        if(isalnum(symbol)) { 
            int val;
            if(isdigit(symbol)) val = symbol - '0';
            else { printf("Value for %c: ", symbol); scanf("%d", &val); }
            Push(val);
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            switch(symbol) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: result = 0;
            }
            Push(result);
        }
    }
    return pop();
}

int main() {
    char expr[MAXSIZE];
    printf("--- Postfix Evaluation ---\nEnter postfix expression: ");
    scanf("%s", expr);
    printf("Evaluated Result: %d\n", Evaluate_Postfix(expr));
    return 0;
}
