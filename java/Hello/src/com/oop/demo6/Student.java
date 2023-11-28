package com.oop.demo6;

import com.oop.demo6.Person;

public class Student extends Person {
    public void speaking() {
        System.out.println("student is speaking...");
    }

    public void run() {
        System.out.println("student is running...");
    }

    /*
    多态注意事项：
    1. 多态是方法的多态，属性没有多态
    2. 父类和子类，有联系，类型转换异常！ ClassCastException
    3. 存在条件：继承关系，方法需要重写，父类引用指向子类对象！ Father f1 = new Son();
        以下三种方法不能重写
           ① static 方法，属于类，它不属于实例
           ② final 常量
           ③ private 方法
     */
}
