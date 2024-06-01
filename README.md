# Employee-Management-System

## Overview

Welcome to the Employee Management System! This project is a console-based application designed to manage employee data effectively. Developed during my first semester, this system demonstrates fundamental CRUD (Create, Read, Update, Delete) operations. The project is implemented in a command-line interface, making it straightforward and easy to use. It is purely developed in C language.

## Features

- **Add Employee**: Input employee details such as ID, name, department, and salary to create a new employee record.
- **View Employees**: Display a list of all employees with their respective details.
- **Update Employee**: Modify the details of an existing employee by providing their ID and the updated information.
- **Delete Employee**: Remove an employee's record from the system using their ID.
- **Search Employee**: Find and display information about a specific employee by their ID.

## Installation

To get started with the Employee Management System, follow these steps:

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/employee-management-system.git
    ```
2. **Navigate to the Project Directory**:
    ```bash
    cd employee-management-system
    ```
3. **Compile the Application**:
    ```bash
    gcc employee_management_system.c -o employee_management_system
    ```
4. **Run the Application**:
    ```bash
    ./employee_management_system
    ```

## Usage

Upon running the application, you will be greeted with a menu that offers various options:

1. **Add Employee**
2. **View Employees**
3. **Update Employee**
4. **Delete Employee**
5. **Search Employee**
6. **Exit**

Simply enter the number corresponding to the action you want to perform and follow the on-screen instructions.

## Example

Here is an example of how the application works:

```plaintext
Welcome to Employee Management System
-------------------------------------
1. Add Employee
2. View Employees
3. Update Employee
4. Delete Employee
5. Search Employee
6. Exit

Enter your choice: 1
Enter Employee ID: 101
Enter Employee Name: John Doe
Enter Department: IT
Enter Salary: 60000
Employee added successfully!

Enter your choice: 2
-------------------------------------
ID    Name        Department  Salary
-------------------------------------
101   John Doe    IT          60000
-------------------------------------
```

## Technologies Used

- **Programming Language**: C
- **Database**: In-memory data storage (array) and then on your local storage using file management.
- **Environment**: Command Line Interface (CLI)

## Contributing

Contributions are welcome! If you have any ideas to improve the system or encounter any issues, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Special thanks to my professors and peers for their guidance and support during the development of this project.

---
