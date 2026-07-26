#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

typedef std::vector<std::pair<int, int> >  pair;
typedef std::vector<int>                   vector_int;
typedef std::list<int>                     list_int;

bool    isValidNumber(const std::string &token);
bool    parseArguments(int argc, char **argv, vector_int &numbers);

void    GetInput(pair &pairs, std::vector<std::string> &args);
void    SortPairs(pair &pairs);
void    SplitPairs(vector_int &bigs, vector_int &smalls, pair &pairs);

std::vector<unsigned long> jacobsthalOrder(unsigned long count);

void    MergeInsertionSortVector(vector_int &vec);
void    MergeInsertionSortList(list_int &lst);

void    printVector(const std::string &label, const vector_int &v);
void    printList(const std::string &label, const list_int &l);

#endif
