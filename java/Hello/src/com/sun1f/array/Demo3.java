package com.sun1f.array;

import java.util.Arrays;

public class Demo3 {
    public static void main(String[] args) {
       int a[] = {1, 2, 3, 5, 6, 7, 2, 34, 23};

        System.out.println(a);
        // println打印带回车换行
        System.out.println(Arrays.toString(a));
        printArray(a);

        Arrays.sort(a);
        printArray(a);

        Arrays.fill(a, 2, 4, 0);
    }

    public static void printArray(int[] a) {
        System.out.print('[');
        for(int i = 0; i < a.length; ++i) {
            if(i == a.length - 1) {
                System.out.print(a[i]);
            }
            else {
                System.out.print(a[i] + ", ");
            }
        }
        System.out.println(']');
    }
}
