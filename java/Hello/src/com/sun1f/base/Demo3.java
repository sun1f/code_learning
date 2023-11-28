package com.sun1f.base;

public class Demo3 {
    // 类变量 static，final表示常量
    static double salary = 2500;
    static final double PI = 3.14;

    String name;
    int age;

    public static void main(String[] args) {
        // 局部变量
        int i = 10;
        System.out.println(i);

        // 调用name age
        Demo3 demo3 = new Demo3();
        System.out.println(demo3.age);
        System.out.println(demo3.name);
    }

}
