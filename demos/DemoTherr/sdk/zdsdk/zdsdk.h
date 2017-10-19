#pragma once
#ifndef __ZDSDK__H__
#define __ZDSDK__H__

#include <zmm/zmmdec.h>

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

#define NOTIFY_TYPE_RUN                     0

#define MSG_TYPE_LOGIN						1
#define MSG_TYPE_LOGOUT						2
#define MSG_TYPE_START_MONITOR				3
#define MSG_TYPE_STOP_MONITOR				4
#define MSG_TYPE_PTZ_CONTROL				5
#define MSG_TYPE_QUERY_RECORD				6
#define MSG_TYPE_START_PLAYBACK				7
#define MSG_TYPE_STOP_PLAYBACK				8
#define MSG_TYPE_CTRL_PLAYBACK				9
#define MSG_TYPE_DOWNLOAD_RECORD			10
#define MSG_TYPE_START_AUDIO				11 //���������Խ���Ϣ;
#define MSG_TYPE_STOP_AUDIO					12 //ֹͣ�����Խ���Ϣ;
#define MSG_TYPE_CHANNEL_LIST               13 //��ȡͨ���б�֪ͨ;
#define MSG_TYPE_QUERY_GROUP                14
#define MSG_TYPE_QUERY_PRESET				15
#define MSG_TYPE_PRESET_CONTROL				16
#define	MSG_TYPE_PRESET_GOTO				17
#define MSG_TYPE_FD_LIST					18
#define MSG_TYPE_FD_CHANNELLIST				19
#define MSG_TYPE_UA_RECORDSTART				20
#define MSG_TYPE_UA_RECORDSTOP				21
#define MSG_TYPE_CONFIG_RECORD_PLAN			22
#define MSG_TYPE_QUERY_RECORD_PLAN			23
#define MSG_TYPE_QUERY_PRESETSCHEDULE		24
#define MSG_TYPE_SET_PRESETSCHEDULE			25
#define MSG_TYPE_QUERY_FDSTATUS				26
#define MSG_TYPE_MODIFY_PASSWORD			27
#define MSG_TYPE_MODIFY_FDNAME				28
#define MSG_TYPE_MODIFY_CHANNELNAME			29

