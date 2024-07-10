// modified 18/05/2023 -> admin password replaced by stars

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>

using namespace std;

/* The class StudentAttendanceManagement contains methods for registering students, managing student
and admin logins, marking attendance, and generating attendance reports. */
class StudentAttendanceManagement
{
public:
    int Register_students();
    int checkStudentCredentials(string username, string password);
    int studentView();
    int viewMyAttendanceReport(string username);
    int adminView();
    int studentLogin();
    int adminLogin();
    int delay();
    int deleteAllStudents();
    int viewStudentAttendanceReportbyUsername();
    int checkListOfStudentsRegistered();
    int deleteStudentbyusername();
    int markstudentattendance(string username);
    int countStudentAttendance(string username);
    int viewAttendancecountToadmin();
    int studentCounter();
    int student_isAlreadyExist(string username);
};

/**
 * This function checks if a given student username already exists in a CSV file.
 *
 * username A string variable representing the username of a student.l;'
 *
 * @return an integer value. If the given username is found in the "StudentData.csv" file, it returns 1
 * indicating that the student already exists. If the username is not found or if there is an error in
 * opening the file, it returns 0 indicating that the student does not exist.
 */
int StudentAttendanceManagement ::student_isAlreadyExist(string username)
{
    ifstream read;
    read.open("studentDATA\\StudentData.csv", ios::app);

    if (read)
    {
        // The file exists, and is open for input
        int recordFound = 0;
        string line, passline;
        string temp = username;
        while (getline(read, line))
        {
            if (line == temp)
            {
                recordFound = 1;
                break;
            }
        }

        if (recordFound == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}
/**
 * The function allows a admin to login and access options to view their attendance report, count
 * their attendance, and mark their attendance.
 *
 * @return an integer value, which is either 0 or 1. If the student's credentials are invalid, the
 * function returns 0. If the credentials are valid, the function displays a menu and waits for the
 * user to make a choice. The function returns 1 if the user chooses to go back to the main menu.
 */
int StudentAttendanceManagement ::studentCounter()
{
    system("cls");
    cout << "\n ------- STUDENT LOGIN -------- \n";

    string username, password;

    cout << "\n Enter username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >> password;

    int res = checkStudentCredentials(username, password);

    if (res == 0)
    {
        cout << "\n Invalid Credentials !!";
        cout << "\n Press any key for Main Menu..";
        cout << "\nPress any key to continue..." << endl;
        getch();
        system("cls");
        return 0;
    }
    else if (res == 1)
    {
        int choice;
        int goBack = 0;
        while (1)
        {
            system("cls");
            cout << "\n******* STUDENT COUNTER *******\n";
            cout << "---------------------------------\n";
            cout << "\n 1. view student attendance report";
            cout << "\n 2. view student attendance count";
            cout << "\n 3. mark student attendance";
            cout << "\n 0. Go Back <- \n";

            cout << "\n Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                viewMyAttendanceReport(username);
                break;
            case 2:
                countStudentAttendance(username);
                break;
            case 3:
                markstudentattendance(username);
                break;
            case 0:
                goBack = 1;
                break;
            default:
                cout << "\n Invalid choice. Enter again ";
                getch();
            }

            if (goBack == 1)
            {
                delay();
                break; // break the loop
            }
        }
    }
}

/**
 * This function counts the number of present, absent, and tardy days for a student based on their
 * attendance data stored in a CSV file.
 *
 *  username a string variable representing the username of the student whose attendance is being
 * counted.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::countStudentAttendance(string username)
{
    ifstream file;
    file.open("studentDATA\\" + username + ".csv");
    if (file.fail())
    {
        cout << "File failed to open..." << endl;
        return 1;
    }
    char ch;
    int present = 0, absent = 0, late = 0;
    while (!file.eof())
    {
        /* code */
        file.get(ch);
        if (ch == 'P')
        {
            present++;
        }
        else if (ch == 'A')
        {
            absent++;
        }
        else if (ch == 'L')
        {
            late++;
        }
    }

    file.close();
    cout << "\nPresent days : " << present << "\n"
         << "Absent days : " << absent << endl;
    cout << "late days : " << late << endl;
    int total = present + absent + late;
    cout << "Total days : " << total << endl;
    cout << "\nPress any key to continue..." << endl;
    getch();
    system("cls");

    return 0;
}
/**
 * The function allows a user to mark the attendance of a Sdent and saves it in a CSV file.
 *
 * username The username of the student whose attendance is being marked.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::markstudentattendance(string username)
{
    system("cls");
    cout << "------- MARK STUDENT ATTENDANCE -------" << endl;
    cout << "------------------------------------------\n";
    ofstream out;
    char ch;
    out.open("studentDATA\\" + username + ".csv", ios::app);
    string date;
    cout << "\nIf student is present -> P ,absent -> A , or late -> L\n";
    cout << "Mark attendance using capital letters\n";
    cout << "\nEnter date ( DD/MM/YYYY ) : ";
    cin >> date;
    cout << "\nMark attendance of student ( P / A / L ): ";
    cin >> ch;
    out << date << " : " << ch << "\n";
    cout << "\nPress any key to continue..." << endl;
    getch();
    system("cls");
    return 0;
}
/**
 * This function deletes a student's data from a CSV file based on their username and password line
 * numbers.
 *
 * @return an integer value, which is either 0 or 1.
 */
