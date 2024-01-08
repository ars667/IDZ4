#include <iostream>
#include <random>

using namespace std;
int generator(double p)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double randomValue = dis(gen);
    if (randomValue < p)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int field[2][2];
    field[0][0] = 2;
    field[0][1] = -3;
    field[1][0] = -1;
    field[1][1] = 2;

    int valueA = 0;
    int valueB = 0;
    int sumValues = 0;
    vector<pair<int, int>> results;
    vector<int> values;

    int red = 100;
    int blue = 100;
    double pValue = static_cast<double>(red) / static_cast<double>(blue+red);

    for (int i = 0; i < 100; i++)
    {
        int a = generator(pValue);
        int b = generator(0.25);
        results.push_back(make_pair(a, b));
        int m = get<0>(results[i]);
        int n = get<1>(results[i]);
        valueA += field[m][n];
        valueB -= field[m][n];
        values.push_back(valueA);
        if (field[m][n] < 0)
        {
            if (m == 0)
            {
                red += field[m][n];
            }
            else
            {
                blue += field[m][n];
            }
        }
        pValue = static_cast<double>(red) / static_cast<double>(blue+red);
        cout << "pValue: " << pValue << endl;
        sumValues += valueA;
        cout << "value = " << valueA << endl;
    }
    cout << "A result: " << valueA << endl;

    double midA = static_cast<double>(sumValues) / 100;
    cout << "A middle: " << midA << endl;

    double MSD = 0;
    for (int i = 0; i < 100; i++)
    {
        MSD += pow((values[i] - values[i-1]), 2);
    }
    MSD /= 100;
    cout << "MSD = " << MSD << endl;

    return 0;
}