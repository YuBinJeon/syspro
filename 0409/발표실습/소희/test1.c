#include<stdio.h>

int main(){
	FILE *fp = fopen("hello.txt","w"); // 쓰기모드"w"로 "hello.txt"
	FILE *fp2 = fopen("hello2.txt","w"); // 쓰기모드"w"로 "hello.txt"
	while (1){
	}
	fclose(fp); // 파일 열었으니 닫기
	return 0;
}
