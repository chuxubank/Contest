#include <bits/stdc++.h>
using namespace std;

char *prefix(char *haystack_start, char *needle_start)
{
    char *haystack = haystack_start;
    char *needle = needle_start;

    while (*haystack && *needle)
    {
        if (*haystack++ != *needle++) //填空位置
            return NULL;
    }

    if (*needle)
        return NULL;

    return haystack_start;
}

int main()
{
    char a[] = "abc123", b[] = "abc";
    printf("%s", prefix(a, b));
    return 0;
}