#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Book
{
    string name;
    string author;
    string genre;
    string status;
};

struct User
{
    string name;
    string book;
    string issue;
    string returndate;
};

map<string, Book> books;
map<string, User> users;

void Add()
{
    Book b;
    string code;

    cout << "Enter book code: ";
    cin >> code;
    cin.ignore();
    cout << "Enter book's name: ";
    getline(cin, b.name);
    cout << "Enter author's name: ";
    getline(cin, b.author);
    cout << "Enter book's genre: ";
    getline(cin, b.genre);
    b.status = "available";
    books[code] = b;
    cout << "Book added successfully!" << endl;
}

void Issue()
{
    string code;
    cout << "Enter code of issued book: ";
    cin >> code;

    if (books.find(code) != books.end())
    {
        if (books[code].status == "available")
        {
            User u;
            string ino;
            cout << "Enter issue number: ";
            cin >> ino;
            cin.ignore();
            cout << "Enter user's name: ";
            getline(cin, u.name);
            u.book = code;
            cout << "Enter date of issue: ";
            getline(cin, u.issue);
            u.returndate = "";
            books[code].status = "unavailable";
            users[ino] = u;
            cout << "Book issued successfully!" << endl;
        } 
        else
        {
            cout << "Book unavailable!" << endl;
        }
    }
    else 
    {
        cout << "Book not found!" << endl;
    }
}

void Return()
{
    string ino;
    cout << "Enter issue number: ";
    cin >> ino;
    if (users.find(ino) != users.end())
    {
        cout << "Enter date of return: ";
        cin.ignore();
        getline(cin, users[ino].returndate);
        string code = users[ino].book;
        books[code].status = "available";
        cout << "Book returned successfully!" << endl;
    }
    else
    {
        cout << "Issue number not found!" << endl;
    }
}

void Search()
{
    int option;
    cout << "Press 1 to search by book's name, 2 to search by author's name, 3 to search by book's genre: ";
    cin >> option;
    cin.ignore();
    string s;
    bool found = false;
    switch (option)
    {
        case 1:
            cout << "Enter book's name: ";
            getline(cin, s);
            for (const auto& pair : books)
            {
                const Book& book = pair.second;
                if (book.name == s)
                {
                    cout << "Book found!" << endl;
                    cout << "Code: " << pair.first << endl;
                    cout << "Name: " << book.name << endl;
                    cout << "Author: " << book.author << endl;
                    cout << "Genre: " << book.genre << endl;
                    cout << "Status: " << book.status << endl;
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        case 2:
            cout << "Enter author's name: ";
            getline(cin, s);
            for (const auto& pair : books)
            {
                const Book& book = pair.second;
                if (book.author == s)
                {
                    cout << "Book found!" << endl;
                    cout << "Code: " << pair.first << endl;
                    cout << "Name: " << book.name << endl;
                    cout << "Author: " << book.author << endl;
                    cout << "Genre: " << book.genre << endl;
                    cout << "Status: " << book.status << endl;
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        case 3:
            cout << "Enter genre: ";
            getline(cin, s);

            for (const auto& pair : books)
            {
                const Book& book = pair.second;
                if (book.genre == s)
                {
                    cout << "Book found!" << endl;
                    cout << "Code: " << pair.first << endl;
                    cout << "Name: " << book.name << endl;
                    cout << "Author: " << book.author << endl;
                    cout << "Genre: " << book.genre << endl;
                    cout << "Status: " << book.status << endl;
                    found = true;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        default:
            cout << "Invalid option!" << endl;
    }
}

void Modify()
{
    string code;
    cout << "Enter book's code: ";
    cin >> code;
    if (books.find(code) != books.end())
    {
        int option;
        cout << "Press 1 to change book's name, 2 to change author's name, 3 to change book's genre: ";
        cin >> option;
        cin.ignore();
        string s;

        switch (option)
        {
            case 1:
                cout << "Enter updated name: ";
                getline(cin, s);
                books[code].name = s;
                cout << "Book's name updated successfully!" << endl;
                break;
            case 2:
                cout << "Enter updated author's name: ";
                getline(cin, s);
                books[code].author = s;
                cout << "Author's name updated successfully!" << endl;
                break;
            case 3:
                cout << "Enter updated genre: ";
                getline(cin, s);
                books[code].genre = s;
                cout << "Book's genre updated successfully!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    }
    else
    {
        cout << "Book not found!" << endl;
    }
}

void DisplayBooks()
{
    if (books.empty())
    {
        cout << "No books available!" << endl;
        return;
    }
    cout << "Books:" << endl;
    for (const auto& pair : books)
    {
        const Book& book = pair.second;
        cout << "Code: " << pair.first << endl;
        cout << "Name: " << book.name << endl;
        cout << "Author: " << book.author << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "Status: " << book.status << endl;
        cout << endl;
    }
}

void DisplayUsers()
{
    if (users.empty()) 
    {
        cout << "No users found!" << endl;
        return;
    }
    cout << "Users:" << endl;
    for (const auto& pair : users)
    {
        const User& user = pair.second;
        cout << "Issue Number: " << pair.first << endl;
        cout << "Name: " << user.name << endl;
        cout << "Book Code: " << user.book << endl;
        cout << "Date of Issue: " << user.issue << endl;
        cout << "Date of Return: " << user.returndate << endl;
        cout << endl;
    }
}

void Delete()
{
    string code;
    cout << "Enter book's code: ";
    cin >> code;
    if (books.find(code) != books.end())
    {
        books.erase(code);
        cout << "Book removed successfully!" << endl;
    }
    else
    {
        cout << "Book not found!" << endl;
    }
}

int main()
{
    int choice;

    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Search Book" << endl;
        cout << "5. Modify Book" << endl;
        cout << "6. Delete Book" << endl;
        cout << "7. Display All Books" << endl;
        cout << "8. Display All Users" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                Add();
                break;
            case 2:
                Issue();
                break;
            case 3:
                Return();
                break;
            case 4:
                Search();
                break;
            case 5:
                Modify();
                break;
            case 6:
                Delete();
                break;
            case 7:
                DisplayBooks();
                break;
            case 8:
                DisplayUsers();
                break;
            case 9:
                cout << "Exiting system." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
        cout << endl;
    }
}