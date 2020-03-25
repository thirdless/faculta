package com.company;

public class Main {

    public static void main(String[] args) {
        StudentClass clasa = new StudentClass(5);
        Consultant[] consultant = {
            new ConsultantOrderByName(),
            new ConsultantOrderByAge(),
            new ConsultantOrderByGrade(),
            new ConsultantPrint()
        };
        Student[] student = {
            new Student("Mihai", 20, 5),
            new Student("Ion", 18, 1),
            new Student("Vasile", 19, 7),
            new Student("Gheorghe", 22, 3),
            new Student("Marian", 21, 9)
        };

        for(int i = 0; i < student.length; i++) clasa.Add(student[i]);
        clasa.Add(consultant);
        clasa.ExecuteOrder(consultant[1]);
        clasa.ExecuteOrder(consultant[3]);
    }
}
