#define _CRT_SECURE_NO_WARNINGS
#define MUL1(x,y) x*y

#define MUL2(x,y) (x)*(y)

#define MUL3(x,y) (x*y)

void main()

{

	int m = 2, n = 3;

	printf("%d, ", MUL1(m, m + n) * 2);

	printf("%d, ", MUL2(m, m + n) * 2);

	printf("%d\n", MUL3(m, m + n) * 2);

}