#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
void Task1();
void Task2();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Task2();
	return 0;
}
char* CreateWord(char* line, int index, int secondIndex) {
	int size = secondIndex - index + 1;
	char* result = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size - 1; i++) {
		result[i] = line[index + i];
	}
	result[size - 1] = '\0';
	return result;
}
char* ReverseWord(char* line, int lenght) {
	char* result = (char*)malloc(sizeof(char) * (lenght + 1));
	for (int i = 0; i < lenght; i++) {
		result[lenght - i - 1] = line[i];
	}
	result[lenght] = '\0';
	return result;
}
void Task1() {
	char gChar[13] = "аеоуиіАЕОУИІ";
	char line[256];
	puts("Введіть речення");
	gets_s(line);
	int lenght = strlen(line);
	int count = 0;
	int start = -1;
	puts("Слова, які мають більше 2х голосних");
	for (int i = 0; i <= lenght; i++) {
		if (!(line[i] == ' ' || line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == '\0')) {
			for (int g = 0; g < 12;  g++) {
				if (line[i] == gChar[g]) {
					count++;
					break;
				}
			}
		}
		else {
			start++;
			if (count > 2) {
				puts(CreateWord(line, start, i));
			}
			count = 0;
			start = i;
		}
	}
}
void Task2() {
	char line[256];
	puts("Введіть речення");
	gets_s(line);
	int lenght = strlen(line);
	int start = -1;
	puts("Слова паліндроми:");
	for (int i = 0; i <= lenght; i++) {
		if ((line[i] == ' ' || line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == '\0')) {
			start++;
			char* word = CreateWord(line, start, i);
			if (!strcmp(word, ReverseWord(word, i - start))) {
				puts(word);
			}
			start = i;
		}
	}
}