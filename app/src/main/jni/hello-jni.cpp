/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>
#include "sip_rtp.h"
//#include "cJSON/cJSON.h"
#include "../cJSON/cJSON.h"

//#define LOG_TAG "hello-jni.c"
//#include <utils/Log.h>
#include <unistd.h>
#include <pthread.h>

#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "ANDROID_LOG_DEBUG: hello-jni", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "ANDROID_LOG_ERROR: hello-jni", __VA_ARGS__)

void callbackFromUI(char *str);
void CallJavaFuntionByByteArray(char *strJsonCommand);

static int pfd[2];
static pthread_t thr;
static const char *tag = "myapp";
static int g_logging = 0;
static void* thread_func(void*)
{
    ssize_t rdsz;
    char buf[128];
    while((rdsz = read(pfd[0], buf, sizeof buf - 1)) > 0) {
        if(buf[rdsz - 1] == '\n') --rdsz;
        buf[rdsz] = 0;  /* add null-terminator */
        __android_log_write(ANDROID_LOG_DEBUG, tag, buf);
    }
    return (void *)0;
}

int start_logger(const char *app_name)
{
    if(g_logging != 0)
    {
        return -1;
    }
    tag = app_name;

    /* make stdout line-buffered and stderr unbuffered */
    setvbuf(stdout, 0, _IOLBF, 0);
    setvbuf(stderr, 0, _IONBF, 0);

    /* create the pipe and redirect stdout and stderr */
    pipe(pfd);
    dup2(pfd[1], 1);
    dup2(pfd[1], 2);

    /* spawn the logging thread */
    if(pthread_create(&thr, 0, thread_func, (void *)0) == -1)
        return -1;
    pthread_detach(thr);

    g_logging = 1;

    return 0;
}
/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
static JavaVM* g_pJvmCTestNDk = NULL;
static jobject g_pObjectCTestNDk = NULL;


jclass SipJNIJava = NULL;
jobject mSipJNIJava = NULL;

jmethodID callbackByteArray = NULL;

static int is_attached = 0;

extern "C"
void Java_com_example_administrator_mcpttclient_SipJNI_RegistJavaClassToJni( JNIEnv* env,
                                                      jobject thiz )
{

    LOGD("InitSipJNIJava Begin 1" );
    start_logger("Shen Jinqi");
    LOGD("InitSipJNIJava Begin 2" );

    if(!g_pObjectCTestNDk)
    {
    	LOGD("RegistJavaClassToJni----------");
    	env->GetJavaVM(&g_pJvmCTestNDk);
    	g_pObjectCTestNDk = env->NewGlobalRef(thiz);
    }

   LOGD("InitSipJNIJava ok" );

}

