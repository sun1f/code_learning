package com.sun1f.scanner;

import java.util.Scanner;

public class Demo3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入double类型的数字：");

        double sum = 0;

        int count = 0;

        while(scanner.hasNextDouble()) {
            sum += scanner.nextDouble();
            count++;
        }

        double average = sum / count;
        System.out.println("sum is: " + sum + ", count is: " + count + ", average is: " + average);

        scanner.close();
    }
}
