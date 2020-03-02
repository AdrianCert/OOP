#include <iostream>
using namespace std;

int myAtoi(char* s) {
	int res = 0; 
 
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i]>='0' && s[i]<='9')
			res = res * 10 + s[i] - '0';
	}

	// return result. 
	return res;
}

int p2() {
	FILE* file;
	char chars[100];
	char m[10][20];
	int sum = 0;
	int wcount = 0;
	int word[10];
	int order[10];
	for (int i = 0; i < 10; i++) {
		word[i] = 0;
		order[i] = 0;
	}

	file = fopen("p2.in", "r");
	if (!file) {
		return 0;
	}
	if (fgets(chars, 100, file) != NULL) {
		for (int i = 0; chars[i] != '\0'; ++i) {
			if (chars[i] != ' ') {
				word[wcount]++;
				m[wcount][word[wcount]] = chars[i];
			}
			else {
				wcount++;
			}
		}
	}

	for (int i = 0; i <= wcount; i++) {
		for (int j = 0; j <= wcount; j++) {
			if (word[i] < word[order[i]]) {
				for (int z = i; j > z; z--) {
					order[z] = order[z - 1];
				}
				order[j] = i;
			}
			else if (word[i] == word[order[i]]) {
				// pune problema sortarii pe aflabetice
			}
		}
	}

	for (int i = 0; i < wcount; i++) {
		for (int j = 0; j < word[order[i]]; i++) {
			printf("%c", m[order[i]][j]);
		}
		printf("\n");
	}

	fclose(file);

	printf("%d", sum);
}

int main() {
	// play with problem 2 
	if (1)
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