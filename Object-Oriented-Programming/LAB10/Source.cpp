#include<stdio.h>
#include<algorithm>  
#include<vector>
#include<string>
#include<list>
#include "myVector.h"

using namespace std;

#pragma region ShowContext
struct showMe {
	const char* name;
	showMe(const char* _name):name(_name) {
		printf("\n\tContext execution %s \n",name);
		printf("_________________________________________________\n\n");
	}
	~showMe() {
		printf("\n_________________________________________________\n");
		printf("\tEnd context execution %s\n", name);
	}
};
#define __context(s) showMe showMeInstance(s)
#define __cts showMe showMeInstance(__FUNCSIG__);
#pragma endregion

void ex_01()
{
	__context("Exercitiul 1");
	bool reverse = false;
	vector<string> sample_vector{
		"info",
		"iasi",
		"program",
		"cpp",
		"std"
	};
	sort(sample_vector.begin(), sample_vector.end(), [&reverse](string a, string b) ->  bool { return (a.size() == b.size() ? a < b : a.size() < b.size()) xor reverse; });
	for (auto i : sample_vector) {
		printf("%s\n", i.c_str());
	}
	printf("\nReverse sorting \n");
	reverse = true;
	sort(sample_vector.begin(), sample_vector.end(), [&reverse](string a, string b) ->  bool { return (a.size() == b.size() ? a < b : a.size() < b.size()) xor reverse; });
	for (auto i : sample_vector) {
		printf("%s\n", i.c_str());
	}
}

void ex_02()
{
	__cts;
	list<int> sample_list;
	sample_list.push_back(10);
	sample_list.push_back(20);
	sample_list.push_back(21);
	sample_list.push_back(12);
	sample_list.push_back(6);
	sample_list.push_back(12);
	sample_list.push_back(8);
	sample_list.push_back(17);
	sample_list.push_back(27);
	sample_list.push_back(83);
	auto max = [](list<int> x) mutable -> int {int max = *x.begin(); for (auto i : x) if (max < i) max = i; return max; };

	int mint_ = max(sample_list);
	printf("%d\n", mint_);
	
	sample_list.pop_back();
	mint_ = max(sample_list);
	printf("%d\n", mint_);
}

int main()
{
	ex_01();
	ex_02();
	__context("myVector");

	mVector a;

	a.Add(20);
	a.Add(21);
	a.Add(212);
	a.Add(6);
	a.Add(12);
	a.Add(8);
	a.Add(17);
	a.Add(27);
	a.Add(83);
	printf("\nThe vector after add\n");
	a.Print();

	printf("\nDelete index 3 from vector\n");
	a.Delete(3);
	a.Print();

	a.Iterate([](int & a) { a += 2; });
	printf("\nThe vector after iteration\n");
	a.Print();

	a.Filter([](int x) { return x % 7 != 0; });
	printf("\nThe vector after filter\n");
	a.Print();

	return 0;
}