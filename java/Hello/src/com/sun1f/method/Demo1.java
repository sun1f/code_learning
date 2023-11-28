package com.sun1f.method;

public class Demo1 {
    public static void main(String[] args) {
        // 命令行传递参数
        for (int i = 0; i < args.length; ++i) {
            System.out.println("args[" + i + "]: " + args[i]);
        }
    }
}
