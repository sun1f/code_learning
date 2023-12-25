package com.test;

public class Demo1 {
    public static String getValidString(int n, int a, int b) {
        if (n != a + b - 1 || n > a * b) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        char[] chars = new char[]{'r', 'e', 'd'};

        int count = Math.min(a, b);

        for (int i = 0; i < n; i++) {
            if (i < count - 1 || (i % count == count - 1 && i < a - 1)) {
                result.append(chars[1]);  // 插入字符 'e'
            } else {
                result.append(chars[i % 3]);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        System.out.println(getValidString(7, 3, 2));
    }
}