#define NOTIFY_TYPE_ALARM					100
#define NOTIFY_TYPE_FD_ONLINE				101
#define NOTIFY_TYPE_DOWNLOAD_URL			102


    enum ERV_NET_TYPE {
        NET_TYPE_AUTO,
        NET_TYPE_UDP = 1,
        NET_TYPE_TCP = 2,
    };

    enum ERV_PLAYBACK_CTRL_ACTION
    {
        PLAYBACK_CTRL_ACTION_FastForward = 0x01,//���
        PLAYBACK_CTRL_ACTION_FastBackward = 0x02,//����
        PLAYBACK_CTRL_ACTION_Pause = 0x03,//��ͣ 
        PLAYBACK_CTRL_ACTION_Stop = 0x04,//ֹͣ 
        PLAYBACK_CTRL_ACTION_Continue = 0x05,//�����ط� 
        PLAYBACK_CTRL_ACTION_DragPlay = 0x06,//�ط��϶�
        PLAYBACK_CTRL_ACTION_SlowForward = 0x07,//���� 
        PLAYBACK_CTRL_ACTION_SlowBackward = 0x08,//����
        PLAYBACK_CTRL_ACTION_FramePlay = 0x09,//��֡��
        PLAYBACK_CTRL_ACTION_Forward = 0x0a,//�Ե�ǰ������ǰ��
        PLAYBACK_CTRL_ACTION_Backward = 0x0b,//�Ե�ǰ��������
    };

    enum ERV_CAMERA_CONTROL_ACTION
    {
        CAMERA_CONTROL_ACTION_UP = 0x00000001 /*����ת*/,
        CAMERA_CONTROL_ACTION_LEFT = 0x00000002 /*����ת*/,
        CAMERA_CONTROL_ACTION_ROTATE = 0x00000003 /*��ת*/,
        CAMERA_CONTROL_ACTION_RIGHT = 0x00000004 /*����ת*/,
        CAMERA_CONTROL_ACTION_DOWN = 0x00000005 /*����ת*/,
        CAMERA_CONTROL_ACTION_FAR = 0x00000006 /*��ͷ��Զ*/,
        CAMERA_CONTROL_ACTION_FOCUSNEAR = 0x00000007 /*�۽�*/,
        CAMERA_CONTROL_ACTION_AUTO = 0x00000008 /*�Զ�*/,
        CAMERA_CONTROL_ACTION_FOCUSFAR = 0x00000009 /*ɢ��*/,
        CAMERA_CONTROL_ACTION_NEAR = 0x0000000a /*��ͷ����*/,
        CAMERA_CONTROL_ACTION_DIAPHRAGM_LARGE = 0x0000000b /*��Ȧ���󣨱�����*/,
        CAMERA_CONTROL_ACTION_DIAPHRAGM_SMALL = 0x0000000c /*��Ȧ��С���䰵��*/,
        CAMERA_CONTROL_ACTION_STOP = 0x0000000d /*ֹͣ����*/,
        CAMERA_CONTROL_ACTION_SPEAKER_ON = 0x0000000e /*������*/,
        CAMERA_CONTROL_ACTION_LIGHT_ON = 0x0000000f /*�򿪵ƹ�*/,
        CAMERA_CONTROL_ACTION_HOTDOG = 0x00000010 /*�ȹ�ɨ��*/,
        CAMERA_CONTROL_ACTION_SPEAKER_OFF = 0x00000011 /*�ر�����*/,
        CAMERA_CONTROL_ACTION_LIGHT_OFF = 0x00000012 /*�رյƹ�*/,
        CAMERA_CONTROL_ACTION_PRESET_GOTO = 0x00000013 /*�л���Ԥ�õ�*/,
        CAMERA_CONTROL_ACTION_PRESET_SET = 0x00000014 /*����Ԥ�õ�*/,
        CAMERA_CONTROL_ACTION_PRESET_DEL = 0x00000015 /*ɾ��Ԥ�õ�*/,
        CAMERA_CONTROL_ACTION_CAMERA_RESET = 0x00000016 /*�������λ*/,
        CAMERA_CONTROL_ACTION_WIPER_ON = 0x00000017 /*����ˢ*/,
        CAMERA_CONTROL_ACTION_WIPER_OFF = 0x00000018 /*�ر���ˢ*/,
        CAMERA_CONTROL_ACTION_AUTOCRUISE = 0x0000001d /*�Զ�Ѳ��*/,
        CAMERA_CONTROL_ACTION_PRESET_CLEAR = 0x0000001e /*�������Ԥ�õ�*/,
        CAMERA_CONTROL_ACTION_STARTTRACKING = 0x0000001f /*��������*/,
        CAMERA_CONTROL_ACTION_STOPTRACKING = 0x00000020 /*ֹͣ����*/,
        CAMERA_CONTROL_ACTION_LEFTUP = 0x00000021 /*����ת*/,
        CAMERA_CONTROL_ACTION_RIGHTUP = 0x00000022 /*����ת*/,
        CAMERA_CONTROL_ACTION_LEFTDOWN = 0x00000023 /*����ת*/,
        CAMERA_CONTROL_ACTION_RIGHTDOWN = 0x00000024 /*����ת*/,
        CAMERA_CONTROL_ACTION_CAMERAACTIVE = 0x00000028 /*���������*/,
        CAMERA_CONTROL_ACTION_SETPANSPEED = 0x00000029 /*��������ת���ٶ�*/,
        CAMERA_CONTROL_ACTION_SETTILTSPEED = 0x00000030 /*��������ת���ٶ�*/,
        CAMERA_CONTROL_ACTION_SETZOOMSPEED = 0x00000031 /*���ù�Ȧ�ٶ�*/,
        CAMERA_CONTROL_ACTION_SETFOCUSSPEED = 0x00000032 /*���þ۽�/ɢ���ٶ�*/,
        CAMERA_CONTROL_ACTION_SPEEDSETTINGGET = 0x00000033 /*��ȡ������ٶ�����*/,
        CAMERA_CONTROL_ACTION_MATRIXSWITCH = 0x00000040 /*�����л�*/,
        CAMERA_CONTROL_ACTION_BRIGHTNESS = 0x00000050 /*����*/,
        CAMERA_CONTROL_ACTION_CONTRAST = 0x00000051 /*�Աȶ�*/,
        CAMERA_CONTROL_ACTION_SATURATION = 0x00000052 /*���Ͷ�*/,
        CAMERA_CONTROL_ACTION_HUE = 0x00000053 /*ɫ��*/,
		CAMERA_CONTROL_ACTION_PTZ_LOCK = 0x000000FF /*PTZ����*/,
    };

    enum ERV_ZDSDK_ERRORCODE
    {
        ZDSDK_OK = 0x00000000,
        ZDSDK_SUCCESS_COMMON_BASE = 0x00010000 /*UAS BASE*/,
        ZDSDK_SUCCESS_UA_BASE = 0x00020000,
        ZDSDK_SUCCESS_UA_UPDATE = 0x00020001,
        ZDSDK_SUCCESS_UA_REDIRECT = 0x00020002,
        ZDSDK_SUCCESS_UA_LOGINREPLACED = 0x00020003,
        ZDSDK_SUCCESS_FD_BASE = 0x00030000,
        ZDSDK_SUCCESS_AAA_BASE = 0x00040000,
        ZDSDK_SUCCESS_MSS_BASE = 0x00050000,
        ZDSDK_SUCCESS_DBMS_BASE = 0x00060000,
        ZDSDK_SUCCESS_FDMS_BASE = 0x00070000,
        ZDSDK_SUCCESS_CMS_BASE = 0x00080000,
        ZDSDK_ERROR_COMMON_BASE = 0x80010000,
        ZDSDK_ERROR_COMMON_UNPACK = 0x80010001,
        ZDSDK_ERROR_COMMON_PACK = 0x80010002,
        ZDSDK_ERROR_COMMON_SERVICE_UNAVAILABLE = 0x80010003,
        ZDSDK_ERROR_COMMON_CMDERROR = 0x80010004,
        ZDSDK_ERROR_COMMON_NODBMSPROXY = 0x80010005,
        ZDSDK_ERROR_COMMON_NOFDMSPROXY = 0x80010006,
        ZDSDK_ERROR_COMMON_NOMSSPROXY = 0x80010007,
        ZDSDK_ERROR_COMMON_DBMSFAIL = 0x80010008,
        ZDSDK_ERROR_COMMON_DBMS_NORECORD = 0x80010009,
        ZDSDK_ERROR_COMMON_MSSFAIL = 0x8001000a,
        ZDSDK_ERROR_COMMON_FDMSFAIL = 0x8001000b,
        ZDSDK_ERROR_COMMON_ICEEXCEPTION = 0x8001000c,
        ZDSDK_ERROR_COMMON_RESULTERROR = 0x8001000d,
        ZDSDK_ERROR_COMMON_MONITOR_IN_PROCESS = 0x8001000e,
        ZDSDK_ERROR_COMMON_MONITOR_NOT_IN_PROCESS = 0x8001000f,
        ZDSDK_ERROR_COMMON_RECORD_IN_PROCESS = 0x80010010,
        ZDSDK_ERROR_COMMON_RECORD_NOT_IN_PROCESS = 0x80010011,
        ZDSDK_ERROR_COMMON_DOWNLOAD_IN_PROCESS = 0x80010012,
        ZDSDK_ERROR_COMMON_DOWNLOAD_NOT_IN_PROCESS = 0x80010013,
        ZDSDK_ERROR_COMMON_PLAYBACK_IN_PROCESS = 0x80010014,
        ZDSDK_ERROR_COMMON_PLAYBACK_NOT_IN_PROCESS = 0x80010015,
        ZDSDK_ERROR_COMMON_USER_CANCELED = 0x80010016 /*�����ѱ��û�ȡ�������緢��STOP*/,
        ZDSDK_ERROR_COMMON_NOTSUPPORT = 0x80010017 /*���ܲ�֧��*/,
        ZDSDK_ERROR_COMMON_RECORD_TIME = 0x80010018,
        ZDSDK_ERROR_COMMON_REACH_MAX = 0x80010019,
        ZDSDK_ERROR_COMMON_CSS_NOSPACE = 0x8001001a /*���Ĵ洢���ϵ��ܿռ�Ϊ0*/,
        ZDSDK_ERROR_COMMON_MSS_INVALID_PARAM = 0x8001001b,
        ZDSDK_ERROR_COMMON_REACH_CUSTOMERMAX = 0x8001001c,
        ZDSDK_ERROR_COMMON_TIME = 0x8001001d /*ʱ�������ץ�ġ�¼�����Ҫָ��ʱ���ָ���У�ʱ����Ч*/,
        ZDSDK_ERROR_COMMON_LOCKED = 0x8001001e /*�豸����ס������̨���������У���̨�������û���ס*/,
        ZDSDK_ERROR_COMMON_REMOTE_DOMAIN_OFFLINE = 0x8001001f /*���������δ����*/,
        ZDSDK_ERROR_COMMON_VERSION_TOOLD = 0x80010020 /*�汾̫��*/,
        ZDSDK_ERROR_COMMON_BUSY = 0x80010021 /*̫æ*/,
        ZDSDK_ERROR_COMMON_NOTENOUGH = 0x80010021 /*̫С*/,

        ZDSDK_ERROR_UA_BASE = 0x80020000,
        ZDSDK_ERROR_UA_NOTEXIST = 0x80020001,
        ZDSDK_ERROR_UA_OUTOFDATE = 0x80020002,
        ZDSDK_ERROR_UA_LOGINFAIL = 0x80020003,
        ZDSDK_ERROR_UA_NOPRIVILEGE = 0x80020004,
        ZDSDK_ERROR_UA_ERRORTYPE = 0x80020005,
        ZDSDK_ERROR_UA_EMAILEXISTED = 0x80020006,
        ZDSDK_ERROR_UA_CMDNOCONTENT = 0x80020007,
        ZDSDK_ERROR_UA_NOTSPECIFIED = 0x80020008,
        ZDSDK_ERROR_UA_UACANCELED = 0x80020009,
        ZDSDK_ERROR_UA_CLIENTCANCELED = 0x8002000a,
        ZDSDK_ERROR_FD_BASE = 0x80030000,
        ZDSDK_ERROR_AAA_BASE = 0x80040000,
        ZDSDK_ERROR_AAA_UNKNOWN = 0x80040001 /*δ֪ԭ�����*/,
        ZDSDK_ERROR_AAA_INVALIDPACKET = 0x80040002 /*Radius�����Ϸ�*/,
        ZDSDK_ERROR_AAA_MISSATTRIBUTE = 0x80040003 /*Radius��ȱ�ٱ�Ҫ������*/,
        ZDSDK_ERROR_AAA_INTERNAL = 0x80040004 /*AAA�����������ڲ�����*/,
        ZDSDK_ERROR_AAA_DBMS = 0x80040005 /*AAA�������������ݿ�ʧ��*/,
        ZDSDK_ERROR_AAA_STOPPED = 0x80040006 /*AAA������ֹͣ����*/,
        ZDSDK_ERROR_AAA_PASSWORD = 0x80040007 /*�������*/,
        ZDSDK_ERROR_AAA_BADUSERID = 0x80040008 /*�û�ID������*/,
        ZDSDK_ERROR_AAA_BADDEVID = 0x80040009 /*�豸ID������*/,
        ZDSDK_ERROR_AAA_BADCHANNEL = 0x8004000a /*�豸ͨ���Ų�����*/,
        ZDSDK_ERROR_AAA_FORBIDDEN = 0x8004000b /*û��Ȩ��ִ��������Ĳ���*/,
        ZDSDK_ERROR_AAA_NOMONEY = 0x8004000c /*���ò���*/,
        ZDSDK_ERROR_AAA_NODISK = 0x8004000d /*��������*/,
        ZDSDK_ERROR_AAA_CUSTOMERSTATUS = 0x8004000e /*�ͻ�״̬������*/,
        ZDSDK_ERROR_AAA_USERSTATUS = 0x8004000f /*�û�״̬������*/,
        ZDSDK_ERROR_AAA_USERIPDENIED = 0x80040010 /*�û�IP��ַ�ܾ�*/,
        ZDSDK_ERROR_AAA_SMSCODEFAIL = 0x80040011 /*���ŵ�¼��������*/,
        ZDSDK_ERROR_AAA_SMSBAD = 0x80040012 /*������֤�����*/,
        ZDSDK_ERROR_AAA_SMSSENDFAILED = 0x80040013 /*������֤�뷢��ʧ��*/,
        ZDSDK_ERROR_MSS_BASE = 0x80050000,
        ZDSDK_ERROR_MSS_FAIL = 0x80050001 /*:-1         ʧ��*/,
        ZDSDK_ERROR_MSS_INVALID_ID = 0x80050002 /*:-2         �Ƿ�ID*/,
        ZDSDK_ERROR_MSS_INVALID_HANDLE = 0x80050003 /*:-3         �Ƿ����*/,
        ZDSDK_ERROR_MSS_INVALID_PARAM = 0x80050004 /*:-4         �Ƿ�����*/,
        ZDSDK_ERROR_MSS_NULLPTR = 0x80050005 /*:-5         ָ��ΪNULL*/,
        ZDSDK_ERROR_MSS_REPEAT = 0x80050006 /*:-6         �ظ�����*/,
        ZDSDK_ERROR_MSS_TIMEOUT = 0x80050007 /*:-7         ��ʱ*/,
        ZDSDK_ERROR_MSS_OUTOF_MEMORY = 0x80050008 /*:-8         �ڴ治��*/,
        ZDSDK_ERROR_MSS_OUTOF_RANGE = 0x80050009 /*:-9         ������Χ*/,
        ZDSDK_ERROR_MSS_FULL = 0x8005000a /*:-10        ��������*/,
        ZDSDK_ERROR_MSS_UNEXPECTED = 0x8005000b /*:-11        δ֪�쳣*/,
        ZDSDK_ERROR_MSS_PRIVILEGE_LIMIT = 0x8005000c /*:-12        Ȩ������*/,
        ZDSDK_ERROR_MSS_BUSY = 0x80050100 /*MSS����æ*/,
        ZDSDK_ERROR_MSS_SCHEDULE_FD = 0x80050101 /*MSS����FDʧ��*/,
        ZDSDK_ERROR_MSS_SCHEDULE_RTMDS = 0x80050102 /*MSS����RTMDSʧ��*/,
        ZDSDK_ERROR_MSS_SCHEDULE_SMS = 0x80050103 /*MSS����SMSʧ��*/,
        ZDSDK_ERROR_MSS_SCHEDULE_FTS = 0x80050104 /*MSS����FTSʧ��*/,
        ZDSDK_ERROR_MSS_SCHEDULE_CSS = 0x80050105 /*MSS����CSSʧ��*/,
        ZDSDK_ERROR_MSS_SCHEDULE_CANCELLED = 0x80050106 /*MSS���ȱ�ȡ��*/,
        ZDSDK_ERROR_MSS_FD_OFFLINE = 0x80050200 /*FDδ����, ����VPN��*/,
        ZDSDK_ERROR_MSS_FD_CHANNEL_INVALID = 0x80050201 /*FDδ����*/,
        ZDSDK_ERROR_MSS_FD_BUSY = 0x80050202 /*FDæ*/,
        ZDSDK_ERROR_MSS_FD_NO_RIGHT = 0x80050203 /*FD����δ����Ȩ*/,
        ZDSDK_ERROR_MSS_FD_FAILTURE = 0x80050204 /*FD����ʧ��*/,
        ZDSDK_ERROR_MSS_FD_RETURN_ERROR = 0x80050205 /*FD���ش���*/,
        ZDSDK_ERROR_MSS_FD_PACKAGE_ERROR = 0x80050206 /*FD�������*/,
        ZDSDK_ERROR_MSS_FDMS_OFFLINE = 0x80050300 /*FDMS����δ���� 0x300*/,
        ZDSDK_ERROR_MSS_FDMS_TIMEOUT = 0x80050301 /*FDMS������Ӧ��ʱ*/,
        ZDSDK_ERROR_MSS_FDMS_FAILTURE = 0x80050302 /*FDMS������Ӧʧ��*/,
        ZDSDK_ERROR_MSS_RTMDS_OFFLINE = 0x80050400 /*RTMDS����δ���� 0x400*/,
        ZDSDK_ERROR_MSS_RTMDS_TIMEOUT = 0x80050401 /*RTMDS������Ӧ��ʱ*/,
        ZDSDK_ERROR_MSS_RTMDS_FAILTURE = 0x80050402 /*RTMDS������Ӧʧ��*/,
        ZDSDK_ERROR_MSS_SMS_OFFLINE = 0x80050500 /*SMS����δ����  0x500*/,
        ZDSDK_ERROR_MSS_SMS_TIMEOUT = 0x80050501 /*SMS������Ӧ��ʱ*/,
        ZDSDK_ERROR_MSS_SMS_FAILTURE = 0x80050502 /*SMS������Ӧʧ��*/,
        ZDSDK_ERROR_MSS_SMS_NO_FILE = 0x80050503 /*SMS������Ӧ�ļ�������*/,
        ZDSDK_ERROR_MSS_FTS_OFFLINE = 0x80050600 /*FTS����δ���� 0x600*/,
        ZDSDK_ERROR_MSS_FTS_TIMEOUT = 0x80050601 /*FTS������Ӧ��ʱ*/,
        ZDSDK_ERROR_MSS_FTS_FAILTURE = 0x80050602 /*FTS������Ӧʧ��*/,
        ZDSDK_ERROR_MSS_FTS_NO_FILE = 0x80050603 /*FTS������Ӧ�ļ�������*/,
        ZDSDK_ERROR_MSS_CSS_OFFLINE = 0x80050700 /*CSS����δ���� 0x700*/,
        ZDSDK_ERROR_MSS_CSS_TIMEOUT = 0x80050701 /*CSS������Ӧ��ʱ*/,
        ZDSDK_ERROR_MSS_CSS_FAILTURE = 0x80050702 /*CSS������Ӧʧ��*/,
        ZDSDK_ERROR_MSS_CSS_NO_FILE = 0x80050703 /*CSS������Ӧ�ļ�������*/,
        ZDSDK_ERROR_MSS_CSS_RECORDING = 0x80050704 /*CSS������Ӧ����¼��*/,
        ZDSDK_ERROR_MSS_CSS_BUSY = 0x80050705 /*CSS������Ӧæ*/,
        ZDSDK_ERROR_MSS_CSS_DISK_FULL = 0x80050706 /*CSS������Ӧ��������*/,
        ZDSDK_ERROR_MSS_CSS_DISK_QUOTA = 0x80050707 /*CSS������Ӧ�����޶�*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_STOP = 0x80050708 /*CSS���񱨸�¼��ֹͣ*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_EXPIRE = 0x80050709 /*CSS���񱨸�¼��ʱ�䵽��*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_QUOTA = 0x8005070a /*CSS���񱨸�¼������޶���*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NETWORKIO = 0x8005070b /*CSS���񱨸�¼������IO����*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_FILEIO = 0x8005070c /*CSS���񱨸�¼���ļ�IO����*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_STOPBYCMS = 0x8005070d /*CSS���񱨸�¼��ϵͳ����Աֹͣ*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NOPACKET = 0x8005070e /*CSS���񱨸�¼����һ�������ڽ��յ������ݰ�̫��*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NOFRAME = 0x8005070f /*CSS���񱨸�¼����һ�������ڽ��յ������ݰ�����ɵ�֡��Ϊ0*/,
        ZDSDK_ERROR_MSS_SSU_OFFLINE = 0x80050d00,
        ZDSDK_ERROR_MSS_SSU_TIMEOUT = 0x80050d01,
        ZDSDK_ERROR_MSS_SSU_FAILTURE = 0x80050d02,
        ZDSDK_ERROR_MSS_SID_MISMATCH = 0x80059000 /*��������sessionid��ƥ��*/,
        ZDSDK_ERROR_DBMS_BASE = 0x80060000,
        ZDSDK_ERROR_DBMS_QUERY_FD_DOMAIN = 0x80060001,
        ZDSDK_ERROR_DBMS_CUSTOM_NOTEXISTS = 0x80060002 /*DBMS��ѯ�ͻ�������*/,
        ZDSDK_ERROR_FDMS_BASE = 0x80070000 /*generic error*/,
        ZDSDK_ERROR_FDMS_DBMS = 0x80075000 /*fdms-dbms error*/,
        ZDSDK_ERROR_FDMS_FD_BASE = 0x80077000 /*fd generic error*/,
        ZDSDK_ERROR_FDMS_FD_TOO_MANY = 0x80077001 /*too many fd                                    1*/,
        ZDSDK_ERROR_FDMS_FD_BAD_STATE = 0x80077002 /*fd bad state, disabled in dbms                2*/,
        ZDSDK_ERROR_FDMS_FD_LICENSE = 0x80077003 /*license, too many fd                            3*/,
        ZDSDK_ERROR_FDMS_FD_MSG_SENDFAILED = 0x80077004 /*failed send msg to fd                    4*/,
        ZDSDK_ERROR_FDMS_FD_MULTI_LOGIN = 0x80077005 /*login more than 1 time                      5*/,
        ZDSDK_ERROR_FDMS_FD_CANCELED = 0x80077006 /*canceled                                       6*/,
        ZDSDK_ERROR_FDMS_FD_NOT_IN_DB = 0x80077007 /*fd not in the database                        7*/,
        ZDSDK_ERROR_FDMS_FD_EXCEPTION = 0x80077008 /*fd response exception, such as unpack failed  8*/,
        ZDSDK_ERROR_FDMS_FD_BAD_FDID = 0x80077009 /*bad fdid, such as length != 18                 9*/,
        ZDSDK_ERROR_FDMS_FD_TIMEOUT = 0x8007700a /*fd response timeout                             a*/,
        ZDSDK_ERROR_FDMS_FD_NOT_EXIST = 0x8007700b /*fd not online                                 b*/,
        ZDSDK_ERROR_FDMS_FD_FACTORY = 0x8007700c /*fd factory license, too many fd                 c*/,
        ZDSDK_ERROR_FDMS_FD_PTZLOCKED = 0x8007700d /*ptz locked                                    d*/,
        ZDSDK_ERROR_FDMS_BUSY = 0x8007700e /*too many fd logining, please wait                     e*/,
        ZDSDK_ERROR_FDMS_FD_NOTSUPPORTED = 0x8007700f /*not supported by fd                        f*/,
        ZDSDK_ERROR_FDMS_AAA = 0x80078000,
        ZDSDK_ERROR_FDMS_AAA_PARAM = 0x80078001 /*fd login failed because of bad parameter*/,
        ZDSDK_ERROR_FDMS_AAA_AUTH = 0x80078002 /*fd login failed because of bad password*/,
        ZDSDK_ERROR_CMS_BASE = 0x80080000,
        ZDSDK_ERROR_CMS_NAMEID_INDEX_OVERFLOW = 0x80080001 /*�±���Խ��*/,
        ZDSDK_ERROR_CMS_ID_NOTEXIST = 0x80080002 /*���󲻴���*/,
        ZDSDK_ERROR_CMS_TRAP_NOTSETABLE = 0x80080003 /*���󲻿�����*/,
        ZDSDK_ERROR_CMS_CLASS_NOTEXIST = 0x80080004 /*�಻����*/,
        ZDSDK_ERROR_CMS_METHOD_NOTEXIST = 0x80080005 /*����������*/,
        ZDSDK_ERROR_CMS_MEMBER_NOTEXIST = 0x80080006 /*��Ա������*/,
        ZDSDK_ERROR_PARALLEL_INTERVAL = 0x10000000,
        ZDSDK_ERROR_PARALLEL_BASE = 0x90090000,
        ZDSDK_ERROR_PARALLEL_TIMEOUT = 0x90090001,
        ZDSDK_ERROR_PARALLEL_DOMAINNOTEXIST = 0x90090002,
        ZDSDK_ERROR_PARALLEL_XMLPACK = 0x90090003,
        ZDSDK_ERROR_PARALLEL_XMLUNPACK = 0x90090004,
        ZDSDK_ERROR_PARALLEL_UPACKFDMSRES = 0x90090005,
    };

    typedef struct
    {
        char            channel_name[128]/*ͨ������*/;
        char            unique_id[38];
        char            domain_id[10];
        char            fd_id[22];
        char            db33_code[19]/*DB33���*/;
        char            gab_code[21]/*������*/;
        char            org_code[21]/*�������*/;
        unsigned char   isonline/*�豸����״̬*/;
        unsigned short  channel_type;
        unsigned short  channel_id;
        unsigned short  factory_code/*���̴��룬�鿴��Ƶ��ʱ��Ͳ����ٲ���ϸ��Ϣ��*/;
        unsigned int    channel_status/*BIT 1,�Ƿ�ɿأ�2,����ǰ��¼��3����������¼��4����Ƶ, 5����������¼��6������ǰ��¼��7~12,ǰ������(���ɿأ�ǹ����=0,�ɿأ������=1,ץ��ǹ��=2,����=3,ץ�ĸ���=4)*/;
        unsigned int    longitude/*����*/;
        unsigned int    latitude/*γ��*/;
        unsigned int    reserve/*����״̬*/;
    }ZDSDK_CHANNEL_INFO, *PZDSDK_CHANNEL_INFO;

    typedef struct
    {
        unsigned short  group_type; /* ����� */
        char    group_name[256];    /* ��ʾ����*/
        char    group_id[32];       /* ���ID��ʶ*/
        char    parent_id[32];      /* �����ID��ʶ*/
        char    full_path[256];     /* ȫ·��*/
        unsigned short  level;    /* ��ʾ����*/
        int     sort_id;            /* ������������*/
    }ZDSDK_GROUP_INFO, *PZDSDK_GROUP_INFO;

    typedef struct
    {
        char	flag;
        char	status;
        int		begin_time/*��ʼʱ��*/;
        int		end_time/*����ʱ��*/;
        char    qos;
        int		size;
        char	area[256]/*�洢����*/;
        char	name[256]/*�ļ���*/;
        char    deviceId[20];
        int     channeltype;
		int     channelno;
    }ZDSDK_RECORD_INFO, *PZDSDK_RECORD_INFO;

    typedef struct
    {
        char	dev_channel[38]/*ͨ����ʽ��200000-200000000100011835-0001-0001*/;
        char	rule_guid[16]/*Rule's GUID*/;
        char	major_type/*�澯������*/;
        char	minor_type/*�澯������*/;
        char	alarm_level/*�澯���ؼ���(5��10��15��20��25��ֵԽ��Խ����)*/;
        char	alarm_confidence/*�澯���Ŷ�*/;
        int		alarm_session_id/*�澯�Ự��ţ�0,������1-0xFFFFFFFF*/;
        short	alarm_sequence_id/*�澯��ţ�0,����; n��N�θ澯��0xFFFF����*/;
        char	alarm_guid[16]/*�澯GUID��UAͨ����GUID���������ѯ����澯��Ϣ*/;
        char	content_type[16]/*�澯����ı�����*/;
        char	content[256]/*�澯����ı�����*/;
        int		alarm_flag/*�澯��־��1:���ڸ澯ͼƬ*/;
        int		alarm_time/*�澯ʱ��*/;
        char	storage_area_id[128]/*�澯ͼƬ�洢��AreaId*/;
    }ZDSDK_NOTIFY_ALARM_INFO;

    typedef struct
    {
        char    url[256];	//����URL
        void*   context;	//��������ʱ��������
    }ZDSDK_NOTIFY_DOWNLOAD_URL;

    typedef struct
    {
        char	dev_id[20]/*�豸ID��200000000100011835*/;
        bool	is_online/*����״̬*/;
    }ZDSDK_NOTIFY_FD_ONLINE;

	typedef struct
	{
		unsigned char preset_id;
		char description[128];
	}ZDSDK_PRESET_INFO, *PZDSDK_PRESET_INFO;

	typedef struct
	{
		char lock_email[64];
		unsigned int lock_level;
		unsigned int lock_time;
	}ZDSDK_PTZLOCK_INFO,*PZDSDK_PTZLOCK_INFO;

	typedef struct {
		char  id[38]/*�豸���*/;
		char  domain_id[10]/*�豸��������*/;
		char  name[255]/*�豸����*/;
        char  gbtid[32];
		char  factory_name[128]/*�豸������������*/;
        char  location[256]/*�豸��װλ��*/;
        char  desc[256]/*�豸����*/;
		char  fd_state/*'W'����װ��'A' ������'P' ͣ�á�'C'����*/;
        unsigned char vincount /*��Ƶ����ͨ������*/;
        unsigned short factory_code /*�豸�������Ҵ���*/;
        unsigned int type/*�豸����*/;
		unsigned int software_version/*�豸�汾��*/;		
		unsigned int longitude/*����*/;
		unsigned int latitude/*ά��*/;
		unsigned int last_login/*����¼ʱ��*/;
		unsigned int last_logout/*���ǳ�ʱ��*/;		
		int   online_state /*BIT0, �Ƿ�����*/;
	}ZDSDK_FD_INFO, *PZDSDK_FD_INFO;

	typedef struct
	{
		BOOL	bCenter;
		unsigned int 	timeBegin;
		unsigned int 	timeEnd;
		int		mode;
		int		timespan;
	}ZDSDK_RCSTORAGE_CONFIG, *PZDSDK_RCSTORAGE_CONFIG;

	typedef struct
	{
		char   guid[16];
		short  plan_type;
		int    period;
		unsigned int   begin_date;
		unsigned int   end_date;
		int    work_day;
		short  work_month;
		short  begin_hour;
		short  begin_minute;
		short  end_hour;
		short  end_minute;
		int    time_span;
		char   qos;
		short  compress_type;
		char   memo[128];
		char   modifier[128];
		int    modify_date;
	}ZDSDK_RECORD_PLAN, *PZDSDK_RECORD_PLAN;

	typedef struct {
		unsigned short	  preset_no;
		unsigned short    begin_hour;
		unsigned short    begin_minute;
		unsigned short    end_hour;
		unsigned short    end_minute;
	}ZDSDK_PERSET_PLAN,*PZDSDK_PERSET_PLAN;

    //��Ϣ�ص�;
    typedef void(__cdecl *MESSAGE_CALLBACK)(void* identity, int msg_type, int error_code, void* msg_context);

    //֪ͨ�ص�;
    typedef void(__cdecl *NOTIFY_CALLBACK)(void* identity, int notify_type, void* notify_info);

    //¼�����صĻص���identity: SDK��ʼ��ʱ��downlod�����ؾ����percent�����ؽ��ȣ�context���û��þ�;
    typedef void(__cdecl *DOWNLOAD_PROC)(void* downlod, int percent, void *context);


    //codec type;
