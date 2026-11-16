#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int display1(char *string);
int display2(char *string1);
int main()
{
    char string[] = "Embedded Linux";
    display1(string);
    display2(string);
}
int display1(char *string)
{
    printf("The original string is %s \n", string);
}
int display2(char *string1)
{
    char *string2;
    int size, i;
    size = strlen(string1);
    string2 = (char *)malloc(size + 1);
        for (i = 0; i < size; i++)              /* 去掉 = 号 */
        string2[size - 1 - i] = string1[i]; /* 下标改成 size - 1 - i */
string2[size] = '\0';                   /* 补结束符，替代下面那行越界代码 */
printf("The string afterward is %s\n", string2);
}

