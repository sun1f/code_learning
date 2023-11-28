package com.sun1f.scanner;

import java.util.Scanner;

public class Demo2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int i = 0;
        float f = 0.0F;

        System.out.println("请输入整数：");

        if(scanner.hasNextInt()) {
            System.out.println(scanner.nextInt());
        }
        else {
            System.out.println("输入的不是整数！");
        }

        System.out.println("请输入小数");

        if(scanner.hasNextFloat()) {
            System.out.println(scanner.nextFloat());
        }
        else {
            System.out.println("输入的不是小数！");
        }


        scanner.close();
    }
}
