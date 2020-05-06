#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAXSIZE 100

//使用顺序栈
typedef struct node
{
    char elements[MAXSIZE];
    int Top;
} stack;
stack *S;

stack *setnull(stack *S)
{
    S->Top = -1;
    return S;
}
// return '\0' -> Error
char pop(stack *S)
{
    S->Top--;
    if (S->Top < -1)
    {
        return '\0'; //Error
    }
    else
    {
        //printf("pop %c\n",S->elements[S->Top + 1]);
        return S->elements[S->Top + 1];
    }
}
void *push(stack *S, char e)
{
    S->Top++;
    S->elements[S->Top] = e;
    //printf("push %c\n",e);
}
int correct(char String[], int len)
{
    S = (stack *)malloc(sizeof(stack));
    S = setnull(S);

    int i;
    if (len % 2 == 0)
    {
        for (i = 0; i < len; i++)
        {
            //printf("i=%d\n",i);
            if (i < len / 2)
            {
                push(S, String[i]);
            }
            else
            {
                char c = pop(S);
                //printf("<-%c->\n",c);
                if (c != String[i])
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            if (i < len / 2)
            {
                push(S, String[i]);
            }
            else if (i > len / 2)
            {
                char c = pop(S);
                if (c != String[i])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main()
{
    int sign; //sign为标志，sign=1是回文，sign=0不是回文
    int len;
    char str[100];

    gets(str); //输入字符串
    len = strlen(str);
    sign = correct(str, len);
    if (sign)
        printf("right\n");
    else
        printf("wrong\n");
    return 0;
}
