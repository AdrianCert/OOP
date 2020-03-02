#include<stdlib.h>

class Student
{
	char Name[20];
	int nMate;
	int nEnglish;
	int nHistory;
public:
	bool Init(char* name, int n);
	int Get_nMate();
	int Get_nEnglish();
	int Get_nHistory();
	bool Set_nMate(int x);
	bool Set_nEnglish(int x);
	bool Set_nHistory(int x);
};

