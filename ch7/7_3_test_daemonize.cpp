/*
 * �����嵥7-3 : ���������������ػ����̵ķ�ʽ���С�
 */
 
 bool daemonize(){
 
 	/* �����ӽ��̣��رո����̣���������ʹ�����ٺ�̨���� */	
 	pid_t pid = fork();
 	if( pid < 0 ){
 		return false;
 	}
 	else if( pid > 0){		// �˳�������
 		exit(0);
 	}
 	
 	/*  �����ļ�Ȩ�����룬�����̴������ļ�ʱ
 	 * ��ʹ��open(const char *pathname, int flags, mode_t mode)ϵͳ���ã�
 	 *  �ļ���Ȩ�޽���mode & 0777
 	 */
 	 umask( 0 );
 	 
 	 /* �����µĻỰ�����ñ�����Ϊ����������� */
 	 pid_t sid = setsid();
 	 if( sid < 0 ){
 	 	return false;
 	 }
 	 
 	 /* �л�����Ŀ¼ */
 	 if( ( chdir( "/" ) ) ){
 	 	return false;
 	 }
 	 
 	 /* �رձ�׼�����豸����׼����豸�ͱ�׼��������豸 */
 	 close( STDIN_FILENO );
 	 close( STDOUT_FILENO );
 	 close( STDERR_FILENO );
 	 
 	 /* �ر������Ѿ��򿪵��ļ�������������ʡ�� */
 	 
 	 /* ����׼���롢��׼����ͱ�׼������������� /dev/null �ļ� */
 	 open( "/dev/null", O_RDONLY );
 	 open( "/dev/null", O_RDWR );
 	 open( "/dev/null", O_RDWR );
 	 
 	 return true;
 }