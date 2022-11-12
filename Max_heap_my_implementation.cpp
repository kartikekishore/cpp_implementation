#include<bits/stdc++.h>

using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//max heap or priority_queue
class max_heap{
public:
    int capacity,siz;
    vector<int>v;

    max_heap(int cap)
    {
        capacity=cap;
        siz=0;
        v.resize(capacity);
        v.assign(capacity,INT_MIN);
    }//zero based
    //max at root

    int left(int i)//2*i+1
    {
        return 2*i+1;
    }
    int right(int i)//2*i+2
    {
        return 2*i+2;
    }
    int parent(int i)//par of 0 error
    {
        return (i-1)/2;
    }
    int top()//topmost element
    {
        if(siz<=0)return INT_MIN;
        return v[0];

    }
    
    void push(int val)//
    {
        siz++;
        if(siz>capacity)// cant input
        {
            return;
        }
        v[siz-1]=val;
        int i=siz-1;
        while(i>0&&parent(i)>=0&&v[parent(i)]<v[i])
        {
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
  
    void heapify(int i)
    {
        if(i>=capacity)return;

        int mn=i;
        if(left(i)<capacity&&v[left(i)]>v[mn])
        {
            mn=left(i);
        }
        if(right(i)<capacity&&v[right(i)]>v[mn])
        {
            mn=right(i);
        }
        if(mn==i)return;

        swap(v[i],v[mn]);
        heapify(mn);
    }
    void pop();

};
void max_heap::pop()
{
    siz--;
    if(siz<=0)return;

    swap(v[0],v[siz]);
    v[siz]=INT_MIN;//or INT_MIN
    heapify(0);

}

void sol()
{
    max_heap pq(10);;
    pq.push(10);
    pq.push(9);
    pq.push(189);
    pq.push(0);
    pq.push(-10);
    pq.push(1);
    pq.push(1790);

    pq.pop();
    cout<<pq.top()<<'\n';//189

    pq.pop();
    pq.pop();
    cout<<pq.top()<<'\n';//9
    pq.pop();
    pq.push(80);
    cout<<pq.top()<<'\n';//80
    pq.pop();pq.pop();pq.pop();
    cout<<pq.top()<<'\n';//-10





    
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();

    return 0;
}