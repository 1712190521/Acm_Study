import java.math.BigInteger;
import java.util.Scanner;
import java.math.BigDecimal;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext()) {
            BigDecimal x=sc.nextBigDecimal();
            BigDecimal a=sc.nextBigDecimal();
            BigDecimal y=sc.nextBigDecimal();
            BigDecimal b=sc.nextBigDecimal();
            if(x.multiply(b).compareTo(y.multiply(a))==1)
                System.out.println(">");
            else if(x.multiply(b).compareTo(y.multiply(a))==-1)
                System.out.println("<");
            else
                System.out.println("=");
            BigInteger x=sc.nextBigInteger();
            System.out.println(n1.add(n2));//加法
            System.out.println(n1.subtract(n2));//减法
            System.out.println(n1.multiply(n2));//乘法
            System.out.println(n1.divide(n2));//除法(相除取整)
            System.out.println(n1.mod(n2));//取余
            System.out.println(n1.gcd(n2));//最大公约数GCD
            System.out.println(n1.abs());//取绝对值
            System.out.println(num1.negate());//取反
            System.out.println(num1.max(num2));//取最大值
            System.out.println(num1.min(num2));//取最小值
            System.out.println(num1.equals(num2));//是否相等
            System.out.println(num1.add(num2));//加法
            System.out.println(num1.subtract(num2));//减法
            System.out.println(num1.multiply(num2));//乘法
            System.out.println(num1.divide(num2,10,BigDecimal.ROUND_HALF_DOWN));//除法（在divide的时候就设置好要精确的小数位数和舍入模式）
            System.out.println(num1.abs());//取绝对值
            System.out.println(num1.negate());//取反
            System.out.println(num1.max(num2));//取最大值
            System.out.println(num1.min(num2));//取最小值
            System.out.println(num1.equals(num2));//是否相等
            System.out.println(num2.compareTo(num1));//判断大小( > 返回1, < 返回-1)
        }
    }
}
