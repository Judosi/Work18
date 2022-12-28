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
	printf("������� �������� 1 �����: ");
	scanf("%c", &a.name);
	printf("������� x ���������� 1 �����: ");
	scanf("%f", &a.x);
	printf("������� y ���������� 1 �����: ");
	scanf("%f", &a.y);
	getchar();
	printf("������� �������� 2 �����: ");
	scanf("%c", &b.name);
	getchar();
	printf("������� x ���������� 2 �����: ");
	scanf("%f", &b.x);
	printf("������� y ���������� 2 �����: ");
	scanf("%f", &b.y);
	put_point(a);
	put_point(b);
	printf("\n���������� ����� %c � %c = %f", a.name, b.name, dist(a, b));
	printf("\n����� ������� ����� ������� %c � %c ��������� � ����� M(%.2f;%.2f)", a.name, b.name, findCenterX(a, b), findCenterY(a, b));
	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("\n\n���������� ����� %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	switch (mytime->tm_wday)
	{
	case 0:
		printf("\n������� �����������");
		break;
	case 1:
		printf("\n������� �����������");
		break;
	case 2:
		printf("\n������� �������");
		break;
	case 3:
		printf("\n������� �����");
		break;
	case 4:
		printf("\n������� �������");
		break;
	case 5:
		printf("\n������� �������");
		break;
	case 6:
		printf("\n������� �������");
		break;
	default:
		printf("\n� ��� �������� ������");

	}

	//3

	puts("\n");

	Employee report;
	puts("������� ������� ����������: ");
	scanf("%s", report.lastname);
	puts("������� ��� ����������:");
	scanf("%s", report.name);
	puts("������� �������� ����������:");
	scanf("%s", report.patronymic);
	puts("������� ��������� ����������:");
	scanf("%s", report.position);
	puts("������� ��� ����������:");
	scanf("%s", report.floor);
	puts("������� ���� ����� ���������� �� ������:");
	scanf("%d", &report.day);
	puts("������� ����� ����� ���������� �� ������:");
	scanf("%d", &report.month);
	puts("������� ��� ����� ���������� �� ������:");
	scanf("%d", &report.year);

	printf("\n���������: %s %s %s.\n", report.lastname, report.name, report.patronymic);
	printf("���������: %s.\n", report.position);
	printf("���: %s.\n", report.floor);
	printf("���� ����� ���������� �� ������: %d:%d:%d.\n", report.day, report.month, report.year);

	
	return 0;
}