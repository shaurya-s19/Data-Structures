#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
	int a = 0 , b = 0 , i = 0 , found_index = -1;
	
	if(strlen(needle) > strlen(haystack)){
        	return found_index = -1;
    	}	
	
	for(int i = 0 ; i < strlen(needle) ; i++){
		a += (int)needle[i];
	}
	
	int found = 1;

	while(i < strlen(haystack) - strlen(needle)+1){
		for(int j = 0 ; j < strlen(needle) ; j++){
			b += (int)haystack[j+i];
		}

		if (a == b){
			for(int x = 0 ; x < strlen(needle) ; x++){
				if(haystack[i+x] != needle[x]){
		            		found = 0;
		            		break;
		            	}
		            	else
		            		found = 1;
		        }
		}
		if(a == b && found == 1){
			found_index = i;
			break;
		}
        	b = 0 , i++;
	}
    	return found_index;
}

int main(){
	printf("%d" , strStr("babbbbbabb" , "bbab"));
}