int StudentAttendanceManagement ::deleteStudentbyusername()
{
    string filename;
    int lineNumber;
    int passlineNumber;
    system("cls");
    cout << "\nRefer StudentData.cvs file in the studentDATA folder for the\nPassword line number and username line number\n\n";
    for (int i = 1; i <= 2; i++)
    {
        if (i == 1)
        {
            cout << "Enter password -> line number : ";
            cin >> lineNumber;
        }
        if (i == 2)
        {
            cout << "Enter username -> line number : ";
            cin >> passlineNumber;
        }
        fstream read_file;
        read_file.open("studentDATA\\StudentData.csv");

        if (read_file.fail())
        {
            cout << "Error opening file..." << endl;
            return 1;
        }
        vector<string> lines;
        string line;

        while (getline(read_file, line))
            lines.push_back(line);

        read_file.close();

        if (lineNumber < line.size() && passlineNumber < line.size())
        {
            cout << "line number : " << lineNumber << endl;
            cout << "not found in file..." << endl;

            cout << "file has " << lines.size() << " lines." << endl;
            return 1;
        }
        ofstream write_file;
        write_file.open("studentDATA\\StudentData.csv");
        if (write_file.fail())
        {
            cout << "Error opening file..." << endl;
            return 1;
        }
        lineNumber--;
        passlineNumber--;
        for (int i = 0; i < lines.size(); i++)
            if (i != lineNumber && i != passlineNumber)
                write_file << lines[i] << endl;

        write_file.close();
    }
    cout << "\nPress any key to continue..." << endl;
    getch();
    system("cls");
    return 0;
}
/**
 * The function displays the contents of a CSV file containing student data and prompts the user to
 * continue.
 */
int StudentAttendanceManagement ::checkListOfStudentsRegistered()
{
    system("cls");
    cout << "Note :-\n\tIn file first line contains username , and\n\tnext line contains password of it , respectively\n";
    ifstream file;
    file.open("studentDATA\\StudentData.csv");
    stringstream buffer;
    buffer << file.rdbuf();
    string file_contents;
    file_contents = buffer.str();
    cout << "\n"
         << file_contents;
    file.close();
    cout << "\nPress any key to continue..." << endl;
    getch();
    system("cls");
}

/**
 * The function deletes all student data from the system.
 */
int StudentAttendanceManagement ::deleteAllStudents()
{
    system("cls");

    int r = system("del studentDATA");
    cout << "\n";
    for (int i = 0; i < 1; i++)
    {
        if (r = 1)
        {
            break;
        }
    }
}
/**
 * The function "delay" creates a delay by running nested loops.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::delay()
{
    for (int i = 0; i < 1; i++)
    {
        cout << "\n Saving Records ...";
        for (int j = 0; j < 20000; j++)
        {
            for (int k = 0; k < 20000; k++)
            {
            }
        }
    }

    cout << "\n Exiting Now ...";
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 20000; j++)
        {
            for (int k = 0; k < 20000; k++)
            {
            }
        }
    }

    return 0;
}
/**
 * This function registers students by taking their information and storing it in CSV files.
 */
