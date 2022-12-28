#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

struct point 
{
	float x;
	float y;
	char name;
};

typedef struct point Point;
typedef struct employee Employee;

int put_point(Point z);
float dist(Point z, Point w);
float findCenterX(Point z, Point w);
float findCenterY(Point z, Point w);

struct employee 
{
	char lastname[32];
	char name[32];
	char patronymic[32];
	char position[32];
	char floor[32];
	int day;
	int month;
	int year;
};


int put_point(Point z) 
{
	printf("\npoint %c (%.1f; %.1f)", z.name, z.x, z.y);
	return 0;
}

float dist(Point z, Point w) 
{
	float res = sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
	return res;
}

float findCenterX(Point z, Point w) 
{
	float res = (z.x + w.x) / 2;
	return res;
}

float findCenterY(Point z, Point w)
{
	float res = (z.y + w.y) / 2;
	return res;
}
int main(void)
{
	setlocale(LC_ALL, "RUS");

	// 1
	Point b, a;
	printf("Введите название 1 точки: ");
	scanf("%c", &a.name);
	printf("Введите x координату 1 точки: ");
	scanf("%f", &a.x);
	printf("Введите y координату 1 точки: ");
	scanf("%f", &a.y);
	getchar();
	printf("Введите название 2 точки: ");
	scanf("%c", &b.name);
	getchar();
	printf("Введите x координату 2 точки: ");
	scanf("%f", &b.x);
	printf("Введите y координату 2 точки: ");
	scanf("%f", &b.y);
	put_point(a);
	put_point(b);
	printf("\nРасстояние между %c и %c = %f", a.name, b.name, dist(a, b));
	printf("\nЦентр отрезка между точками %c и %c находится в точке M(%.2f;%.2f)", a.name, b.name, findCenterX(a, b), findCenterY(a, b));
	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("\n\nМосковское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	switch (mytime->tm_wday)
	{
	case 0:
		printf("\nСегодня воскресенье");
		break;
	case 1:
		printf("\nСегодня понедельник");
		break;
	case 2:
		printf("\nСегодня вторник");
		break;
	case 3:
		printf("\nСегодня среда");
		break;
	case 4:
		printf("\nСегодня четверг");
		break;
	case 5:
		printf("\nСегодня пятница");
		break;
	case 6:
		printf("\nСегодня суббота");
		break;
	default:
		printf("\nУ вас странная неделя");

	}

	//3

	puts("\n");

	Employee report;
	puts("Введите фамилию сотрудника: ");
	scanf("%s", report.lastname);
	puts("Введите имя сотрудника:");
	scanf("%s", report.name);
	puts("Введите отчество сотрудника:");
	scanf("%s", report.patronymic);
	puts("Введите должность сотрудника:");
	scanf("%s", report.position);
	puts("Введите пол сотрудника:");
	scanf("%s", report.floor);
	puts("Введите день приёма сотрудника на работу:");
	scanf("%d", &report.day);
	puts("Введите месяц приёма сотрудника на работу:");
	scanf("%d", &report.month);
	puts("Введите год приёма сотрудника на работу:");
	scanf("%d", &report.year);

	printf("\nСотрудник: %s %s %s.\n", report.lastname, report.name, report.patronymic);
	printf("Должность: %s.\n", report.position);
	printf("Пол: %s.\n", report.floor);
	printf("Дата приёма сотрудника на работу: %d:%d:%d.\n", report.day, report.month, report.year);

	
	return 0;
}