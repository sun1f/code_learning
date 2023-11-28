package com.oop.demo5;

public class Student extends Person {

    private String name = "syf";

    public void test(String name) {
        System.out.println(name);
        System.out.println(this.name);
        // super 可以调用父类的属性和方法（仅public和protected）
        System.out.println(super.name);
    }
}
