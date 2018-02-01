#include <stdio.h>

double min(double a, double b)
{
	return a < b ? a : b;
}

double max(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	struct point
	{
		double x;
		double y;
	} r1p1, r1p2, r2p1, r2p2, a, b;

	double width, height, area;
	scanf("%lf %lf", &r1p1.x, &r1p1.y);
	scanf("%lf %lf", &r1p2.x, &r1p2.y);
	scanf("%lf %lf", &r2p1.x, &r2p1.y);
	scanf("%lf %lf", &r2p2.x, &r2p2.y);
	a.x = min(max(r1p1.x, r1p2.x), max(r2p1.x, r2p2.x));
	a.y = min(max(r1p1.y, r1p2.y), max(r2p1.y, r2p2.y));
	b.x = max(min(r1p1.x, r1p2.x), min(r2p1.x, r2p2.x));
	b.y = max(min(r1p1.y, r1p2.y), min(r2p1.y, r2p2.y));
	width = a.x - b.x;
	height = a.y - b.y;
	area = width * height;
	if(width >= 0 && height >= 0)
		printf("%.2lf", area);
	else
		printf("0.00");
	return 0;
}