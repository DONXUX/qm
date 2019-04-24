#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	/****** Assignment ******/
	int var_num, min_num, don_num;
	int* minterms;
	int* dontcare;
	printf("Variable의 수 : ");
	scanf("%d", &var_num);
	printf("Minterm의 수 : ");
	scanf("%d", &min_num);
	printf("Don't care의 수 : ");
	scanf("%d", &don_num);

	minterms = (int*)malloc(sizeof(int) * min_num);
	dontcare = (int*)malloc(sizeof(int) * don_num);

	for (int i = 0; i < min_num; i++) {
		printf("%d번째 Minterm(오름차순으로 입력) : ", i + 1);
		scanf("%d", &minterms[i]);
	}
	for (int i = 0; i < don_num; i++) {
		printf("%d번째 Don't care(오름차순으로 입력) : ", i + 1);
		scanf("%d", &dontcare[i]);
	}
	 
	/****** Make Table ******/
	int** tmp_table = (int**)malloc(sizeof(int*) * (min_num + don_num));
	for (int i = 0; i < min_num + don_num; i++)
		tmp_table[i] = (int*)malloc(sizeof(int) * (var_num + 1));
	
	int* idx_num = (int*)malloc(sizeof(int) * (var_num + 1));		// Index number
	for (int i = 0; i < var_num + 1; i++) idx_num[i] = 0;

	// Change Binaray
	for (int i = 0; i < min_num; i++) {
		int tmp = minterms[i];
		tmp_table[i][0] = 0;	// index
		for (int j = 0; j < var_num; j++) {
			int bit;
			bit = tmp % 2;
			tmp /= 2;
			tmp_table[i][var_num - j] = bit;
			tmp_table[i][0] += bit;		
		}
		idx_num[tmp_table[i][0]]++;
	}
	for (int i = 0; i < don_num; i++) {
		int tmp = dontcare[i];
		tmp_table[min_num + i][0] = 0;		// index
		for (int j = 0; j < var_num; j++) {
			int bit;
			bit = tmp % 2;
			tmp /= 2;
			tmp_table[min_num + i][var_num - j] = bit;
			tmp_table[min_num + i][0] += bit;	
		}
		idx_num[tmp_table[min_num + i][0]]++;
	}

	int*** table = (int***)malloc(sizeof(int**) * (var_num + 1));
	for (int i = 0; i < var_num + 1; i++) {
		table[i] = (int**)malloc(sizeof(int*) * idx_num[i]);
		int k = 0;
		for (int j = 0; j < idx_num[i]; j++) {
			while (k < min_num + don_num) {
				if (i != tmp_table[k][0]) {
					k++;
					continue;
				}
				table[i][j] = tmp_table[k++];
				break;
			}
		}
	}
	/////////////////////////////////////////////////////////
	
	for (int i = 0; i < var_num - 1; i++) {
		if (idx_num[i] == 0)
			continue;
		for (int j = 0; j < idx_num[j]; j++) {
			
		}
	}
	// debug
	for (int i = 0; i < var_num + 1; i++) {
		for (int j = 0; j < idx_num[i]; j++) {
			for (int k = 0; k < var_num + 1; k++) {
				printf("%d ", table[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}