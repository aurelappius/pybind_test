#include <iostream>
#include <pybind11/embed.h> // everything needed for embedding
namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive
    
    py::eval_file("script.py"); // use the Python API
}
