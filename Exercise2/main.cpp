#include <iostream>
#include <fstream>
#include <iomanip>

double rescale(double a, double b, double c, double d, double v)
{
    double x = (d-c)/(b-a);
    double y = c-a*x;
    double n = v*x + y;
    return n;
}

int main()
{
    double a = 1;
    double b = 5;
    double c = -1;
    double d = 2;
    std::string nameFile = "data.csv";
    std::ifstream f(nameFile);

    if (f.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    std::ofstream outFile("result.csv");
    outFile << "#N Mean" << std::endl;

    double val = 0;
    unsigned int countVal = 0;
    double sum = 0;
    double mean = 0;

    while (f >> val)
    {
        double newval = rescale(a, b, c, d, val);
        countVal ++;
        sum += newval;
        mean = sum/countVal;
        outFile << countVal << " " << std::scientific << std::setprecision(16) << mean << std::endl;
    }

    f.close();
    outFile.close();

    return 0;
}
