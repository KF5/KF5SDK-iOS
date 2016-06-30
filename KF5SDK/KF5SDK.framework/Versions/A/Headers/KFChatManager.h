//
//  KFChatManager.h
//  KF5Chatdemo
//
//  Created by admin on 15/12/8.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@class KFMessage;
@class KFAgent;
@class KFUser;


@class KFChatManager;

@protocol KFChatManagerDelegate <NSObject>

@optional
/**
 *  接受聊天消息
 *
 *  @param chatManager  聊天管理对象
 *  @param chatMessages 聊天消息数组
 *
 */
- (void)chatManager:(KFChatManager *)chatManager receiveMessages:(NSArray *)chatMessages;
/**
 *  用户排队的当前位置
 *
 *  @param chatManager  聊天管理对象
 *  @param queueIndex   当前位置
 */
- (void)chatManager:(KFChatManager *)chatManager queueIndex:(NSInteger)queueIndex;
/**
 *  分配到客服/转接客服
 *
 *  @param chatManager 聊天管理对象
 *  @param agent       客服,当客服为空时,说明对话已结束
 */
- (void)chatManager:(KFChatManager *)chatManager currectAgent:(KFAgent *)agent;
/**
 *  客服发起满意度评价
 *
 *  @param chatManager 聊天管理对象
 */
- (void)chatManagerRating:(KFChatManager *)chatManager;
/**
 *  录音振幅变化
 *
 *  @param chatManager 聊天管理对象
 *  @param amplitude   录音振幅
 */
-(void)chatManager:(KFChatManager *)chatManager recordingAmplitude:(double)amplitude;
/**
 *  录音完成的代理
 *
 *  @param chatManager 聊天管理对象
 *  @param message     音频消息
 *  @param error       错误信息,为nil表示为成功
 */
- (void)chatManager:(KFChatManager *)chatManager recordVoiceMessage:(KFMessage *)message error:(KFError *)error;

#pragma mark - deprecated

- (void)chatManager:(KFChatManager *)chatManager transferAgent:(KFAgent *)agent __deprecated_msg("该方法被弃用,请使用chatManager:currectAgent:");

@end

@interface KFChatManager : NSObject
/**
 *  添加代理
 *
 * @warning 在不使用时建议调用删除代理方法(removeDelegate)
 */
- (void)addDelegate:(id<KFChatManagerDelegate>)delegate;
/**
 *  删除代理
 */
- (void)removeDelegate:(id<KFChatManagerDelegate>)delegate;
/**
 *  删除所有代理
 *
 * @warning 会删除所有代理方法(包括KFChatViewController里的代理),不建议开发者调用
 */
- (void)removeAllDelegates;
/**
 *  请求超时时间,默认15秒
 */
@property (nonatomic, assign) NSTimeInterval timeout;
/**
 *  当前客服
 */
@property (nonatomic, strong,readonly) KFAgent *currentAgent;

/**
 *  socket是否连接成功
 */
@property (nonatomic, assign,readonly) BOOL isConnectSuccess;

/**
 *  当前对话状态
 *
 *  @warning socket连接成功后有效
 */
@property (nonatomic, assign,readonly) KFChatStatus chatStatus;
/**
 *  用户自定义信息
 *
 *  @warning 需要在连接服务器之前定义(格式@[@{@"name":@"性别",@"value":@"男"},@{@"name":@"爱好",@"value":@"篮球"}])
 */
@property (nonatomic, strong) NSArray *customFields;
/**
 *  单例
 */
