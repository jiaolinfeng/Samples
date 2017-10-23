/**
 * @file unorder_set.cpp
 * @brief unorder_set test
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-23
 */

#include <iostream>
#include <unordered_set>

struct Data
{
    int val;
};

struct EqualFunc
{
    bool operator()(const Data* p_data_a, const Data* p_data_b) const
    {
        std::cout << "judge whether " << p_data_a->val <<
            " == " << p_data_b->val << std::endl;
        return p_data_a->val == p_data_b->val;
    }
};

struct HashFunc
{
    size_t operator()(const Data* p_data) const
    {
        std::cout << "hash " << p_data->val << std::endl;
        return static_cast<size_t>(p_data->val) % 5;
    }
};

int main()
{
    using namespace std;
    using DataSet = unordered_set<Data*, HashFunc, EqualFunc>;
    DataSet data_set;
    Data* data = nullptr;
    pair<DataSet::iterator, bool> ret;
    for (int i = 0; i < 10; ++i)
    {
        data = new Data;
        data->val = i + 1;
        ret = data_set.insert(data);
        if (!ret.second)
        {
            cerr << "insert data failed" << endl;
        }
    }
    cout << "data set size : " << data_set.size() << endl;
    for (auto it = data_set.begin(); it != data_set.end();)
    {
        data = *(it++);
        cout << "element : " << data->val << endl;
        delete data;
    }

    return 0;
}
