#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//从键盘输入一个点和一个圆，判断点和圆的位置关系。（点由x，y坐标确定；圆由圆心和半径确定）
//假设圆心坐标( x0, y0) ，圆的半径为R，点的坐标(x, y) 。
//判断点在圆内：(x - x0) * (x - x0) + (y - y0) * (y - y0) <= R*R
//判断点在圆外：(x - x0) * (x - x0) + (y - y0) * (y - y0) > R*R

typedef struct
{
	double x;
	double y;
}point, *ppoint;

typedef struct
{
	double R;
	point center;
}circle, *pcircle;

enum {
	in_circle,
	on_circle,
	out_circle
}c;

int WhereIsPoint(const ppoint p, const pcircle r)
{
	double IS = (p->x - r->center.x)*(p->x - r->center.x) +
		(p->y - r->center.y)*(p->y - r->center.y);
	const double R2 = r->R*r->R;
	if (IS == R2) return on_circle;
	if (IS < R2)  return in_circle;
	if (IS>R2)	  return out_circle;
}


int main()
{
	point p;
	circle c;
	printf("请输入一个圆<圆半径，圆心横坐标，圆心纵坐标>\n");
	scanf("%lf %lf %lf", &(c.R), &(c.center.x), &(c.center.y));

	printf("请输入一个点<x,y>\n");
	scanf("%lf %lf", &(p.x), &(p.y));
	switch (WhereIsPoint(&p, &c))
	{
	case in_circle:
		printf("这个点在圆里\n");
		break;
	case on_circle:
		printf("这个点在圆上\n");
		break;
	case out_circle:
		printf("这个点不在圆上\n");
		break;
	default:
		printf("悲催！出bug了！\n");
	}
}