#include <stdio.h>
#include <math.h>
#include <windows.h>
const double PI = 3.14159265358979;
double RadiansToDegree(double radians);
double DegreeToRadians(double degree);
double SeachAreaSizeU_HS(double h, double c);
double SeachSideU_SSD(double side1, double side2, double degree);
double GetDegreeU_SizSS(double side1, double side2, double areaSize);
double SeachSideU_SizDS(double side1, double degree1, double areaSize);
void CorrectDegree(double* alp, double* bet, double* gam, double sA, double sB, double sC);
void printStartInfo();
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b, c, S, P, h, alp, bet, gam;
	printf_s("Початок роботи\n");
	while (true)
	{
		printStartInfo();
		int workMode;
		scanf_s("%d", &workMode);
		if (workMode == 4) {
			return 0;
		}
		printf_s("Введіть необхідну інформацію про трикутник(кути в градусах)\n");
		switch (workMode)
		{
		case 1:
			printf_s("h = ");
			scanf_s("%lf", &h);
			printf_s("c = ");
			scanf_s("%lf", &c);
			printf_s("b = ");
			scanf_s("%lf", &b);
			S = SeachAreaSizeU_HS(h, c); // h c b S
			alp = GetDegreeU_SizSS(b,c,S); // alp h c b S
			a = SeachSideU_SSD(b,c,alp); // alp a h c b S P
			bet = GetDegreeU_SizSS(a, c, S);
			gam = GetDegreeU_SizSS(a, b, S); // end
			break;
		case 2:
			printf_s("h = ");
			scanf_s("%lf", &h);
			printf_s("c = ");
			scanf_s("%lf", &c);
			printf_s("alpha = ");
			scanf_s("%lf", &alp);
			alp = DegreeToRadians(alp);
			S = SeachAreaSizeU_HS(h, c);
			b = SeachSideU_SizDS(c, alp, S);
			a = SeachSideU_SSD(c,b, alp);
			bet = GetDegreeU_SizSS(a,c,S);
			gam = GetDegreeU_SizSS(a, b, S);
			break;
		case 3:
			printf_s("S = ");
			scanf_s("%lf", &S);
			printf_s("h = ");
			scanf_s("%lf", &h);
			printf_s("beta = ");
			scanf_s("%lf", &bet);
			bet = DegreeToRadians(bet);
			c = 2 * S / h;
			a = SeachSideU_SizDS(c, bet, S);
			b = SeachSideU_SSD(a,c, bet);
			gam = GetDegreeU_SizSS(a, b, S);
			alp = GetDegreeU_SizSS(c, b, S);
			break;
		default:
			printf_s("Введено невірне число!\n");
			continue;
		}
		P = a + b + c;
		printf_s("Сторони трикутника a = %lf,b = %lf, c= %lf\n", a, b, c);
		printf_s("Площа трикутника = %lf\n", S);
		printf_s("Периметр трикутника = %lf\n", P);
		CorrectDegree(&alp,&bet,&gam,a,b,c);
		printf_s("Кути альфа = %lf,\n бета = %lf, гама = %lf\n",
			RadiansToDegree(alp), RadiansToDegree(bet), RadiansToDegree(gam));
		printf_s("-----------------------------------------------------\n");
	}
}
double DegreeToRadians(double degree) {
	return degree / 180.0 * PI;
}
double RadiansToDegree(double radians) {
	return radians * 180.0 / PI;
}
void printStartInfo() {
	printf_s("Оберіть режим роботи\n");
	printf_s("Обчислити параметри трикутника через:\n");
	printf_s("1-висоту проведену до сторони с, сторону b та сторону с\n");
	printf_s("2-висоту проведену до сторони с, сторону с та кут між с та b\n");
	printf_s("3-площу, висоту проведену до с та кут між с та а\n");
	printf_s("4-вихід з програми\n");
}
double SeachAreaSizeU_HS(double h, double c) {
	return h * c / 2.0;
}
double SeachSideU_SSD(double side1, double side2, double degree) {
	return sqrt(pow(side1, 2) + pow(side2, 2) - 2 * side1 * side2 * cos(degree));
}
double GetDegreeU_SizSS(double side1, double side2, double areaSize) {
	return asin(2.0 * areaSize / (side1 * side2));
}
double SeachSideU_SizDS(double side1, double degree1, double areaSize) {
	return 2 * areaSize / (side1 * sin(degree1));
}
void CorrectDegree(double* alp, double* bet, double* gam, double sA, double sB, double sC) {
	if (pow(sA,2) + pow(sB,2) - pow(sC, 2) < 0 && *gam < PI/2) {
		*gam = -*gam + PI;
	}
	if (pow(sA, 2) + pow(sC, 2) - pow(sB, 2) < 0 && *bet < PI / 2) {
		*bet = -*bet + PI;
	}
	if (pow(sC, 2) + pow(sB, 2) - pow(sA, 2) < 0 && *alp < PI / 2) {
		*alp = -*alp + PI;
		double als = 1E0;
	}
}