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
            System.out.println(n1.add(n2));//�ӷ�
            System.out.println(n1.subtract(n2));//����
            System.out.println(n1.multiply(n2));//�˷�
            System.out.println(n1.divide(n2));//����(���ȡ��)
            System.out.println(n1.mod(n2));//ȡ��
            System.out.println(n1.gcd(n2));//���Լ��GCD
            System.out.println(n1.abs());//ȡ����ֵ
            System.out.println(num1.negate());//ȡ��
            System.out.println(num1.max(num2));//ȡ���ֵ
            System.out.println(num1.min(num2));//ȡ��Сֵ
            System.out.println(num1.equals(num2));//�Ƿ����
            System.out.println(num1.add(num2));//�ӷ�
            System.out.println(num1.subtract(num2));//����
            System.out.println(num1.multiply(num2));//�˷�
            System.out.println(num1.divide(num2,10,BigDecimal.ROUND_HALF_DOWN));//��������divide��ʱ������ú�Ҫ��ȷ��С��λ��������ģʽ��
            System.out.println(num1.abs());//ȡ����ֵ
            System.out.println(num1.negate());//ȡ��
            System.out.println(num1.max(num2));//ȡ���ֵ
            System.out.println(num1.min(num2));//ȡ��Сֵ
            System.out.println(num1.equals(num2));//�Ƿ����
            System.out.println(num2.compareTo(num1));//�жϴ�С( > ����1, < ����-1)
        }
    }
}