#define MEDIA_CODECTYPE_AUDIO_ENCODE	(0x00000001)	// ��Ƶ����
#define MEDIA_CODECTYPE_AUDIO_DECODE	(0x00000002)	// ��Ƶ����
#define MEDIA_CODECTYPE_VIDEO_ENCODE	(0x00000004)	// ��Ƶ����
#define MEDIA_CODECTYPE_VIDEO_DECODE	(0x00000008)	// ��Ƶ����

    //net type;
#define MEDIA_NETTYPE_UDP				(0x00000001)	// UDP�ͻ���
#define MEDIA_NETTYPE_TCP				(0x00000002)	// TCP�ͻ���
#define MEDIA_NETTYPE_BLOCK				(0x00000004)	// ΪTCP�طš������޶�֡�����Ӳ���
#define MEDIA_NETTYPE_NORMAL			(0x00000000)    //��ͨ����
#define MEDIA_NETTYPE_3G				(0x00000100)    //��ʾ3G���������磬��Ҫ���ö���ͳ�ƻش��Ȳ��� ��MEDIA_NETTYPE_UDP ���ϴ˺꼴��
#define MEDIA_NETTYPE_ZB				(0x00010000)    //��ʾ�㽭����RTP
#define MEDIA_NETTYPE_RTP_DB33			(0x00020000)    //��ʾDB33��RTP
#define MEDIA_NETTYPE_NODECODE			(0x00100000)    //�������ʾ,���ڽ���¼��
#define MEDIA_NETTYPE_PLAYBACK			(0x01000000)    //¼��طű�ʶ��������ʵʱ��Ƶ����  
#define MEDIA_NETTYPE_RTP               (0x00001000)
#define MEDIA_NETTYPE_NWP               (0x00002000)

    //factory type
