#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd1 = open("file.txt", O_RDONLY); // 파일 디스크립터 3으로 파일을 엽니다.
	if (fd1 == -1) {
		// perror("open");
		return 1; // 파일을 열지 못하면 오류 메시지를 출력하지 않고 프로그램을 종료합니다.
	}

	int fd2 = dup(fd1); // 파일 디스크립터 3을 복제하여 새로운 파일 디스크립터 4를 만듭니다.
	if (fd2 == -1) {
		perror("dup");
		close(fd1); // 파일 디스크립터 3를 닫습니다.
		return 1;
	}

	printf("File descriptors: %d, %d\n", fd1, fd2);

	close(fd1);
	close(fd2);

	return 0;
}
