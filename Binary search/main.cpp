#include <iostream>
using namespace std;
int main()
{  const int N=10;
   int A[N],Temp,num,beg,end,mid;

   for(int i=0;i<=9;i++)
   {
    cout<<"Enter numbers in ascending order:";
    cin>>A[i];
   }

   cout<<"Enter number you want to find :";
   cin>>num;
   
   beg=0;
   end=9;
   while(beg<=end)
   {
    mid=(beg+end)/2;

    if(A[mid]==num)
    {cout<<"Found in loc"<<mid;
    break;}
    else if(num>A[mid])
    {beg=mid+1;}
    else if(num<A[mid])
    {end=mid-1;}
   }
   if(beg>end)
   {cout<<"NOT found!";}
   
   return 0;
}