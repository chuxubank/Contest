#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

/**
 * 为保证控制台程序输出中文不乱码：
 * 1、xxx.c xxx.cpp使用utf-8编码，来支持linux和window的中文。
 * 2、window cmd需要进行下面设置
 */
int main(void)
{
#ifdef _WIN32
    //http://m.blog.csdn.net/article/details?id=52789570
    //控制台显示乱码纠正
    // system("chcp 65001"); //设置字符集（使用SetConsoleCP(65001)设置无效，原因未知）
    SetConsoleOutputCP(65001);
    CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体来支持中文显示。
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 16; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
#endif
    printf("Hello World!\n");
    printf("测试中文!\n");
    printf("我是中文!\n");
    printf("Hello World!\n");
    getchar();
    return 0;
}
