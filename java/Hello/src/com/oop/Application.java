package com.oop;

import com.oop.demo6.Person;
import com.oop.demo6.Student;

public class Application {
    public static void main(String[] args) {
        Person person1 = new Person();
        Person person2 = new Student();
        Student student1 = new Student();

        person1.speaking();
        person2.speaking();

        student1.run();

    }
}
