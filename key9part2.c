#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int input(int *buff, int *length);
int output(int *buff, int length);
void reverse_array(int *buff, int length);
int compare(int *buff1, int len1, int *buff2, int len2);

int main()
{
    int buff1[LEN], buff2[LEN];
    int len1, len2;
    int result[LEN];
    int result_length;

    if (input(buff1, &len1) && input(buff2, &len2))
    {
        reverse_array(buff1, len1);
        reverse_array(buff2, len2);

        sum(buff1, len1, buff2, len2, result, &result_length);
        reverse_array(result, result_length);
        output(result, result_length);

        if (compare(buff1, len1, buff2, len2) >= 0)
        {
            sub(buff1, len1, buff2, len2, result, &result_length);
            reverse_array(result, result_length);
            output(result, result_length);
        }
        else
        {
            printf("n/a\n");
        }
    }
    return 0;
}

int input(int *buff, int *length)
{
    int c;
    *length = 0;

    while ((c = getchar()) != '\n' && *length < LEN)
    {
        if (c >= '0' && c <= '9')
        {
            buff[*length] = c - '0';
            (*length)++;
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            printf("n/a\n");
            return 0;
        }
    }

    if (*length == 0)
    {
        printf("n/a\n");
        return 0;
    }

    return 1;
}

int output(int *buff, int length)
{
    int start = 0;
    while (start < length - 1 && buff[start] == 0)
    {
        start++; 
    }

    for (int i = start; i < length; i++)
    {
        printf("%d", buff[i]);
    }
    printf("\n");
    return 1;
}

void reverse_array(int *buff, int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        int temp = buff[i];
        buff[i] = buff[length - 1 - i];
        buff[length - 1 - i] = temp;
    }
}

int compare(int *buff1, int len1, int *buff2, int len2)
{
    if (len1 != len2)
    {
        return len1 - len2;
    }
    for (int i = len1 - 1; i >= 0; i--)
    {
        if (buff1[i] != buff2[i])
        {
            return buff1[i] - buff2[i];
        }
    }
    return 0; 
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int carry = 0;
    *result_length = len1 > len2 ? len1 : len2;

    for (int i = 0; i < *result_length; i++)
    {
        int a = i < len1 ? buff1[i] : 0;
        int b = i < len2 ? buff2[i] : 0;
        result[i] = (a + b + carry) % 10;
        carry = (a + b + carry) / 10;
    }

    if (carry)
    {
        result[*result_length] = carry;
        (*result_length)++;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length)
{
    int carry = 0;
    *result_length = len1;

    for (int i = 0; i < *result_length; i++)
    {
        int a = i < len1 ? buff1[i] : 0;
        int b = i < len2 ? buff2[i] : 0;
        result[i] = (a - b - carry + 10) % 10;
        carry = (a < b + carry) ? 1 : 0;
    }

    while (*result_length > 1 && result[*result_length - 1] == 0)
    {
        (*result_length)--;
    }
}