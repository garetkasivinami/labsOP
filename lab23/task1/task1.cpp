#include <stdio.h>
#include <string>
#include <Windows.h>
void Task1();
void Task2();
void Task3();
void Task4();

int CmpWords(char *word, char *target,int startIndex, int length) {
	int i = 0;
	for (; i < length && target[i] != '\0'; i++) {
		if (target[i] != word[i + startIndex]) {
			return 0;
		}
	}
	if (i < length || i < strlen(target)) {
		return 0;
	}
	return 1;
}
int IsLatish(char _char) {
	if (_char >= 'a' && _char <= 'z' || _char >= 'A' && _char <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}
int IsLetter(char _char) {
	if (_char >= 'a' && _char <= 'z' || _char >= 'A' && _char <= 'Z' || _char >= 'А' && _char <= 'Я'|| _char >= 'а' && _char <= 'я') {
		return 1;
	}
	else {
		return 0;
	}
}
void MostlyWord(char* line) {
	int i = -1;
	int startIndex = 0;
	int length = 0;
	int mLength = 0;
	while (line[i++] != '\0') {
		if (IsLetter(line[i])) {
			length++;
		}
		else {
			if (length > mLength) {
				mLength = length;
				startIndex = i - mLength;
			}
			length = 0;
		}
	}
	if (length > mLength) {
		mLength = length;
	}
	char* word = new char[mLength+1];
	for (int i = 0; i < mLength; i++) {
		word[i] = line[i + startIndex];
	}
	word[mLength] = '\0';
	puts(word);
}
void AddWord(char *line, int index, int firstSize, int secondSize, char *word) {
	int length = strlen(line) + 1;
	int coef = (secondSize > firstSize) ? secondSize - firstSize: 0;
	if (coef) {
		line = (char*)realloc(line, (length + coef) * sizeof(char));
		for (int z = length + 1; z >= index + secondSize; z--) {
			line[z] = line[z - coef];
		}
	}
	for (int i = 0; i < secondSize; i++) {
		line[index + i] = word[i];
	}
	//
	if (secondSize < firstSize) {
		int z = index + secondSize - 1;
		coef = firstSize - secondSize;
		while (line[z++] != '\0')
		{
			line[z] = line[z + coef];
		}
		line = (char*)realloc(line, strlen(line) * sizeof(char));
	}
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
void Help() {
	char prigolos[26] = "бвгджзйклмнпрстфxцчш";
	int countL = strlen(prigolos);
	char line[256] = "баба мила мило детерминант матриц поляки стронг";
	int startindex = -1;
	int count = strlen(line);
	int lenght = 0;
	for (int i = 0; i < count + 1; i++) {
		if (IsLetter(line[i])) {
			lenght++;
		}
		else {
			if (lenght > 0) {
				startindex++;
				char *word = CreateWord(line, startindex, i);
				int u = 0;
				for (int b = 0; b < lenght; b++) {
					for (int v = 0; v < countL; v++) {
						if (word[b] == prigolos[v]) {
							u++;
							break;
						}
					}
				}
				if (u % 2 == 1) {
					puts(word);
				}
			}
			startindex = i;
			lenght = 0;
		}
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	return 1;
}
void Task1() {
	char line[256];
	puts("Введіть лінію для розрахунку кількості малих літер");
	gets_s(line);
	int counter = -1;
	int result = 0;
	while (line[counter++])
	{
		if (line[counter] >= 'a' && line[counter] <= 'z') {
			result++;
		}
	}
	printf_s("%d\n", result);
}
void Task2() {
	puts("Введіть лінію дял розрахунку кількості малих літер");
	char *line = new char[256];
	gets_s(line, 256);
	for (int i = 0; line[i] != '\0'; i++) {
		if (isspace(line[i]) && isspace(line[i + 1])) {
			for (int k = i; line[k] != '\0'; k++)
				line[k] = line[k + 1]; i--;
		}
	}
	puts(line);
}
void Task3() { // варто доробити
	char* line = new char[256]{"word is good! word kek word kol lol zgd nmg word"};
	char* target = new char[10] {"word"};
	char* newword = new char[6]{ "Kekee" };
	int startIndex = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ' && line[i] != ',' && line[i] != '.' && line[i] != '\0') {
			startIndex = i;
			for (; line[i] != ' ' && line[i] != ',' && line[i] != '.' && line[i] != '\0'; i++) {

			}
			if (CmpWords(line, target, startIndex, i - startIndex)) {
				printf_s("True\n");
				AddWord(line, i - 4, 4, 5, newword);
			}
		}
	}
	puts(line);
}

void Task4() {
	char* line = new char[256]{"Was лол еуе кек is das міша  дурачок(lol kek)[symv] (lalaley)[(none)]"};
	int skobkaC = 0;
	int skobkaS = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		switch (line[i])
		{
		case '(':
			skobkaC++;
			break;
		case ')':
			skobkaC--;
			break;
		case '[':
			skobkaS++;
			break;
		case ']':
			skobkaS--;
			break;
		default:
			break;
		}
	}
	printf_s("LOl %d\n", skobkaC);
	printf_s("LOl %d\n", skobkaS);
	int startIndex;
	char* result;
	char* mostWord = new char[1];
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ' && line[i] != ',' && line[i] != '.' && line[i] != '\0') {
			startIndex = i;
			for (; line[i] != ' ' && line[i] != ',' && line[i] != '.' && line[i] != '\0'; i++) {

			}
			result = CreateWord(line, startIndex, i);
			if (strlen(result) > strlen(mostWord)) {
				mostWord = result;
			}
		}
	}
	MostlyWord(line);
	startIndex = -1;
	int length = 0;
	int tLength = 0;
	int count = strlen(line);
	for (int i = 0; i < count; i++)
	{
		if (IsLetter(line[i])) {
			length++;
			if (IsLatish(line[i])) {
				tLength++;
			}
		}
		else {
			if (length > 0 && tLength == length) {
				startIndex++;
				for (int m = 0; m < length; m++) {
					for (int z = startIndex; z < count - 1; z++) {
						line[z] = line[z + 1];
					}
					i--;
				}
				count -= length;
			}
			startIndex = i;
			length = 0;
			tLength = 0;
		}
	}
	line = (char*)realloc(line,sizeof(char) * (count + 1));
	line[count] = '\0';
	puts(line);
}