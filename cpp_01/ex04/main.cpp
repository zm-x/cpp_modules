#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#define RED "\033[1;31m"
#define RESET "\033[0m"

int print_error(std::string msg)
{
    std::cerr << RED << msg << RESET << std::endl;
    return 1;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (print_error("Valid arguments: filename, string1, string2"));
    std::ifstream infile(av[1]);
    if (!infile)
        return (print_error("ifstream failed!"));
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string file = av[1];
    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    size_t index = 0;
    while ((index = content.find(s1, index)) != std::string::npos)
    {
        content.erase(index,s1.length());
        content.insert(index,s2);
        index += s2.length();
    }
    std::ofstream outfile((file + ".replace").c_str());
    if (!outfile)
        print_error("Failed to create output file!");
    outfile << content;
}