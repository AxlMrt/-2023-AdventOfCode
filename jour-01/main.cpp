#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");
    vector<int> numbers;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            string digits, answer;
            for (int i = 0; i < line.length(); i++)
            {

                if (line[i] >= '0' && line[i] <= '9')
                {
                    digits += line[i];
                }
            }
            if (digits.length() == 1)
            {
                digits += digits[0];
            }

            answer += digits[0];
            answer += digits.back();
            numbers.push_back(stoi(answer));
        }
    }

    cout << accumulate(numbers.begin(), numbers.end(), 0);
    return 0;
}
