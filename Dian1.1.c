#include <stdio.h>

int main()
{
	char type;
	int pass, price, number = 0;
	//摆放货物。第一节为方便没有设置对变量是否符合要求的判断，在后续1.3会添加。
	printf("请分别输入货物种类（A-E）、货物所在通道标号（1-5）、货物单价（1-10整数）以及其个数（1-50）\n （例如：A 3 7 5）：");
	unsigned int a = sizeof(type);
	scanf_s("%c %d %d %d", &type,a, & pass, &price, &number);
	printf("%d: ", pass);
	while (number > 0) {
		printf("%c", type);
		number--;
	}
	printf(" %d", price);
	return 0;
}
