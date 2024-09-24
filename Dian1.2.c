#include <stdio.h>
int main() {
	int total = 0;
	printf("请输入购买商品的总价（元）：");
	scanf_s("%d", &total);
	//对总价正确与否判断
	while (total <= 0) {
		printf("总价输入错误，请重新输入：");
		scanf_s("%d", &total);
	}
	printf("请投币：(只能投入1、2、5元）");
	int money = 0;
	int totalmoney = 0;
	do {
		scanf_s(" %d", &money);
		//对投币面值的正确与否判断。
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
	int change = totalmoney - total;
	printf("总价%d元，您共支付了%d元，找您%d元", total, totalmoney, change);
	return 0;
}