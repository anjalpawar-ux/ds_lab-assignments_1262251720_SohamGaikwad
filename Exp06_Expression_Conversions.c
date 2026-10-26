#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXSIZE 100
char stack[MAXSIZE]; int top = -1;
char str_stack[MAXSIZE][MAXSIZE]; int str_top = -1;

void push(char item) { if (top < MAXSIZE - 1) stack[++top] = item; }
char pop() { if (top >= 0) return stack[top--]; return '\0'; }
void pushStr(char* item) { if (str_top < MAXSIZE - 1) strcpy(str_stack[++str_top], item); }
char* popStr() { if (str_top >= 0) return str_stack[str_top--]; return ""; }

int icp(char ch) { if(ch=='+'||ch=='-') return 1; if(ch=='*'||ch=='/') return 2; if(ch=='^') return 4; if(ch=='(') return 5; return 0; }
int isp(char ch) { if(ch=='+'||ch=='-') return 1; if(ch=='*'||ch=='/') return 2; if(ch=='^') return 3; return 0; }

void in_post(char inexp[], char postexp[]) {
    int k = 0, i = 0; char tkn = inexp[i]; top = -1;
    while (tkn != '\0') {
        if (isalnum(tkn)) postexp[k++] = inexp[i];
        else {
            if (tkn == '(') push('(');
            else if (tkn == ')') { while ((tkn = pop()) != '(') postexp[k++] = tkn; }
            else { while (top != -1 && isp(stack[top]) >= icp(tkn)) postexp[k++] = pop(); push(tkn); }
        }
        tkn = inexp[++i];
    }
    while (top != -1) postexp[k++] = pop(); postexp[k] = '\0';
}

void pre_post(char E[]) {
    int l = strlen(E); str_top = -1;
    for (int i = l - 1; i >= 0; i--) {
        char x = E[i];
        if (isalnum(x)) { char temp[2] = {x, '\0'}; pushStr(temp); }
        else {
            char op1[MAXSIZE], op2[MAXSIZE], E1[MAXSIZE];
            strcpy(op1, popStr()); strcpy(op2, popStr());
            sprintf(E1, "%s%s%c", op1, op2, x); pushStr(E1);
        }
    }
    printf("Postfix Expression: %s\n", popStr());
}

int main() {
    int choice; char expr[MAXSIZE], res[MAXSIZE];
    do {
        printf("\n1. Infix to Postfix\n2. Prefix to Postfix\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Infix: "); scanf("%s", expr); in_post(expr, res); printf("Postfix: %s\n", res); break;
            case 2: printf("Prefix: "); scanf("%s", expr); pre_post(expr); break;
        }
    } while(choice != 3);
    return 0;
}
