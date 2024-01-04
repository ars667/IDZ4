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