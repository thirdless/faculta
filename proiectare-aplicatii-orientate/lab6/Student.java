package com.company;

class Student implements Comparable<Student>{

    protected String name;
    protected int age;
    protected int grade;

    public Student(){
        name = "Generic";
        age = 20;
        grade = 10;
    }

    public Student(String name, int age, int grade){
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    public Student(Student s){
        name = s.name;
        age = s.age;
        grade = s.grade;
    }

    public String GetName(){
        return name;
    }

    public int GetAge(){
        return age;
    }

    public int GetGrade(){
        return grade;
    }

    @Override
    public String toString() {
        return "Nume: " + name + "; Varsta: " + age + "; Nota: " + grade + "\n";
    }

    @Override
    public Student clone(){
        return new Student(this);
    }

    @Override
    public int compareTo(Student student, int type) {
        if(type == 1){
            // name
            return name.compareTo(student.name);
        }
        else if(type == 2){
            //age
            if(age > student.age) return 1;
            else if(age == student.age) return 0;
            else return -1;
        }
        else if(type == 3){
            // grade
            if(grade > student.grade) return 1;
            else if(grade == student.grade) return 0;
            else return -1;
        }
        else{
            // order by name, then age, then grade
            if(name.equals(student.name)){
                if(age == student.age){
                    if(grade == student.grade) return 0;
                    else if(grade > student.grade) return 1;
                    else return -1;
                }
                else{
                    if(age > student.age) return 1;
                    else return -1;
                }
            }
            else return name.compareTo(student.name);
        }
    }
}