#define MEDIA_FACTORYTYPE_ME			0x00010000		//����
#define MEDIA_FACTORYTYPE_HK			0x00020000		//����
#define MEDIA_FACTORYTYPE_SH			0x00040000		//�Ϻ�����
#define MEDIA_FACTORYTYPE_DH			0x00080000		//��
#define MEDIA_FACTORYTYPE_ZB			0x00100000		//����
#define MEDIA_FACTORYTYPE_DL			0x00200000		//����
#define MEDIA_FACTORYTYPE_ST			0x00400000		//����
#define MEDIA_FACTORYTYPE_FH			0x00800000		//���
#define MEDIA_FACTORYTYPE_HX			0x01000000		//����
#define MEDIA_FACTORYTYPE_ZB2			0x02000000		//����
#define MEDIA_FACTORYTYPE_H3C			0x04000000		//����
#define MEDIA_FACTORYTYPE_XC			0x08000000		//�Ų�
#define MEDIA_FACTORYTYPE_XW            0x10000000      //�������ϣ�
#define MEDIA_FACTORYTYPE_ZV            0x12000000      //�Ͼ���·
#define MEDIA_FACTORYTYPE_JL            0x20000000      //����
#define MEDIA_FACTORYTYPE_SR            0x40000000      //����
#define MEDIA_FACTORYTYPE_DB33V2		0x80000000		//DB33V2���г���

    //encode type
