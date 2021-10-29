#include <iostream>
#include <pybind11/embed.h> // everything needed for embedding

#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>


namespace py = pybind11;
constexpr float radius = 10;
constexpr float stepsize = 0.05;
int main() {
    float theta=0;
    int i =0;
    std::ofstream myLog;
    myLog.open ("log/Flight_1.csv");
    
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    while(theta<4*M_PI){
         myLog<<i<<","<<radius*cos(theta)<<","<<radius*sin(theta)<<","<<theta<<","<<radius*cos(theta)<<","<<radius*sin(theta)<<","<<theta<<"\n"; //xyzrpy
         theta+=stepsize;
         i++;
    }
    myLog.close();
    py::eval_file("script.py"); // use the Python API
}
