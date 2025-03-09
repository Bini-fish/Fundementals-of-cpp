#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <sstream>
#include <fstream>
#include <regex>

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
void addClients(Client *clients, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "Enter details for client " << (i + 1) << ":" << endl;

        cout << "Client Name: ";
        cin.ignore();
        getline(cin, clients[i].clientName);
        // used getline to handle the whitespace, because the code enters an infinite loop when i enter a space i.e (biniyam f).

        cout << "Phone Number: ";
        cin >> clients[i].phoneNumber;

        string temp_date;
        // storing the input into a temporary string and checking if it's in a valid format.
        do
        {
            cout << "Appointment Date (YYYY/MM/DD): ";
            cin >> temp_date;
        } while (!isValidDate(temp_date));
        clients[i].appointmentDate = temp_date;

        while (true)
        {
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
                while (true)
                {
                    string url;
                    cout << "URL: ";
                    regex url_pattern(R"(/(?:(?:http|https):\/\/)?(?:www.)?(?:instagram.com|instagr.am|instagr.com)\/(\w+)/igm)");
                    getline(cin, url);
                    if (!regex_match(url, url_pattern))
                    {
                        cerr << "Invalid URL format." << endl;
                    }
                    else
                    {
                        cin >> clients[i].url;
                        break;
                    }
                }

                break;
            }
            else if (clients[i].completed == "no")
            {
                break;
            }
            else
            {
                cout << "Please Enter a valid Input" << endl;
            }
        }
        cout << endl;
    }
}

void saveToText(Client *clients, int len)
{
    ofstream output_f;
    output_f.open("client_list.txt");
    if (output_f.is_open())
    {
        for (int i = 0; i < len; i++)
        {
            output_f << "============== Client " << (i + 1) << " ==============" << endl;
            output_f << endl;
            output_f << "Client Name: " << clients[i].clientName << endl;
            output_f << "Phone Number: " << clients[i].phoneNumber << endl;
            output_f << "Appointement Date (YYYY/MM/DD): " << clients[i].appointmentDate << endl;
            output_f << "Completed: " << clients[i].completed << endl;
            if (clients[i].completed == "yes")
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
void displayText(const string &fileName)
{
    ifstream file(fileName);

    if (file.is_open())
    {
        string text;
        while (!file.eof())
        {
            getline(file, text);
            cout << text << endl;
        }
    }
    else
    {
        cout << "Unable to open the file";
    }
    file.close();
}

int main()
{
    int choice;
    cout << "============== Welcome to the Photography Booking Software ==============" << endl;
    cout << "What do you want to do? (1-4)" << endl;
    cout << "1. Add Client: " << endl;
    cout << "2. Remove Client: " << endl;
    cout << "3. Edit Client: " << endl;
    cout << "4. Display client list: " << endl;
    cin >> choice;
    // checking if the input is an integer and is between 1-4.
    while (choice > 1 || choice < 5)
    {
        cout << "Invalid input. Please enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore();
    }
    cout << choice;
    Client clients[numClients];
    switch (choice)
    {
    case '1':
        addClients(clients, numClients);
        saveToText(clients, numClients);
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        displayText("client_list.txt");
        break;
    default:
        break;
    }

    return 0;
}