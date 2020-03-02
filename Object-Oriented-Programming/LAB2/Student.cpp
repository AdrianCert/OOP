#include "Student.h"
bool Student::Init(char* name, int n)
{
	if (n <= 20) {
		for (int i = 0; i <= n; i++) {
			Name[i] = name[i];
		}
		nMate = 0;
		nEnglish = 0;
		nHistory = 0;
		return true;
	}
	return false;
}
int Student::Get_nMate()
{
	return nMate;
}
int Student::Get_nEnglish() {
	return nEnglish;
}
int Student::Get_nHistory()
{
	return nHistory;
}
bool Student::Set_nMate(int x)
{
	if (x > 0 && x < 11) {
		nMate = x;
		return true;
	}
	return false;
}
bool Student::Set_nEnglish(int x)
{
	if (x > 0 && x < 11) {
		nEnglish = x;
		return true;
	}
	return false;
}
bool Student::Set_nHistory(int x)
{
	if (x > 0 && x < 11) {
		nHistory = x;
		return true;
	}
	return false;
}