extern "C"
void Java_com_example_administrator_mcpttclient_SipJNI_Request_1from_1UI_1with_1ByeArray
  (JNIEnv* env, jobject thiz,jbyteArray szArrayCommand)
  {

    LOGD("ParseCommandByByeArray");
    jbyte* pszData = NULL;
    pszData = env->GetByteArrayElements(szArrayCommand, NULL);
    const char* pszCommand = (const char*)pszData;

    cJSON *root;
    root = cJSON_Parse(pszCommand);
    if(!root)
    {
        LOGE("cJSON_CreateObject failes");
        return;
    }

    cJSON *cmd = cJSON_GetObjectItem(root, "cmd");
    if(!cmd)
    {
        LOGE("No cmd included");
        return;
    }
    LOGD("cmd = %s", cmd->valuestring);

    LOGD("Recieved %s",cJSON_Print(root));

    cJSON *params = cJSON_GetObjectItem(root, "params");
    if(!params)
    {
        LOGE("No params");
        return;
    }


    if( 0 == strcmp(cmd->valuestring, "init_sip_rtp") )
    {
        cJSON *js_ip, *js_sip_uri, *js_media_server_uri, *js_sip_port, *js_rtp_port;
        js_ip = cJSON_GetObjectItem(params, "ip");
        js_sip_uri = cJSON_GetObjectItem(params, "sip_uri");
        js_media_server_uri = cJSON_GetObjectItem(params, "media_server_uri");
        js_sip_port = cJSON_GetObjectItem(params, "sip_port");
        js_rtp_port = cJSON_GetObjectItem(params, "rtp_port");

        init_sip_rtp(js_ip->valuestring, js_sip_uri->valuestring, js_media_server_uri->valuestring, js_sip_port->valueint, js_rtp_port->valueint);
        set_callbackUI(callbackFromUI);

    }
    else if( 0 == strcmp(cmd->valuestring, "register") )
    {
        cJSON *js_mcptt_id;
        js_mcptt_id = cJSON_GetObjectItem(params, "mcptt_id");

        make_register(js_mcptt_id->valuestring);
    }
    else if( 0 == strcmp(cmd->valuestring, "pre-establishedSessionSetup") )
    {
        sip_invite();
    }
    else if( 0 == strcmp(cmd->valuestring, "pre-establishedSessionRelease") )
    {
            sip_bye();
    }
    else if( 0 == strcmp(cmd->valuestring, "pre-arrangedGroupCallSetup") )
    {
        cJSON *js_group_id;
        js_group_id = cJSON_GetObjectItem(params, "group_id");

        sip_refer(js_group_id->valuestring, false);
    }
    else if( 0 == strcmp(cmd->valuestring, "pre-arrangedGroupCallRelease") )
    {
        cJSON *js_group_id;
        js_group_id = cJSON_GetObjectItem(params, "group_id");

        sip_refer(js_group_id->valuestring, true);
    }
    else if( 0 == strcmp(cmd->valuestring, "floor_request") )
    {
        mcpt_floor_request_send();
    }
    else if( 0 == strcmp(cmd->valuestring, "floor_release") )
    {
        mcpt_floor_release_send();
    }
    else if( 0 == strcmp(cmd->valuestring, "sip_exit") )
    {
        sip_exit();
    }
    else
    {
        LOGE("Unsupported API");
        // return;
    }
#if 0
    {
        char *ip = "10.0.2.15";
        char *sip_uri = "sip:10.0.2.2:5080";
        char *media_server_uri = "10.0.2.2";
        int sip_port = 5090;
        int rtp_port = 4000;
        init_sip_rtp(ip, sip_uri, media_server_uri, sip_port, rtp_port);

        set_callbackUI(callbackFromUI);

        char *mcptt_id = "mcptt_id_1";
        make_register(mcptt_id);

        sip_invite();

        // char *mcptt_group_id = "test_group_1";
        // sip_refer(mcptt_group_id, false);
        // sip_bye();
    }
#endif

  }

  void callbackFromUI(char *str)
  {
        LOGD("in callbackFromUI");

        cJSON *root_back;
            root_back=cJSON_CreateObject();//创建项目
            cJSON_AddItemToObject(root_back, "cmd", cJSON_CreateString("SDP Answer"));

            cJSON * js_params;
            js_params = cJSON_CreateObject();
            cJSON_AddItemToObject(root_back, "params", js_params);
            cJSON_AddStringToObject(js_params,"sdp",str);

            char *out = cJSON_Print(root_back);

            LOGD("start to call java %s",out);
            //CallJavaFuntionByByteArray(out);
            LOGD("end to call java");

        LOGD("out callbackFromUI");
  }


// http://blog.csdn.net/jancyliu/article/details/9049597
  void CallJavaFuntionByByteArray(char *strJsonCommand)
  {
    JNIEnv *env = NULL;
    jclass cls = NULL;
    jmethodID pfunMethodId = NULL;

    //try
    {
        if(0 == is_attached)
        {
            g_pJvmCTestNDk->AttachCurrentThread(&env, NULL);
    		if(NULL == env)
    		{
    		    LOGD("AttachCurrentThread failed");
    			return;
    		}
    		LOGD("AttachCurrentThread OK");
    	}

        if( NULL == SipJNIJava )
        {
    		cls = env->GetObjectClass(g_pObjectCTestNDk);
    		if(NULL == cls)
    		{
    		    LOGD("GetObjectClass failed");
    			return;
    		}

    		SipJNIJava = cls;
    		LOGD("GetObjectClass OK");
    	}
    	else
    	{
    	    cls = SipJNIJava;
    	}

    	if( NULL == callbackByteArray)
    	{
    		callbackByteArray = env->GetMethodID(cls, "callbackByteArray", "([B)V");

    		if(NULL == callbackByteArray)
    		{
    		    LOGD("callbackByteArray failed");
    			return;
    		}
    		LOGD("callbackByteArray OK");
        }


        int len = strlen(strJsonCommand);
        jbyteArray  jbarray = env->NewByteArray(len);//建立jbarray数组
        jbyte *jy=(jbyte*)strJsonCommand;  //BYTE强制转换成Jbyte；
        env->SetByteArrayRegion(jbarray, 0, len, jy);            //将Jbyte 转换为jbarray数组

        //(*env)->CallStaticVoidMethod(env,SipJNIJava, callbackByteArray,jbarray);           //回调java方法
        env->CallVoidMethod(g_pObjectCTestNDk, callbackByteArray,jbarray);           //回调java方法

        g_pJvmCTestNDk->DetachCurrentThread();
    }

  }


