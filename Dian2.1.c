#include <stdio.h>
int main() {
	char type, type2, judge='y';
	int channel, price, remain, a, c, channel2, number2, total=0, money, totalmoney = 0, change;
	int pricestore[5], remainstore[5] = { 0,0,0,0,0 };
	char typestore[5];
	do {
		printf("��ֱ�����������ࣨA-E������������ͨ����ţ�1-5�������ﵥ�ۣ�1-10�������Լ��������1-50��\n �����磺A 3 7 5����");
		scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
		while ((c = getchar()) != '\n' && c != EOF);
		//�Դ���������ų�
		while (type < 'A' || type > 'E' || channel > 5 || channel < 1 || price>10 || price < 1 || remain>50 || remain < 1) {
			printf("������������������:");
			scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
			while ((c = getchar()) != '\n' && c != EOF);
		}
		pricestore[channel - 1] = price;
		typestore[channel - 1] = type;
		remainstore[channel - 1] += remain;
		printf("�Ƿ���Ҫ�����ڷţ�������y/n����");
			scanf_s("%c", &judge,1);
			while ((c = getchar()) != '\n' && c != EOF);
	} while (judge == 'y');
	do {
		do {
			printf("��ӭ������ֱ����빺��������ࡢ��������ͨ��������������");
			scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			//�Դ���������ų�
			while (typestore[channel2 - 1] != type2 || number2 > remainstore[channel2 - 1] || number2 <= 0) {
				printf("��Ϣ�������������룺");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			}
			remainstore[channel2 - 1] -= number2;
			total += pricestore[channel2-1] * number2;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("�Ƿ���Ҫ�������򣿣�����y/n����");
			scanf_s("%c", &judge, 1);
			while ((c = getchar()) != '\n' && c != EOF);
		} while (judge == 'y');
		printf("��Ͷ�ң�(ֻ��Ͷ��1��2��5Ԫ��");
		do {
			scanf_s(" %d", &money);
			//��Ͷ�����������
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
		change = totalmoney - total;
		printf("�ܼ�%dԪ������֧����%dԪ������%dԪ\n", total, totalmoney, change);
		//���Ƿ���Ҫ���������ѡ��
		printf("����������y�������򣬻�����n�˳�����");
		while ((c = getchar()) != '\n' && c != EOF);
		scanf_s("%c",&judge,1);
		while ((c = getchar()) != '\n' && c != EOF);
	} while (judge=='y');
	printf("��ӭ�´ι��١�");
	return 0;
}