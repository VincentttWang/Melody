#include <stdio.h>
	int main() {
		char type,type2;
		int channel, price, remain,a,c,channel2, number2, total, money, totalmoney = 0, change;
		printf("请分别输入货物种类（A-E）、货物所在通道标号（1-5）、货物单价（1-10整数）以及其个数（1-50）\n （例如：A 3 7 5）：");
		scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
		//对错误输入的排除
		while (type < 'A' || type > 'E' || channel>5 || channel < 1 || price>10 || price < 1 || remain>50 || remain < 1) {
			printf("数据有误，请重新输入:");
			//清理缓存区
			while ((c = getchar()) != '\n' && c != EOF);
			scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
		}
		do {
			printf("欢迎购买。请分别输入购买货物种类、货物所在通道、购买数量：");
			scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			//对错误输入的排除
			while (type != type2 || channel != channel2 || number2 >= remain || number2 <= 0) {
				printf("信息错误，请重新输入：");
				while ((c = getchar()) != '\n' && c != EOF);
				scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
			}
			remain -= number2;
			total = price * number2;
			printf("请投币：(只能投入1、2、5元）");
			do {
				scanf_s(" %d", &money);
				//对投币种类的限制
				if (money == 1 || money == 2 || money == 5) {
					totalmoney += money;
					if (totalmoney < total) {
						printf("请继续投币。");
					}
				}
				else {
					printf("金额有误，请重新输入。");
				}
			} while (totalmoney < total);
			change = totalmoney - total;
			printf("总价%d元，您共支付了%d元，找您%d元\n", total, totalmoney, change);
			//对是否需要继续购买的选择
			printf("您可以输入1继续购买，或输入0退出购买。");
			scanf_s("%d", &a);
		} while (remain > 0 && a == 1);
		printf("欢迎下次光临。");
	return 0;
}

