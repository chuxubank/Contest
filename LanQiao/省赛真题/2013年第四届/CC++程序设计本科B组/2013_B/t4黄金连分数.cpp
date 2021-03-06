//
// Created by zhengwei.
//
/*

标题: 黄金连分数


    黄金分割数0.61803... 是个无理数，这个常数十分重要，在许多工程问题中会出现。有时需要把这个数字求得很精确。

    对于某些精密工程，常数的精度很重要。也许你听说过哈勃太空望远镜，它首次升空后就发现了一处人工加工错误，
    对那样一个庞然大物，其实只是镜面加工时有比头发丝还细许多倍的一处错误而已，却使它成了“近视眼”!!


    言归正传，我们如何求得黄金分割数的尽可能精确的值呢？有许多方法。

    比较简单的一种是用连分数：

                  1
    黄金数 = ---------------------
                        1
             1 + -----------------
                          1
                 1 + -------------
                            1
                     1 + ---------
                          1 + ...



    这个连分数计算的“层数”越多，它的值越接近黄金分割数。

    请你利用这一特性，求出黄金分割数的足够精确值，要求四舍五入到小数点后100位。

    小数点后3位的值为：0.618
    小数点后4位的值为：0.6180
    小数点后5位的值为：0.61803
    小数点后7位的值为：0.6180340
   （注意尾部的0，不能忽略）

你的任务是：写出精确到小数点后100位精度的黄金分割值。

注意：尾数的四舍五入！ 尾数是0也要保留！

显然答案是一个小数，其小数点后有100位数字，请通过浏览器直接提交该数字。
注意：不要提交解答过程，或其它辅助说明类的内容。

 */

/*1、转为求斐波那契数列的n和n+1项
 * 2、n取多少？再增加n，小数点后的101位没有变化
 * 3、不能用c语言定义的整数型直接运算，而要手工地写大数加法和除法（减法）*/
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int n = 400;


void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

string add(string a, string b) {
    a = a.substr(a.find_first_not_of('0'));
    b = b.substr(b.find_first_not_of('0'));
    long long lenA = a.length();
    long long lenB = b.length();
    long long len = max(lenA, lenB) + 10;
//翻转，便于从低位逐步求和
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans(len, '0');//初始化答案为len长，全部为字符0
//    把a拷贝到ans中
    for (int i = 0; i < lenA; ++i) {
        ans[i] = a[i];
    }
    int tmp = 0;//tmp是上一位相加后的进位
    for (int i = 0; i < len; ++i) {
        if (i < b.length())
            tmp += (ans[i] - '0') + (b[i] - '0');//假设为18
        else
            tmp += (ans[i] - '0');
        ans[i] = tmp % 10 + '0';//8 8+'0'
        tmp /= 10;//1
    }
    reverse(ans.begin(), ans.end());
    return ans.substr(ans.find_first_not_of('0'));
}

int cmp(string a, string b) {
    unsigned long i1 = a.find_first_not_of('0');
    if (i1 == string::npos)a = '0';
    else a.substr(i1);

    unsigned long i2 = b.find_first_not_of('0');
    if (i2 == string::npos)b = '0';
    else b.substr(i2);

    if (a.length() > b.length())return 1;
    else if (a.length() < b.length())return -1;
    else {//长度相等
        if (a < b)return -1;
        if (a > b)return 1;
        else return 0;
    }
}

//此处，a一定大于等于b
string subtract(string a, string b) {
//    完整的减法里面，a可以小于b，这时结果为负数，交换ab进行下面的代码
//    1.翻转
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
//    2.按位做减法
    for (int i = 0; i < b.length(); ++i) {
        if (a[i] >= b[i]) {
            a[i] = a[i] - b[i] + '0';
        } else {//就要借
            int k = 1;
            while (a[i + k] == '0') {
                a[i + k] = '9';
                k++;
            }
//            这里可以保证i+k这一位上不是0
            a[i + k] = a[i + k] - '1' + '0';

            a[i] = (a[i] - '0' + 10) - (b[i] - '0') + '0';
        }
    }

    reverse(a.begin(), a.end());
    if (a.find_first_not_of('0') == string::npos)return "0";
    return a.substr(a.find_first_not_of('0'));
}

/*转换成减法*/
string divide(string a, string b) {
//    只考虑a<b的情况
    string ans = "0.";
//    转化成减法
    for (int i = 0; i < 101; ++i) {//101次
        a.append("0");
        int t = 0;
        while (cmp(a, b) >= 0) {//a>=b
            a = subtract(a, b);//不停地做减法
            t++;//记录减法做了多少次
        }
        string t_str;
        i2s(t, t_str);
        ans.append(t_str);
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    string a = "1";
    string b = "1";
    cout << subtract(a, b) << endl;
    for (int i = 3; i <= n; ++i) {
        string tmp = b;
        b = add(a, b);
        a = tmp;
//        cout << b << " " << endl;
    }
//    a b是斐波那契的n-1和n项
    string ans = divide(a, b);
    cout << ans << endl;
    cout << ans.length()-2 << endl;
    return 0;
}



