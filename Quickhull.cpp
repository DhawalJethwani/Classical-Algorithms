#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <graphics.h>
#include <windows.h>
using namespace std;

struct coord
{
    double x,y;
};
typedef struct coord coord;

typedef vector<coord> vpt;

vpt convex_hull;
coord lftpt;

bool comp(coord &a,coord &b)
{
    return (a.x==b.x ? a.y < b.y : a.x < b.x);
}
bool comp1(coord &a,coord &b)
{
    return (((a.y-lftpt.y)/(a.x-lftpt.x))<((b.y-lftpt.y)/(b.x-lftpt.x)));
}

void findhull(vpt &sk,coord p,coord q)
{
    if(!sk.size())
    {
        return;
    }
    else
    {
        float maxi=0,dist;
        int j;
        for(int i=0;i<sk.size();i++)
        {
            dist=((q.y-p.y)*sk[i].x-(q.x-p.x)*sk[i].y)+(p.y*q.x-p.x*q.y);
            dist=dist>0?dist:(-1)*dist;
            if(dist>maxi)
            {
                maxi=dist;
                j=i;
            }
        }
        convex_hull.push_back(sk[j]);
        double v1=(q.y-((p.y-sk[j].y)/(p.x-sk[j].x))*q.x-((sk[j].y*p.x-sk[j].x*p.y)/(p.x-sk[j].x)));
        double v2=(p.y-((q.y-sk[j].y)/(q.x-sk[j].x))*p.x-((sk[j].y*q.x-sk[j].x*q.y)/(q.x-sk[j].x)));
        vpt s1;
        vpt s2;
        for(int i=0;i<sk.size();i++)
        {
            if(i==j)
            {
                continue;
            }
            if(((sk[i].y-((p.y-sk[j].y)/(p.x-sk[j].x))*sk[i].x-((sk[j].y*p.x-sk[j].x*p.y)/(p.x-sk[j].x)))*v1)<0)
            {
                s1.push_back(sk[i]);
            }
            else if(((sk[i].y-((q.y-sk[j].y)/(q.x-sk[j].x))*sk[i].x-((sk[j].y*q.x-sk[j].x*q.y)/(q.x-sk[j].x)))*v2)<0)
            {
                s2.push_back(sk[i]);
            }
        }
        findhull(s1,p,sk[j]);
        findhull(s2,sk[j],q);
    }
}

void quickhull(vpt &pt)
{
    sort(pt.begin(),pt.end(),comp);
    lftpt.x=pt[0].x;
    lftpt.y=pt[0].y;
    coord a=pt[0];
    coord b=pt.back();
    convex_hull.push_back(a);
    convex_hull.push_back(b);
    vpt s1;
    vpt s2;
    for(int i=1;i<pt.size()-1;i++)
    {
        if((pt[i].y-((b.y-a.y)/(b.x-a.x))*pt[i].x-((a.y*b.x-a.x*b.y)/(b.x-a.x)))<0)
        {
            s1.push_back(pt[i]);
        }
        else if((pt[i].y-((b.y-a.y)/(b.x-a.x))*pt[i].x-((a.y*b.x-a.x*b.y)/(b.x-a.x)))>0)
        {
            s2.push_back(pt[i]);
        }
    }
    findhull(s1,a,b);
    findhull(s2,b,a);
}

int input(float x,float y)
{
    string s;
    char ss[200],ch;
    int j=0;
    while(true)
    {
        ch=getch();
        if((int)ch==13) break;
        s.push_back(ch);
        ss[j++]=ch;
        ss[j]='\0';
        outtextxy(x,y,ss);
    }
    int n=0,c=1;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        n+=(c*(s[i]-'0'));
        c*=10;
    }
    return n;
}

int main()
{
    vpt pt;
    coord a;
    int t=0;
    initwindow(1500,1000,"Convex Hull");
    settextstyle(6,0,2);
    setcolor(BLUE);
    outtextxy(100,100,"Enter no. of Points: ");
    int n;
    n=input(550,100);
    while(true)
    {
        POINT P;
        GetCursorPos(&P);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            a.x=(double)P.x;
            a.y=(double)P.y;
            pt.push_back(a);
            t++;
            setcolor(YELLOW);
            circle(P.x,P.y,6);
            if(t==n) break;
            delay(200);
        }
    }
    quickhull(pt);
    sort(convex_hull.begin()+1,convex_hull.end(),comp1);
    for(int i=0;i<convex_hull.size();i++)
    {
        cout << convex_hull[i].x << " " << convex_hull[i].y << endl;
    }
    for(int i=0;i<convex_hull.size();i++)
    {
        if(i<convex_hull.size()-1)
        {
            line(convex_hull[i].x,convex_hull[i].y,convex_hull[i+1].x,convex_hull[i+1].y);
        }
        else
        {
            line(convex_hull[i].x,convex_hull[i].y,convex_hull[0].x,convex_hull[0].y);
        }
        delay(1000);
    }
    getch();
    closegraph();
    return 0;
}
