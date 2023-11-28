package com.oop.demo2;

// alt + insert 快捷键
public class Student {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Student() {

    }

    public void study() {
        System.out.println(this.name + '.' + this.age + " is studying");
    }
}
