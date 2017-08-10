#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector <float> fv;

void heapup(fv &v,int i)
{
    int t=i;
    while((t-1)/2>=0)
    {
        if(v[t]<v[(t-1)/2])
        {
            swap(v[t],v[(t-1)/2]);
            t=(t-1)/2;
        }
        else
        {
            break;
        }
    }
}

void heapify(fv &v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        heapup(v,i);
    }
}

void heapdown(fv &v,int j,int n)
{
    int i=j;
    while(1)
    {
        if(2*i+2<n)
        {
            if(v[2*i+1]<v[i] && v[2*i+2]<v[i])
            {
                if(v[2*i+1]<v[2*i+2])
                {
                    swap(v[2*i+1],v[i]);
                    i=2*i+1;
                }
                else
                {
                    swap(v[2*i+2],v[i]);
                    i=2*i+2;
                }
            }
            else if(v[2*i+1]<v[i])
            {
                swap(v[2*i+1],v[i]);
                i=2*i+1;
            }
            else if(v[2*i+2]<v[i])
            {
                swap(v[2*i+2],v[i]);
                i=2*i+2;
            }
            else
            {
                break;
            }
        }
        else if(2*i+1<n)
        {
            if(v[i]>v[2*i+1])
            {
                swap(v[i],v[2*i+1]);
                i=2*i+1;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void heapsort(fv v)
{
    int n=v.size();
    heapify(v);
    for(int i=0;i<n;i++)
    {
        swap(v[0],v[n-1-i]);
        heapdown(v,0,n-i-1);
    }
    for(int i=0;i<n;i++)
    {
        cout << v[n-i-1] << " ";
    }
    cout << endl;
}

void ins(fv &v)
{
    int n=v.size();
    float k;
    cout << "Enter the number to insert : ";
    cin >> k;
    v.push_back(k);
    heapup(v,n);
}

void del(fv &v)
{
    int n=v.size();
    float k;
    cout << "Enter the number to delete : ";
    cin >> k;
    int flag=0;
    int j;
    for(j=0;j<n;j++)
    {
        if(v[j]==k)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        swap(v[j],v[n-1]);
        heapdown(v,j,n-1);
        v.pop_back();
    }
    else
    {
        cout << "Number not found!!";
    }
}

void print(fv &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    fv v;
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the numbers : ";
    for(int i=0;i<n;i++)
    {
        float p;
        cin >> p;
        v.push_back(p);
    }
    int op=1,d=0;
    cout << "............Keys corresponding to the function to implement............" << endl;
    cout << " 1 - Insert\n 2 - Delete\n 3 - Heap Sort\n 4 - Print the array\n 5 - Heapify\n 6 - Exit\n";
    cout << "Press one of the above keys to continue...... ";
    while(1)
    {
        if(op>0 && op<7)
        {
            if(d)
            {
                cout << "Which function are you about to execute next?\n";
                cout << "Look up from the above table and enter the corresponding key : ";
            }
            cin >> op;
            if(op>0 && op<7)
            {
                cout << "Instruction Accepted!!\n";
            }
            if(op==1)
            {
                ins(v);
                d=1;
            }
            else if(op==2)
            {
                del(v);
                d=1;
            }
            else if(op==3)
            {
                heapsort(v);
                d=1;
            }
            else if(op==4)
            {
                print(v);
                d=1;
            }
            else if(op==5)
            {
                heapify(v);
                d=1;
            }
            else if(op==6)
            {
                break;
            }
        }
        else
        {
            cout << "Invalid Input!! Try Again.\n\n";
            op=1;
            d=1;
        }
    }
}
