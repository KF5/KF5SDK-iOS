//
//  KFChatMessage.h
//  Pods
//
//  Created by admin on 15/12/9.
//
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@interface KFMessage : NSObject

/**
 *  消息的id
 */
@property (nonatomic, assign) int message_id;
/**
 *  信息的发送人
 */
@property (nonatomic, assign) kMessageFrom messageFrom;

/**
 *  消息类型
 */
@property (nonatomic, assign) kMessageType messageType;
/**
 *  消息.(当消息类型不是文本时,此属性会保存图片或语音的token,不建议开发者处理)
 */
@property (nonatomic, copy) NSString *content;
/**
 *  图片或语音的url
 */
@property (nonatomic, copy) NSString *url;
/**
 *  图片或语音的本地路径
 */
@property (nonatomic, copy) NSString *local_path;

/**
 *  消息创建时间
 */
@property (nonatomic, assign) int created;
/**
 *   消息是否发送成功
 */
@property (nonatomic, assign) kMessageStatus messageStatus;
/**
 *  传输标记
 */
@property (nonatomic, assign) int mark;

/**
 *  快速创建一个文本消息
 *
 *  @param content 文本信息
 *
 *  @return 文本消息对象
 */
+ (instancetype)messageWithContent:(NSString *)content;

/**
 *  快速创建一个图片消息
 *
 *  @param image 图片
 *
 *  @return 图片消息对象.(注意:创建后,会自动保存到本地)
 */
+ (instancetype)messageWithImage:(UIImage *)image;
/**
 *  快速创建一个语音消息
 *
 *  @param voice 语音
 *
 *  @return 图片消息对象.(注意:创建后,会自动保存到本地)
 */
+ (instancetype)messageWithVoicelocalPath:(NSString *)localPath;

@end
