#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int empNumber;
    char empName[50];
    char designation[30];
    int age;
    char address[100];
};

void displayMenu() {
    printf("\n***** Employee Record System *****\n");
    printf("1. Insert new record\n");
    printf("2. Display all records\n");
    printf("3. Delete record(s)\n");
    printf("4. Update record(s)\n");
    printf("5. Display record by Employee Number\n");
    printf("6. Exit\n");
    printf("**********************************\n");
}

void insertRecord(FILE *file, FILE *indexFile) {
    struct Employee employee;

    printf("Enter Employee Number: ");
    scanf("%d", &employee.empNumber);
    fflush(stdin);
    printf("Enter Employee Name: ");
    gets(employee.empName);
    printf("Enter Designation: ");
    gets(employee.designation);
    printf("Enter Age: ");
    scanf("%d", &employee.age);
    fflush(stdin);
    printf("Enter Address: ");
    gets(employee.address);

    fseek(file, 0, SEEK_END);
    fwrite(&employee, sizeof(struct Employee), 1, file);

    fwrite(&employee.empNumber, sizeof(int), 1, indexFile);

    printf("Record inserted successfully!\n");
}

void displayAllRecords(FILE *file) {
    struct Employee employee;

    rewind(file);
    printf("\n***** Employee Records *****\n");
    printf("%-15s%-30s%-20s%-5s%s\n", "Emp Number", "Emp Name", "Designation", "Age", "Address");
    while (fread(&employee, sizeof(struct Employee), 1, file) == 1) {
        printf("%-15d%-30s%-20s%-5d%s\n", employee.empNumber, employee.empName, employee.designation, employee.age, employee.address);
    }
    printf("****************************\n");
}

void deleteRecord(FILE *file, FILE *indexFile) {
    int empNumber;
    printf("Enter Employee Number to delete: ");
    scanf("%d", &empNumber);

    FILE *tempFile = fopen("temp.dat", "wb");
    FILE *tempIndexFile = fopen("tempIndex.dat", "wb");
    if (tempFile == NULL || tempIndexFile == NULL) {
        printf("Error creating temporary files!\n");
        return;
    }

    struct Employee employee;
    int index;

    rewind(file);
    while (fread(&employee, sizeof(struct Employee), 1, file) == 1) {
        if (employee.empNumber != empNumber) {
            fwrite(&employee, sizeof(struct Employee), 1, tempFile);
        }
    }

    rewind(indexFile);
    while (fread(&index, sizeof(int), 1, indexFile) == 1) {
        if (index != empNumber) {
            fwrite(&index, sizeof(int), 1, tempIndexFile);
        }
    }

    fclose(file);
    fclose(indexFile);
    fclose(tempFile);
    fclose(tempIndexFile);

    remove("employee.dat");
    remove("employeeIndex.dat");
    rename("temp.dat", "employee.dat");
    rename("tempIndex.dat", "employeeIndex.dat");

    printf("Record(s) deleted successfully!\n");
}

void updateRecord(FILE *file) {
    int empNumber;
    printf("Enter Employee Number to update: ");
    scanf("%d", &empNumber);

    struct Employee employee;

    rewind(file);
    while (fread(&employee, sizeof(struct Employee), 1, file) == 1) {
        if (employee.empNumber == empNumber) {
            printf("Enter new Employee Name: ");
            fflush(stdin);
            gets(employee.empName);
            printf("Enter new Designation: ");
            gets(employee.designation);
            printf("Enter new Age: ");
            scanf("%d", &employee.age);
            fflush(stdin);
            printf("Enter new Address: ");
            gets(employee.address);

            fseek(file, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&employee, sizeof(struct Employee), 1, file);

            printf("Record updated successfully!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void displayRecordByNumber(FILE *file) {
    int empNumber;
    printf("Enter Employee Number to display: ");
    scanf("%d", &empNumber);

    struct Employee employee;

    rewind(file);
    while (fread(&employee, sizeof(struct Employee), 1, file) == 1) {
        if (employee.empNumber == empNumber) {
            printf("\n***** Employee Record *****\n");
            printf("%-15s%-30s%-20s%-5s%s\n", "Emp Number", "Emp Name", "Designation", "Age", "Address");
            printf("%-15d%-30s%-20s%-5d%s\n", employee.empNumber, employee.empName, employee.designation, employee.age, employee.address);
            printf("****************************\n");
            return;
        }
    }

    printf("Record not found!\n");
}

int main() {
    FILE *file = fopen("employee.dat", "ab+");
    FILE *indexFile = fopen("employeeIndex.dat", "ab+");
    if (file == NULL || indexFile == NULL) {
        printf("Error opening file(s)!\n");
        return 1;
    }

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord(file, indexFile);
                break;
            case 2:
                displayAllRecords(file);
                break;
            case 3:
                deleteRecord(file, indexFile);
                break;
            case 4:
                updateRecord(file);
                break;
            case 5:
                displayRecordByNumber(file);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    fclose(file);
    fclose(indexFile);

    return 0;
}