#define MEDIA_ENCODETYPE_MPEG4			0x00000001
#define MEDIA_ENCODETYPE_H264			0x00000002
#define MEDIA_ENCODETYPE_G711A			0x00000100
#define MEDIA_ENCODETYPE_G711U			0x00000200
#define MEDIA_ENCODETYPE_G7221			0x00000300
#define MEDIA_ENCODETYPE_G7231			0x00000400
#define MEDIA_ENCODETYPE_G726			0x00000500

    //color space type
#define MEDIA_CSTYPE_YV12				0
#define MEDIA_CSTYPE_YUY2				1
#define MEDIA_CSTYPE_UYVY				2
#define MEDIA_CSTYPE_I420				3
#define MEDIA_CSTYPE_RGB24				4
#define MEDIA_CSTYPE_YVYU				5
#define MEDIA_CSTYPE_RGB32				6
#define MEDIA_CSTYPE_RGB555				7
#define MEDIA_CSTYPE_RGB565				8

    //notify event
#define LOCAL_RECORD_STOP				101	//¼���Զ�ֹ֪ͣͨ
#define DECODE_FIRST_FRAME				102	//�յ��������һ֡��Ƶ
#define DISPLAY_END_NOTIFY              103
#define LOCAL_STREAM_STOP				105	//�յ��Է��Ľ���ͨ�������
#define LOCAL_STREAM_NULL				106	//����֡�ط�ģʽ�������յ�֪ͨ
#define LOCAL_FLAG_FRAME				107	//����֡�ط�ģʽ�⵽��ʶ֪֡ͨ

    typedef enum
    {
        HW_DISPLAY_FORMAT_INVALID = 0x00000000,
        HW_DISPLAY_FORMAT_CVBS = 0x00000001,
        HW_DISPLAY_FORMAT_DVI = 0x00000002,
        HW_DISPLAY_FORMAT_VGA = 0x00000004,
        HW_DISPLAY_FORMAT_HDMI = 0x00000008,
        HW_DISPLAY_FORMAT_YPbPr = 0x00000010
    }HW_DISPLAY_FORMAT;

    /*resolution*/
    typedef enum
    {
        HW_DISPLAY_RESOLUTION_INVALID = 0x00000000,
        HW_DISPLAY_RESOLUTION_D1 = 0x00000001,
        HW_DISPLAY_RESOLUTION_XGA_60HZ = 0x00000002,
        HW_DISPLAY_RESOLUTION_SXGA_60HZ = 0x00000004,
        HW_DISPLAY_RESOLUTION_SXGA_960_60HZ = 0x00000008,
        HW_DISPLAY_RESOLUTION_720P_50HZ = 0x00000010,
        HW_DISPLAY_RESOLUTION_720P_60HZ = 0x00000020,
        HW_DISPLAY_RESOLUTION_1080I_50HZ = 0x00000040,
        HW_DISPLAY_RESOLUTION_1080I_60HZ = 0x00000080,
        HW_DISPLAY_RESOLUTION_1080P_24HZ = 0x00000100,
        HW_DISPLAY_RESOLUTION_1080P_25HZ = 0x00000200,
        HW_DISPLAY_RESOLUTION_1080P_30HZ = 0x00000400,
        HW_DISPLAY_RESOLUTION_1080P_60HZ = 0x00000800,
        HW_DISPLAY_RESOLUTION_UXGA_60HZ = 0x00001000
    }HW_DISPLAY_RESOLUTION;
	
    typedef struct tagConfigData
    {
        char	szName[32];
        char	szValue[256];
    }TCfgData, *LPTCfgData;

	/* �汾��Ϣ�ṹ; */
    typedef struct
    {
        unsigned	unMouduleLevel;		// ������ʾ������
        char		szModuleName[32];	//ģ����
        unsigned	unVer;				//0xyy.yy.yyyy�汾��
        int			nTime;				// compile time_t
        char		szVerInfo[128];
        char		szDescribe[256];
    }MEDIA_VERSION_INFO;

    typedef struct tagtFrameParam
    {
        bool			bAgain;				//��������
        bool			bIsIFrame;			//�Ƿ�ΪI֡
        unsigned char	byType;				//����:��Ƶ����Ƶ AUDIO_TYPE �� VIDEO_TYPE
        unsigned char	byFrameRate;		//֡�� fps
        unsigned int	unCodecType;		//��������v2����(MAKEFOURCC('S', 'V', 'M', '4')) ��ʾ ����mpeg4
        unsigned short	usWidth;			//ͼ����
        unsigned short	usHeight;			//ͼ��߶�
        unsigned short	usFactoryCode;		//���Ҵ���V2��0x686b��ʾ"hk"
        unsigned	unTimeStamp;		//32λʱ������λΪms����0��ʼ���ʱ��
        unsigned	dwFrameSeq;			//֡���кţ�ÿ֡��1
        unsigned long long	un64Timestamp;	//64λʱ������λΪms����19700101 00:00:00��ʼ���ʱ�䣬��Ҫ���ڻط�ʱ�������Ķ�λ
        unsigned	unOrgTimeStamp;		//�Ӱ�ͷ��ȡ����δ�޸ĵ�ʱ��
    }TFrameParam;

    /* ý������ṹ ;*/
    typedef struct tagTMediaParam
    {
        bool			bAgain;				//��������
        unsigned char	byType;				//����:��Ƶ����Ƶ AUDIO_TYPE �� VIDEO_TYPE
        unsigned char	byEncodeType;		//�������ͣ����ֽڵ���������
        bool			bIsIFrame;			//�Ƿ�ΪI֡
        unsigned char	byFrameRate;		//֡�� fps
        unsigned char	byImageSize;		//ͼ��ֱ���
        unsigned	unTimeStamp;		//32λʱ������λΪms����0��ʼ���ʱ��
        unsigned	dwFrameSeq;			//֡���кţ�ÿ֡��1
    }TMediaParam;

    //�¼�֪ͨ�ص���¼����ֹͣ�������һ֡��ɵ��¼��ص���unEventIdΪ��ϢID���μ�notify event��pParam���û��þ�
    //typedef	int(__cdecl *MEDIA_NOTIFY_PROC)(unsigned unEventId, void* pParam);

    //����ǰ������Ƶ�������ݻص���pBuf��֡���ݣ�nLen�����ݳ��ȣ�pFrameParam����ز�����pParam���û��þ�
    typedef	int(__cdecl *MEDIA_FRAME_PROC)(unsigned char* pBuf, int nLen, TFrameParam* pFrameParam, void* pParam);

    //��������Ƶ���ݻص���pBuf����Ƶ���ݣ�nLen�����ݳ��ȣ�nWidth����ȣ�nHeight���߶ȣ�
    //nTime��ʱ���������ͬtime_t��nCSType����ɫ�ռ����� color space type��pParam���û��þ�

    //typedef	int(__cdecl *MEDIA_VIDEO_PROC)(unsigned char* pBuf, int nLen, int nWidth, int nHeight, int nTime, int nCSType, void* pParam);

    //��������Ƶ���ݻص���pBuf����Ƶ���ݣ�nLen�����ݳ��ȣ�lpAudioFormat����Ƶ��ʽ����ΪWAVEFORMATEX*ʹ�ã�
    //unTimeStamp��ʱ�������λms��pParam���û��þ�

    //typedef	int(__cdecl *MEDIA_AUDIO_PROC)(unsigned char* pBuf, int nLen, void* lpAudioFormat, unsigned unTimeStamp, void* pParam);

    //��������Ƶ���ݻص���pBuf���������Ƶ���ݣ�nLen�����ݳ��ȣ�unCodecType����Ƶ��ʽ��unTimeStamp��ʱ�������λms��pParam���û��þ�
    typedef	int(__cdecl *MEDIA_AUDIO_ENCODE_PROC)(unsigned char* pBuf, int nLen, unsigned unCodecType, unsigned unTimeStamp, void* pParam);

