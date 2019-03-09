import java.math.BigDecimal;
import java.math.RoundingMode;

public class ans {
    public static int n = 500;

    public static void main(String[] args) {
        BigDecimal a = new BigDecimal(1);
        BigDecimal b = new BigDecimal(1);
        for (int i = 3; i <= n; i++) {
            BigDecimal tmp = b;
            b = b.add(a);
            a = tmp;
        }
        System.out.println(a.divide(b, 100, RoundingMode.HALF_UP));
    }
}

// 找规律，发现f_n/f_{n-1} f_n 为 fibonacci 数列
// 四舍五入精确到小数点后100位 -> 小数点后101位保持不变（通过改变n的大小查看）

// 0.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375