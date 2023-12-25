package com.test;

public class Demo2 {

    public static int findPassword(String myString) {
        int[] charCount = new int[26];  // 用于统计字符出现的次数
        int questionMarkCount = 0;      // 用于统计问号出现的次数
        int uniqueCharCount = 0;        // 用于统计不同字符的数量

        // 初始化字符计数数组
        for (char c : myString.toCharArray()) {
            if (c == '?') {
                questionMarkCount++;
            } else if (charCount[c - 'a'] == 0) {
                uniqueCharCount++;
            }
            charCount[c - 'a']++;
        }

        int left = 0;    // 滑动窗口的左边界
        int right = 0;   // 滑动窗口的右边界
        int minLength = Integer.MAX_VALUE;

        while (right < myString.length()) {
            char rightChar = myString.charAt(right);

            if (rightChar != '?') {
                charCount[rightChar - 'a']--;

                if (charCount[rightChar - 'a'] == 0) {
                    uniqueCharCount--;
                }
            } else {
                questionMarkCount--;
            }

            // 缩小窗口，直到不再满足条件
            while (uniqueCharCount == 26 || (uniqueCharCount + questionMarkCount == 26 && questionMarkCount > 0)) {
                minLength = Math.min(minLength, right - left + 1);

                char leftChar = myString.charAt(left);

                if (leftChar != '?') {
                    charCount[leftChar - 'a']++;

                    if (charCount[leftChar - 'a'] == 1) {
                        uniqueCharCount++;
                    }
                } else {
                    questionMarkCount++;
                }

                left++;
            }

            right++;
        }

        return (minLength == Integer.MAX_VALUE) ? -1 : minLength;
    }

    public static void main(String[] args) {
        String mystring1 = "abcdefghijklmnopqrstuvwxxxxxyz";

        System.out.println(findPassword(mystring1));
    }
}
