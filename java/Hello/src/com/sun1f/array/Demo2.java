package com.sun1f.array;

public class Demo2 {
    public static void main(String[] args) {
        // 静态初始化：创建 + 赋值
        int[] a = {1, 2, 4, 5};
        Man[] man = {new Man(), new Man()};

        // 动态初始化：包含默认初始化
        int[] b = new int[10];
        b[0] = 10;

        System.out.println(b[0]);
        System.out.println(b[1]);
    }
}
