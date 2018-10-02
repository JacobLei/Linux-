/*
 * �����嵥7-1�����Խ��̵�UID��EUID������
 * ������ļ��������ɵĿ�ִ���ļ�����Ϊtest_uid��������������Ϊroot��
 * �����ø��ļ���set_user_id��־��Ȼ�����иó�����Բ鿴UID��EUID��
 * ����������£�
 * sudo chown root:root test_uid	# �޸�Ŀ���ļ���������Ϊroot
 * sudo chmod +s test_uid					# ����Ŀ���ļ���set_user_id��־ 
 * ./test_uid											# ���г���
 * 
 * ��������userid is: 1000, effective userid is: 0
 */

#include <unistd.h>
#include <stdio.h>

int main(){
	uid_t uid = getuid();
	uid_t euid = geteuid();
	printf("userid is: %d, effective userid is: %d\n", uid, euid);
	
	return 0;
}