package com.sun1f.scanner;

import java.util.Scanner;

public class Demo1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner((System.in));

        System.out.println("请输入");

        if(scanner.hasNext()) {
           /* String str = scanner.next();*/

            String str = scanner.nextLine();
            System.out.println("输出内容为：" + str);
        }



        scanner.close();
    }
}
