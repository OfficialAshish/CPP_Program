#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Helper function to count vowels and consonants in a word
void countVowelsAndConsonants(const string &word, int &vowelCount, int &consonantCount)
{
    static const string vowels = "aeiou";
    vowelCount = 0;
    consonantCount = 0;
    for (char ch : word)
    {
        if (vowels.find(ch) != string::npos)
        {
            vowelCount++;
        }
        else if (isalpha(ch))
        {
            consonantCount++;
        }
    }
}

// Helper function to check if a word has at least 3 consecutive consonants
bool hasThreeConsecutiveConsonants(const string &word)
{
    int count = 0;
    for (char ch : word)
    {
        if (!isalpha(ch) || (string("aeiou").find(ch) != string::npos))
        {
            count = 0;
        }
        else
        {
            count++;
            if (count >= 3)
            {
                return true;
            }
        }
    }
    return false;
}

int Difficulty(const string &s)
{
    if (s.empty())
        return 0;

    istringstream iss(s);
    string word;
    int hardCount = 0;
    int easyCount = 0;

    while (iss >> word)
    {
        cout << word<<endl;
        int vowelCount, consonantCount;
        countVowelsAndConsonants(word, vowelCount, consonantCount);

        if (consonantCount > vowelCount or hasThreeConsecutiveConsonants(word))
        {
            hardCount++;
        }
        else
        {
            easyCount++;
        }
    }

    return (5 * hardCount) - (2 * easyCount);
}

int main()
{
    string input = "qiewldoaa life ace by fantasy";
    cout << Difficulty(input) << endl; // Should print 11
    return 0;
}
 