+ (instancetype)sharedChatManager;
/**
 *  连接服务器
 *
 * @warning 如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)connectWithUser:(KFUser *)user completion:(void (^)(KFError *error))completion;
/**
 *  同步离线消息
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)syncMessageWithCompletion:(void (^)(KFError *error,NSArray<KFMessage *> *history))completion;

/**
 *  给机器人发送消息
 *
 *  @param message    消息实体
 *  @param completion 成功或失败的回调,回调中有机器人返回的消息
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求)
 *           与机器人的聊天内容将不保存到数据库.
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)sendAITextMessage:(KFMessage *)message completion:(void (^)(KFError *error,KFMessage *me_message,KFMessage *ai_message))completion;
/**
 *  获取机器人客服的信息
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)getAIAgentWithCompletion:(void (^)(KFError *error,KFAgent *agent))completion;
/**
 *  用户加入排队
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)queueUpWithCompletion:(void (^)(KFError *error,NSInteger queue_index))completion;
/**
 *  用户取消排队
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)queueCancelWithCompletion:(void (^)(KFError *error))completion;
/**
 *  发送消息
 *
 *  @param message    消息实体
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           当处于排队期间:1.允许发送一条消息,用于在排队结束,客服能看到并处理该用户的问题;
 *                        2.发送的消息不会存储到本地数据库,需开发者自行保存;
 *                        3.只能发送文本消息,否则会失败;
 *                        4.多次调用此接口,则客服在排队完成后只会接收最后一条消息.
 *           状态通过chatStatus得到
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口.
 */
- (void)sendMessage:(KFMessage *)message completion:(void (^)(KFError *error,KFMessage *message))completion;
/**
 *  重新发送消息
 *
 *  @param message    消息实体
 *  @param completion 成功或失败的回调
 *
 *  @return 用于显示的消息实体
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (KFMessage *)resendMessage:(KFMessage *)message completion:(void (^)(KFError *error,KFMessage *message))completion;
/**
 *  发送满意度
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)sendRating:(BOOL)rating completion:(void (^)(KFError *error))completion;
/**
 *  获取历史记录
 *
 *  @param from_id    消息的id,从哪条消息开始
 *  @param count      要获取的数量
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)getHistoryWithFrom_id:(NSString *)from_id count:(int)count completion:(void (^)(KFError *error,NSArray<KFMessage *> *history))completion;
/**
 *  设置用户离线,KF5服务器回向推送url发送推送,建议在应用进入后台时调用
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 */
- (void)setUserOffline;

#pragma mark - 音频相关
/**
 *  开始录制音频
 */
-(void)startVoiceRecord;
/**
 *  取消录制音频
 */
- (void)cancleVoiveRecord;
/**
 *  停止录制音频
 */
-(void)stopVoiceRecord;
/**
 *  播放音频消息
 *
 *  @param completion 成功或失败的回调
 */
- (void)playVoiceMessage:(KFMessage *)message completion:(void (^)(KFError *error))completion;
/**
 *  停止音频播放
 */
-(void)stopVoicePlayingMessage;
/**
 *  获取音频时长
 *
 *  @param message 音频消息
 *
 *  @return 时长
 */
+ (double)voiceDurationWithMessage:(KFMessage *)message;
/**
 *  判断是否是正在播放的文件
 *
 *  @param message 必须是语音消息
 *
 */
- (BOOL)isPlayingWithVoiceMessage:(KFMessage *)voiceMessage;

#pragma mark 其他
/**
 *  获取聊天消息未读数
 *
 * @warning 未读消息数不是很精确,不建议直接使用其数量提示用户;最好的方式是用此接口获取是否有未读消息(HTTP请求)
 */
- (void)getUnReadMessageCountWithCompletion:(void (^)(KFError *error,int unReadMessageCount))completion;




#pragma mark - deprecated
/**
 *  是否有在线客服
 */
@property (nonatomic, assign) BOOL hasOnlineAgent __deprecated_msg("该变量已被弃用");
/**
 *  是否开启聊天机器人
 *
 *  @warning socket连接成功后有效
 */
@property (nonatomic, assign,readonly) BOOL isOpenAIAgent __deprecated_msg("该变量已被弃用,请使用chatStatus");
/**
 *  是否正在和客服对话
 *
 *  @warning socket连接成功后有效
 */
@property (nonatomic, assign,readonly) BOOL isChatting __deprecated_msg("该变量已被弃用,请使用chatStatus");
/**
 *  分配客服
 *
 *  @param completion 成功或失败的回调
 *
 *  @warning 需要先调用connectWithUser:completion:连接服务器(socket请求).
 *           如果使用KFChatViewController,在无特殊需求的情况下,不必调用此接口
 */
- (void)getAgentWithCompletion:(void (^)(KFError *error,KFAgent *agent))completion  __deprecated_msg("该方法已被弃用,SDK现已加入排队功能,请调用排队接口,之后在代理里接收分配的客服");

@end
