#include <iostream>

int myAtoi(char* s) {
	int res = 0; 
 
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i]>='0' && s[i]<='9')
			res = res * 10 + s[i] - '0';
	}

	// return result. 
	return res;
}
// Function to Sort the array of string 
// according to lengths. This function  
// implements Insertion Sort.  
void sort(std::string s[], int n)
{
	for (int i = 1; i < n; i++)
	{
		std::string temp = s[i];

		// Insert s[j] at its correct position 
		int j = i - 1;
		while (j >= 0 && temp.length() < s[j].length())
		{
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = temp;
	}
}

int p2() {
	FILE* file;
	std::string arr[10];
	char chars[100];
	int wcount = 0;

	file = fopen("p2.in", "r");
	if (!file) {
		return 0;
	}
	fclose(file);
	if (fgets(chars, 100, file) != NULL) {
		arr[wcount] = "";
		for (int i = 0; chars[i] != '\0'; ++i) {
			if (chars[i] != ' ') {
				arr[wcount] += chars[i];
			}
			else {
				wcount++;
				arr[wcount] = "";
			}
		}
	}
	// sort by lenghts
	sort(arr, wcount);

	//distinction of words of the same alphabetical length
	for (int i = 1; i < wcount; i++)
	{
		if (arr[i - 1].length() == arr[i].length())
		{
			int k = i;
			while (arr[k].length() == arr[i - 1].length())
			{
				k++;
			}
			for (int sort_i = i - 1; i < k; i++)
			{
				for(int sort_j = i; sort_j < k; sort_j++)
				{
					if ( arr[sort_j - 1] > arr[sort_j])
					{
						std::string t;
						t = arr[sort_j];
						t = arr[sort_j - 1];
						arr[sort_j - 1] = arr[sort_j];
						arr[sort_j] = t;
					}
				}
			}
			i = k;
		}
	}

	for (int i = 0; i < wcount; i++)
	{
		//printf("%s \n", arr[i]);
		std::cout << arr[i] << " ";
	}

	return 0;
}

int main() {
	// play with problem 2 
	if (0)
	{
		p2();
		return 1;
	}
	FILE* file;
	char chars[100];
	//char* chars = 0;
	//chars = (char*)malloc(100 * sizeof(char));
	int sum = 0;
	file = fopen("p1.in", "r");
	if (!file) {
		return 0;
	}
	while (fgets(chars, 100, file) != NULL) {
		sum += myAtoi(chars);

	}
	fclose(file);

	printf("%d", sum);

	return 0;
}