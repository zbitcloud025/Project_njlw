#ifndef __PRESET_PROC_H__
#define __PRESET_PROC_H__


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
#include "libxml/Packet.h"

#include "common/gbldef.inc"
#include "common/DBOper.h"

#include <vector>
#include <string>
using namespace std;

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

    /* Ԥ��λ�Զ���λ�ṹ */
    typedef struct  _preset_auto_back_t
    {
        unsigned int uDeviceIndex;                        /* �豸����*/
        unsigned int uPresetID;                           /* Ԥ��λID */
        int iDurationTime;                                /* �Զ���λʱ�� */
        int iDurationTimeCount;                           /* �Զ���λʱ����� */
        int iStatus;                                      /* �Ƿ���Ҫ�Զ���λ:0:��1:�� */
    } preset_auto_back_t;

    /* Ԥ��λ�Զ���λ����*/
    typedef struct _preset_auto_back_list_t
    {
        osip_list_t* preset_auto_back_list;

        /* the lock */
#ifdef MULTI_THR
        osip_mutex_t*  lock;
#endif

    } preset_auto_back_list_t;

    /* ������Ԥ��λ�Զ���λ���� */
    typedef std::deque <preset_auto_back_t*> needtoproc_preset_auto_back_queue;


    /* ��λ�Զ������ṹ */
    typedef struct  _device_auto_unlock_t
    {
        unsigned int uDeviceIndex;                        /* �豸����*/
        int iDurationTimeCount;                           /* �Զ�����ʱ����� */
        int iStatus;                                      /* �Ƿ���Ҫ�Զ�����:0:��1:�� */
    } device_auto_unlock_t;

    /* ��λ�Զ���������*/
    typedef struct _device_auto_unlock_list_t
    {
        osip_list_t* device_auto_unlock_list;

        /* the lock */
#ifdef MULTI_THR
        osip_mutex_t*  lock;
#endif

    } device_auto_unlock_list_t;

    /* ��������λ�Զ��������� */
    typedef std::deque <device_auto_unlock_t*> needtoproc_device_auto_unlock_queue;

    extern device_auto_unlock_t* device_auto_unlock_find(unsigned int uDeviceIndex);
    extern device_auto_unlock_t* device_auto_unlock_find2(unsigned int uDeviceIndex);
    extern void device_auto_unlock_free(device_auto_unlock_t* node);
    extern int device_auto_unlock_init(device_auto_unlock_t** node);
    extern int device_auto_unlock_list_clean();
    extern void device_auto_unlock_list_free();
    extern int device_auto_unlock_list_init();
    extern int device_auto_unlock_proc(unsigned int uDeviceIndex);
    extern int device_auto_unlock_remove(unsigned int uDeviceIndex);
    extern int device_auto_unlock_update(unsigned int uDeviceIndex);
    extern int device_auto_unlock_use(unsigned int uDeviceIndex);
    extern preset_auto_back_t* preset_auto_back_find(unsigned int uDeviceIndex);
    extern preset_auto_back_t* preset_auto_back_find2(unsigned int uDeviceIndex);
    extern void preset_auto_back_free(preset_auto_back_t* node);
    extern int preset_auto_back_init(preset_auto_back_t** node);
    extern int preset_auto_back_list_clean();
    extern void preset_auto_back_list_free();
    extern int preset_auto_back_list_init();
    extern int preset_auto_back_proc(unsigned int uDeviceIndex, unsigned int uPresetID);
    extern int preset_auto_back_remove(unsigned int uDeviceIndex);
    extern int preset_auto_back_update(unsigned int uDeviceIndex);
    extern int preset_auto_back_use(unsigned int uDeviceIndex, unsigned int uPresetID, int iDurationTime);
    extern void scan_device_auto_unlock_list();
    extern void scan_preset_auto_back_list();
    extern void ShowDeviceAutoUnLockTaskInfo(int sock);
    extern void ShowPresetAutoBackTaskInfo(int sock);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */