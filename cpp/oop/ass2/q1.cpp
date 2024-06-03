#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }

    bool operator<(const Book& other) {
        return year < other.year;
    }
        bool operator>(const Book& other) {
        return year > other.year;
    }

    bool operator==(const Book& other) {
        return title == other.title && author == other.author && year == other.year;
    }

    Book operator+(const Book& other) {
        string combinedTitle = title + " and " + other.title;
        return Book(combinedTitle, author, year);
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    string title1, author1, title2, author2;
    int year1, year2;

    cout << "Enter the title of the first book: ";
    cin >> title1;
    cout << "Enter the author of the first book: ";
    cin >> author1;
    cout << "Enter the publication year of the first book: ";
    cin >> year1;

    cout << "Enter the title of the second book: ";
    cin >> title2;
    cout << "Enter the author of the second book: ";
    cin >> author2;
    cout << "Enter the publication year of the second book: ";
    cin >> year2;

    Book book1(title1, author1, year1);
    Book book2(title2, author2, year2);

    if (book1 < book2) {
        cout << book1.getTitle() << " is older than " << book2.getTitle() << "." << endl;
    } else if (book1 > book2) {
        cout << book1.getTitle() << " is newer than " << book2.getTitle() << "." << endl;
    } else {
        cout << book1.getTitle() << " and " << book2.getTitle() << " were published in the same year." << endl;
    }

    Book combinedBook = book1 + book2;
    cout << "Combined Title: " << combinedBook.getTitle() << endl;

    cout << "\nBook 1 Information:" << endl;
    book1.display();
    cout << "\nBook 2 Information:" << endl;
    book2.display();

    return 0;
}