int StudentAttendanceManagement ::Register_students()
{
    system("cls");
    typedef struct registerStudent
    {
        /* data */
        string username;
        string password;
        string stname;
        string fatherName;
        string surName;
        string birthDate;
        string stdYear;
        string semester;
        int rollno;
        long int prnNo;
    } streg;
    int already_Exist;
    cout << "\n##**## REGISTER STUDENTS ##**##" << endl;
    cout << "------------------------------------------------\n";
    int size;
    cout << "\n";
    cout << "Enter how many students you want to register : ";
    cin >> size;
    streg st[size];
    cout << "\n";
    cout << "fill the all data using the small letters" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\n";
        cout << "Enter student username : ";
        cin >> st->username;
        already_Exist = student_isAlreadyExist(st->username);
        if (already_Exist == 1)
        {
            cout << "\nUser already exists . Please enter a new username..." << endl;
            cout << "\nPress any key to continue..." << endl;
            getch();
            system("cls");
            break;
        }
        else
        {
            cout << "Enter student password : ";
            cin >> st->password;
            cout << "Enter student name : ";
            cin >> st->stname;
            cout << "Enter student father name : ";
            cin >> st->fatherName;
            cout << "Enter student sur name : ";
            cin >> st->surName;
            cout << "Enter student birth date ( DD/MM/YYYY ): ";
            cin >> st->birthDate;
            cout << "Enter studying year : ";
            cin >> st->stdYear;
            cout << "Enter student semester : ";
            cin >> st->semester;
            cout << "Enter student roll number : ";
            cin >> st->rollno;
            cout << "Enter student PRN number : ";
            cin >> st->prnNo;

            ofstream out("studentDATA\\StudentData.csv", ios::app);
            out << st->username << "\n";
            out << st->password << "\n";
            out.close();

            ofstream out1("studentDATA\\" + st->username + ".csv", ios::app);

            out1 << "first name : " << st->stname << "\n";
            out1 << "middle name : " << st->fatherName << "\n";
            out1 << "last name : " << st->surName << "\n";
            out1 << "studying year : " << st->stdYear << "\n";
            out1 << "birth date : " << st->birthDate << "\n";
            out1 << "semester : " << st->semester << "\n";
            out1 << "roll no. : " << st->rollno << "\n";
            out1 << "prn no. : " << st->prnNo << "\n";
            out1.close();

            ofstream out2("allStudentRegisterLog\\" + st->username + ".csv", ios::app);
            out2 << "first name : " << st->stname << "\n";
            out2 << "middle name : " << st->fatherName << "\n";
            out2 << "last name : " << st->surName << "\n";
            out2 << "studying year : " << st->stdYear << "\n";
            out2 << "birth date : " << st->birthDate << "\n";
            out2 << "semester : " << st->semester << "\n";
            out2 << "roll no. : " << st->rollno << "\n";
            out2 << "prn no. : " << st->prnNo << "\n";
            out2.close();
        }
        delay();
    }
}

/**
 * This function checks if a given username and password exist in a CSV file and returns 1 if found, 0
 * if not found.
 *
 * username A string representing the username of the student whose credentials need to be
 * checked.
 *
 * password The password string that needs to be checked for authentication.
 *
 * @return an integer value of 1 if the given username and password match with any record in the
 * "StudentData.csv" file, and returns 0 if either the file does not exist or the given credentials do
 * not match with any record in the file.
 */
