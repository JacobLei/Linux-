/*
 * 代码清单7-2 : 将以root身份启动程序的进程
 * 							 切换以一个普通用户身份运行。  
 */

#include <unistd.h>
#include <stdio.h>

static bool switch_to_user( uid_t user_id, gid_t gp_id){
	/* 先确保目标用户不是root */
	if( ( user_id == 0 ) && ( gp_id == 0 ) ){
		return false;
	}
	
	/* 确保当前用户时合法用户：root或目标用户 */
	gid_t gid = getgid();
	uid_t uid = getuid();
	if( ((gid != 0) || (uid != 0)) 
		&& (gid != gp_id) || (uid != user_id) ){
			returnf false;
	}
	
	/* 如果不是root，则已经是目标用户 */
	if( uid != 0 ){
		return true;
	}
	
	/* 切换到目标用户 */
	if( (setgid(gp_id) < 0 ) || (setuid(user_id) < 0) ){
		return false;
	}
	
	return true;

}