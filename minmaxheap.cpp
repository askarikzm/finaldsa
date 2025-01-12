#include<iostream>
using namespace std;
class A
{
public:
int *arr;
int size;
int totalsize;
A(int n){
arr=new int[n];
size=0;
totalsize=n;
}
void insert(int value);
void print();
};
void A::insert(int value)
{
if(size==totalsize)
{
cout<<"STACK OVERFLOW"<<endl;
}
else
{
arr[size]=value;
int index=size;
size++;
while(arr[(index-1)/2]<arr[index])
{
swap(arr[index],arr[(index-1)/2]);
index=(index-1)/2;
}
cout<<arr[index]<<" inserted"<<endl;
}
}void A::print()
{
for(int i=0;i<size;i++)
{
cout<<arr[i]<<endl;
}
}
int main(){
A s1(7);
s1.insert(3);
s1.insert(1);
s1.insert(4);
s1.insert(1);
s1.insert(5);
s1.insert(9);
s1.insert(6);
cout<<endl;
s1.print();
}
