#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *p_function(void *data)
{
	char *mess;

	mess = (char *)data;
	printf("%s \n", mess);
	pthread_exit((void *)100);
}

int main(void)
{
	pthread_t pthread1, pthread2;
	char *mess1 = "thread1";
	char *mess2 = "thread2";
	int ret, status;

	ret = pthread_create(&pthread1, NULL, p_function, (void*)mess1);
	printf("%d\n", ret);
	if (ret == 0)
	{
		printf("pthread_create returns %d\n", ret);
	}
	else
	{
		printf("pthread_create returns error: %d\n", ret);
		exit(1);
	}
	ret = pthread_create(&pthread2, NULL, p_function, (void*)mess2);
	if (ret == 0)
	{
		printf("pthread_create returns %d\n", ret);
	}
	else
	{
		printf("pthread_create returns error: %d\n", ret);
		exit(1);
	}
	pthread_join(pthread2, (void **)&status);
	printf("thread2 returns: %d\n", status);
	pthread_join(pthread1, (void **)&status);
	printf("thread1 returns: %d\n", status);
	return (0);
}