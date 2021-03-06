/*
 * =============================================================================
 *
 *       Filename:  create_bucket.c
 *
 *    Description:  create_bucket example.
 *
 *        Created:  09/21/2012 09:21:49 AM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 为用户创建一个bucket
*/

#include <ossc/client.h>
#include <stdio.h>

static const char *access_id = "ACSfLOiddaOzejOP";   //设置用户帐号
static const char *access_key = "MUltNpuYqE";  //设置用户密码
static const char *endpoint = "oss.aliyuncs.com";    //设置hostname

int main()
{
	unsigned short retcode;			//保存服务器http返回码的解析结果;
	const char *retinfo;            //保存通过retcode获得的错误信息

	oss_client_t *client = client_initialize_with_endpoint(access_id, access_key, endpoint);
	const char *bucket_name = "bucket_example";       //设置bucket_name

	client_create_bucket(client, bucket_name, &retcode);
	printf("create_bucket result:\n\n");
	if(retcode == OK) {
		printf("create bucket successfully.\n");
	} else {
		retinfo = oss_get_error_message_from_retcode(retcode);
		printf("error = %s\n", retinfo);
	}

	client_finalize(client);
	return 0;
}

