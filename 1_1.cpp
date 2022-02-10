#include "My_file.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	int menu;
	while (1) {
		setlocale(LC_ALL, "rus");
		printf("\n   * **МЕНЮ** *\n   ввод - 1\n   вывод - 2\n   рассчёт - 3\n   добавить - 4\n   удалить - 5\n   выход - 6\n   * **####** *\n\n  Ваш выбор: ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: enter();
			break;
		case 2: print();
			break;
		case 3: calculation();
			break;
		case 4: plus();
			break;
		case 5: del();
			break;
		case 6:
			printf("\n     ....Завершение работы.....\n");
			return 0;
			break;
		}
	}
}