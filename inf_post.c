#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {

        if(isalnum(infix[i]))
            postfix[k++] = infix[i];

        else if(infix[i] == '(')
            push(infix[i]);

        else if(infix[i] == ')') {
            while(peek() != '(')
                postfix[k++] = pop();
            pop();
        }

        else {
            while(!isEmpty() && precedence(peek()) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }

    while(!isEmpty())
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix Expression: %s", postfix);
    return 0;
}
