#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
 
const int maxn = 100000+10;
 
struct ListNode
{
    int value;
    ListNode *next;
    ListNode *prevous;
    ListNode(int i):value(i){}
};
 
ListNode *elements[maxn] = {NULL};
ListNode *first;
ListNode *last;
bool isreversed;
 
void creatList(int n)
{
    elements[0] = NULL;
    for(int i = 1; i<=n; i++)
    {
        elements[i] = new ListNode(i);
        elements[i]->prevous = elements[i-1];
    }
    for(int i = 1; i<=n-1; i++)
    {
        elements[i]->next = elements[i+1];
    }
    elements[n]->next = NULL;
    first = elements[1];
    last = elements[n];
}
 
void clearList(int n)
{
    first = NULL;
    last = NULL;
    for(int i = 1; i<=n; i++)
    {
        delete elements[i];
        elements[i] = NULL;
    }
}
 
void removelink(int x)
{
    if(last == elements[x])
    {
        elements[x]->prevous->next = NULL;
        last = elements[x]->prevous;
    }
    else if(first==elements[x])
    {
        first = elements[x]->next;
        elements[x]->next->prevous = NULL;
    }
    else
    {
        elements[x]->prevous->next = elements[x]->next;
        elements[x]->next->prevous = elements[x]->prevous;
    }
}
 
void moveleft(int x, int y)
{
    if(elements[y]->prevous==elements[x])
    {
        return;
    }
    removelink(x);
    if(first==elements[y])
    {
        first = elements[x];
        elements[x]->prevous = NULL;
        elements[x]->next = elements[y];
        elements[y]->prevous = elements[x];
    }
    else
    {
        elements[y]->prevous->next = elements[x];
        elements[x]->next = elements[y];
        elements[x]->prevous = elements[y]->prevous;
        elements[y]->prevous = elements[x];
    }
}
 
void moveright(int x, int y)
{
    if(elements[y]->next==elements[x])
    {
        return;
    }
    removelink(x);
    if(last==elements[y])
    {
        elements[y]->next = elements[x];
        elements[x]->prevous = elements[y];
        last = elements[x];
        elements[x]->next = NULL;
    }
    else
    {
        elements[y]->next->prevous = elements[x];
        elements[x]->next = elements[y]->next;
        elements[y]->next = elements[x];
        elements[x]->prevous = elements[y];
    }
}
 
void swapbox(int x, int y)
{
    if(first==elements[x])
    {
        int rightx = elements[x]->next->value;
        moveright(x, y);
        if(y!=rightx)
            moveleft(y, rightx);
    }
    else
    {
        int leftx = elements[x]->prevous->value;
        moveleft(x, y);
        if(y!=leftx)
            moveright(y, leftx);
    }
}
 
void solve(int order, int x, int y)
{
    if(!isreversed)
    {
        switch(order)
        {
            case 1: moveleft(x, y); break;
            case 2: moveright(x, y); break;
            case 3: swapbox(x, y); break;
            case 4: isreversed = !isreversed; break;
        }
    }
    else
    {
        switch(order)
        {
            case 1: moveright(x, y); break;
            case 2: moveleft(x, y); break;
            case 3: swapbox(x, y); break;
            case 4: isreversed = !isreversed; break;
        }
    }
}
 
long long getoddsum()
{
    long long sum = 0;
    if(!isreversed)
    {
        ListNode *p;
        int i = 1;
        for(p = first; p!=NULL; p = p->next, i++)
        {
            if(i%2==1)
            {
                sum += p->value;
            }
        }
    }
    else
    {
        ListNode *p;
        int i = 1;
        for(p = last; p!=NULL; p = p->prevous, i++)
        {
            if(i%2==1)
            {
                sum += p->value;
            }
        }
    }
    return sum;
}
 
int main()
{
    int n, m, serial = 1;
    int order, x, y;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        creatList(n);
        isreversed = false;
        while(m--)
        {
            scanf("%d", &order);
            if(order!=4)
                scanf("%d%d", &x, &y);
            solve(order, x, y);
        }
        printf("Case %d: %lld\n", serial++, getoddsum());
        clearList(n);
    }
    return 0;
}