//
//  KFDispatcher.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
@class KFAgent;
@class KFError;
@class KFMessage;
@class KFUser;
@interface KFDispatcher : NSObject

/**
 *  用户信息验证方式
 */
typedef NS_ENUM(NSInteger,KFVerifyUserType){
    KFVerifyUserTypeDefault = 0,    // 使用默认,以邮箱为验证方式
    KFVerifyUserTypeEmail,          // 以邮箱为验证方式
    KFVerifyUserTypePhone           // 以手机号为验证方式
};

/**
 *  NavBarButton的显示方式
 */
typedef NS_ENUM(NSInteger,KFNavBarUIType){
    KFNavBarUITypeLocalizedLabel = 0,   // NavBarButton设置为文字
    KFNavBarUITypeImage,                // NavBarButton设置为图片
    KFNavBarUITypeNone                  // NavBarButton不显示
};

/**
 *  文档展示方式
 */
typedef NS_ENUM(NSInteger,KFHelpCenterType){
    KFHelpCenterTypeDefault = 0,  // 使用默认,默认使用KFHelpCenterTypeCategory
    KFHelpCenterTypeCategory,     // 分区列表
    KFHelpCenterTypeForum,        // 分类列表
    KFHelpCenterTypePost,         // 文档列表
};

/**
 *  消息发送状态
 */
typedef NS_ENUM(NSInteger,KFMessageStatus) {
    KFMessageStatusSending = 0,
    KFMessageStatusSuccess,
    KFMessageStatusFailure
};
/**
 *  消息类型
 */
typedef NS_ENUM(NSInteger,KFMessageType) {
    KFMessageTypeText = 0,
    KFMessageTypeImage,
    KFMessageTypeVoice,
    KFMessageTypeSystem,
    KFMessageTypeOther,
    KFMessageTypeAIDocument
};
/**
 *  消息来自于
 */
typedef NS_ENUM(NSInteger,KFMessageFrom) {
    KFMessageFromMe = 0,
    KFMessageFromOther
};
/**
 *  聊天客服角色
 */
typedef NS_ENUM(NSInteger,KFAgentRole) {
    KFAgentRoleAgent = 0,    // 人工客服
    KFAgentRoleAI            // 机器人客服
};

/**
 *  错误类型
 */
typedef NS_ENUM(NSInteger,KFErrorCode) {
    KFErrorCodeNone            = 0,     // 没有错误
    KFErrorCodeAgentOffline    = 1001,  // 没有客服在线
    KFErrorCodeAgentBusy       = 1002,  // 客服忙碌
    KFErrorCodeSocketError     = 5000,  // 服务器连接失败
    KFErrorCodeSocketTimeOut   = 303,   // 服务器请求超时
    KFErrorCodeParamError      = 3004,  // 参数错误
    KFErrorCodeNetWorkOff      = 30000, // 网络断开
    KFErrorCodeSocketOff       = 30001, // 与服务器断开连接
    KFErrorCodeRecordError     = 500001,// 录音出错
    KFErrorCodeAudioPalyError  = 500002,// 录音播放出错
    KFErrorCodeRecordTimeShort = 20000, // 录音时间过短
    
};

/**
 * API success block.
 */
typedef void (^KFAPISuccess) (NSDictionary *result);

typedef void (^KFAPIDownloadVoiceSuccess) (KFMessage *message);


typedef void (^KFInitSuccess) (KFUser *user,NSString *message);

/**
 * API error block
 */
typedef void (^KFAPIError) (KFError *error);
/**
 *  API progress block
 */
typedef void  (^KFAPIUploadProgress)(NSProgress * progress);

/**
 *  点击BarButton的回调
 */
typedef void (^KFBarButtonActionBlock)();

/**
 *  alert点击确定的回调
 */
typedef void (^KFAlertActionBlock)();


typedef void (^KFChatUnReadMessageCountCompletion)(KFError *error,int unReadMessageCount);

typedef void (^KFChatMessageCompletion)(KFError *error,KFMessage *message);

typedef void (^KFChatAIMessageCompletion)(KFError *error,KFMessage *me_message,KFMessage *ai_message);

typedef void (^KFChatGetHistoryCompletion)(KFError *error,NSArray<KFMessage *> *history);

typedef void (^KFChatGetAgentCompletion)(KFError *error,KFAgent *agent);

typedef void (^KFChatCompletion)(KFError *error);

typedef void (^KFChatDefaultCompletion)(KFError *error,NSDictionary *dict);

@end
