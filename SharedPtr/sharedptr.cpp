#include <iostream>
#include <memory>
using namespace std;

void Func1(shared_ptr<int> a)
{
	cout<<"Enter Func1"<<endl;
	cout<<"Ref count: "<<a.use_count()<<endl;
	cout<<"Leave Func1"<<endl;
}

shared_ptr<int> Func2(shared_ptr<int> a)
{
	cout<<"Enter Func2"<<endl;
	cout<<"Ref count: "<<a.use_count()<<endl;
	cout<<"Leave Func2"<<endl;
	return a;
}

int main()
{
	shared_ptr<int> aObj1(new int(10));
	cout<<"Ref count: "<<aObj1.use_count()<<endl;

	{
		shared_ptr<int> aObj2 = aObj1;
		cout<<"Ref count: "<<aObj2.use_count()<<endl;
	}

	Func1(aObj1);

	Func2(aObj1);

	shared_ptr<int> aObj3 = Func2(aObj1);
	cout<<"Ref count:"<<aObj3.use_count()<<endl;

	return 0;
}