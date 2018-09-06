/*
 * Author: Madhu
 * Src: https://www.hackerrank.com/contests/smart-interviews/challenges/si-game-of-letters/problem
 * EmailId: kmadhusudhanreddy3@gmail.com
 * */

#include<stdio.h>
#include<string.h>

int main() {
	int testcases;
	scanf("%d", &testcases);
	while(testcases--) {
		char input[10000];
		int counts[26];
		memset(counts, 0, 26*sizeof(int));
		scanf("%s", input);
		for(int i=0; input[i] != '\0'; i++) {
			counts[input[i] - 'a']++;
		}
		int moreThanOnes = 0, exactOnes = 0;
		for(int i = 0; i < 26; i++) {
			if(counts[i] > 1)
				moreThanOnes++;
			else if(counts[i] == 1)
				exactOnes++;
		}
		int maxTurns = moreThanOnes *(exactOnes==0 ? 1 : 2) + exactOnes;
		if (maxTurns % 2 == 0)
			printf("Banta\n");
		else
			printf("Santa\n");
	}
	return 1;
}
