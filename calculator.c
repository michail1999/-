#include <stdio.h>
int main()
{
    int stack[1000];
    int a =0;
        while ( !feof(stdin) ) {
            int c = getchar();
            int x;
            switch (c) {
                case ' ':
                case '\n':
                    break;
                case '=':
                    printf("Result = %d\n", stack[a - 1]);
                    a--;
                    break;
                case '+':
                    stack[a - 2] = stack[a - 2] + stack[a - 1];
                    a--;
                    break;
                case '-':
                    stack[a - 2] = stack[a - 2] - stack[a - 1];
                    a--;
                    break;
                case '*':
                    stack[a - 2] = stack[a - 1] * stack[a - 2];
                    a--;
                    break;
                case '/':
                    stack[a - 2] = stack[a - 2] / stack[a - 1];
                    a--;
                    break;
                default:
                    ungetc(c, stdin);
                    if (scanf("%d", &x) != 1) {
                        fprintf(stderr, "Can't read integer\n");
                        return -1;
                    } else {
                        stack[a] = x;
                        a++;
                    }
            }
        }
    printf("Result = %d\n",stack[a-1]);
    return 0;
}
