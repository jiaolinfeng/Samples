/**
 * @file set.cpp
 * @brief definition of compare
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-23
 */

#include <iostream>
#include <set>

struct Data
{
    int val;
};

struct Compare
{
    bool operator()(const Data* p_data_a, const Data* p_data_b) const
    {
        std::cout << "judge whether " << p_data_a->val <<
            " < " << p_data_b->val << std::endl;
        return p_data_a->val < p_data_b->val;
    }
};

int main()
{
    using namespace std;
    using DataSet = set<Data*, Compare>;
    DataSet data_set;
    Data *data = nullptr;
    pair<DataSet::iterator, bool> ret;
    for (int i = 0; i < 10; ++i)
    {
        data = new Data;
        data->val = i + 1;
        cout << "insert element " << data->val << endl;
        ret = data_set.insert(data);
        if (ret.second == false)
        {
            cerr << "insert set failed" << endl;
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
