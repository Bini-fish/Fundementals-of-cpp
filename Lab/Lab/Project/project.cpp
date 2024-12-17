#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

using namespace std;
using json = nlohmann::json;

// Define API keys and constants
const string NOTION_API_KEY = "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";
const string DATABASE_ID = "11ccdbea2113807ba68df5e7b037d446";
const string API_URL = "https://api.notion.com/v1/";

// Function prototypes
string format_date(const string& date_str);
bool validate_date(const string& date);
bool validate_name(const string& name);
bool validate_phone_number(const string& phone_number);
bool validate_url(const string& url);
vector<json> get_clients();
void add_client(const json& data);
string format_client(const vector<json>& clients);
void edit_client(const vector<json>& clients);
void remove_client(const vector<json>& clients);

// Function to format date string
string format_date(const string& date_str) {
  struct tm tm_struct;
  stringstream ss(date_str);
  ss >> get_time(&tm_struct, "%Y-%m-%d");
  return asctime(&tm_struct);
}

// Function to validate date format
bool validate_date(const string& date) {
  regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
  return regex_match(date, pattern);
}

// Function to validate name
bool validate_name(const string& name) {
  return name.find_first_of("0123456789!@#$%^&*()-_=+[]{};':\",<.>/?\\|~`") == string::npos;
}

// Function to validate phone number format (Ethiopian format)
bool validate_phone_number(const string& phone_number) {
  regex pattern(R"^((\+2519|09)([0-9]{8}))<span class="math-inline">"\);
return regex\_match\(phone\_number, pattern\);
\}
// Function to validate URL format \(Instagram profile\)
bool validate\_url\(const string& url\) \{
regex pattern\(R"^\(https?\://\)?\(www\\\.\)?\(instagram\\\.com\)/\(\.\+\)</span>");
  return regex_match(url, pattern);
}

// Function to fetch clients from Notion
vector<json> get_clients() {
  CURL *curl;
  CURLcode res;
  string url = API_URL + "databases/" + DATABASE_ID + "/query";
  struct curl_slist *headers = NULL;

  headers = curl_slist_append(headers, "Authorization: Bearer " + NOTION_API_KEY);
  headers = curl_slist_append(headers, "Notion-Version: 2022-06-28");
  headers = curl_slist_append(headers, "Content-Type: application/json");

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, 1);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
      curl_easy_cleanup(curl);
      curl_slist_free_all(headers);
      exit(1);
    }

    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

    if (http_code != 200) {
      cerr << "Failed to fetch clients: HTTP code " << http_code << endl;
      curl_easy_cleanup(curl);
      curl_slist_free_all(headers);
      exit(1);
    }

    curl_easy_