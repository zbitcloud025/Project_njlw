#ifndef __PLATFORM_THREAD_PROC_H__
#define __PLATFORM_THREAD_PROC_H__


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
#include "route/platform_info_mgn.inc"

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

    /* �ϼ�·��ҵ�����߳̽ṹ��*/
    typedef struct _platform_srv_proc_tl_t
    {
        int iUsed;                                  /* �Ƿ����� */
        unsigned int platform_index;                /* ���� */
        char platform_ip[MAX_IP_LEN];               /* ����ƽ̨ IP ��ַ*/
        osip_thread_t* thread;                      /* �ϼ�·��ҵ�����߳� */
        int th_exit;                                /* �ϼ�·��ҵ�����̱߳�־ */
        time_t  run_time;                           /* ����ʱ�� */
        DBOper* pPlatform_Srv_dboper;               /* �ϼ�·��ҵ�������ݿ����� */
        DBOper* pPlatformLogDbOper;                 /* ��־���ݿ����ӱ�ʶ */
        int iPlatformLogDBOperConnectStatus;        /* ��־���ݿ�����״̬ */

        int iTaskMode;                              /* �����ȡģʽ :0: �Զ�ִ�У�1:�ֶ�ִ�У�Ĭ��0 */
        int iTaskRunInterval;                       /* ����ִ�м��ʱ�� */
        int iTaskGetInterval;                       /* �����ȡ���ʱ�� */

        int iTaskBeginTime;                         /* �ֶ�ģʽ�»�ȡ����ʼʱ�� */
        int iTaskEndTime;                           /* �ֶ�ģʽ�»�ȡ����ִ��ʱ�� */
        int iLastGetTaskTime;                       /* �ϴλ�ȡ����ʱ�� */

        int iLastTaskRunTime;                       /* �ϴ�ѹ��ִ��ʱ�� */

        int iCompressTaskStatus;                    /* ѹ������״̬:0:��ʼ״̬, 1:׼����ȡ, 2:���ڻ�ȡ����, 3:��ȡʧ��, 4:��ȡ�ɹ���׼������, 5:���ڷ��䴦��, 6:û�з���ɹ�, 7:����ɹ�, 8:����ѹ��������� */
    } platform_srv_proc_tl_t;

    /* �ϼ�·��ҵ�����̶߳��� */
    typedef struct _platform_srv_proc_tl_list_t
    {
        osip_list_t*    pPlatformSrvProcList;
#ifdef MULTI_THR
        osip_mutex_t* lock;
#endif
    } platform_srv_proc_tl_list_t;

    /* �������ϼ�·��ҵ���̶߳��� */
    typedef std::deque <platform_srv_proc_tl_t*> needtoproc_platformsrvproc_queue;

    extern int debug_platform_srv_proc_thread_list_lock(const char* file, int line, const char* func);
    extern int debug_platform_srv_proc_thread_list_unlock(const char* file, int line, const char* func);
    extern int get_compress_task_from_webservice_thread_execute(void* p);
    extern platform_srv_proc_tl_t* get_free_platform_srv_proc_thread();
    extern platform_srv_proc_tl_t* get_platform_srv_proc_thread(unsigned int platform_index);
    extern platform_srv_proc_tl_t* get_platform_srv_proc_thread2(unsigned int platform_index);
    extern int get_platform_thread_info_from_db(platform_srv_proc_tl_t* plat_thread);
    extern int platform_srv_proc_thread_assign(platform_info_t* pPlatformInfo);
    extern void* platform_srv_proc_thread_execute(void* p);
    extern int platform_srv_proc_thread_find(unsigned int platform_index);
    extern void platform_srv_proc_thread_free(platform_srv_proc_tl_t* run);
    extern int platform_srv_proc_thread_init(platform_srv_proc_tl_t** run);
    extern void platform_srv_proc_thread_list_free();
    extern int platform_srv_proc_thread_list_init();
    extern int platform_srv_proc_thread_list_lock();
    extern int platform_srv_proc_thread_list_unlock();
    extern int platform_srv_proc_thread_recycle(unsigned int platform_index);
    extern int platform_srv_proc_thread_start_all();
    extern int platform_srv_proc_thread_stop_all();
    extern void scan_platform_srv_proc_thread_list();
    extern void set_platform_srv_proc_thread_compress_task_status(int status);
    extern void show_platform_srv_proc_thread(int sock, int type);
    extern int UpdatePlatFormCompressTaskStatusToDB(char* platform_ip, int iLastGetTaskTime, int iCompressTaskStatus, int iErrorCode, DBOper* pDbOper);

#ifdef ENABLE_DEBUG_LOCK
#define PLATFORM_SRV_PROC_THREAD_SMUTEX_LOCK() debug_platform_srv_proc_thread_list_lock(__FILE__, __LINE__, __func__)
#define PLATFORM_SRV_PROC_THREAD_SMUTEX_UNLOCK() debug_platform_srv_proc_thread_list_unlock(__FILE__, __LINE__, __func__)
#else
#define PLATFORM_SRV_PROC_THREAD_SMUTEX_LOCK() platform_srv_proc_thread_list_lock()
#define PLATFORM_SRV_PROC_THREAD_SMUTEX_UNLOCK() platform_srv_proc_thread_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */