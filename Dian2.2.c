#include <stdio.h>
#include <stdbool.h>
// ����״̬ö��
enum State {
    PlacementState,
    PurchaseState,
    PaymentState
};
// ����ṹ�屣��״̬��Ϣ
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
    // ��ǰ״̬����ʷ״̬����
    enum State currentState = PlacementState;
    struct StateInfo history[3];
    int historyIndex = -1;
    do {
        printf("��ֱ�����������ࣨA-E������������ͨ����ţ�1-5�������ﵥ�ۣ�1-10�������Լ��������1-50��\n �����磺A 3 7 5����");
        scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
        while ((c = getchar()) != '\n' && c != EOF);
        // �Դ���������ų�
        while (type < 'A' || type > 'E' || channel > 5 || channel < 1 || price > 10 || price < 1 || remain > 50 || remain < 1) {
            printf("������������������:");
            scanf_s("%c %d %d %d", &type, 1, &channel, &price, &remain);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        pricestore[channel - 1] = price;
        typestore[channel - 1] = type;
        remainstore[channel - 1] += remain;
        // ���浱ǰ״̬��Ϣ����ʷ��¼
        historyIndex++;
        if (historyIndex >= 3) {
            // ѭ�����Ǿɵ���ʷ��¼
            historyIndex = 0;
        }
        history[historyIndex].type = type;
        history[historyIndex].channel = channel;
        history[historyIndex].price = price;
        history[historyIndex].remain = remain;
        char input[10];
        printf("����'undo'���л��˲����������������ַ�������");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "undo", 4) == 0) {
            if (historyIndex >= 0) {
                // ���ݵ�ǰ״̬���л��˲���
                if (currentState == PlacementState) {
                    pricestore[history[historyIndex].channel - 1] = 0;
                    typestore[history[historyIndex].channel - 1] = '\0';
                    remainstore[history[historyIndex].channel - 1] -= history[historyIndex].remain;
                    historyIndex--;
                    if (historyIndex < 0) {
                        printf("�޷��������ˡ�\n");
                    }
                }
            }
            else {
                printf("�޷��������ˡ�\n");
            }
        }
        else {
            printf("�Ƿ���Ҫ�����ڷţ������� y/n����");
            scanf_s("%c", &judge, 1);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (judge == 'y');
    currentState = PurchaseState;
    do {
        do {
            printf("��ӭ������ֱ����빺��������ࡢ��������ͨ��������������");
            scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
            // �Դ���������ų�
            while (typestore[channel2 - 1] != type2 || number2 > remainstore[channel2 - 1] || number2 <= 0) {
                printf("��Ϣ�������������룺");
                while ((c = getchar()) != '\n' && c != EOF);
                scanf_s("%c %d %d", &type2, 1, &channel2, &number2);
            }
            remainstore[channel2 - 1] -= number2;
            total += pricestore[channel2 - 1] * number2;
            // ���浱ǰ״̬��Ϣ����ʷ��¼
            historyIndex++;
            if (historyIndex >= 3) {
                historyIndex = 0;
            }
            history[historyIndex].type = type2;
            history[historyIndex].channel = channel2;
            history[historyIndex].price = pricestore[channel2 - 1];
            history[historyIndex].remain = remainstore[channel2 - 1];
            char input[10];
            printf("����'undo'���л��˲����������������ַ�������");
            fgets(input, sizeof(input), stdin);
            while ((c = getchar()) != '\n' && c != EOF);
            if (strncmp(input, "undo", 4) == 0) {
                if (historyIndex >= 0) {
                    // ���ݵ�ǰ״̬���л��˲���
                    remainstore[history[historyIndex].channel - 1] += history[historyIndex].remain;
                    total -= history[historyIndex].price * number2;
                    historyIndex--;
                    if (historyIndex < 0) {
                        printf("�޷��������ˡ�\n");
                    }
                }
                else {
                    printf("�޷��������ˡ�\n");
                }
            }
            else {
                printf("�Ƿ���Ҫ�������򣿣����� y/n����");
                scanf_s("%c", &judge, 1);
                while ((c = getchar()) != '\n' && c != EOF);
            }
        } while (judge == 'y');
        currentState = PaymentState;
        printf("��Ͷ�ң�(ֻ��Ͷ�� 1��2��5 Ԫ��");
        do {
            scanf_s(" %d", &money);
            // ��Ͷ�����������
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
        printf("�ܼ�%d Ԫ������֧����%d Ԫ������%d Ԫ\n", total, totalmoney, change);
        char input[10];
        printf("����'undo'���л��˲����������������ַ�������");
        while ((c = getchar()) != '\n' && c != EOF);
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "undo", 4) == 0) {
            if (historyIndex >= 0) {
                // ���ݵ�ǰ״̬���л��˲���
                totalmoney -= money;
                historyIndex--;
                if (historyIndex < 0) {
                    printf("�޷��������ˡ�\n");
                }
            }
            else {
                printf("�޷��������ˡ�\n");
            }
        }
        else {
            // ���Ƿ���Ҫ���������ѡ��
            printf("���������� y �������򣬻����� n �˳�����");
            scanf_s("%c", &judge, 1);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (judge == 'y');
    printf("��ӭ�´ι��١�");
    return 0;
}