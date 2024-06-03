#include<iostream>
using namespace std;

class Student {
protected:
    int rollno;

public:
    void getnum() {
        cout << "Enter Roll Number: ";
        cin >> rollno;
    }

    void putnum() {
        cout << "Roll Number: " << rollno << endl;
    }
};

class Test : public Student {
protected:
    int marks;

public:
    void getmarks() {
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void putmarks() {
        cout << "Marks: " << marks << endl;
    }
};

class Sports : public Student {
protected:
    int score;

public:
    void getscore() {
        cout << "Enter Sports Score: ";
        cin >> score;
    }

    void putscore() {
        cout << "Sports Score: " << score << endl;
    }
};

class Result : public Test, public Sports {
private:
    int total;

public:
    void calculateTotal() {
        total = marks + score;
    }

    void display() {
        Test::putnum();
        putmarks();
        putscore();
        cout << "Total: " << total << endl;
    }
};

int main() {
    Result studentResult;
    studentResult.Test::getnum();
    studentResult.getmarks();
    studentResult.getscore();
    studentResult.calculateTotal();
    studentResult.display();

    return 0;
}
