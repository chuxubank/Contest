//
// Created by zhengwei.
//

/*
交换瓶子

有N个瓶子，编号 1 ~ N，放在架子上。

比如有5个瓶子：
2 1 3 5 4

要求每次拿起2个瓶子，交换它们的位置。
经过若干次后，使得瓶子的序号为：
1 2 3 4 5

对于这么简单的情况，显然，至少需要交换2次就可以复位。

如果瓶子更多呢？你可以通过编程来解决。

输入格式为两行：
第一行: 一个正整数N（N<10000）, 表示瓶子的数目
第二行：N个正整数，用空格分开，表示瓶子目前的排列情况。

输出数据为一行一个正整数，表示至少交换多少次，才能完成排序。

例如，输入：
5
3 1 2 5 4

程序应该输出：
3

再例如，输入：
5
5 4 3 2 1

程序应该输出：
2

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/
#include <iostream>

using namespace std;
int n;
int a[10001];
int ans;

int pos(int x) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] == x)return i;
    }
    return -1;
}

void swap(int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void printArr() {
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char *argv[]) {
// 处理输入
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
//遍历i:1-N
    for (int i = 1; i <= n; ++i) {
//如果a[i]=i,已经到位
        if (a[i] == i)continue;
//否则先找到i在a中的位置pos(i)和i位交换——swap(a,pos(i),i)
        else {
            swap(pos(i), i);
            ans++;
        }
    }

//    printArr();
    printf("%d\n", ans);
    return 0;
}