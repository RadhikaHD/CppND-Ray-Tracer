#include <iostream>
#include <vector>
#include <fstream>
#include <string>


void writeToPPM(std::string filename)
{
    std::ofstream toppm;
    toppm.open(filename);
    toppm<<"P3\n";
    toppm<<"255 255\n";
    toppm<<"255\n";
    int b= 0;
    for (int r=0; r<255; r++)
    {
        for (int g=0; g<255; g++)
        {
            toppm<<r<<" "<<g<<" "<<b<<" ";
        }
        toppm<<"\n";
    }
    toppm.close();
}

int main()
{
    writeToPPM("output.ppm");
    return 0;
}