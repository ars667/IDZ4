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

    int Ared = 10;
    int Ablue = 10;
    double ApValue = static_cast<double>(Ared) / static_cast<double>(Ablue + Ared);

    int Bred = 10;
    int Bblue = 10;
    double BpValue = static_cast<double>(Bred) / static_cast<double>(Bblue + Bred);

    for (int i = 0; i < 100; i++)
    {
        int a = generator(ApValue);
        int b = generator(BpValue);
        results.push_back(make_pair(a, b));
        int m = get<0>(results[i]);
        int n = get<1>(results[i]);
        valueA += field[m][n];
        valueB -= field[m][n];
        values.push_back(valueA);
        if (field[m][n] > 0)
        {
            if (m == 0)
            {
                Ared += field[m][n];
            }
            else
            {
                Ablue += field[m][n];
            }
        }
        else
        {
            if (n == 0)
            {
                Bred -= field[m][n];
            }
            else
            {
                Bblue -= field[m][n];
            }
        }

        ApValue = static_cast<double>(Ared) / static_cast<double>(Ablue + Ared);
        BpValue = static_cast<double>(Bred) / static_cast<double>(Bblue + Bred);
        cout << "ApValue: " << ApValue << endl;
        sumValues += valueA;
        cout << "BpValue: " << BpValue << endl;
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