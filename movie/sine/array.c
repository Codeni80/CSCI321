


#include <math.h>
#include <stdio.h>

int main()
	{
	int x;

	printf("\tint y[701] = {");

	for (x = -50; x <=650; x++)
		{
		printf("%d, ", 100-(int)(100*(sin(x * 3.14159265358979 / 600.0))+.5));
		}
	printf("};\n");
	}

