package com.sun1f.method;

import static java.lang.Math.max;

public class Demo4 {
    public static void main(String[] args) {
        printmax(5, 6.6, 3, 8.6, 10.1);
        printmax(new double[]{1.3, 4.4, 5.5, 3.2, 1.8, 4.5});
    }

    public static void printmax(double... nums) {
        if(nums.length == 0) {
            System.out.println("No argument passed!");
            return;
        }
        double res = nums[0];

        for(double d : nums) {
            res = max(d, res);
        }

        System.out.println("res: " + res);
    }
}
