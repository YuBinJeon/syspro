#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	struct stat buf;
	char *filename;

	// 사용자로부터 파일 경로를 입력 받습니다.
	printf("파일 경로를 입력하세요: ");
	scanf("%s", filename);

	// lstat 함수를 사용하여 파일의 메타데이터를 가져옵니다.
	if (lstat(filename, &buf) < 0) {
		perror("lstat()");
		exit(EXIT_FAILURE);
	}

	// 파일의 메타데이터를 출력합니다.
	printf("파일 이름: %s\n", filename);
	printf("파일 크기: %lld bytes\n", (long long)buf.st_size);
	printf("소유자 ID: %d\n", buf.st_uid);
	printf("그룹 ID: %d\n", buf.st_gid);
	printf("파일 타입: ");

	// 파일 타입을 확인하고 출력합니다.
	if (S_ISREG(buf.st_mode)) 
		printf("일반 파일\n");
	else if (S_ISDIR(buf.st_mode)) 
		printf("디렉터리\n");
	else if (S_ISCHR(buf.st_mode)) 
		printf("문자 장치 파일\n");
	else if (S_ISBLK(buf.st_mode)) 
		printf("블록 장치 파일\n");
	else if (S_ISFIFO(buf.st_mode)) 
		printf("FIFO 파일\n");
	else if (S_ISLNK(buf.st_mode)) 
		printf("심볼릭 링크\n");
	else if (S_ISSOCK(buf.st_mode)) 
		printf("소켓\n");

	return 0;
}

