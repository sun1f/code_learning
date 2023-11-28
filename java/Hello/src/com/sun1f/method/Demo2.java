package com.sun1f.method;

public class Demo2 {
    public static void main(String[] args) {
        Demo2 demo2 = new Demo2();
        demo2.method(1, 3.3, 5.3, 6.7);
    }

    // 可变参数必须放在形参的最后面
    public static void method(int t, double... d) {
        System.out.println(t);
        int i = 0;
        while(i < d.length) {
            System.out.println(d[i++]);
        }
    }
}
