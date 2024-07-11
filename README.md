# Student Attendance Management System

This project is a console-based application developed in C++ that manages student attendance. It includes functionalities for both students and administrators to interact with the system. The project consists of several functions to handle registration, login, attendance marking, and report viewing.

**allStudentRegisterLog** - This directory stores all student's data, deleted and existing.
**studentDATA** - This directory stores only existing student's data, in this folder (StudentData.csv) file the existing student's usernames and passwords
---
# Features

1. **Register Students**
2. **Check Student Credentials**
3. **Student View**
4. **View My Attendance Report**
5. **Admin View**
6. **Student Login**
7. **Admin Login**
8. **Delay**
9. **Delete All Students**
10. **View Student Attendance Report by Username**
11. **Check List of Students Registered**
12. **Delete Student by Username**
13. **Mark Student Attendance**
14. **Count Student Attendance**
15. **View Attendance Count to Admin**
16. **Student Counter**
17. **Check if Student Already Exists**

# Function Descriptions

### 1. Register_students
```
int Register_students();
```
Registers a new student in the system. It collects necessary details and stores them for future reference.

### 2. checkStudentCredentials
```cpp
int checkStudentCredentials(string username, string password);
```
Validates the provided username and password against the stored credentials to authenticate a student.

### 3. studentView
```cpp
int studentView();
```
Displays the student dashboard where students can perform various actions like viewing their attendance report.

### 4. viewMyAttendanceReport
```cpp
int viewMyAttendanceReport(string username);
```
Allows students to view their own attendance report based on their username.

### 5. adminView
```cpp
int adminView();
```
Displays the admin dashboard where administrators can manage student data and view attendance reports.

### 6. studentLogin
```cpp
int studentLogin();
```
Handles the login process for students, verifying their credentials and granting access to their dashboard.

### 7. adminLogin
```cpp
int adminLogin();
```
Handles the login process for administrators, verifying their credentials and granting access to the admin dashboard.

### 8. delay
```cpp
int delay();
```
Introduces a delay in the system, typically used to create a pause or wait for user input.

### 9. deleteAllStudents
```cpp
int deleteAllStudents();
```
Deletes all student records from the system, effectively resetting the student database.

### 10. viewStudentAttendanceReportbyUsername
```cpp
int viewStudentAttendanceReportbyUsername();
```
Allows the admin to view the attendance report of a specific student by entering their username.

### 11. checkListOfStudentsRegistered
```cpp
int checkListOfStudentsRegistered();
```
Displays a list of all registered students in the system.

### 12. deleteStudentbyusername
```cpp
int deleteStudentbyusername();
```
Deletes a specific student from the system based on their username.

### 13. markstudentattendance
```cpp
int markstudentattendance(string username);
```
Marks the attendance for a student based on their username.

### 14. countStudentAttendance
```cpp
int countStudentAttendance(string username);
```
Counts and returns the total number of attendance entries for a specific student.

### 15. viewAttendancecountToadmin
```cpp
int viewAttendancecountToadmin();
```
Allows the admin to view the total attendance count of all students.

### 16. studentCounter
```cpp
int studentCounter();
```
Counts and returns the total number of registered students in the system.

### 17. student_isAlreadyExist
```cpp
int student_isAlreadyExist(string username);
```
Checks if a student with the given username already exists in the system.

## Getting Started

### Prerequisites
- C++ compiler
- Basic understanding of C++ programming

### Installation
1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/StudentAttendanceManagement.git
    ```
2. Navigate to the project directory:
    ```sh
    cd StudentAttendanceManagement
    ```
3. Compile the program:
    ```sh
    g++ main.cpp -o AttendanceSystem
    ```

### Usage
1. Run the compiled program:
    ```sh
    ./AttendanceSystem
    ```
2. Follow the on-screen instructions to navigate through the system.

## Contributing
1. Fork the repository
2. Create your feature branch:
    ```sh
    git checkout -b feature/YourFeature
    ```
3. Commit your changes:
    ```sh
    git commit -m 'Add some feature'
    ```
4. Push to the branch:
    ```sh
    git push origin feature/YourFeature
    ```
5. Open a pull request

## Contact
Your Name - Omkar Tipugade [ omtipugade3904@gmail.com ]

---

Feel free to customize this README file further based on your specific project details and preferences!
