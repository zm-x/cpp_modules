#include "PmergeMe.hpp"
#include <sys/time.h>

static double nowMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, 0);
    return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}

int main(int argc, char **argv)
{
    vector_int numbers;

    if (!parseArguments(argc, argv, numbers))
        return 1;

    vector_int forVector = numbers;
    list_int   forList(numbers.begin(), numbers.end());

    printVector("Before: ", numbers);

    double t1 = nowMicroseconds();
    MergeInsertionSortVector(forVector);
    double t2 = nowMicroseconds();

    double t3 = nowMicroseconds();
    MergeInsertionSortList(forList);
    double t4 = nowMicroseconds();

    printVector("After:  ", forVector);

    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(3) << (t2 - t1) << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::list   : "
              << std::fixed << std::setprecision(3) << (t4 - t3) << " us" << std::endl;

    return 0;
}
