#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const string NOTION_API_KEY = "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";
const string DATABASE_ID = "11ccdbea2113807ba68df5e7b037d446";
const string NOTION_VERSION = "2022-06-28";

struct Client {
    string name;
    string contactInfo;
    string appointmentDate;
    bool completed;
    string completedDate;
    string url;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool is_name(const string& name) {
    return all_of(name.begin(), name.end(), [](char c) { return isalpha(c) || c == ' '; });
}

bool is_phone_num(const string& phone_num) {
    regex pattern(R"(^(\+2519|09)(\d{8})$)");
    return regex_match(phone_num, pattern);
}

bool is_url(const string& url) {
    regex pattern(R"(^https?://(www\.)?instagram\.com/.+$)");
    return regex_match(url, pattern);
}

bool valid_date(const string& date) {
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm);
}

string make_api_request(const string& url, const string& payload) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + NOTION_API_KEY).c_str());
        headers = curl_slist_append(headers, ("Notion-Version: " + NOTION_VERSION).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "Request failed: " << curl_easy_strerror(res) << endl;
            return "";
        }

        curl_global_cleanup();
        return readBuffer;
    }

    return "";
}

json get_client() {
    string url = "https://api.notion.com/v1/databases/" + DATABASE_ID + "/query";
    string payload = R"({"page_size": 100})";
    string response = make_api_request(url, payload);
    return json::parse(response);
}

void add_client(const json& data) {
    string url = "https://api.notion.com/v1/pages";
    string payload = R"({"parent": {"database_id": ")" + DATABASE_ID + R"("}, "properties": )" + data.dump() + "}";
    string response = make_api_request(url, payload);
    if (response.find("object") != string::npos) {
        cout << "Successfully Added a Client" << endl;
    } else {
        cerr << "Unable to Add a Client" << endl;
    }
}

void format_client(const json& clients) {
    for (const auto& client : clients) {
        cout << "Name: " << client["properties"]["Client's Name"]["title"][0]["text"]["content"] << endl;
        cout << "Contact Info: " << client["properties"]["Contact Info"]["phone_number"] << endl;
        cout << "Appointment: " << client["properties"]["Photo Shoot Appointment"]["date"]["start"] << endl;
        cout << "Completed: " << (client["properties"]["Completed"]["checkbox"].get<bool>() ? "Yes" : "No") << endl;
        cout << "Completed Date: " << client["properties"]["Date Published"]["date"]["start"] << endl;
        cout << "URL: " << client["properties"]["URL"]["url"] << endl;
        cout << "---------------------------------------------" << endl;
    }
}

void edit_client(const string& name) {
    json clients = get_client();
    bool found = false;
    for (auto& client : clients) {
        string client_name = client["properties"]["Client's Name"]["title"][0]["text"]["content"];
        if (client_name == name) {
            found = true;
            int option;
            cout << "Which field do you want to edit?" << endl;
            cout << "1. Name\n2. Contact Info\n3. Appointment\n4. Completed\n5. Completed Date\n6. URL" << endl;
            cin >> option;

            switch (option) {
                case 1: {
                    string new_name;
                    cout << "Enter new name: ";
                    cin >> new_name;
                    if (is_name(new_name)) {
                        client["properties"]["Client's Name"]["title"][0]["text"]["content"] = new_name;
                    } else {
                        cerr << "Invalid name" << endl;
                    }
                    break;
                }
                case 2: {
                    string new_contact;
                    cout << "Enter new contact info: ";
                    cin >> new_contact;
                    if (is_phone_num(new_contact)) {
                        client["properties"]["Contact Info"]["phone_number"] = new_contact;
                    } else {
                        cerr << "Invalid phone number" << endl;
                    }
                    break;
                }
                case 3: {
                    string new_appointment;
                    cout << "Enter new appointment date (YYYY-MM-DD): ";
                    cin >> new_appointment;
                    if (valid_date(new_appointment)) {
                        client["properties"]["Photo Shoot Appointment"]["date"]["start"] = new_appointment;
                    } else {
                        cerr << "Invalid date format" << endl;
                    }
                    break;
                }
                case 4: {
                    string completed;
                    cout << "Is the project completed? (yes/no): ";
                    cin >> completed;
                    if (completed == "yes") {
                        client["properties"]["Completed"]["checkbox"] = true;
                    } else {
                        client["properties"]["Completed"]["checkbox"] = false;
                    }
                    break;
                }
                case 5: {
                    string completed_date;
                    cout << "Enter the completed date (YYYY-MM-DD): ";
                    cin >> completed_date;
                    if (valid_date(completed_date)) {
                        client["properties"]["Date Published"]["date"]["start"] = completed_date;
                    } else {
                        cerr << "Invalid date format" << endl;
                    }
                    break;
                }
                case 6: {
                    string new_url;
                    cout << "Enter new URL: ";
                    cin >> new_url;
                    if (is_url(new_url)) {
                        client["properties"]["URL"]["url"] = new_url;
                    } else {
                        cerr << "Invalid URL" << endl;
                    }
                    break;
                }
                default:
                    cerr << "Invalid option" << endl;
            }

            add_client(client); // Update client in Notion
            return;
        }
    }
    if (!found) {
        cerr << "Client not found" << endl;
    }
}

void remove_client(const string& name) {
    json clients = get_client();
    for (auto& client : clients) {
        string client_name = client["properties"]["Client's Name"]["title"][0]["text"]["content"];
        if (client_name == name) {
            string url = "https://api.notion.com/v1/pages/" + client["id"].get<string>();
            string payload = R"({"archived": true})";
            string response = make_api_request(url, payload);
            if (response.find("object") != string::npos) {
                cout << "Client removed successfully" << endl;
            } else {
                cerr << "Unable to remove client" << endl;
            }
            return;
        }
    }
    cerr << "Client not found" << endl;
}

int main() {
    int option;
    cout << "1. View\n2. Add Client\n3. Edit Client\n4. Remove Client" << endl;
    cout << "Choose an option (1-4): ";
    cin >> option;

    switch (option) {
        case 1:
            format_client(get_client());
            break;
        case 2: {
            string name, contact_info, appointment_date, completed, url, published_date;
            cout << "Enter client's name: ";
            cin >> name;
            if (!is_name(name))