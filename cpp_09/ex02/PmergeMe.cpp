#include "PmergeMe.hpp"

void GetInput(pair &pairs, std::vector<std::string> &args)
{
    for (unsigned long i = 0; i < args.size(); i += 2)
    {
        if (i + 1 < args.size())
            pairs.push_back(std::make_pair(std::atoi(args[i].c_str())
                , std::atoi(args[i + 1].c_str())));
    }
}

void SortPairs(pair &pairs)
{
    for (unsigned long i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first > pairs[i].second)
        {
            int tmp = pairs[i].first;
            pairs[i].first = pairs[i].second;
            pairs[i].second = tmp;
        }
    }
}

void SplitPairs(vector_int &bigs, vector_int &smalls, pair &pairs)
{
    for (unsigned long i = 0; i < pairs.size(); i++)
    {
        bigs.push_back(pairs[i].second);
        smalls.push_back(pairs[i].first);
    }
}

bool isValidNumber(const std::string &token)
{
    if (token.empty() || token.size() > 10)
        return false;

    for (unsigned long i = 0; i < token.size(); i++)
    {
        if (token[i] < '0' || token[i] > '9')
            return false;
    }
    return true;
}

bool containsDuplicate(const vector_int &numbers, int value)
{
    for (unsigned long i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == value)
            return true;
    }
    return false;
}

bool parseArguments(int argc, char **argv, vector_int &numbers)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        std::string token(argv[i]);

        if (!isValidNumber(token))
        {
            std::cout << "Error" << std::endl;
            return false;
        }
        long value = std::atoi(token.c_str());
        if (value <= 0 || value > std::numeric_limits<int>::max())
        {
            std::cout << "Error" << std::endl;
            return false;
        }

        if (containsDuplicate(numbers, value))
        {
            std::cout << "Error" << std::endl;
            return false;
        }

        numbers.push_back(value);
    }
    return true;
}

std::vector<unsigned long> jacobsthalOrder(unsigned long count)
{
    std::vector<unsigned long> order;
    if (count == 0)
        return order;
    order.push_back(1);
    if (count == 1)
        return order;
    std::vector<unsigned long> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac[jac.size() - 1] < count)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
    std::vector<bool> used(count + 1, false);
    used[1] = true;
    unsigned long inserted = 1;
    for (unsigned long k = 2; k < jac.size() && inserted < count; k++)
    {
        unsigned long hi = jac[k];
        unsigned long lo = jac[k - 1];
        if (hi > count)
            hi = count;
        for (unsigned long v = hi; v > lo; v--)
        {
            if (!used[v])
            {
                order.push_back(v);
                used[v] = true;
                inserted++;
            }
        }
    }
    for (unsigned long v = count; inserted < count; v--)
    {
        if (!used[v])
        {
            order.push_back(v);
            inserted++;
        }
        if (v == 1)
            break;
    }
    return order;
}

void MergeInsertionSortVector(vector_int &vec)
{
    if (vec.size() <= 1)
        return;
    bool hasStraggler = (vec.size() % 2 != 0);
    int straggler = hasStraggler ? vec.back() : 0;
    unsigned long pairCount = vec.size() / 2;
    pair pairs;
    for (unsigned long i = 0; i < pairCount; i++)
        pairs.push_back(std::make_pair(vec[2 * i], vec[2 * i + 1]));
    SortPairs(pairs);
    vector_int bigs;
    vector_int smalls;
    SplitPairs(bigs, smalls, pairs);
    vector_int origBigs = bigs;
    MergeInsertionSortVector(bigs);
    vector_int chain = bigs;
    std::vector<unsigned long> rankOfPair(pairCount);
    for (unsigned long i = 0; i < pairCount; i++)
    {
        unsigned long idx = 0;
        while (idx < chain.size() && chain[idx] != origBigs[i])
            idx++;
        rankOfPair[i] = idx;
    }
    std::vector<unsigned long> pairAtRank(pairCount);
    for (unsigned long i = 0; i < pairCount; i++)
        pairAtRank[rankOfPair[i]] = i;
    std::vector<unsigned long> order = jacobsthalOrder(pairCount);
    for (unsigned long k = 0; k < order.size(); k++)
    {
        unsigned long rank = order[k] - 1;
        unsigned long pairIndex = pairAtRank[rank];
        int value = smalls[pairIndex];

        if (rank == 0)
        {
            chain.insert(chain.begin(), value);
            continue;
        }
        vector_int::iterator bound = std::find(chain.begin(), chain.end(), origBigs[pairIndex]);
        vector_int::iterator pos = std::lower_bound(chain.begin(), bound, value);
        chain.insert(pos, value);
    }
    if (hasStraggler)
    {
        vector_int::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    vec = chain;
}

void MergeInsertionSortList(list_int &lst)
{
    if (lst.size() <= 1)
        return;

    bool hasStraggler = (lst.size() % 2 != 0);
    int straggler = 0;
    unsigned long pairCount = lst.size() / 2;

    pair pairs;
    list_int::iterator it = lst.begin();
    for (unsigned long i = 0; i < pairCount; i++)
    {
        int a = *it; ++it;
        int b = *it; ++it;
        pairs.push_back(std::make_pair(a, b));
    }
    if (hasStraggler)
        straggler = *it;

    SortPairs(pairs);

    vector_int bigs;
    vector_int smalls;
    SplitPairs(bigs, smalls, pairs);

    vector_int origBigs = bigs;

    MergeInsertionSortVector(bigs);

    list_int chain(bigs.begin(), bigs.end());

    std::vector<bool> claimed(chain.size(), false);
    std::vector<unsigned long> rankOfPair(pairCount);
    for (unsigned long i = 0; i < pairCount; i++)
    {
        list_int::iterator found = chain.begin();
        unsigned long idx = 0;
        while (found != chain.end() && (*found != origBigs[i] || claimed[idx]))
        {
            ++found;
            idx++;
        }
        claimed[idx] = true;
        rankOfPair[i] = idx;
    }
    std::vector<unsigned long> pairAtRank(pairCount);
    for (unsigned long i = 0; i < pairCount; i++)
        pairAtRank[rankOfPair[i]] = i;

    std::vector<unsigned long> order = jacobsthalOrder(pairCount);
    for (unsigned long k = 0; k < order.size(); k++)
    {
        unsigned long rank = order[k] - 1;
        unsigned long pairIndex = pairAtRank[rank];
        int value = smalls[pairIndex];

        if (rank == 0)
        {
            chain.insert(chain.begin(), value);
            continue;
        }

        list_int::iterator bound = std::find(chain.begin(), chain.end(), origBigs[pairIndex]);
        list_int::iterator pos = std::lower_bound(chain.begin(), bound, value);
        chain.insert(pos, value);
    }

    if (hasStraggler)
    {
        list_int::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }

    lst = chain;
}

void printVector(const std::string &label, const vector_int &v)
{
    std::cout << label;
    for (unsigned long i = 0; i < v.size(); i++)
        std::cout << v[i] << ' ';
    std::cout << std::endl;
}

void printList(const std::string &label, const list_int &l)
{
    std::cout << label;
    for (list_int::const_iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}