#ifdef __cplusplus
#   define ZDSDK_EXTERN_C extern "C"
#else
#   define ZDSDK_EXTERN_C
#endif

#if (defined WIN32 || defined _WIN32 || defined WINCE) && defined ZDSDK_API_EXPORTS
#   define ZDSDK_EXPORTS __declspec(dllexport)
#else
#   define ZDSDK_EXPORTS
#endif

#if defined WIN32 || defined _WIN32
#   define ZDSDK_CDECL __cdecl
#else
#   define ZDSDK_CDECL
#endif

#ifndef ZDSDK_API
#   define ZDSDK_API(rettype) ZDSDK_EXTERN_C ZDSDK_EXPORTS rettype ZDSDK_CDECL
#endif

    typedef struct _zdsdk_t {
        void* dummy;
    } *zdsdk_t;

    typedef struct _zdsdk_playback_t {
        void* dummy;
    } *zdsdk_playback_t;

    typedef struct _zdsdk_download_t {
        void* dummy;
    } *zdsdk_download_t;

    //��ʼ��;
    ZDSDK_API(int)     ZDSDK_Init();

    //����ʼ��;
    ZDSDK_API(void)     ZDSDK_Fini();

    //=============================��¼=====================================
    //uas_ip:ƽ̨��ַ��uas_port��ƽ̨�˿ڣ�5555����email���˺ţ�password������
    ZDSDK_API(zdsdk_t)  ZDSDK_Login(MESSAGE_CALLBACK message_cb, NOTIFY_CALLBACK notify_cb, void* identity,
        const char* uas_ip, unsigned short uas_port, const char* email, const char* password);

    ZDSDK_API(int)      ZDSDK_Run(zdsdk_t hsdk);

    //�ж�ƽ̨�Ƿ��½;
    ZDSDK_API(int)      ZDSDK_IsLogined(zdsdk_t hsdk);
    //���µ�½ƽ̨;
    ZDSDK_API(int)      ZDSDK_ReLogin(zdsdk_t hsdk);
    //�ǳ�ƽ̨;
    ZDSDK_API(int)      ZDSDK_Logout(zdsdk_t hsdk);
	//�޸�����;
	ZDSDK_API(int)		ZDSDK_ModifyPassword(zdsdk_t hsdk, const char* poldpassword, const char* pnewpassword, bool bmd5, void* context);
	//����͸��ͨ������;
	ZDSDK_API(int)		ZDSDK_SendNonStandardData(zdsdk_t hsdk, const char* dev_channel, const char* pData, int nlen, int ntype, int nsubtype, void* context);
	//�޸��豸��Ϣ;
	ZDSDK_API(int)		ZDSDK_ModifyFdName(zdsdk_t hsdk, PZDSDK_FD_INFO fd_info, void* context);
	//�޸�ͨ����Ϣ;
	ZDSDK_API(int)		ZDSDK_ModifyChannelName(zdsdk_t hsdk, PZDSDK_CHANNEL_INFO channel_info, void* context);

    //��Ƶ����ص�;
    ZDSDK_API(int)      ZDSDK_SetMediaDisplayCallback(zdsdk_t hsdk, MEDIA_VIDEOPLAY_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaAudioCallback(zdsdk_t hsdk, MEDIA_AUDIOPLAY_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaEventCallback(zdsdk_t hsdk, MEDIA_EVENT_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaDataCallback(zdsdk_t hsdk, MEDIA_FRAME_PROC callback_ptr);

	//��ȡ�豸�б�;
	ZDSDK_API(int)		ZDSDK_GetFDlist(zdsdk_t hsdk, PZDSDK_FD_INFO fd_list_ptr, int nList);
	//��ѯ�豸״̬;
	ZDSDK_API(int)		ZDSDK_QueryFdStatus(zdsdk_t hsdk);
	//��ȡ�����豸�б�;
	ZDSDK_API(int)		ZDSDK_GetFdOnlineList(zdsdk_t hsdk, PZDSDK_FD_INFO fd_list_ptr, int nList);
    //��ȡͨ������;
    ZDSDK_API(int)      ZDSDK_GetChannelCount(zdsdk_t hsdk);
    //��ѯ�豸��ͨ���б�;
	ZDSDK_API(int)		ZDSDK_QueryFdChannelList(zdsdk_t hsdk, const char* fd_id, void* context);
	//��ȡָ���豸��ͨ���б�;
	ZDSDK_API(int)		ZDSDK_GetFdChannelList(zdsdk_t hsdk, const char* fd_id, PZDSDK_CHANNEL_INFO channel_list_ptr, int nList);
	//��ȡͨ���б�;
    ZDSDK_API(int)      ZDSDK_GetChannleList(zdsdk_t hsdk, PZDSDK_CHANNEL_INFO channel_list_ptr, int nSize);
    ZDSDK_API(int)      ZDSDK_GetChannleInfo(zdsdk_t hsdk, const char* dev_channel, PZDSDK_CHANNEL_INFO channel_info);
    ZDSDK_API(int)      ZDSDK_GetChannleStatus(zdsdk_t hsdk, const char* dev_channel);

    //��ѯ����Ϣ ����ֵΪFALSE��ʾ��֧�֡�group_type��1��ʾDB33��,2��ʾ������;
    ZDSDK_API(int)      ZDSDK_QueryGroupInfo(zdsdk_t hsdk, int group_type);
    //��ȡ���Ϊgroup_id��������顣��group_idΪ��ʱ��ʾ���ڵ㣬��group_list_ptrΪ��ʱ�����ظ�����
    ZDSDK_API(int)      ZDSDK_GetChildGroup(zdsdk_t hsdk, int group_type, const char* group_id, PZDSDK_GROUP_INFO group_list_ptr);
    //��ȡ���Ϊgroup_id���������ͨ������group_idΪ��ʱ��ʾ���ڵ㣬��channel_list_ptrΪ��ʱ�����ظ���;
    ZDSDK_API(int)      ZDSDK_GetGroupChannel(zdsdk_t hsdk, int group_type, const char* group_id, PZDSDK_CHANNEL_INFO channel_list_ptr);

	//��ѯԤ�õ�;
	ZDSDK_API(int)		ZDSDK_QueryCameraPreset(zdsdk_t hsdk, const char* dev_channel, void* context);
	//��ȡԤ�õ��б�;	
	ZDSDK_API(int)		ZDSDK_GetCameraPresetList(zdsdk_t hsdk, const char* dev_channel, PZDSDK_PRESET_INFO preset_list_ptr, int nList);
	//Ԥ�õ�ٿ�;
	ZDSDK_API(int)		ZDSDK_ControlCameraPreset(zdsdk_t hsdk, const char* dev_channel, unsigned char action, unsigned char preset_id, const char* presetname, void* context);
	//��ѯԤ�õ�ƻ��б�; 
	ZDSDK_API(int)		ZDSDK_QueryPresetSchedule(zdsdk_t hsdk, const char* dev_channel, void* context);
	//����Ԥ�õ�ƻ��б�;
	ZDSDK_API(int)		ZDSDK_SetPresetSchedule(zdsdk_t hsdk, const char* dev_channel, int nminutes, PZDSDK_PERSET_PLAN perset_plan_vt, int nSize, void* context);
	//��ȡԤ�õ�ƻ�;
	ZDSDK_API(int)		ZDSDK_GetPresetSchedule(zdsdk_t hsdk, int *nminutes, PZDSDK_PERSET_PLAN preset_plan_list_ptr, int nSize);

    //=============================��Ƶ=====================================
    //������Ƶ;
    ZDSDK_API(int)     ZDSDK_MonitorStart(zdsdk_t hsdk, const char* dev_channel, int net_type, HWND monitor_wnd, void* context);
    ZDSDK_API(int)     ZDSDK_MonitorStop(zdsdk_t hsdk, const char* dev_channel, void* context);
    ZDSDK_API(int)     ZDSDK_ControlCamera(zdsdk_t hsdk, const char* dev_channel, unsigned char action, unsigned char param, PZDSDK_PTZLOCK_INFO lockinfo, void* context);

    //��ȡ����ͳ����Ϣ;
    ZDSDK_API(int)     ZDSDK_GetStatInfo(zdsdk_t hsdk, const char* dev_channel, PTCH_STAT_INFO stat_info);
    ZDSDK_API(int)     ZDSDK_DecodeOnlyIFrame(zdsdk_t hsdk, const char* dev_channel, bool decode_only_IFrame);

    //����ץ��;
    ZDSDK_API(int)     ZDSDK_SnapShot(zdsdk_t hsdk, const char* dev_channel, const char* path_file);

    //����¼��;
    ZDSDK_API(int)     ZDSDK_StartLocalRecord(zdsdk_t hsdk, const char* dev_channel, const char* path_file, long record_time, bool audio_on);
    ZDSDK_API(int)     ZDSDK_StopLocalRecord(zdsdk_t hsdk, const char* dev_channel);

	//ǰ��,����¼��;
	ZDSDK_API(int)	   ZDSDK_StartRecord(zdsdk_t hsdk, const char* dev_channel, PZDSDK_RCSTORAGE_CONFIG recodestorage, void* context);
	ZDSDK_API(int)	   ZDSDK_StopRecord(zdsdk_t hsdk, const char* dev_channel, bool bcenter, void* context);
	//����¼��ƻ�(uOp:2���,uOp:4ɾ��,uOp:1����);
	ZDSDK_API(int)	   ZDSDK_ConfigRecordPlan(zdsdk_t hsdk, const char* dev_channel, unsigned char uOp, bool bCenter, const PZDSDK_RECORD_PLAN record_plan_vt, int nSize, void* context);
	//��ѯ¼��ƻ�;
	ZDSDK_API(int)	   ZDSDK_QueryRecordPlan(zdsdk_t hsdk, const char* dev_channel, bool bCenter, void* context);
	//��ȡ¼��ƻ�;
	ZDSDK_API(int)	   ZDSDK_GetRecordPlan(zdsdk_t hsdk, const char* dev_channel, PZDSDK_RECORD_PLAN plan_list_ptr, int nSize);

    //��������Ƶ;
    ZDSDK_API(int)     ZDSDK_EnableStream(zdsdk_t hsdk, const char* dev_channel, bool enable);

    //��Ƶ��ǽ;
    //dev_channel��ͨ����ţ�����200000-200000112233445566-0001-0001����tv_idx:���ӻ��ţ�tv_area_idx�����ӻ�������;
    ZDSDK_API(int)     ZDSDK_MUA_MonitorStart(zdsdk_t hsdk, const char* dev_channel, int tv_idx, int tv_area_idx);
    ZDSDK_API(int)     ZDSDK_MUA_MonitorStop(zdsdk_t hsdk, int tv_idx, int tv_area_idx);
    //ptz���ƣ�action�����ƶ����� EM_CAMERA_CONTROL_ACTION;
    ZDSDK_API(int)     ZDSDK_MUA_ControlCamera(zdsdk_t hsdk, int tv_idx, int tv_area_idx, unsigned char action);

    //=============================¼��=====================================
    //��ѯ¼��;
    ZDSDK_API(int)     ZDSDK_QueryRecord(zdsdk_t hsdk, const char* dev_channel, bool center, long start_time, long end_time, void* context);    
    ZDSDK_API(int)     ZDSDK_GetRecordList(zdsdk_t hsdk, PZDSDK_RECORD_INFO record_list_ptr, int cnt);

    //�����ط�;
    ZDSDK_API(zdsdk_playback_t)  ZDSDK_StartPlayback(zdsdk_t hsdk, const PZDSDK_RECORD_INFO ptr_record_info, int net_type, HWND playback_wnd, bool is_center, void* context);
    ZDSDK_API(int)     ZDSDK_StopPlayback(zdsdk_t hsdk, zdsdk_playback_t playback, void* context);
    ZDSDK_API(int)     ZDSDK_ControlPlayback(zdsdk_t hsdk, zdsdk_playback_t playback, unsigned char action, unsigned char param, void* context);

    //��ȡ����ͳ����Ϣ;
    ZDSDK_API(int)     ZDSDK_Playback_GetStatInfo(zdsdk_t hsdk, zdsdk_playback_t playback, PTCH_STAT_INFO stat_info);

    ZDSDK_API(int)     ZDSDK_Playback_DecodeOnlyIFrame(zdsdk_t hsdk, zdsdk_playback_t playback, bool decode_only_IFrame);

    //����ץ��;
    ZDSDK_API(int)     ZDSDK_Playback_SnapShot(zdsdk_t hsdk, zdsdk_playback_t playback, const char* path_file);

    //����¼��;
    ZDSDK_API(int)     ZDSDK_Playback_StartLocalRecord(zdsdk_t hsdk, zdsdk_playback_t playback, const char* path_file, long record_time, bool audio_on);
    ZDSDK_API(int)     ZDSDK_Playback_StopLocalRecord(zdsdk_t hsdk, zdsdk_playback_t playback);

    //��������Ƶ;
    ZDSDK_API(int)     ZDSDK_Playback_EnableStream(zdsdk_t hsdk, zdsdk_playback_t playback, bool enable);

    ZDSDK_API(int)     ZDSDK_QueryDownloadURL(zdsdk_t hsdk, const PZDSDK_RECORD_INFO ptr_record_info, void* context);
    ZDSDK_API(zdsdk_download_t)   ZDSDK_StartDownload(const char* record_url, const char* path_file, DOWNLOAD_PROC download_callback, void* context);
    ZDSDK_API(void)     ZDSDK_StopDownload(zdsdk_download_t download);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif //__ZDSDK__H__