int StudentAttendanceManagement ::checkStudentCredentials(string username, string password)
{
    // read file line by line & check if username-password.dat exist?
    // if it exsist return 1 else 0

    ifstream read;
    read.open("studentDATA\\StudentData.csv", ios::app);

    if (read)
    {
        // The file exists, and is open for input
        int recordFound = 0;
        string line, passline;
        string temp = username;
        string temppass = password;
        while (getline(read, line) && getline(read, passline))
        {
            if (line == temp && passline == temppass)
            {
                recordFound = 1;
                break;
            }
        }

        if (recordFound == 0)
            return 0;
        else
            return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * The function allows a student to login and view their attendance report or count.
 *
 * @return an integer value.
 */
int StudentAttendanceManagement ::studentView()
{
    cout << "\n ------- STUDENT LOGIN -------- \n";

    string username, password;

    cout << "\n Enter username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >>password;
    
    int res = checkStudentCredentials(username, password);

    if (res == 0)
    {
        cout << "\n Invalid Credentials !!";
        cout << "\n Press any key for Main Menu..";
        cout << "\nPress any key to continue..." << endl;
        getch();
        return 0;
    }

    int goBack = 0;
    while (1)
    {
        system("cls");

        cout << "\n 1. view my attendance report";
        cout << "\n 2. view my attendance count";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewMyAttendanceReport(username);

            break;
        case 2:
            countStudentAttendance(username);

            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again ";
            getch();
        }

        if (goBack == 1)
        {
            break; // break the loop
        }
    }
}

/**
 * This function reads and displays the attendance report of a student from a CSV file.
 *
 * username a string variable that represents the username of the student whose attendance
 * report is to be viewed.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::viewMyAttendanceReport(string username)
{
    ifstream file;
    file.open("studentDATA\\" + username + ".csv", ios::app);
    stringstream buffer;
    buffer << file.rdbuf();
    string file_contents;
    file_contents = buffer.str();
    cout << "\n\n"
         << file_contents;
    file.close();
    // todo: implement this functionality

    cout << "\nPress any key to continue..." << endl;
    getch();
    system("cls");

    return 0;
}

/**
 * The function adminLogin() prompts the user to enter a username and password, and if the credentials
 * match, it displays the admin view, otherwise it displays an error message.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::adminLogin()
{
    char ch;
    system("cls");
    cout << "\n --------- ADMIN LOGIN --------";
    cout << "\n ---------------------------------\n";

    string username;
    string password="mypro@2023";
    string pass;
    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    ch=_getch();

    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    if (username == "mypro@2023" && pass == password)
    {
        adminView();
        getch();
        delay();
    }
    else
    {
        cout << "\n Error ! Invalid Credintials..";
        cout << "\n Press any key for main menu " << endl;
        getch();
    }

    return 0;
}

/**
 * The function displays a menu of options for an admin to manage student attendance and performs the
 * selected action.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::adminView()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1. Register Students";
        cout << "\n 2. Delete All students name registered";
        cout << "\n 3. delete student by userame";
        cout << "\n 4. Check list of students username registered";
        cout << "\n 5. Student counter";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Register_students();
            break;
        case 2:
            deleteAllStudents();
            break;
        case 3:
            deleteStudentbyusername();
            break;
        case 4:
            checkListOfStudentsRegistered();
            break;
        case 5:
            studentCounter();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again ";
            getch();
        }

        if (goBack == 1)
        {
            break; // break the loop
        }
    }

    return 0;
}

/**
 * This function clears the console screen, displays the student view, introduces a delay, and returns
 * 0.
 *
 * @return an integer value of 0.
 */
int StudentAttendanceManagement ::studentLogin()
{
    system("cls");
    studentView();
    return 0;
}

/**
 * The function presents a menu for a student attendance management system and allows the user to
 * choose between student login, admin login, or exit.
 *
 * @return The main function is returning an integer value of 0.
 */
int main()
{
    StudentAttendanceManagement out;
    while (1)
    {
        system("cls");
        cout << "##**## << STUDENT ATTENDANCE MANAGEMENT SYSTEM >> ##**##\n";
        cout << "----------------------------------------------------------\n";
        cout << "\nInstructions :-\n\t1. fill all the information correctly and carefully\n\t2. "
                "Give all the inputs in correct order\n\n";
        cout << "1. Student Login\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";
        int choice;

        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            out.studentLogin();
            break;
        case 2:
            out.adminLogin();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\n Are you sure, you want to exit? y | n \n";
                char ex;
                cout << "\n Enter your choice: ";
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                    exit(0);
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\n Invalid choice !!!";
                    cout << "\nPress any key to continue..." << endl;
                    getch();
                }
            }
            break;

        default:
            cout << "\n Invalid choice. Enter again ";
            cout << "\nPress any key to continue..." << endl;
            getch();
        }
    }
    return 0;
}