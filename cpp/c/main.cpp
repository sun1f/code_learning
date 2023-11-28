//
// Created by sun on 2023/11/27.
//

#include "Student.cpp"
#include "People.cpp"

int main() {
    People* person1 = new People();
    People* person2 = new Student();

    person1->speaking();
    person2->speaking();


    return 0;
}
