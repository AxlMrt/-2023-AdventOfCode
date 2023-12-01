#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    string line;
    ifstream file("input2.txt");

    vector<string> numbers_list{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> numbers;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            vector<int> digits;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] >= '0' && line[i] <= '9')
                    digits.push_back(line[i] - '0');

                for (int j = 0; j < numbers_list.size(); j++)
                {
                    if (line.size() >= i + numbers_list[j].size())
                    {
                        if (line.substr(i, numbers_list[j].size()) == numbers_list[j])
                            digits.push_back(j + 1);
                    }
                }
            }
            cout << digits[0] << endl;
            numbers.push_back(digits[0] * 10 + digits.back());
        }
    }

    cout << accumulate(numbers.begin(), numbers.end(), 0);
    return 0;
}
