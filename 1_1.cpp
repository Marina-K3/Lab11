#include "My_file.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	int menu;
	while (1) {
		setlocale(LC_ALL, "rus");
		printf("\n   * **����** *\n   ���� - 1\n   ����� - 2\n   ������� - 3\n   �������� - 4\n   ������� - 5\n   ����� - 6\n   * **####** *\n\n  ��� �����: ");
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
			printf("\n     ....���������� ������.....\n");
			return 0;
			break;
		}
	}
}