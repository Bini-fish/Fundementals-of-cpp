#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <sstream>
#include <fstream>

using namespace std;
// Photography Booking software
struct Client
{
    string clientName;
    int phoneNumber;
    string appointmentDate;
    string completed;
    string completedDate;
    string url;
};

int numClients;

// checking if the value is a valid date
bool isValidDate(const string &date)
{
    // Extract year, month, and day from the input string
    int year, month, day;
    istringstream ss(date);
    char delimiter;
    if (!(ss >> year >> delimiter >> month >> delimiter >> day))
    {
        return false; // if invalid date format
    }

    // Check if the values are within valid ranges
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }

    // Handle months with 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return day <= 30;
    }

    return true; // Date is valid
}

bool isDateAfter(const string &date1, const string &date2)
{
    int year1, month1, day1;
    int year2, month2, day2;

    istringstream ss1(date1);
    char delimiter;
    ss1 >> year1 >> delimiter >> month1 >> delimiter >> day1;

    istringstream ss2(date2);
    ss2 >> year2 >> delimiter >> month2 >> delimiter >> day2;

    if (year1 < year2)
    {
        return true;
    }
    else if (year1 == year2)
    {
        if (month1 < month2)
        {
            return true;
        }
        else if (month1 == month2)
        {
            if (day1 < day2)
            {
                return true;
            }
        }
    }
    return false;
}

void add_clients(Client *clients, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Enter details for client " << (i + 1) << ":" << endl;

        cout << "Client Name: ";
        cin >> clients[i].clientName;

        cout << "Phone Number: ";
        cin >> clients[i].phoneNumber;

        string tempDate;
        do
        {
            cout << "Appointment Date (YYYY/MM/DD): ";
            cin >> tempDate;
        } while (!isValidDate(tempDate));
        clients[i].appointmentDate = tempDate;

        cout << "Is the task completed? (yes/no): ";
        cin >> clients[i].completed;
        if (clients[i].completed == "yes")
        {
            string tempCompletedDate;
            do
            {
                cout << "Completed Date (YYYY/MM/DD): ";
                cin >> tempCompletedDate;
            } while (!isValidDate(tempCompletedDate) || !isDateAfter(clients[i].appointmentDate, tempCompletedDate));
            clients[i].completedDate = tempCompletedDate;

            cout << "URL: ";
            cin >> clients[i].url;
        }
        else if (clients[i].completed == "no")
        {
            continue;
        }
        else
        {
            cout << "Please Enter a valid Input" << endl;
        }

        cout << endl;
    }
}
void display_client(Client *clients, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "============== Client " << (i + 1) << " ==============" << endl;
        cout << "Client Name: " << clients[i].clientName << endl;
        cout << "Phone Number: " << clients[i].phoneNumber << endl;
        cout << "Appointement Date (YYYY/MM/DD): " << clients[i].appointmentDate << endl;
        cout << "Completed: " << clients[i].completed << endl;
        if (clients[i].completed == "Yes")
        {
            cout << "Completed Date (YYYY/MM/DD): " << clients[i].completedDate << endl;
            cout << "URL: " << clients[i].url << endl;
        }
        else if (clients[i].completed == "No")
        {
            continue;
        }
    }
    cout << "------------------------------------------" << endl;
}
void saveToTxt(Client *clients, int len)
{
    ofstream output_f;
    output_f.open("client_list.txt");
    if (output_f.is_open())
    {
        for (int i = 0; i < len; i++)
        {
            output_f << "============== Client " << (i + 1) << " ==============" << endl;
            output_f << "Client Name: " << clients[i].clientName << endl;
            output_f << "Phone Number: " << clients[i].phoneNumber << endl;
            output_f << "Appointement Date (YYYY/MM/DD): " << clients[i].appointmentDate << endl;
            output_f << "Completed: " << clients[i].completed << endl;
            if (clients[i].completed == "Yes")
            {
                output_f << "Completed Date (YYYY/MM/DD): " << clients[i].completedDate << endl;
                output_f << "URL: " << clients[i].url << endl;
            }
            output_f << endl;
        }
        output_f << "------------------------------------------" << endl;
        output_f.close();
        cout << "Client saved Successfully" << endl;
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}

int main()
{
    cout << "How many clients do you want to add? ";
    cin >> numClients;
    Client clients[numClients];
    add_clients(clients, numClients);
    display_client(clients, numClients);
    saveToTxt(clients, numClients);
    return 0;
}