package com.sun1f.base;

public class Demo1 {
    public static void main(String[] args) {
        // 八大基本数据类型
        int num1 = 10;
        byte num2 = 20;
        short num3 = 30;
        long num4 = 40L;

        float num5 = 50.4F;
        double pi = 3.1415926;

        char name = 'A';
        // String 不是关键字
        String namea = "sun1f";

        boolean flag = true;
        boolean flag2 = false;

        // 0开头是八进制，0x开头是十六进制
        int i = 10;
        int i2 = 010;
        int i3 = 0x10;

        System.out.println(i);
        System.out.println(i2);
        System.out.println(i3);

        // 最好避免使用浮点数进行比较
        float f1 = 0.1f;
        double d = 1.0 / 10;
        System.out.println(f1 == d); // false

        float f2 = 232334234324234F;
        float f3 = f2 + 1;
        System.out.println(f2 == f3); // true

        System.out.println("-------------------------");
        String s1  = "hello world";
        String s2 = "hello world";
        System.out.println(s1 == s2); // true

        String s3 = new String("hello world");
        String s4 = new String("hello world");
        System.out.println(s3 == s4); // false
    }
}
