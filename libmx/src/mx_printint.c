#include "libmx.h"

void mx_printint(int n) {
	if (n == -2147483648) {
		mx_printchar('-');
		mx_printchar('2');
		mx_printchar('1');
		mx_printchar('4');
		mx_printchar('7');
		mx_printchar('4');
        mx_printchar('8');
        mx_printchar('3');
        mx_printchar('6');
        mx_printchar('4');
        mx_printchar('8');
		return;
	}
	if (n == 0) {
		mx_printchar('0');
		return;
	}
	if (n < 0) {
		mx_printchar('-');
		n = -n;
	}
	if (n/10) {
		mx_printint(n/10);
	}
	mx_printchar(n%10 + '0');
}

