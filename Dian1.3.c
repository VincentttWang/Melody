#include <stdio.h>
	int main() {
		char type,type2;
		int channel, price, remain,a,c,channel2, number2, total, money, totalmoney = 0, change;
		printf("��ֱ�����������ࣨA-E������������ͨ����ţ�1-5�������ﵥ�ۣ�1-10�������Լ��������1-50��\n �����磺A 3 7 5����");
		scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
		//�Դ���������ų�
		while (type < 'A' || type > 'E' || channel>5 || channel < 1 || price>10 || price < 1 || remain>50 || remain < 1) {
			printf("������������������:");
			//��������
			while ((c = getchar()) != '\n' && c != EOF);
			scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
		}
		do {
			printf("��ӭ������ֱ����빺��������ࡢ��������ͨ��������������");
			scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			//�Դ���������ų�
			while (type != type2 || channel != channel2 || number2 >= remain || number2 <= 0) {
				printf("��Ϣ�������������룺");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			}
			remain -= number2;
			total = price * number2;
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
			printf("����������1�������򣬻�����0�˳�����");
			scanf_s("%d", &a);
		} while (remain > 0 && a == 1);
		printf("��ӭ�´ι��١�");
	return 0;
}

