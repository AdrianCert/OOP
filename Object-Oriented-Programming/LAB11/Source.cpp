#include "ArrayException.h"
#include <iostream>
#include <vector>

using namespace std;

class myComp : public Compare {
public:
	virtual int CompareElements(void* a, void* b) override
	{
		return *(int*)a - *(int*)b;
	}
};

int main() {
	Array<int> s;
	Array<int> b;
	myComp comp;
	try {
		s.Add(100);
		s.Add(80);
		s.Add(-1220);
		s.Add(5);
		s.Add(-20);
		s.Add(11);
		s.Add(-7);

		s += 10;
		s += 20;
		s += 30;
		s += 340;
		s += 40;
		s += 1;

		cout << "\nFirst instance: " << endl;
		for (auto i : s)
			cout << i << endl;
		
		cout << "\nSorting ..." << endl;
		s.Sort(&comp);
		auto funct = [](const int& a, const int& b)-> int { return a < 0 ? -(a - b) : a - b; };
		s.Sort(funct);
		for (auto i : s)
			cout << i << endl;


		cout << "Find element 1 in s: " << s.Find(1) << endl;
		cout << "Find element 1 in s using funct: " << s.Find(1,funct) << endl;
		cout << "Find element 12 in s: " <<s.Find(12) << endl;

		cout << "\nInserting ..." << endl;

		s.Insert(2, 22);
		s.Insert(2, 11);
		s.Insert(5, 14);
		s.Insert(6, 21);

		
		b+= 22;
		b+= 11;
		b+= 14;
		b+= 21;
		
		s.Insert(0, b);
		s.Insert(1, b);
		s.Insert(2, b);

		for (auto i : s)
			cout << i << endl;

		cout << "\nDeleting ..." << endl;

		s.Delete(2);
		s.Delete(2);
		s.Delete(2);

		for (auto i : s)
			cout << i << endl;
		s.Delete(222);
		// cout << "Binary search element 1 in s: " << s.BinarySearch(1) << endl;
		// cout << "Binary search element 12 in s: " << s.BinarySearch(12) << endl;
	}
	/*catch (out_range e)
	{
		cout << e.what() << endl;
		return 1;
	}*/
	catch (exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}
