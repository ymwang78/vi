#pragma once
#ifndef __ZDSDK__H__
#define __ZDSDK__H__

#include <zmm/zmmdec.h>

#ifdef __cplusplus
    extern "C" {
#endif	// __cplusplus

    enum ERV_MSG_TYPE {
        MSG_TYPE_LOGIN,
        MSG_TYPE_LOGOUT,
        MSG_TYPE_START_MONITOR,
        MSG_TYPE_STOP_MONITOR,
        MSG_TYPE_PTZ_CONTROL,
        MSG_TYPE_QUERY_RECORD,
        MSG_TYPE_START_PLAYBACK,
        MSG_TYPE_STOP_PLAYBACK,
        MSG_TYPE_CTRL_PLAYBACK,
        MSG_TYPE_DOWNLOAD_RECORD,
        MSG_TYPE_START_AUDIO,    //启动语音对讲消息;
        MSG_TYPE_STOP_AUDIO,      //停止语音对讲消息;
        MSG_TYPE_CHANNEL_LIST,    //获取通道列表通知;
        MSG_TYPE_QUERY_GROUP,
        MSG_TYPE_QUERY_PRESET,
        MSG_TYPE_PRESET_CONTROL,
        MSG_TYPE_PRESET_GOTO,
        MSG_TYPE_FD_LIST,
        MSG_TYPE_FD_CHANNELLIST,
        MSG_TYPE_UA_RECORDSTART,
        MSG_TYPE_UA_RECORDSTOP,
        MSG_TYPE_CONFIG_RECORD_PLAN,
        MSG_TYPE_QUERY_RECORD_PLAN,
        MSG_TYPE_QUERY_PRESETSCHEDULE,
        MSG_TYPE_SET_PRESETSCHEDULE,
        MSG_TYPE_QUERY_FDSTATUS,
        MSG_TYPE_MODIFY_PASSWORD,
        MSG_TYPE_MODIFY_FDNAME,
        MSG_TYPE_MODIFY_CHANNELNAME,
        MSG_TYPE_DOWNLOAD_RCVIDEO,
        MSG_TYPE_FD_SET_VIDEO,
        MSG_TYPE_FD_GET_VIDEO,
    };

    enum ERV_EVENT_TYPE {
        EVENT_TYPE_RUN,
        EVENT_TYPE_ALARM = 100,
        EVENT_TYPE_FDONLINE,
        EVENT_TYPE_DOWNLOADURL,
    };

    enum ERV_NET_TYPE {
        NET_TYPE_AUTO,
        NET_TYPE_UDP = 1,
        NET_TYPE_TCP = 2,
    };

    enum ERV_PLAYBACK_CTRL_ACTION
    {
        PLAYBACK_CTRL_ACTION_FastForward = 0x01,//快进
        PLAYBACK_CTRL_ACTION_FastBackward = 0x02,//快退
        PLAYBACK_CTRL_ACTION_Pause = 0x03,//暂停 
        PLAYBACK_CTRL_ACTION_Stop = 0x04,//停止 
        PLAYBACK_CTRL_ACTION_Continue = 0x05,//继续回放 
        PLAYBACK_CTRL_ACTION_DragPlay = 0x06,//回放拖动
        PLAYBACK_CTRL_ACTION_SlowForward = 0x07,//慢进 
        PLAYBACK_CTRL_ACTION_SlowBackward = 0x08,//慢退
        PLAYBACK_CTRL_ACTION_FramePlay = 0x09,//单帧放
        PLAYBACK_CTRL_ACTION_Forward = 0x0a,//以当前倍率向前放
        PLAYBACK_CTRL_ACTION_Backward = 0x0b,//以当前倍率向后放
		PLAYBACK_CTRL_ACTION_PlayIFrame = 0x0c,//在指定倍数只播I帧 (SSU 倍数*100)
		PLAYBACK_CTRL_ACTION_PauseAt = 0x0d,//在指定时间暂停
    };

    enum ERV_CAMERA_CONTROL_ACTION
    {
        CAMERA_CONTROL_ACTION_UP = 0x00000001 /*向上转*/,
        CAMERA_CONTROL_ACTION_LEFT = 0x00000002 /*向左转*/,
        CAMERA_CONTROL_ACTION_ROTATE = 0x00000003 /*旋转*/,
        CAMERA_CONTROL_ACTION_RIGHT = 0x00000004 /*向右转*/,
        CAMERA_CONTROL_ACTION_DOWN = 0x00000005 /*向下转*/,
        CAMERA_CONTROL_ACTION_FAR = 0x00000006 /*镜头拉远*/,
        CAMERA_CONTROL_ACTION_FOCUSNEAR = 0x00000007 /*聚焦*/,
        CAMERA_CONTROL_ACTION_AUTO = 0x00000008 /*自动*/,
        CAMERA_CONTROL_ACTION_FOCUSFAR = 0x00000009 /*散焦*/,
        CAMERA_CONTROL_ACTION_NEAR = 0x0000000a /*镜头拉近*/,
        CAMERA_CONTROL_ACTION_DIAPHRAGM_LARGE = 0x0000000b /*光圈增大（变亮）*/,
        CAMERA_CONTROL_ACTION_DIAPHRAGM_SMALL = 0x0000000c /*光圈减小（变暗）*/,
        CAMERA_CONTROL_ACTION_STOP = 0x0000000d /*停止动作*/,
        CAMERA_CONTROL_ACTION_SPEAKER_ON = 0x0000000e /*打开喇叭*/,
        CAMERA_CONTROL_ACTION_LIGHT_ON = 0x0000000f /*打开灯光*/,
        CAMERA_CONTROL_ACTION_HOTDOG = 0x00000010 /*热狗扫描*/,
        CAMERA_CONTROL_ACTION_SPEAKER_OFF = 0x00000011 /*关闭喇叭*/,
        CAMERA_CONTROL_ACTION_LIGHT_OFF = 0x00000012 /*关闭灯光*/,
        CAMERA_CONTROL_ACTION_PRESET_GOTO = 0x00000013 /*切换到预置点*/,
        CAMERA_CONTROL_ACTION_PRESET_SET = 0x00000014 /*设置预置点*/,
        CAMERA_CONTROL_ACTION_PRESET_DEL = 0x00000015 /*删除预置点*/,
        CAMERA_CONTROL_ACTION_CAMERA_RESET = 0x00000016 /*摄像机复位*/,
        CAMERA_CONTROL_ACTION_WIPER_ON = 0x00000017 /*打开雨刷*/,
        CAMERA_CONTROL_ACTION_WIPER_OFF = 0x00000018 /*关闭雨刷*/,
        CAMERA_CONTROL_ACTION_AUTOCRUISE = 0x0000001d /*自动巡航*/,
        CAMERA_CONTROL_ACTION_PRESET_CLEAR = 0x0000001e /*清除所有预置点*/,
        CAMERA_CONTROL_ACTION_STARTTRACKING = 0x0000001f /*启动跟踪*/,
        CAMERA_CONTROL_ACTION_STOPTRACKING = 0x00000020 /*停止跟踪*/,
        CAMERA_CONTROL_ACTION_LEFTUP = 0x00000021 /*左上转*/,
        CAMERA_CONTROL_ACTION_RIGHTUP = 0x00000022 /*右上转*/,
        CAMERA_CONTROL_ACTION_LEFTDOWN = 0x00000023 /*左下转*/,
        CAMERA_CONTROL_ACTION_RIGHTDOWN = 0x00000024 /*右下转*/,
        CAMERA_CONTROL_ACTION_CAMERAACTIVE = 0x00000028 /*摄像机激活*/,
        CAMERA_CONTROL_ACTION_SETPANSPEED = 0x00000029 /*设置左右转动速度*/,
        CAMERA_CONTROL_ACTION_SETTILTSPEED = 0x00000030 /*设置上下转动速度*/,
        CAMERA_CONTROL_ACTION_SETZOOMSPEED = 0x00000031 /*设置光圈速度*/,
        CAMERA_CONTROL_ACTION_SETFOCUSSPEED = 0x00000032 /*设置聚焦/散焦速度*/,
        CAMERA_CONTROL_ACTION_SPEEDSETTINGGET = 0x00000033 /*获取摄像机速度设置*/,
        CAMERA_CONTROL_ACTION_MATRIXSWITCH = 0x00000040 /*矩阵切换*/,
        CAMERA_CONTROL_ACTION_BRIGHTNESS = 0x00000050 /*亮度*/,
        CAMERA_CONTROL_ACTION_CONTRAST = 0x00000051 /*对比度*/,
        CAMERA_CONTROL_ACTION_SATURATION = 0x00000052 /*饱和度*/,
        CAMERA_CONTROL_ACTION_HUE = 0x00000053 /*色度*/,
		CAMERA_CONTROL_ACTION_PTZ_LOCK = 0x000000FF /*PTZ锁定*/,
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
        ZDSDK_ERROR_COMMON_USER_CANCELED = 0x80010016 /*操作已被用户取消，例如发送STOP*/,
        ZDSDK_ERROR_COMMON_NOTSUPPORT = 0x80010017 /*功能不支持*/,
        ZDSDK_ERROR_COMMON_RECORD_TIME = 0x80010018,
        ZDSDK_ERROR_COMMON_REACH_MAX = 0x80010019,
        ZDSDK_ERROR_COMMON_CSS_NOSPACE = 0x8001001a /*中心存储器上的总空间为0*/,
        ZDSDK_ERROR_COMMON_MSS_INVALID_PARAM = 0x8001001b,
        ZDSDK_ERROR_COMMON_REACH_CUSTOMERMAX = 0x8001001c,
        ZDSDK_ERROR_COMMON_TIME = 0x8001001d /*时间错误，在抓拍、录像等需要指定时间的指令中，时间无效*/,
        ZDSDK_ERROR_COMMON_LOCKED = 0x8001001e /*设备被锁住，在云台控制命令中，云台被其他用户锁住*/,
        ZDSDK_ERROR_COMMON_REMOTE_DOMAIN_OFFLINE = 0x8001001f /*跨域服务器未在线*/,
        ZDSDK_ERROR_COMMON_VERSION_TOOLD = 0x80010020 /*版本太旧*/,
        ZDSDK_ERROR_COMMON_BUSY = 0x80010021 /*太忙*/,
        ZDSDK_ERROR_COMMON_NOTENOUGH = 0x80010021 /*太小*/,

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
        ZDSDK_ERROR_AAA_UNKNOWN = 0x80040001 /*未知原因错误*/,
        ZDSDK_ERROR_AAA_INVALIDPACKET = 0x80040002 /*Radius包不合法*/,
        ZDSDK_ERROR_AAA_MISSATTRIBUTE = 0x80040003 /*Radius包缺少必要的属性*/,
        ZDSDK_ERROR_AAA_INTERNAL = 0x80040004 /*AAA服务器发生内部错误*/,
        ZDSDK_ERROR_AAA_DBMS = 0x80040005 /*AAA服务器操作数据库失败*/,
        ZDSDK_ERROR_AAA_STOPPED = 0x80040006 /*AAA服务器停止服务*/,
        ZDSDK_ERROR_AAA_PASSWORD = 0x80040007 /*密码错误*/,
        ZDSDK_ERROR_AAA_BADUSERID = 0x80040008 /*用户ID不存在*/,
        ZDSDK_ERROR_AAA_BADDEVID = 0x80040009 /*设备ID不存在*/,
        ZDSDK_ERROR_AAA_BADCHANNEL = 0x8004000a /*设备通道号不存在*/,
        ZDSDK_ERROR_AAA_FORBIDDEN = 0x8004000b /*没有权限执行所请求的操作*/,
        ZDSDK_ERROR_AAA_NOMONEY = 0x8004000c /*费用不足*/,
        ZDSDK_ERROR_AAA_NODISK = 0x8004000d /*磁盘配额不足*/,
        ZDSDK_ERROR_AAA_CUSTOMERSTATUS = 0x8004000e /*客户状态不正常*/,
        ZDSDK_ERROR_AAA_USERSTATUS = 0x8004000f /*用户状态不正常*/,
        ZDSDK_ERROR_AAA_USERIPDENIED = 0x80040010 /*用户IP地址拒绝*/,
        ZDSDK_ERROR_AAA_SMSCODEFAIL = 0x80040011 /*短信登录次数超出*/,
        ZDSDK_ERROR_AAA_SMSBAD = 0x80040012 /*短信验证码错误*/,
        ZDSDK_ERROR_AAA_SMSSENDFAILED = 0x80040013 /*短信验证码发送失败*/,
        ZDSDK_ERROR_MSS_BASE = 0x80050000,
        ZDSDK_ERROR_MSS_FAIL = 0x80050001 /*:-1         失败*/,
        ZDSDK_ERROR_MSS_INVALID_ID = 0x80050002 /*:-2         非法ID*/,
        ZDSDK_ERROR_MSS_INVALID_HANDLE = 0x80050003 /*:-3         非法句柄*/,
        ZDSDK_ERROR_MSS_INVALID_PARAM = 0x80050004 /*:-4         非法参数*/,
        ZDSDK_ERROR_MSS_NULLPTR = 0x80050005 /*:-5         指针为NULL*/,
        ZDSDK_ERROR_MSS_REPEAT = 0x80050006 /*:-6         重复操作*/,
        ZDSDK_ERROR_MSS_TIMEOUT = 0x80050007 /*:-7         超时*/,
        ZDSDK_ERROR_MSS_OUTOF_MEMORY = 0x80050008 /*:-8         内存不足*/,
        ZDSDK_ERROR_MSS_OUTOF_RANGE = 0x80050009 /*:-9         超出范围*/,
        ZDSDK_ERROR_MSS_FULL = 0x8005000a /*:-10        缓冲区满*/,
        ZDSDK_ERROR_MSS_UNEXPECTED = 0x8005000b /*:-11        未知异常*/,
        ZDSDK_ERROR_MSS_PRIVILEGE_LIMIT = 0x8005000c /*:-12        权限限制*/,
        ZDSDK_ERROR_MSS_BUSY = 0x80050100 /*MSS服务忙*/,
        ZDSDK_ERROR_MSS_SCHEDULE_FD = 0x80050101 /*MSS调度FD失败*/,
        ZDSDK_ERROR_MSS_SCHEDULE_RTMDS = 0x80050102 /*MSS调度RTMDS失败*/,
        ZDSDK_ERROR_MSS_SCHEDULE_SMS = 0x80050103 /*MSS调度SMS失败*/,
        ZDSDK_ERROR_MSS_SCHEDULE_FTS = 0x80050104 /*MSS调度FTS失败*/,
        ZDSDK_ERROR_MSS_SCHEDULE_CSS = 0x80050105 /*MSS调度CSS失败*/,
        ZDSDK_ERROR_MSS_SCHEDULE_CANCELLED = 0x80050106 /*MSS调度被取消*/,
        ZDSDK_ERROR_MSS_FD_OFFLINE = 0x80050200 /*FD未在线, 或在VPN内*/,
        ZDSDK_ERROR_MSS_FD_CHANNEL_INVALID = 0x80050201 /*FD未在线*/,
        ZDSDK_ERROR_MSS_FD_BUSY = 0x80050202 /*FD忙*/,
        ZDSDK_ERROR_MSS_FD_NO_RIGHT = 0x80050203 /*FD访问未被授权*/,
        ZDSDK_ERROR_MSS_FD_FAILTURE = 0x80050204 /*FD操作失败*/,
        ZDSDK_ERROR_MSS_FD_RETURN_ERROR = 0x80050205 /*FD返回错误*/,
        ZDSDK_ERROR_MSS_FD_PACKAGE_ERROR = 0x80050206 /*FD打包错误*/,
        ZDSDK_ERROR_MSS_FDMS_OFFLINE = 0x80050300 /*FDMS服务未在线 0x300*/,
        ZDSDK_ERROR_MSS_FDMS_TIMEOUT = 0x80050301 /*FDMS服务响应超时*/,
        ZDSDK_ERROR_MSS_FDMS_FAILTURE = 0x80050302 /*FDMS服务响应失败*/,
        ZDSDK_ERROR_MSS_RTMDS_OFFLINE = 0x80050400 /*RTMDS服务未在线 0x400*/,
        ZDSDK_ERROR_MSS_RTMDS_TIMEOUT = 0x80050401 /*RTMDS服务响应超时*/,
        ZDSDK_ERROR_MSS_RTMDS_FAILTURE = 0x80050402 /*RTMDS服务响应失败*/,
        ZDSDK_ERROR_MSS_SMS_OFFLINE = 0x80050500 /*SMS服务未在线  0x500*/,
        ZDSDK_ERROR_MSS_SMS_TIMEOUT = 0x80050501 /*SMS服务响应超时*/,
        ZDSDK_ERROR_MSS_SMS_FAILTURE = 0x80050502 /*SMS服务响应失败*/,
        ZDSDK_ERROR_MSS_SMS_NO_FILE = 0x80050503 /*SMS服务响应文件不存在*/,
        ZDSDK_ERROR_MSS_FTS_OFFLINE = 0x80050600 /*FTS服务未在线 0x600*/,
        ZDSDK_ERROR_MSS_FTS_TIMEOUT = 0x80050601 /*FTS服务响应超时*/,
        ZDSDK_ERROR_MSS_FTS_FAILTURE = 0x80050602 /*FTS服务响应失败*/,
        ZDSDK_ERROR_MSS_FTS_NO_FILE = 0x80050603 /*FTS服务响应文件不存在*/,
        ZDSDK_ERROR_MSS_CSS_OFFLINE = 0x80050700 /*CSS服务未在线 0x700*/,
        ZDSDK_ERROR_MSS_CSS_TIMEOUT = 0x80050701 /*CSS服务响应超时*/,
        ZDSDK_ERROR_MSS_CSS_FAILTURE = 0x80050702 /*CSS服务响应失败*/,
        ZDSDK_ERROR_MSS_CSS_NO_FILE = 0x80050703 /*CSS服务响应文件不存在*/,
        ZDSDK_ERROR_MSS_CSS_RECORDING = 0x80050704 /*CSS服务响应正在录像*/,
        ZDSDK_ERROR_MSS_CSS_BUSY = 0x80050705 /*CSS服务响应忙*/,
        ZDSDK_ERROR_MSS_CSS_DISK_FULL = 0x80050706 /*CSS服务响应磁盘已满*/,
        ZDSDK_ERROR_MSS_CSS_DISK_QUOTA = 0x80050707 /*CSS服务响应磁盘限额*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_STOP = 0x80050708 /*CSS服务报告录像停止*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_EXPIRE = 0x80050709 /*CSS服务报告录像时间到达*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_QUOTA = 0x8005070a /*CSS服务报告录像磁盘限额满*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NETWORKIO = 0x8005070b /*CSS服务报告录像网络IO错误*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_FILEIO = 0x8005070c /*CSS服务报告录像文件IO错误*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_STOPBYCMS = 0x8005070d /*CSS服务报告录像被系统管理员停止*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NOPACKET = 0x8005070e /*CSS服务报告录像在一定的秒内接收到的数据包太少*/,
        ZDSDK_ERROR_MSS_CSS_RECORD_NOFRAME = 0x8005070f /*CSS服务报告录像在一定的秒内接收到的数据包所组成的帧数为0*/,
        ZDSDK_ERROR_MSS_SSU_OFFLINE = 0x80050d00,
        ZDSDK_ERROR_MSS_SSU_TIMEOUT = 0x80050d01,
        ZDSDK_ERROR_MSS_SSU_FAILTURE = 0x80050d02,
        ZDSDK_ERROR_MSS_SID_MISMATCH = 0x80059000 /*返回来的sessionid不匹配*/,
        ZDSDK_ERROR_DBMS_BASE = 0x80060000,
        ZDSDK_ERROR_DBMS_QUERY_FD_DOMAIN = 0x80060001,
        ZDSDK_ERROR_DBMS_CUSTOM_NOTEXISTS = 0x80060002 /*DBMS查询客户不存在*/,
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
        ZDSDK_ERROR_CMS_NAMEID_INDEX_OVERFLOW = 0x80080001 /*下标层次越界*/,
        ZDSDK_ERROR_CMS_ID_NOTEXIST = 0x80080002 /*对象不存在*/,
        ZDSDK_ERROR_CMS_TRAP_NOTSETABLE = 0x80080003 /*对象不可设置*/,
        ZDSDK_ERROR_CMS_CLASS_NOTEXIST = 0x80080004 /*类不存在*/,
        ZDSDK_ERROR_CMS_METHOD_NOTEXIST = 0x80080005 /*方法不存在*/,
        ZDSDK_ERROR_CMS_MEMBER_NOTEXIST = 0x80080006 /*成员不存在*/,
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
        char            channel_name[128]/*通道名称*/;
        char            unique_id[38];
        char            domain_id[10];
        char            fd_id[22];
        char            db33_code[19]/*DB33编号*/;
        char            gab_code[21]/*国标编号*/;
        char            org_code[21]/*行政编号*/;
        unsigned char   isonline/*设备在线状态*/;
        unsigned short  channel_type;
        unsigned short  channel_id;
        unsigned short  factory_code/*厂商代码，查看视频的时候就不用再查详细信息了*/;
        unsigned int    channel_status/*BIT 1,是否可控，2,正在前端录像，3，正在中心录像，4，视频, 5，启用中心录像，6，启用前端录像，7~12,前端类型(不可控（枪机）=0,可控（球机）=1,抓拍枪机=2,高清=3,抓拍高清=4)*/;
        unsigned int    longitude/*经度*/;
        unsigned int    latitude/*纬度*/;
        unsigned int    reserve/*保留状态*/;
    }ZDSDK_CHANNEL_INFO, *PZDSDK_CHANNEL_INFO;

    typedef struct
    {
        unsigned short  group_type; /* 组类别 */
        char    group_name[256];    /* 显示名称*/
        char    group_id[32];       /* 组的ID标识*/
        char    parent_id[32];      /* 父组的ID标识*/
        char    full_path[256];     /* 全路径*/
        unsigned short  level;    /* 显示级别*/
        int     sort_id;            /* 用于组中排序*/
    }ZDSDK_GROUP_INFO, *PZDSDK_GROUP_INFO;

    typedef struct
    {
        char	flag;
        char	status;
        int		begin_time/*起始时间*/;
        int		end_time/*结束时间*/;
        char    qos;
        int		size;
        char	area[256]/*存储区域*/;
        char	name[256]/*文件名*/;
        char    deviceId[20];
        int     channeltype;
		int     channelno;
    }ZDSDK_RECORD_INFO, *PZDSDK_RECORD_INFO;

    typedef struct
    {
        char	dev_channel[38]/*通道格式：200000-200000000100011835-0001-0001*/;
        char	rule_guid[16]/*Rule's GUID*/;
        char	major_type/*告警主类型*/;
        char	minor_type/*告警子类型*/;
        char	alarm_level/*告警严重级别(5、10、15、20、25数值越大越严重)*/;
        char	alarm_confidence/*告警置信度*/;
        int		alarm_session_id/*告警会话编号，0,保留，1-0xFFFFFFFF*/;
        short	alarm_sequence_id/*告警序号，0,保留; n第N次告警，0xFFFF销警*/;
        char	alarm_guid[16]/*告警GUID，UA通过此GUID向服务器查询具体告警信息*/;
        char	content_type[16]/*告警相关文本类型*/;
        char	content[256]/*告警相关文本内容*/;
        int		alarm_flag/*告警标志：1:存在告警图片*/;
        int		alarm_time/*告警时间*/;
        char	storage_area_id[128]/*告警图片存储的AreaId*/;
    }ZDSDK_NOTIFY_ALARM_INFO;

    typedef struct
    {
        char    url[256];	//下载URL
        void*   context;	//请求下载时的上下文
    }ZDSDK_NOTIFY_DOWNLOAD_URL;

    typedef struct
    {
        char	dev_id[20]/*设备ID：200000000100011835*/;
        bool	is_online/*在线状态*/;
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
		char  id[38]/*设备编号*/;
		char  domain_id[10]/*设备所在域编号*/;
		char  name[255]/*设备名称*/;
        char  gbtid[32];
		char  factory_name[128]/*设备所属厂家名称*/;
        char  location[256]/*设备安装位置*/;
        char  desc[256]/*设备描述*/;
		char  fd_state/*'W'待安装、'A' 正常、'P' 停用、'C'销户*/;
        unsigned char vincount /*视频输入通道个数*/;
        unsigned short factory_code /*设备所属厂家代码*/;
        unsigned int type/*设备类型*/;
		unsigned int software_version/*设备版本号*/;		
		unsigned int longitude/*经度*/;
		unsigned int latitude/*维度*/;
		unsigned int last_login/*最后登录时间*/;
		unsigned int last_logout/*最后登出时间*/;		
		int   online_state /*BIT0, 是否在线*/;
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

	typedef struct {
		char ie_url[256];		/*软件升级URL;*/
		char ie_web_url[256];	/*WEB服务URL*/
		char ie_map_url[256];	/*电子地图URL地址*/;
	}ZDSDK_NEGOTIATEURL_INFO, *PZDSDK_NEGOTIATEURL_INFO;

    //消息回调;
    typedef void(__cdecl *MESSAGE_CALLBACK)(void* identity, int msg_type, int error_code, void* msg_context);

    //通知回调;
    typedef void(__cdecl *NOTIFY_CALLBACK)(void* identity, int notify_type, void* notify_info);

    //录像下载的回调，identity: SDK初始化时，downlod：下载句柄；percent：下载进度；context：用户用据;
    typedef void(__cdecl *DOWNLOAD_PROC)(void* downlod, int percent, void *context);


    //codec type;
#define MEDIA_CODECTYPE_AUDIO_ENCODE	(0x00000001)	// 音频编码
#define MEDIA_CODECTYPE_AUDIO_DECODE	(0x00000002)	// 音频解码
#define MEDIA_CODECTYPE_VIDEO_ENCODE	(0x00000004)	// 视频编码
#define MEDIA_CODECTYPE_VIDEO_DECODE	(0x00000008)	// 视频解码

    //net type;
#define MEDIA_NETTYPE_UDP				(0x00000001)	// UDP客户端
#define MEDIA_NETTYPE_TCP				(0x00000002)	// TCP客户端
#define MEDIA_NETTYPE_BLOCK				(0x00000004)	// 为TCP回放、下载无丢帧的连接策略
#define MEDIA_NETTYPE_NORMAL			(0x00000000)    //普通网络
#define MEDIA_NETTYPE_3G				(0x00000100)    //表示3G等无线网络，需要启用丢包统计回传等策略 在MEDIA_NETTYPE_UDP 或上此宏即可
#define MEDIA_NETTYPE_ZB				(0x00010000)    //表示浙江贝的RTP
#define MEDIA_NETTYPE_RTP_DB33			(0x00020000)    //表示DB33的RTP
#define MEDIA_NETTYPE_NODECODE			(0x00100000)    //不解码标示,用于仅仅录像
#define MEDIA_NETTYPE_PLAYBACK			(0x01000000)    //录像回放标识，以区分实时视频请求  
#define MEDIA_NETTYPE_RTP               (0x00001000)
#define MEDIA_NETTYPE_NWP               (0x00002000)

    //factory type
#define MEDIA_FACTORYTYPE_ME			0x00010000		//南望
#define MEDIA_FACTORYTYPE_HK			0x00020000		//海康
#define MEDIA_FACTORYTYPE_SH			0x00040000		//上海测试
#define MEDIA_FACTORYTYPE_DH			0x00080000		//大华
#define MEDIA_FACTORYTYPE_ZB			0x00100000		//杭卡
#define MEDIA_FACTORYTYPE_DL			0x00200000		//大立
#define MEDIA_FACTORYTYPE_ST			0x00400000		//三立
#define MEDIA_FACTORYTYPE_FH			0x00800000		//烽火
#define MEDIA_FACTORYTYPE_HX			0x01000000		//虹信
#define MEDIA_FACTORYTYPE_ZB2			0x02000000		//杭卡
#define MEDIA_FACTORYTYPE_H3C			0x04000000		//华三
#define MEDIA_FACTORYTYPE_XC			0x08000000		//信产
#define MEDIA_FACTORYTYPE_XW            0x10000000      //南望（老）
#define MEDIA_FACTORYTYPE_ZV            0x12000000      //南京北路
#define MEDIA_FACTORYTYPE_JL            0x20000000      //金陵
#define MEDIA_FACTORYTYPE_SR            0x40000000      //数尔
#define MEDIA_FACTORYTYPE_DB33V2		0x80000000		//DB33V2所有厂家

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
#define LOCAL_RECORD_STOP				101	//录像自动停止通知
#define DECODE_FIRST_FRAME				102	//收到并解码第一帧视频
#define DISPLAY_END_NOTIFY              103
#define LOCAL_STREAM_STOP				105	//收到对方的结束通道信令包
#define LOCAL_STREAM_NULL				106	//本地帧回放模式缓冲区空的通知
#define LOCAL_FLAG_FRAME				107	//本地帧回放模式解到标识帧通知

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

	/* 版本信息结构; */
    typedef struct
    {
        unsigned	unMouduleLevel;		// 用来标示树级别
        char		szModuleName[32];	//模块名
        unsigned	unVer;				//0xyy.yy.yyyy版本号
        int			nTime;				// compile time_t
        char		szVerInfo[128];
        char		szDescribe[256];
    }MEDIA_VERSION_INFO;

    typedef struct tagtFrameParam
    {
        bool			bAgain;				//保留变量
        bool			bIsIFrame;			//是否为I帧
        unsigned char	byType;				//类型:音频或视频 AUDIO_TYPE 或 VIDEO_TYPE
        unsigned char	byFrameRate;		//帧率 fps
        unsigned int	unCodecType;		//编码类型v2，如(MAKEFOURCC('S', 'V', 'M', '4')) 表示 星望mpeg4
        unsigned short	usWidth;			//图像宽度
        unsigned short	usHeight;			//图像高度
        unsigned short	usFactoryCode;		//厂家代码V2，0x686b表示"hk"
        unsigned	unTimeStamp;		//32位时戳，单位为ms，从0开始相对时间
        unsigned	dwFrameSeq;			//帧序列号，每帧加1
        unsigned long long	un64Timestamp;	//64位时戳，单位为ms，从19700101 00:00:00开始相对时间，主要用于回放时进度条的定位
        unsigned	unOrgTimeStamp;		//从包头里取出的未修改的时戳
    }TFrameParam;

    /* 媒体参数结构 ;*/
    typedef struct tagTMediaParam
    {
        bool			bAgain;				//保留变量
        unsigned char	byType;				//类型:音频或视频 AUDIO_TYPE 或 VIDEO_TYPE
        unsigned char	byEncodeType;		//编码类型，单字节的码流类型
        bool			bIsIFrame;			//是否为I帧
        unsigned char	byFrameRate;		//帧率 fps
        unsigned char	byImageSize;		//图像分辨率
        unsigned	unTimeStamp;		//32位时戳，单位为ms，从0开始相对时间
        unsigned	dwFrameSeq;			//帧序列号，每帧加1
    }TMediaParam;

    //事件通知回调，录像已停止，解码第一帧完成等事件回调，unEventId为消息ID，参见notify event；pParam：用户用据
    //typedef	int(__cdecl *MEDIA_NOTIFY_PROC)(unsigned unEventId, void* pParam);

    //解码前的音视频编码数据回调，pBuf：帧数据；nLen：数据长度；pFrameParam：相关参数；pParam：用户用据
    typedef	int(*MEDIA_FRAME_PROC)(unsigned char* pBuf, int nLen, TFrameParam* pFrameParam, void* pParam);

    //解码后的视频数据回调，pBuf：视频数据；nLen：数据长度；nWidth：宽度；nHeight：高度；
    //nTime：时间戳，定义同time_t；nCSType：颜色空间类型 color space type；pParam：用户用据

    //typedef	int(__cdecl *MEDIA_VIDEO_PROC)(unsigned char* pBuf, int nLen, int nWidth, int nHeight, int nTime, int nCSType, void* pParam);

    //解码后的音频数据回调，pBuf：音频数据；nLen：数据长度；lpAudioFormat：音频格式，换为WAVEFORMATEX*使用；
    //unTimeStamp：时间戳，单位ms；pParam：用户用据

    //typedef	int(__cdecl *MEDIA_AUDIO_PROC)(unsigned char* pBuf, int nLen, void* lpAudioFormat, unsigned unTimeStamp, void* pParam);

    //编码后的音频数据回调，pBuf：编码后音频数据；nLen：数据长度；unCodecType：音频格式；unTimeStamp：时间戳，单位ms；pParam：用户用据
    typedef	int(*MEDIA_AUDIO_ENCODE_PROC)(unsigned char* pBuf, int nLen, unsigned unCodecType, unsigned unTimeStamp, void* pParam);

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

    //初始化;
    ZDSDK_API(int)     ZDSDK_Init();

    //反初始化;
    ZDSDK_API(void)     ZDSDK_Fini();

    //=============================登录=====================================
    //uas_ip:平台地址；uas_port：平台端口（5555）；email：账号；password：密码
    ZDSDK_API(zdsdk_t)  ZDSDK_Login(MESSAGE_CALLBACK message_cb, NOTIFY_CALLBACK notify_cb, void* identity,
        const char* uas_ip, unsigned short uas_port, const char* email, const char* password);

    ZDSDK_API(int)      ZDSDK_Run(zdsdk_t hsdk);

    //判断平台是否登陆;
    ZDSDK_API(int)      ZDSDK_IsLogined(zdsdk_t hsdk);
    //重新登陆平台;
    ZDSDK_API(int)      ZDSDK_ReLogin(zdsdk_t hsdk);
    //登出平台;
    ZDSDK_API(int)      ZDSDK_Logout(zdsdk_t hsdk);
	//获取协商后URL信息;
	ZDSDK_API(int)		ZDSDK_GetNegotiateUrl(zdsdk_t hsdk, PZDSDK_NEGOTIATEURL_INFO url_info, int nsize);
	//修改密码;
	ZDSDK_API(int)		ZDSDK_ModifyPassword(zdsdk_t hsdk, const char* poldpassword, const char* pnewpassword, bool bmd5, void* context);
	//发送透明通道数据;
	ZDSDK_API(int)		ZDSDK_SendNonStandardData(zdsdk_t hsdk, const char* dev_channel, const char* pData, int nlen, int ntype, int nsubtype, void* context);
	//修改设备信息;
	ZDSDK_API(int)		ZDSDK_ModifyFdName(zdsdk_t hsdk, PZDSDK_FD_INFO fd_info, void* context);
	//修改通道信息;
	ZDSDK_API(int)		ZDSDK_ModifyChannelName(zdsdk_t hsdk, PZDSDK_CHANNEL_INFO channel_info, void* context);

    //视频解码回调;
    ZDSDK_API(int)      ZDSDK_SetMediaDisplayCallback(zdsdk_t hsdk, MEDIA_VIDEOPLAY_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaAudioCallback(zdsdk_t hsdk, MEDIA_AUDIOPLAY_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaEventCallback(zdsdk_t hsdk, MEDIA_EVENT_PROC callback_ptr);
    ZDSDK_API(int)      ZDSDK_SetMediaDataCallback(zdsdk_t hsdk, MEDIA_FRAME_PROC callback_ptr);
	ZDSDK_API(int)		ZDSDK_SetMediaRawFrameCallback(zdsdk_t hsdk, MEDIA_VIDEORAWFRAME_PROC callback_ptr);

	//获取设备列表;
	ZDSDK_API(int)		ZDSDK_GetFDlist(zdsdk_t hsdk, PZDSDK_FD_INFO fd_list_ptr, int nList);
	//查询设备状态;
	ZDSDK_API(int)		ZDSDK_QueryFdStatus(zdsdk_t hsdk);
	//获取在线设备列表;
	ZDSDK_API(int)		ZDSDK_GetFdOnlineList(zdsdk_t hsdk, PZDSDK_FD_INFO fd_list_ptr, int nList);
    //获取通道数量;
    ZDSDK_API(int)      ZDSDK_GetChannelCount(zdsdk_t hsdk);
    //查询设备组通道列表;
	ZDSDK_API(int)		ZDSDK_QueryFdChannelList(zdsdk_t hsdk, const char* fd_id, void* context);
	//获取指定设备组通道列表;
	ZDSDK_API(int)		ZDSDK_GetFdChannelList(zdsdk_t hsdk, const char* fd_id, PZDSDK_CHANNEL_INFO channel_list_ptr, int nList);
	//获取通道列表;
    ZDSDK_API(int)      ZDSDK_GetChannleList(zdsdk_t hsdk, PZDSDK_CHANNEL_INFO channel_list_ptr, int nSize);
    ZDSDK_API(int)      ZDSDK_GetChannleInfo(zdsdk_t hsdk, const char* dev_channel, PZDSDK_CHANNEL_INFO channel_info);
    ZDSDK_API(int)      ZDSDK_GetChannleStatus(zdsdk_t hsdk, const char* dev_channel);

    //查询组信息 返回值为FALSE表示不支持。group_type：1表示DB33组,2表示国标组;
    ZDSDK_API(int)      ZDSDK_QueryGroupInfo(zdsdk_t hsdk, int group_type);
    //获取编号为group_id的组的子组。当group_id为空时表示根节点，当group_list_ptr为空时仅返回个数。
    ZDSDK_API(int)      ZDSDK_GetChildGroup(zdsdk_t hsdk, int group_type, const char* group_id, PZDSDK_GROUP_INFO group_list_ptr);
    //获取编号为group_id的组的所属通道。当group_id为空时表示根节点，当channel_list_ptr为空时仅返回个数;
    ZDSDK_API(int)      ZDSDK_GetGroupChannel(zdsdk_t hsdk, int group_type, const char* group_id, PZDSDK_CHANNEL_INFO channel_list_ptr);

	//查询预置点;
	ZDSDK_API(int)		ZDSDK_QueryCameraPreset(zdsdk_t hsdk, const char* dev_channel, void* context);
	//获取预置点列表;	
	ZDSDK_API(int)		ZDSDK_GetCameraPresetList(zdsdk_t hsdk, const char* dev_channel, PZDSDK_PRESET_INFO preset_list_ptr, int nList);
	//预置点操控;
	ZDSDK_API(int)		ZDSDK_ControlCameraPreset(zdsdk_t hsdk, const char* dev_channel, unsigned char action, unsigned char preset_id, const char* presetname, void* context);
	//查询预置点计划列表; 
	ZDSDK_API(int)		ZDSDK_QueryPresetSchedule(zdsdk_t hsdk, const char* dev_channel, void* context);
	//配置预置点计划列表;
	ZDSDK_API(int)		ZDSDK_SetPresetSchedule(zdsdk_t hsdk, const char* dev_channel, int nminutes, PZDSDK_PERSET_PLAN perset_plan_vt, int nSize, void* context);
	//获取预置点计划;
	ZDSDK_API(int)		ZDSDK_GetPresetSchedule(zdsdk_t hsdk, int *nminutes, PZDSDK_PERSET_PLAN preset_plan_list_ptr, int nSize);

    //=============================视频=====================================
    //开启视频;
    ZDSDK_API(int)     ZDSDK_MonitorStart(zdsdk_t hsdk, const char* dev_channel, int net_type, HWND monitor_wnd, void* context);
    ZDSDK_API(int)     ZDSDK_MonitorStop(zdsdk_t hsdk, const char* dev_channel, void* context);
    ZDSDK_API(int)     ZDSDK_ControlCamera(zdsdk_t hsdk, const char* dev_channel, unsigned char action, unsigned char param, PZDSDK_PTZLOCK_INFO lockinfo, void* context);

    //获取码流统计信息;
    ZDSDK_API(int)     ZDSDK_GetStatInfo(zdsdk_t hsdk, const char* dev_channel, PTCH_STAT_INFO stat_info);
    ZDSDK_API(int)     ZDSDK_DecodeOnlyIFrame(zdsdk_t hsdk, const char* dev_channel, bool decode_only_IFrame);

    //本地抓拍;
    ZDSDK_API(int)     ZDSDK_SnapShot(zdsdk_t hsdk, const char* dev_channel, const char* path_file);

    //本地录象;
    ZDSDK_API(int)     ZDSDK_StartLocalRecord(zdsdk_t hsdk, const char* dev_channel, const char* path_file, long record_time, bool audio_on);
    ZDSDK_API(int)     ZDSDK_StopLocalRecord(zdsdk_t hsdk, const char* dev_channel);

	//获取录像码流统计信息;
	ZDSDK_API(int)	   ZDSDK_GetRecordStatInfo(zdsdk_t sdk_t, zdsdk_playback_t playback, PTCH_STAT_INFO stat_info);

	//前端,中心录像;
	ZDSDK_API(int)	   ZDSDK_StartRecord(zdsdk_t hsdk, const char* dev_channel, PZDSDK_RCSTORAGE_CONFIG recodestorage, void* context);
	ZDSDK_API(int)	   ZDSDK_StopRecord(zdsdk_t hsdk, const char* dev_channel, bool bcenter, void* context);
	//配置录像计划(uOp:2添加,uOp:4删除,uOp:1更新);
	ZDSDK_API(int)	   ZDSDK_ConfigRecordPlan(zdsdk_t hsdk, const char* dev_channel, unsigned char uOp, bool bCenter, const PZDSDK_RECORD_PLAN record_plan_vt, int nSize, void* context);
	//查询录像计划;
	ZDSDK_API(int)	   ZDSDK_QueryRecordPlan(zdsdk_t hsdk, const char* dev_channel, bool bCenter, void* context);
	//获取录像计划;
	ZDSDK_API(int)	   ZDSDK_GetRecordPlan(zdsdk_t hsdk, const char* dev_channel, PZDSDK_RECORD_PLAN plan_list_ptr, int nSize);

    //开启音视频;
    ZDSDK_API(int)     ZDSDK_EnableStream(zdsdk_t hsdk, const char* dev_channel, bool enable);

    //视频上墙;
    //dev_channel：通道编号（例：200000-200000112233445566-0001-0001）；tv_idx:电视机号；tv_area_idx：电视机分区号;
    ZDSDK_API(int)     ZDSDK_MUA_MonitorStart(zdsdk_t hsdk, const char* dev_channel, int tv_idx, int tv_area_idx);
    ZDSDK_API(int)     ZDSDK_MUA_MonitorStop(zdsdk_t hsdk, int tv_idx, int tv_area_idx);
    //ptz控制：action：控制动作： EM_CAMERA_CONTROL_ACTION;
    ZDSDK_API(int)     ZDSDK_MUA_ControlCamera(zdsdk_t hsdk, int tv_idx, int tv_area_idx, unsigned char action);

    //=============================录像=====================================
    //查询录像;
    ZDSDK_API(int)     ZDSDK_QueryRecord(zdsdk_t hsdk, const char* dev_channel, bool center, long start_time, long end_time, void* context);    
    ZDSDK_API(int)     ZDSDK_GetRecordList(zdsdk_t hsdk, PZDSDK_RECORD_INFO record_list_ptr, int cnt);

    //启动回放;
    ZDSDK_API(zdsdk_playback_t)  ZDSDK_StartPlayback(zdsdk_t hsdk, const PZDSDK_RECORD_INFO ptr_record_info, int net_type, HWND playback_wnd, bool is_center, void* context);
    ZDSDK_API(int)     ZDSDK_StopPlayback(zdsdk_t hsdk, zdsdk_playback_t playback, void* context);
    ZDSDK_API(int)     ZDSDK_ControlPlayback(zdsdk_t hsdk, zdsdk_playback_t playback, unsigned char action, int param, void* context);

    //获取码流统计信息;
    ZDSDK_API(int)     ZDSDK_Playback_GetStatInfo(zdsdk_t hsdk, zdsdk_playback_t playback, PTCH_STAT_INFO stat_info);

    ZDSDK_API(int)     ZDSDK_Playback_DecodeOnlyIFrame(zdsdk_t hsdk, zdsdk_playback_t playback, bool decode_only_IFrame);

    //本地抓拍;
    ZDSDK_API(int)     ZDSDK_Playback_SnapShot(zdsdk_t hsdk, zdsdk_playback_t playback, const char* path_file);

    //本地录象;
    ZDSDK_API(int)     ZDSDK_Playback_StartLocalRecord(zdsdk_t hsdk, zdsdk_playback_t playback, const char* path_file, long record_time, bool audio_on);
    ZDSDK_API(int)     ZDSDK_Playback_StopLocalRecord(zdsdk_t hsdk, zdsdk_playback_t playback);

    //开启音视频;
    ZDSDK_API(int)     ZDSDK_Playback_EnableStream(zdsdk_t hsdk, zdsdk_playback_t playback, bool enable);

    ZDSDK_API(int)     ZDSDK_QueryDownloadURL(zdsdk_t hsdk, const PZDSDK_RECORD_INFO ptr_record_info, void* context);
    ZDSDK_API(zdsdk_download_t)   ZDSDK_StartDownload(const char* record_url, const char* path_file, DOWNLOAD_PROC download_callback, void* context);
    ZDSDK_API(void)     ZDSDK_StopDownload(zdsdk_download_t download);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif //__ZDSDK__H__
