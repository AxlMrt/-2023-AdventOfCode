#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream file("input1.txt"); // Remplacer avec le chemin vers votre fichier
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier." << endl;
        return 1;
    }

    vector<string> grid;
    string line;
    while (file >> line)
    {
        grid.push_back(line);
    }
    file.close();

    int N = grid.size();
    int M = grid[0].size();

    auto isSymbol = [&](char c) { return !(isdigit(c) || c == '.'); };
    auto valid = [&](int i, int j) -> bool { return 0 <= i && i < N && 0 <= j && j < M; };

    vector<vector<vector<int>>> V(N, vector<vector<int>>(M));

    int part1 = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (isdigit(grid[i][j]))
            {
                int n = 0;
                int l = j;
                while (j < M && isdigit(grid[i][j]))
                {
                    n = n * 10 + (grid[i][j++] - '0');
                }
                int r = j - 1;

                bool p = false;
                for (int k = l - 1; k < r + 2; ++k)
                {
                    for (int ii = i - 1; ii < i + 2; ++ii)
                    {
                        bool b = valid(ii, k) && isSymbol(grid[ii][k]);
                        p |= b;
                        if (b)
                            V[ii][k].push_back(n);
                    }
                }
                if (p)
                    part1 += n;
            }
        }
    }

    int part2 = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == '*' && V[i][j].size() == 2)
            {
                part2 += V[i][j][0] * V[i][j][1];
            }
        }
    }

    cout << "Part 1: " << part1 << '\n';
    cout << "Part 2: " << part2 << '\n';

    return 0;
}
