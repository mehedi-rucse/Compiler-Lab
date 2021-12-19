#include <stdio.h>
#include <string.h>

char str[100];
int isArithmeticOperator()
{

    if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 ||
        strcmp(str, "/") == 0 || strcmp(str, "^") == 0 || strcmp(str, "=") == 0)
        return 1;
    return 0;
}

int isRelationalOperator()
{
    if (strcmp(str, "<") == 0 || strcmp(str, ">") == 0 || strcmp(str, "!=") == 0 ||
        strcmp(str, "==") == 0 || strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0)
        return 1;

    return 0;
}

int isIdentifier()
{

    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
        return 1;

    return 0;
}

int isFloat()
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '.')
        {
            for (int j = 0; j < len; j++)
            {
                if (j != i && (str[j] < '0' && str[j] > '9'))
                    return 0;
            }
            if (str[0] == '0' && str[1] != '.')
                return 0;

            return 1;
        }
    }
    return 0;
}

int isInteger()
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            continue;
        }
        return 0;
    }
    return 1;
}
int isKeyword()
{

    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") ||
        !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") ||
        !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1;
    return 0;
}

int main()
{
    int len;
    while (scanf("%s", str) != EOF)
    {
        len = strlen(str);
        if (isInteger())
        {
            printf("Integer\n");
        }
        else if (isFloat())
        {
            printf("Float\n");
        }
        else if (isKeyword())
        {
            printf("Keyword\n");
        }
        else if (isIdentifier())
        {
            printf("Identifier\n");
        }
        else if (isArithmeticOperator())
        {
            printf("Arithmetic Operator\n");
        }
        else if (isRelationalOperator())
        {
            printf("Relational Operator");
        }
    }
}