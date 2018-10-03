/*
 * �����嵥7-2 : ����root�����������Ľ���
 * 							 �л���һ����ͨ�û�������С�  
 */

#include <unistd.h>
#include <stdio.h>

static bool switch_to_user( uid_t user_id, gid_t gp_id){
	/* ��ȷ��Ŀ���û�����root */
	if( ( user_id == 0 ) && ( gp_id == 0 ) ){
		return false;
	}
	
	/* ȷ����ǰ�û�ʱ�Ϸ��û���root��Ŀ���û� */
	gid_t gid = getgid();
	uid_t uid = getuid();
	if( ((gid != 0) || (uid != 0)) 
		&& (gid != gp_id) || (uid != user_id) ){
			returnf false;
	}
	
	/* �������root�����Ѿ���Ŀ���û� */
	if( uid != 0 ){
		return true;
	}
	
	/* �л���Ŀ���û� */
	if( (setgid(gp_id) < 0 ) || (setuid(user_id) < 0) ){
		return false;
	}
	
	return true;

}