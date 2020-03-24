#include "Extends.h"

char* ContextName(const char* path) {
	int last_seen_separator = -1;
	int poz_of_extention = -1;
	int size_path_name = 0;
	char* rez = nullptr;
	for (int i = 0; path[i] != '\0'; i++)
	{
		size_path_name++;
		if (path[i] == '\\') last_seen_separator = i;
		if (path[i] == '.') poz_of_extention = i;
	}
	poz_of_extention = poz_of_extention == -1 ? size_path_name : poz_of_extention;
	rez = new char[poz_of_extention - last_seen_separator + 1];
	for (int i = last_seen_separator + 1; i < poz_of_extention; i++) {
		rez[i - last_seen_separator - 1] = path[i];
	}
	rez[poz_of_extention - last_seen_separator -1] = '\0';
	return rez;
}
