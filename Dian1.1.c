#include <stdio.h>

int main()
{
	char type;
	int pass, price, number = 0;
	//�ڷŻ����һ��Ϊ����û�����öԱ����Ƿ����Ҫ����жϣ��ں���1.3����ӡ�
	printf("��ֱ�����������ࣨA-E������������ͨ����ţ�1-5�������ﵥ�ۣ�1-10�������Լ��������1-50��\n �����磺A 3 7 5����");
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
