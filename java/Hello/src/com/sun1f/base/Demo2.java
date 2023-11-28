package com.sun1f.base;

public class Demo2 {
    public static void main(String[] args) {
        // JDK7新特性，数字之间可以用下划线分隔
        int money = 10_0000_0000;
        int year = 20;
        int total = money * year;
        long total2 = money * year;

        long total3 = money * ((long)year);

        System.out.println(total); // -1474836480
        System.out.println(total2); // -1474836480
        System.out.println(total3); // 20000000000
    }
}
