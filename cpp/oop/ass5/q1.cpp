#include <iostream>
#include <fstream>

using namespace std;

class Employee {
public:
    string name;
    int employeeID;
    double salary;

    Employee(const string& n, int id, double sal) : name(n), employeeID(id), salary(sal) {}
};

class EmployeeDatabase {
public:
    static void addEmployee(const Employee& emp) {
        ofstream outFile("employees.txt", ios::app); 
        if (outFile.is_open()) {
            outFile << emp.name << " " << emp.employeeID << " " << emp.salary << endl;
            cout << "Employee added successfully." << endl;
            outFile.close(); // Close the file
        } else {
            cerr << "Unable to open the file." << endl;
        }
    }

    static void displayEmployees() {
        ifstream inFile("employees.txt");
        if (inFile.is_open()) {
            string name;
            int id;
            double salary;

            cout << "Employee Details:" << endl;
            while (inFile >> name >> id >> salary) {
                cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
            }

            inFile.close();
        } else {
            cerr << "Unable to open the file." << endl;
        }
    }
};

int main() {
    int choice;

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            double salary;

            cout << "Enter employee details:\n";
            cout << "Name: ";
            cin.ignore(); 
            getline(cin, name);

            cout << "ID: ";
            cin >> id;

            cout << "Salary: ";
            cin >> salary;

            Employee emp(name, id, salary);
            EmployeeDatabase::addEmployee(emp);
        } else if (choice == 2) {
            EmployeeDatabase::displayEmployees();
        } else if (choice == 3) {
            cout << "Exiting the program.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
