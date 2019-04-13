#include <stdio.h>
char* valuesDp(Qm q, char* raw_val);
char* oneMintermDp(Qm q, char* raw_om);
char* dontCareDp(Qm q, char* raw_dc);

typedef struct _Qm_ {
	char values[10];
	char one_mint[1024];
	char dont_care[1024];
} Qm;

int main(void) {
	// Row data input
	char raw_val[20];
	char raw_om[100];
	char raw_dc[100];

	printf("Values (ex : a b c d) : ");
	fgets(raw_val, sizeof(raw_val), stdin);
	printf("One Minterm (ex : 1 3 5 7 8 9) : ");
	fgets(raw_om, sizeof(raw_om), stdin);
	printf("Don't care (ex : 2 6) : ");
	fgets(raw_dc, sizeof(raw_dc), stdin);

	// Data Processing
	Qm q;
	valuesDp(&q, raw_val);
	oneMintermDp(&q, raw_om);
	dontCareDp(&q, raw_dc);

	return 0;
}

char* valuesDp(Qm q, char* raw_val) {

}

char* oneMintermDp(Qm q, char* raw_om) {

}

char* dontCareDp(Qm q, char* raw_dc) {

}
