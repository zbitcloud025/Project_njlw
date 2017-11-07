/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : initfunc.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : initfunc.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __INITFUNC_H__
#define __INITFUNC_H__

/* modified by chenyu 130522 */
#ifdef WIN32

#ifdef EV9000SIP_EXPORTS
#define EV9000SIP_API    __declspec(dllexport)
#else
#define EV9000SIP_API    __declspec(dllimport)
#endif

#else
#define EV9000SIP_API    extern
#endif //end WIN32

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/

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

    EV9000SIP_API void SIP_Free();
    EV9000SIP_API int SIP_Init();
    extern int sip_stack_cell_free_for_recv();
    extern int sip_stack_cell_free_for_recv_msg();
    extern int sip_stack_cell_free_for_recv_register();
    extern int sip_stack_cell_free_for_send();
    extern int sip_stack_cell_free_for_send_msg();
    extern int sip_stack_cell_init_for_recv();
    extern int sip_stack_cell_init_for_recv_msg();
    extern int sip_stack_cell_init_for_recv_register();
    extern int sip_stack_cell_init_for_send();
    extern int sip_stack_cell_init_for_send_msg();
    EV9000SIP_API int sip_stack_free();
    EV9000SIP_API int sip_stack_init();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __INITFUNC_H__ */