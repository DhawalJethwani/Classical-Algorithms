#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char add_bin(char s1,char s2,char s3)
{
	if(s1=='0' && s2=='0' && s3=='0')
	{
		return '0';
	}
	else if((s1=='0' && s2=='0' && s3=='1') || (s1=='1' && s2=='0' && s3=='0') || (s1=='0' && s2=='1' && s3=='0'))
	{
		return '1';
	}
	else if((s1=='0' && s2=='1' && s3=='1') || (s1=='1' && s2=='1' && s3=='0') || (s1=='1' && s2=='0' && s3=='1'))
	{
		return '2';
	}
	else
	{
		return '3';
	}
}

string add_bin_str(string s1,string s2)
{
    int n1=s1.size();
    int n2=s2.size();
	int n=n1;
    if(n1<n2)
    {
		string p=string((n2-n1),'0');
		s1=p+s1;
		n=n2;
    }
	else
	{
		string p=string((n1-n2),'0');
		s2=p+s2;
	}
	char c='0';
	string sum="";
	cout << n;
	for(int i=0;i<n;i++)
	{
		char q=add_bin(s1[n-i-1],s2[n-i-1],c);
		if(q<2)
		{
			sum=q+sum;
			c='0';
		}
		else
		{
			c='1';
			sum=char(int(q)-2)+sum;
		}
	}
	return sum;
}

int main()
{
    string a,b;
    cout << "Enter 2 binary numbers to multiply :\n";
    cin >> a;
    cin >> b;
    cout << add_bin_str(a,b);
    /*int n=b.size();
    string product;
    for(int i=0;i<n;i++)
    {
        string s=string(i,'0');
        if(b[i]=='0')
        {
            continue;
        }
        else
        {
            s=a+s;
            product=add_bin_str(s,product);
        }
    }
    cout << "Product : " << product;*/
    return 0;
}
