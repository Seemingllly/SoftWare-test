#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct SListNode
{
    float coef;
    int index;
    SListNode* next;
};

SListNode* BuyListNode(float co, int in)
{
    SListNode* newnode = new SListNode;
    newnode->coef = co;
    newnode->index = in;
    newnode->next = nullptr;
    return newnode;
}

void SListPushFront(SListNode*& pphead, float co, int in)
{
    SListNode* newnode = BuyListNode(co, in);
    newnode->next = pphead;
    pphead = newnode;
}

void SListSub(SListNode*& pphead)
{
    SListNode* cur = pphead;
    int maxin = 0;
    while (cur != nullptr)
    {
        if (cur->index > maxin)
        {
            maxin = cur->index;
        }
        cur = cur->next;
    }
    vector<float> v(maxin);
    cur = pphead;
    while (cur != nullptr)
    {
        float co = cur->coef;
        int in = cur->index;
        v[in] += co;
        cur = cur->next;
    }

    for (int i = 0; i <= maxin; ++i)
    {
        if (v[i] != 0)
        {
            cout << v[i] << ' ' << i << endl;
        }
    }
    cout << '#';
}

int main()
{
    SListNode* slist = nullptr;

    // Test data
    float test_data[9] = { 1.1, 2, -2.2, 3, -3.3, 4, -4.4, 5, -5.5 };
    int index_data[9] = { 1, 2, 1, 3, 2, 4, 3, 5, 4 };

    for (int i = 0; i < 9; ++i)
    {
        SListPushFront(slist, test_data[i], index_data[i]);
    }

    SListSub(slist);

    return 0;
}