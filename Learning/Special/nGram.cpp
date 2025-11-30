#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

pair<string, int> findMostFrequentNgram(const string &str, int N)
{
    unordered_map<string, int> ngramFrequency;
    int maxFreq = 0;
    string mostFrequentNgram;

    for (size_t i = 0; i <= str.length() - N; ++i)
    {
        string ngram = str.substr(i, N);
        ngramFrequency[ngram]++;

        if (ngramFrequency[ngram] > maxFreq)
        {
            maxFreq = ngramFrequency[ngram];
            mostFrequentNgram = ngram;
        }
    }

    return make_pair(mostFrequentNgram, maxFreq);
}

void get_ngram(string s, int k)
{
    unordered_map<string, int> ngramFrequency;
    int maxFreq = 0;
    string mostFrequentNgram;

    for (int i = 0; i <= s.length() - k; ++i)
    {
        string ngram = s.substr(i, k);
        ngramFrequency[ngram]++;

        if (ngramFrequency[ngram] > maxFreq)
        {
            maxFreq = ngramFrequency[ngram];
            mostFrequentNgram = ngram;
        }
    }
    cout << mostFrequentNgram << " " << maxFreq;
}

int main()
{
    string inputString;
    int N;

    cout << "Enter the string: ";
    cin >> inputString;

    cout << "Enter the value of N: ";
    cin >> N;

    if (N > inputString.length())
    {
        cout << "N cannot be greater than the length of the string." << endl;
        return 1;
    }
    get_ngram(inputString, N);

    // pair<string, int> result = findMostFrequentNgram(inputString, N);
    // cout << "Most frequent N-gram: " << result.first << endl;
    // cout << "Frequency: " << result.second << endl;

    return 0;
}
