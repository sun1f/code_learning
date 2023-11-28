package com.sun1f.operator;

public class Demo1 {
    public static void main(String[] args) {
        short a = 10;
        int b = 209;
        byte c = 30;
        long d = 4839184912424L;

        System.out.println(a + b + c + d);
        System.out.println(a + b + c);
        System.out.println(a * b * c);
        System.out.println(a / (double)c);

        // Math工具类
        double ans = Math.pow(2, 3);
        System.out.println(ans);
    }
}
