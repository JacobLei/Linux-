#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]){

	if( argc != 2 ){
		printf("usage:%s <file> \n", basename(argv[0]));
		return 1;
	}

    int filefd = open( argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
    assert( filefd > 0 );
    
	int pipefd_stdout[2];
    int ret = pipe( pipefd_stdout );
    assert( ret != -1 );

    int pipefd_file[2];
    ret = pipe( pipefd_file );
    assert( ret != -1 );

    /* ����׼�����������뵽�ܵ� pipefd_stdout �������*/
    ret = splice( STDIN_FILENO, NULL, pipefd_stdout[1], NULL, 32768, 
                 SPLICE_F_MORE | SPLICE_F_MOVE );
    assert( ret != -1 );

    /* ���ܵ�pipefd_stdout��������Ƶ��ܵ�pipefd_file������� */
    ret = tee( pipefd_stdout[0], pipefd_file[1], 32768, SPLICE_F_NONBLOCK);
    assert( ret != -1 );

    /* ���ܵ�pipefd_stdout����������ļ�������filefd�ϣ� �Ӷ�����׼���������д���ļ�*/
    ret = splice( pipefd_file[0], NULL, filefd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
    assert( ret != -1 );

    /* ���ܵ�pipefd_stdout��������򵽱�׼����� �����ݺ�д���ļ���������ȫһ�� */
    ret = splice( pipefd_stdout[0], NULL, STDOUT_FILENO, NULL, 
            32768, SPLICE_F_MORE | SPLICE_F_MOVE );
    assert( ret != -1 );

    close( filefd );
    close( pipefd_stdout[0] );
    close( pipefd_stdout[1] );
    close( pipefd_file[0] );
    close( pipefd_file[1] );

	return 0;
}
