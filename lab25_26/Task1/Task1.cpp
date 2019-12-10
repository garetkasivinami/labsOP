#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "DList.h"
struct SchoolChild {
public:
	char *FirstName;
	char *SecondName;
	char *FatherName;
	int SLW; // стать, клас, зріст та вага закодовані в бітному форматі
	// 0000 0000 0000 ВВВВ ВВВК КККЗ ЗЗЗЗ ЗЗЗС
	int BirthData; // Закодована дата народження
	// 0000 0000 000Р РРРР РРРР РРРМ МММД ДДДД
	long long NumberPhone;
	char *Adress;
	char *School;
};
void CheckError();
void FindName(char* name);
void FindSecondName(char* name);
void FindFatherName(char* name);
void FindBirthDate(int day, int month, int year);
void FindBirthDateG(int day, int month, int year);
void FindBirthDateL(int day, int month, int year);
void FindBirthYear(int year);
void FindBirthYearG(int year);
void FindBirthYearL(int year);
void FindState(int value);
void FindClass(int value);
void FindClassG(int value);
void FindClassL(int value);
void FindHeight(int value);
void FindHeightG(int value);
void FindHeightL(int value);
void FindWeight(int value);
void FindWeightG(int value);
void FindWeightL(int value);
void FindAdress(char* value);
void FindSchool(char* value);
void FindNumber(long long value);
void FindNumberG(long long value);
void FindNumberL(long long value);
void FindMenu();
void NumberSeach(int index);
void StringSeach(int);
void StateSeach();
void DateSeach();
void PrintArr();
void SortTableMenu();
char* GETS();
void PrintHeader();
void PrintElement(int index);
char* GetCopy(char*);
int ConvertData(int, int, int, int);
void ConvertData(int);
int ConvertDate(int, int, int);
void ConvertDate(int);
void Add(SchoolChild*);
void Remove(int index);
void printfLine();
void printfHLine();
int GetYear(int data);
int GetMonth(int data);
int GetDay(int data);
int GetSex(int data);
int GetClass(int data);
int GetHeight(int data);
int GetWeight(int data);
SchoolChild* CreateNew(char*, char*, char*, int, int, int, int, int, int, int, long long, char*, char*);
int cmp_name(const void* fir, const void* sec);
int cmp_secondName(const void* fir, const void* sec);
int cmp_fatherName(const void* fir, const void* sec);
int cmp_numberPhone(const void* fir, const void* sec);
int cmp_birthDate(const void* fir, const void* sec);
int cmp_sex(const void* fir, const void* sec);
int cmp_class(const void* fir, const void* sec);
int cmp_height(const void* fir, const void* sec);
int cmp_weight(const void* fir, const void* sec);
int cmp_adress(const void* fir, const void* sec);
int cmp_school(const void* fir, const void* sec);
void CreateNewScanf();
void Menu(int target);
void SortArray(int type);
int day = 0, month = 0, year = 0;
int weight = 0, sex = 0, _class = 0, height = 0;
int reallySize = 0;
int lenghtArr = 0;
SchoolChild* list; // резервуємо для 0 дітей :D
int main() {
	/*list = (SchoolChild*)malloc(0);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number;
	CreateNew(new char[5]{"Anto"}, new char[5]{ "kek" }, new char[5]{ "Fran" }, 3, 1, 2009, 1, 11, 195, 75, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	CreateNew(new char[5]{ "key" }, new char[5]{ "cha" }, new char[5]{ "dech" }, 8, 11, 2006, 0, 9, 185, 75, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	CreateNew(new char[5]{ "mey" }, new char[5]{ "by" }, new char[5]{ "long" }, 15, 6, 2002, 1, 11, 180, 76, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	CreateNew(new char[5]{ "ley" }, new char[5]{ "rek" }, new char[5]{ "int" }, 28, 8, 2001, 0, 7, 190, 65, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	CreateNew(new char[5]{ "bey" }, new char[5]{ "xa" }, new char[5]{ "lof" }, 26, 4, 1999, 1, 11, 199, 85, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	CreateNew(new char[5]{ "bzzz" }, new char[5]{ "Lxa" }, new char[5]{ "doub" }, 23, 7, 2010, 0, 6, 180, 65, 380973269205, new char[5]{ "Sch" }, new char[5]{ "Five" });
	printf_s("Програмування з використанням структур 1.0!\n");
	while (1) {
		puts("Меню");
		puts("1 - створення нового записа");
		puts("2 - видалення існуючого записа");
		puts("3 - виведення таблиці");
		puts("4 - сортування таблиці за...");
		puts("5 - пошук запису за параметром...");
		puts("6 - збереження (не реалізовано)");
		puts("7 - завантаження (не реалізовано)");
		puts("8 - очистити консоль");
		puts("0 - вихід");
		scanf_s("%d", &number);
		if (number == 0) {
			break;	
		}
		Menu(number);
	}*/
	DList<int> list;
	list.Add(16);
	list.Add(15);
	list.Add(14);
	list.RemoveAt(2);
	int numbers[5] = {15,96,32,45,22};
	list.Add(numbers, 5);
	for (int i = 0; i < 7; i++) {
		printf_s("%d\n", list[i]);
	}
	char o1[10] = "test1";
	char o2[8] = "test2";
	char o3[6] = "test3";
	char o4[9] = "test4";
	char o5[7] = "test5";
	DList<char*> CharList;
	CharList.Add(o1);
	CharList.Add(o2);
	CharList.Add(o3);
	CharList.Add(o4);
	CharList.Add(o5);
	for (int i = 0;i < 5; i++) {
		puts(CharList[i]);
	}
	return 0;
}
void Menu(int target) {
	printfHLine();
	switch (target)
	{
	case 1:
		CreateNewScanf();
		break;
	case 2:
		puts("Напишіть індекс для видалення");
		int index;
		scanf_s("%d", &index);
		Remove(index);
	case 3:
		PrintArr();
		break;
	case 4:
		SortTableMenu();
		break;
	case 5:
		FindMenu();
		break;
	case 8:
		system("cls");
		break;
	default:
		puts("Wrong target");
		break;
	}
}
void SortTableMenu() {
	puts("Оберіть за яким параметром сортувати");
	puts("1 - за іменем");
	puts("2 - за фамілією");
	puts("3 - по-батькові");
	puts("4 - по номеру");
	puts("5 - по даті народження");
	puts("6 - по статі");
	puts("7 - по класу");
	puts("8 - по висоті");
	puts("9 - по вазі");
	puts("10 - по адресі");
	puts("11 - по школі");
	int target;
	scanf_s("%d", &target);
	SortArray(target);
}
void FindMenu() {
	puts("Оберіть за чим шукати");
	puts("1 - за іменем");
	puts("2 - за фамілією");
	puts("3 - по-батькові");
	puts("4 - по номеру");
	puts("5 - по класу");
	puts("6 - по висоті");
	puts("7 - по вазі");
	puts("8 - по даті народження");
	puts("9 - по статі");
	puts("10 - по адресі");
	puts("11 - по школі");
	int index;
	scanf_s("%d", &index);
	if (index > 0 && index < 4 || index > 8 && index < 12) {
		StringSeach(index);
	}
	else if (index == 4) {
		int mode;
		long long numb;
		scanf_s("%lld", &numb);
		puts("Оберіть режим");
		puts("1 - ==");
		puts("2 - >=");
		puts("3 - <=");
		scanf("%d", &mode);
		if (mode == 1)
			FindNumber(numb);
		else if (mode == 2)
			FindNumberG(numb);
		else
			FindNumberL(numb);
	}
	else if (index > 4 && index < 8) {
		NumberSeach(index);
	}
	else if (index == 9) {
		StateSeach();
	}
	else if (index == 8) {
		DateSeach();
	}
	else {
		puts("Wrong index");
	}
}
void NumberSeach(int index) {
	puts("Введіть значення");
	int numb, mode;
	scanf_s("%d", &numb);
	puts("Оберіть режим");
	puts("1 - ==");
	puts("2 - >=");
	puts("3 - <=");
	scanf("%d", &mode);
	switch (index)
	{
	case 5:
		if (mode == 3)
			FindClass(numb);
		else if (mode == 2)
			FindClassG(numb);
		else
			FindClassL(numb);
		break;
	case 6:
		if (mode == 3)
			FindHeight(numb);
		else if (mode == 2)
			FindHeightG(numb);
		else
			FindHeightL(numb);
		break;
	case 7:
		if (mode == 3)
			FindWeight(numb);
		else if (mode == 2)
			FindWeightG(numb);
		else
			FindWeightL(numb);
		break;
	default:
		break;
	}
}
void StringSeach(int index) {
	getchar();
	puts("Напишіть строку для пошуку");
	char* string = GETS();
	switch (index)
	{
	case 1:
		FindName(string);
		break;
	case 2:
		FindSecondName(string);
		break;
	case 3:
		FindFatherName(string);
		break;
	case 10:
		FindAdress(string);
		break;
	case 11:
		FindSchool(string);
		break;
	default:
		break;
	}
}
void StateSeach() {
	puts("Введіть стать(0 - жіноча, 1 - чоловіча)");
	scanf_s("%d", &sex);
	FindState(sex);
}
void DateSeach() {
	int mode1, mode2;
	puts("Оберіть режим");
	puts("1 - тільки рік");
	puts("2 - повна дата");
	scanf_s("%d", &mode1);
	puts("Оберіть режим");
	puts("1 - ==");
	puts("2 - >=");
	puts("3 - <=");
	scanf("%d", &mode2);
	puts("Введіть рік");
	scanf_s("%d", &year);
	switch (mode1)
	{
	case 1:
		if (mode2 == 2)
			FindBirthYearG(year);
		else if (mode2 == 3)
			FindBirthYearL(year);
		else
			FindBirthYear(year);
		break;
	case 2:
		puts("Введіть місяць");
		scanf_s("%d", &month);
		puts("Введіть день");
		scanf_s("%d", &day);
		if (mode2 == 1)
			FindBirthDateG(day, month, year);
		else if (mode2 == 2)
			FindBirthDateL(day, month, year);
		else
			FindBirthDate(day, month, year);
		break;
	default:
		break;
	}
}
void CreateNewScanf() {
	char *fname = NULL, *sname = NULL, *fhname = NULL, *adress = NULL, *school = NULL;
	getchar();
	puts("Введіть імя");
	fname = GETS();
	puts("Введіть фамілію");
	sname = GETS();
	puts("Введіть по-батькові");
	fhname = GETS();
	puts("Введіть школу");
	adress = GETS();
	puts("Введіть адресу");
	school = GETS();
	//
	puts("Введіть стать(0 - жіноча, 1 - чоловіча)");
	scanf_s("%d", &sex);
	puts("Введіть вагу");
	scanf_s("%d", &weight);
	puts("Введіть висоту");
	scanf_s("%d", &height);
	puts("Введіть клас");
	scanf_s("%d", &_class);
	//
	long long number = 2;
	puts("Номер телефона");
	scanf_s("%lld", &number);
	puts("Введіть день народження");
	scanf_s("%ld", &day);
	puts("Введіть місяць народження");
	scanf_s("%ld", &month);
	puts("Введіть рік народження");
	scanf_s("%ld", &year);
	//
	CreateNew(fname, sname, fhname, day, month, year, sex, _class, height, weight, number, adress, school);
	//
	free(fname);
	free(sname);
	free(fhname);
	free(adress);
	free(school);
}
char* GETS() {
	char* string = (char*)malloc(sizeof(char) * 256);
	gets_s(string, 256);
	string = (char*)realloc(string, sizeof(char) * (strlen(string) + 1));
	return string;
}
void PrintArr() {
	PrintHeader();
	if (lenghtArr == 0) {
		puts("NoData!");
	}
	for (int i = 0; i < lenghtArr; i++) {
		PrintElement(i);
	}
	printfHLine();
}
void PrintHeader() {
	printfLine();
	printf_s("|  №  ");
	printf_s("|    Ім'я    |");//12
	printf_s("  Фамілія   |");//12
	printf_s(" По-батькові  |");//14
	printf_s("День|");//4
	printf_s("Місяць|");//6
	printf_s(" Рік |");//5
	printf_s("Стать|");//5
	printf_s("Клас|");//4
	printf_s("Зріст|");//5
	printf_s("Вага|");//4
	printf_s("            Адреса            |");//20
	printf_s("            Школа             |");//20
	printf_s("Номер телефона |\n");
	printfHLine();
}
void PrintElement(int index) {
	SchoolChild* element = &list[index];
	printf_s("|%5d", index);
	printf_s("|%-12s|", element->FirstName);
	printf_s("%-12s|", element->SecondName);
	printf_s("%-14s|", element->FatherName);
	ConvertDate(element->BirthData);
	printf_s("%4d|", day);
	printf_s("%6d|", month);
	printf_s("%5d|", year);
	ConvertData(element->SLW);
	if (sex)
		printf_s("чол. |");
	else
		printf_s("жін. |");
	printf_s("%4d|", _class);
	printf_s("%5d|", height);
	printf_s("%4d|", weight);
	printf_s("%-30s|", element->Adress);
	printf_s("%-30s|", element->School);
	printf_s("+%-14lld|\n", element->NumberPhone);
}
char* GetCopy(char* target) {
	char* result = new char[strlen(target) + 1];
	strcpy(result, target);
	return result;
}
int ConvertData(int sex, int _class, int lenght, int weight) {
	int result = sex;
	lenght = lenght << 1;
	result += lenght;
	_class = _class << 9;
	result += _class;
	weight = weight << 13;
	result += weight;
	return result;
}
void ConvertData(int data) {
	sex = data & 1;
	data = data >> 1;
	height = data & 255;
	data = data >> 8;
	_class = data & 15;
	data = data >> 4;
	weight = data & 127;
}
int ConvertDate(int day, int month, int year) {
	int result = day;
	month = month << 5;
	result += month;
	year = year << 9;
	result += year;
	return result;
}
void ConvertDate(int data) {
	day = data & 31;
	data = data >> 5;
	month = data & 15;
	data = data >> 4;
	year = data & 4095;
}
void Add(SchoolChild* child) {
	lenghtArr++;
	if (lenghtArr > reallySize) {
		list = (SchoolChild*)realloc(list, sizeof(SchoolChild) * lenghtArr);
		reallySize++;
	}
	list[lenghtArr - 1] = *child;
}
void Remove(int index) {
	SchoolChild temp = list[index];
	lenghtArr--;
	list[index] = list[lenghtArr];
}
void printfLine() {
	printf_s("___________________________________________________________________________________________________________________________________________________\n");
}
void printfHLine() {
	printf_s("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
SchoolChild* CreateNew(char *firstName, char *secondName, char *fatherName, int dayB, int monthB, int yearB, int sex, int _class, int height, int weight, long long numberPhone, char *adress, char *school) {
	SchoolChild child = {GetCopy(firstName), GetCopy(secondName), GetCopy(fatherName), ConvertData(sex, _class, height, weight), ConvertDate(dayB, monthB, yearB), numberPhone, GetCopy(adress), GetCopy(school)};
	strcpy(child.FirstName, firstName);
	Add(&child);
	return &child;
}
void FindName(char *name) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (strcmp(list[i].FirstName, name) == 0) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindSecondName(char *name) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (strcmp(list[i].SecondName, name) == 0) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindFatherName(char* name) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (strcmp(list[i].FatherName, name) == 0) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthDate(int day, int month, int year) {
	PrintHeader();
	CheckError();
	int data = ConvertDate(day,month,year);
	for (int i = 0; i < lenghtArr; i++) {
		if (data == list[i].BirthData) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthDateG(int day, int month, int year) {
	PrintHeader();
	CheckError();
	int data = ConvertDate(day, month, year);
	for (int i = 0; i < lenghtArr; i++) {
		if (data <= list[i].BirthData) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthDateL(int day, int month, int year) {
	PrintHeader();
	CheckError();
	int data = ConvertDate(day, month, year);
	for (int i = 0; i < lenghtArr; i++) {
		if (data >= list[i].BirthData) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthYear(int year) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (year == GetYear(list[i].BirthData)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthYearG(int year) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (year <= GetYear(list[i].BirthData)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindBirthYearL(int year) {
	PrintHeader();
	CheckError();
	int data = ConvertDate(day, month, year);
	for (int i = 0; i < lenghtArr; i++) {
		if (year >= GetYear(list[i].BirthData)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindState(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value == GetSex(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindClass(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value == GetClass(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindClassG(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value <= GetClass(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindClassL(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value >= GetClass(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindHeight(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value == GetHeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindHeightG(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value <= GetHeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindHeightL(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value >= GetHeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindWeight(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value == GetWeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindWeightG(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value <= GetWeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindWeightL(int value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value >= GetWeight(list[i].SLW)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindAdress(char *value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (!strcmp(value, list[i].Adress)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindSchool(char* value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (!strcmp(value, list[i].School)) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindNumber(long long value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value == list[i].NumberPhone) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindNumberL(long long value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value >= list[i].NumberPhone) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void FindNumberG(long long value) {
	PrintHeader();
	CheckError();
	for (int i = 0; i < lenghtArr; i++) {
		if (value <= list[i].NumberPhone) {
			PrintElement(i);
		}
	}
	printfHLine();
}
void CheckError() {
	if (lenghtArr == 0) {
		printf_s("NO_DATA\n");
		return;
	}
}
int GetYear(int data) {
	return (data >> 9) & 4095;
}
int GetMonth(int data) {
	return (data >> 5) & 15;
}
int GetDay(int data) {
	return data & 31;
}
int GetSex(int data) {
	return data & 1;
}
int GetClass(int data) {
	return (data >> 9) & 15;
}
int GetHeight(int data) {
	return (data >> 1) & 255;
}
int GetWeight(int data) {
	return (data >> 13) & 127;
}
int cmp_name(const void *fir, const void *sec) {
	return strcmp(((SchoolChild*)fir)->FirstName, ((SchoolChild*)sec)->FirstName);
}
int cmp_secondName(const void* fir, const void* sec) {
	return strcmp(((SchoolChild*)fir)->SecondName, ((SchoolChild*)sec)->SecondName);
}
int cmp_fatherName(const void* fir, const void* sec) {
	return strcmp(((SchoolChild*)fir)->FatherName, ((SchoolChild*)sec)->FatherName);
}
int cmp_numberPhone(const void* fir, const void* sec) {
	long long res = ((SchoolChild*)fir)->BirthData - ((SchoolChild*)sec)->BirthData;
	return (res == 0) ? 0: ((res > 0)? 1: -1);
}
int cmp_birthDate(const void* fir, const void* sec) {
	int res = ((SchoolChild*)fir)->BirthData - ((SchoolChild*)sec)->BirthData;
	return (res == 0) ? 0 : ((res > 0) ? 1 : -1);
}
int cmp_sex(const void* fir, const void* sec) {
	return (((SchoolChild*)fir)->SLW & 1) - (((SchoolChild*)sec)->SLW & 1);
}
int cmp_class(const void * fir, const void* sec) {
	int res = GetClass(((SchoolChild*)fir)->SLW) - GetClass(((SchoolChild*)sec)->SLW);
	return (res == 0) ? 0 : ((res > 0) ? 1 : -1);
}
int cmp_height(const void* fir, const void* sec) {
	int res = GetHeight(((SchoolChild*)fir)->SLW) - GetHeight(((SchoolChild*)sec)->SLW);
	return (res == 0) ? 0 : ((res > 0) ? 1 : -1);
}
int cmp_weight(const void* fir, const void* sec) {
	int res = GetWeight(((SchoolChild*)fir)->SLW) - GetWeight(((SchoolChild*)sec)->SLW);
	return (res == 0) ? 0 : ((res > 0) ? 1 : -1);
}
int cmp_adress(const void* fir, const void* sec) {
	return strcmp(((SchoolChild*)fir)->Adress, ((SchoolChild*)sec)->Adress);
}
int cmp_school(const void* fir, const void* sec) {
	return strcmp(((SchoolChild*)fir)->School, ((SchoolChild*)sec)->School);
}
void SortArray(int type) {
	switch (type)
	{
	case 1: // по імені
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_name);
		break;
	case 2: // по фамілії
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_secondName);
		break;
	case 3: // по-батькові
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_fatherName);
		break;
	case 4: // по номеру
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_numberPhone);
		break;
	case 5: // по даті народження
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_birthDate);
		break;
	case 6: // по статі
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_sex);
		break;
	case 7: // по класу
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_class);
		break;
	case 8: // по висоті
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_height);
		break;
	case 9: // по вазі
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_weight);
		break;
	case 10: // по адресі
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_adress);
		break;
	case 11: // по школі
		qsort(list, lenghtArr, sizeof(SchoolChild), cmp_school);
		break;
	default:
		break;
	}
	PrintArr();
}