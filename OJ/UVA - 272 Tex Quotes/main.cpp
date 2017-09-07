//
//  main.cpp
//  Tex Quotes UVA - 272
//
//  Created by 褚旭 on 2017/8/23.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <cstdio>
int main() {
    int c,q=1;
    while((c=getchar())!=EOF)
        if(c=='"')
        {
            printf("%s",q?"``":"''");
            q=!q;
        }
        else
            printf("%c",c);
    return 0;
}
