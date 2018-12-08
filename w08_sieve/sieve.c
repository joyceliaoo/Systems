#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sieve.h"

int sieve(int n) {
	int num_buckets = n*log(n)*1.15;
	//printf("%d slots made \n", num_buckets);
	char *buckets = malloc (num_buckets * sizeof(char));
	int nth = 1;
	int ans = 3;
	long i;
	while (1) {
		if (ans%2 && !buckets[ans]) {
			nth++;
			if (nth == n) break;
			//printf("multiples of %d \n", ans);
			for (i = (long)ans*ans; i <= num_buckets; i = i+ans) {
			//printf("cross %ld \n", i);
				if (!buckets[i])
					buckets[i] = 1;
			}
		}
		ans++;
	}
	free(buckets);
	return ans;
}
