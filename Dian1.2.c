#include <stdio.h>
int main() {
	int total = 0;
	printf("�����빺����Ʒ���ܼۣ�Ԫ����");
	scanf_s("%d", &total);
	//���ܼ���ȷ����ж�
	while (total <= 0) {
		printf("�ܼ�����������������룺");
		scanf_s("%d", &total);
	}
	printf("��Ͷ�ң�(ֻ��Ͷ��1��2��5Ԫ��");
	int money = 0;
	int totalmoney = 0;
	do {
		scanf_s(" %d", &money);
		//��Ͷ����ֵ����ȷ����жϡ�
		if (money == 1 || money == 2 || money == 5) {
			totalmoney += money;
			if (totalmoney < total) {
				printf("�����Ͷ�ҡ�");
			}
		}
		else {
			printf("����������������롣");
		}
	} while (totalmoney < total);
	int change = totalmoney - total;
	printf("�ܼ�%dԪ������֧����%dԪ������%dԪ", total, totalmoney, change);
	return 0;
}