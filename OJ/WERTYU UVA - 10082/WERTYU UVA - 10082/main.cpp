//
//  main.cpp
//  WERTYU UVA - 10082
//
//  Created by 褚旭 on 2017/8/22.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <cstdio>
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    int i,c;
    while((c=getchar())!=EOF)
    {
        for(i=1;s[i]&&s[i]!=c;i++);
        if(s[i])
            putchar(s[i-1]);
        else putchar(c);
    }
    return 0;
}
