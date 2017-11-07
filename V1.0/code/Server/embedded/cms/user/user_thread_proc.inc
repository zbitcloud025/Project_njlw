#ifndef __USER_THREAD_PROC_H__
#define __USER_THREAD_PROC_H__


/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <sys/types.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#include "libsip.h"
#include "common/DBOper.h"
#include "user/user_info_mgn.inc"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/

    /* �û�ҵ����Ϣ�ṹ�� */
    typedef struct _user_srv_msg_t
    {
        msg_type_t msg_type;                            /* ��Ϣ���� */
        char caller_id[MAX_ID_LEN + 4];                 /* �����û�ͳһ��� */
        char callee_id[MAX_ID_LEN + 4];                 /* �����û�ͳһ��� */
        int response_code;                              /* ��Ӧ��Ϣ��,ֻ�л�Ӧ��Ϣ�� */
        char reasonphrase[MAX_128CHAR_STRING_LEN + 4];  /* ��Ӧ�Ĵ�����Ϣ��ֻ�л�Ӧ��Ϣ�� */
        int ua_dialog_index;                            /* ��Ӧdialog ������ֻ�лỰ����Ϣ�� */
        char msg_body[MAX_MSG_BODY_STRING_LEN + 4];     /* SIP ��ϢЯ������Ϣ��*/
        int msg_body_len;                               /* SIP ��ϢЯ������Ϣ�峤��*/
        int cr_pos;                                     /* ��Ӧ�ĺ�����Դ������Ϣ */
    } user_srv_msg_t;

    /* �û�ҵ����Ϣ���� */
    typedef std::deque <user_srv_msg_t*> user_srv_msg_queue;

    /* �û�ҵ�����߳̽ṹ��*/
    typedef struct _user_srv_proc_tl_t
    {
        int iUsed;                                       /* �Ƿ����� */
        user_info_t* pUserInfo;                          /* �û���Ϣ */
        osip_thread_t* thread;                           /* �û�ҵ�����߳� */
        int th_exit;                                     /* �û�ҵ�����̱߳�־ */
        time_t  run_time;                                /* ����ʱ�� */
        DBOper* pUser_Srv_dboper;                        /* �û�ҵ�������ݿ����� */
        DBOper* pUserLogDbOper;                          /* ��־���ݿ����ӱ�ʶ */
        int iUserLogDBOperConnectStatus;                 /* ��־���ݿ�����״̬ */
        user_srv_msg_queue* pUserSrvMsgQueue;            /* �û�ҵ����Ϣ���� */
#ifdef MULTI_THR
        osip_mutex_t* pUserSrvMsgQueueLock;              /* �û�ҵ����Ϣ������ */
#endif
    } user_srv_proc_tl_t;

    /* �û�ҵ�����̶߳��� */
    typedef struct _user_srv_proc_tl_list_t
    {
        osip_list_t*    pUserSrvProcList;
#ifdef MULTI_THR
        osip_mutex_t* lock;
#endif
    } user_srv_proc_tl_list_t;

    /* �������û�ҵ���̶߳��� */
    typedef std::deque <user_srv_proc_tl_t*> needtoproc_usersrvproc_queue;

    extern int debug_user_srv_proc_thread_list_lock(const char* file, int line, const char* func);
    extern int debug_user_srv_proc_thread_list_unlock(const char* file, int line, const char* func);
    extern void free_unused_user_tcp_connect();
    extern user_srv_proc_tl_t* get_free_user_srv_proc_thread();
    extern user_srv_proc_tl_t* get_user_srv_proc_thread(char* user_id, char* user_ip, int user_port);
    extern user_srv_proc_tl_t* get_user_srv_proc_thread2(char* user_id, char* user_ip, int user_port);
    extern void scan_user_srv_proc_thread_list();
    extern void ShowConnectTCPUser(int sock);
    extern void show_user_srv_proc_thread(int sock, int type);
    extern void UserLoginServerFree();
    extern int  UserLoginServerInit();
    extern void UserLoginServerMain(DBOper* pDbOper);
    extern int user_srv_proc_thread_assign(user_info_t* pUserInfo);
    extern void* user_srv_proc_thread_execute(void* p);
    extern int user_srv_proc_thread_find(user_info_t* pUserInfo);
    extern void user_srv_proc_thread_free(user_srv_proc_tl_t* run);
    extern int user_srv_proc_thread_init(user_srv_proc_tl_t** run);
    extern void user_srv_proc_thread_list_free();
    extern int user_srv_proc_thread_list_init();
    extern int user_srv_proc_thread_list_lock();
    extern int user_srv_proc_thread_list_unlock();
    extern int user_srv_proc_thread_recycle(char* user_id, char* user_ip, int user_port);
    extern int user_srv_proc_thread_restart(user_info_t* pUserInfo);
    extern int user_srv_proc_thread_start_all();
    extern int user_srv_proc_thread_stop_all();

#ifdef ENABLE_DEBUG_LOCK
#define USER_SRV_PROC_THREAD_SMUTEX_LOCK() debug_user_srv_proc_thread_list_lock(__FILE__, __LINE__, __func__)
#define USER_SRV_PROC_THREAD_SMUTEX_UNLOCK() debug_user_srv_proc_thread_list_unlock(__FILE__, __LINE__, __func__)
#else
#define USER_SRV_PROC_THREAD_SMUTEX_LOCK() user_srv_proc_thread_list_lock()
#define USER_SRV_PROC_THREAD_SMUTEX_UNLOCK() user_srv_proc_thread_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */