#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluate(char exp[])
{
    int i, a, b, val[26] = {0};
    char ch;

    printf("Enter values of variables:\n");

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isalpha(exp[i]))
        {
            ch = exp[i];
            printf("Enter value of %c: ", ch);
            scanf("%d", &val[ch - 'a']);
        }
    }

    for(i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if(isalpha(ch))
            push(val[ch - 'a']);
        else
        {
            b = pop();
            a = pop();

            switch(ch)
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    return pop();
}

int main()
{
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluate(exp));

    return 0;
}