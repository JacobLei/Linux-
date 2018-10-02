/*
 * 代码清单7-1：测试进程的UID和EUID的区别
 * 编译该文件，将生成的可执行文件（名为test_uid）的所有者设置为root，
 * 并设置该文件的set_user_id标志，然后运行该程序可以查看UID和EUID。
 * 具体操作如下：
 * sudo chown root:root test_uid	# 修改目标文件的所有者为root
 * sudo chmod +s test_uid					# 设置目标文件的set_user_id标志 
 * ./test_uid											# 运行程序
 * 
 * 输出结果：userid is: 1000, effective userid is: 0
 */

#include <unistd.h>
#include <stdio.h>

int main(){
	uid_t uid = getuid();
	uid_t euid = geteuid();
	printf("userid is: %d, effective userid is: %d\n", uid, euid);
	
	return 0;
}