#include <stdio.h>
#include <stdbool.h>
// 定义状态枚举
enum State {
    PlacementState,
    PurchaseState,
    PaymentState
};
// 定义结构体保存状态信息
struct StateInfo {
    char type;
    int channel;
    int price;
    int remain;
};
int main() {
    char type, type2, judge = 'y';
    int channel, price, remain, a, c, channel2, number2, total = 0, money, totalmoney = 0, change;
    int pricestore[5], remainstore[5] = { 0,0,0,0,0 };
    char typestore[5];
    // 当前状态和历史状态数组
    enum State currentState = PlacementState;
    struct StateInfo history[3];
    int historyIndex = -1;
    do {
        printf("请分别输入货物种类（A-E）、货物所在通道标号（1-5）、货物单价（1-10整数）以及其个数（1-50）\n （例如：A 3 7 5）：");
        scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
        while ((c = getchar()) != '\n' && c != EOF);
        // 对错误输入的排除
        while (type < 'A' || type > 'E' || channel > 5 || channel < 1 || price > 10 || price < 1 || remain > 50 || remain < 1) {
            printf("数据有误，请重新输入:");
            scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        pricestore[channel - 1] = price;
        typestore[channel - 1] = type;
        remainstore[channel - 1] += remain;
        // 保存当前状态信息到历史记录
        historyIndex++;
        if (historyIndex >= 3) {
            // 循环覆盖旧的历史记录
            historyIndex = 0;
        }
        history[historyIndex].type = type;
        history[historyIndex].channel = channel;
        history[historyIndex].price = price;
        history[historyIndex].remain = remain;
        char input[10];
        printf("输入'undo'进行回退操作，或输入其他字符继续：");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "undo", 4) == 0) {
            if (historyIndex >= 0) {
                // 根据当前状态进行回退操作
                if (currentState == PlacementState) {
                    pricestore[history[historyIndex].channel - 1] = 0;
                    typestore[history[historyIndex].channel - 1] = '\0';
                    remainstore[history[historyIndex].channel - 1] -= history[historyIndex].remain;
                    historyIndex--;
                    if (historyIndex < 0) {
                        printf("无法继续回退。\n");
                    }
                }
            }
            else {
                printf("无法继续回退。\n");
            }
        }
        else {
            printf("是否需要继续摆放？（输入 y/n）：");
            scanf_s("%c", &judge, 1);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (judge == 'y');
    currentState = PurchaseState;
    do {
        do {
            printf("欢迎购买。请分别输入购买货物种类、货物所在通道、购买数量：");
            scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
            // 对错误输入的排除
            while (typestore[channel2 - 1] != type2 || number2 > remainstore[channel2 - 1] || number2 <= 0) {
                printf("信息错误，请重新输入：");
                while ((c = getchar()) != '\n' && c != EOF);
                scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
            }
            remainstore[channel2 - 1] -= number2;
            total += pricestore[channel2 - 1] * number2;
            // 保存当前状态信息到历史记录
            historyIndex++;
            if (historyIndex >= 3) {
                historyIndex = 0;
            }
            history[historyIndex].type = type2;
            history[historyIndex].channel = channel2;
            history[historyIndex].price = pricestore[channel2 - 1];
            history[historyIndex].remain = remainstore[channel2 - 1];
            char input[10];
            printf("输入'undo'进行回退操作，或输入其他字符继续：");
            fgets(input, sizeof(input), stdin);
            while ((c = getchar()) != '\n' && c != EOF);
            if (strncmp(input, "undo", 4) == 0) {
                if (historyIndex >= 0) {
                    // 根据当前状态进行回退操作
                    remainstore[history[historyIndex].channel - 1] += history[historyIndex].remain;
                    total -= history[historyIndex].price * number2;
                    historyIndex--;
                    if (historyIndex < 0) {
                        printf("无法继续回退。\n");
                    }
                }
                else {
                    printf("无法继续回退。\n");
                }
            }
            else {
                printf("是否需要继续购买？（输入 y/n）：");
                scanf_s("%c", &judge, 1);
                while ((c = getchar()) != '\n' && c != EOF);
            }
        } while (judge == 'y');
        currentState = PaymentState;
        printf("请投币：(只能投入 1、2、5 元）");
        do {
            scanf_s(" %d", &money);
            // 对投币种类的限制
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
        printf("总价%d 元，您共支付了%d 元，找您%d 元\n", total, totalmoney, change);
        char input[10];
        printf("输入'undo'进行回退操作，或输入其他字符继续：");
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "undo", 4) == 0) {
            if (historyIndex >= 0) {
                // 根据当前状态进行回退操作
                totalmoney -= money;
                historyIndex--;
                if (historyIndex < 0) {
                    printf("无法继续回退。\n");
                }
            }
            else {
                printf("无法继续回退。\n");
            }
        }
        else {
            // 对是否需要继续购买的选择
            printf("您可以输入 y 继续购买，或输入 n 退出购买。");
            scanf_s("%c", &judge, 1);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (judge == 'y');
    printf("欢迎下次光临。");
    return 0;
}