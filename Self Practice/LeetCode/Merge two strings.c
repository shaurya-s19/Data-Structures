//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char *word1 , char *word2){
	int a = strlen(word1);
	int b = strlen(word2);
	int c = a + b ;
	
	char *merged_word = (char *)malloc((c+1)*sizeof(char));
	int i = 0 , j = 0 , k = 0;
	while( i < a || j < b){
		if(i<a){
			merged_word[k++] = word1[i++];
		}
		
		if (j<b){
			merged_word[k++] = word2[j++];
		}
	}
	
	merged_word[k] = '\0';
	return merged_word;
}

