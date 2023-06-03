## __Title__  
‘Library Database Management System’

## __Problem Definition__  
This project is designed to create a database management system for a library. It is a menu-driven program with various choices to manipulate the stock of books and the registered users. The main aim of creating this project was to simplify the job of librarians.  
Managing the stocking and issuing of every book in a library is quite a hassle, so the implementation of this program hopes to ease the manual efforts and make it faster.

## __Objectives__  
- To enter the details of a new book added to the database  
- To issue a book to a user  
- To return an issued book back to the database  
- To search for the availability of a book in the library  
- To modify, update or correct the details of a book  
- To delete a book from the database  
- To display the details of the books in the database  

## __Data Dictionary__

### Header files:
- `iostream` - To use `cin`, `cout` for input, output.
- `string` - To create objects of `string` class.
- `map` - To create key-value pair maps.

### Functions:
- `Add()` - To enter the details of a new book added to the database.
- `Issue()` - To issue a book to a user.
- `Return()` - To return an issued book back to the database.
- `Search()` - To search for the availability of a book in the library.
- `Modify()` - To modify, update or correct the details of a book.
- `Delete()` - To delete a book from the database.
- `Display()` - To display the details of the books in the database.
- `Display()` - To display the details of the users in the database.
- `main()` - To execute a switch-cased based infinitely iterative loop for user's choices.

### Structures:
- `Book` - Has `string` attributes `name`, `author`, `genre`, and `status`.
- `User` - Has `string` attributes `name`, `book`, `issue`, `returndate`.

### Maps:
- `books` - Structure type `Book` with global scope.
- `users` - Structure type `User` with global scope.

## __Limitations__  
- File-handling has not been implemented to permanently store the records.
- For a large number of records, searching may take time for data retrieval if the system is of a lower model.
- It is not web-based, thus has no online connectivity.
- It has only basic functionalities and lacks a graphic user interface.
