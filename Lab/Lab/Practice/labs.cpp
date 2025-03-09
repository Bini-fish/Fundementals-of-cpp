#include <iostream>
#include <string>

int main()
{
    std::string input_string = "This is a sample string";
    std::string word;
    size_t pos = 0;
    size_t prev_pos = 0;

    while ((pos = input_string.find(' ', prev_pos)) != std::string::npos)
    {
        word = input_string.substr(prev_pos, pos - prev_pos);
        std::cout << word << std::endl;
        prev_pos = pos + 1;
    }

    // Get the last word
    word = input_string.substr(prev_pos);
    std::cout << word << std::endl;

    return 0;
}