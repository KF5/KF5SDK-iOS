//
//  KFComment.h
//  SampleSDKApp
//
//  Created by admin on 15/10/26.
//  Copyright © 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KFDispatcher.h"

@interface KFComment : NSObject
/**
 *  消息发送人的id
 */
@property (nonatomic, strong) NSNumber *author_id;
/**
 *  消息内容
 */
@property (nonatomic, copy) NSString *content;
/**
 *  创建时间
 */
@property (nonatomic, copy) NSString *created_at;
/**
 *  消息id
 */
@property (nonatomic, strong) NSNumber *Id;
/**
 *  附件
 */
@property (nonatomic, strong) NSArray *attachments;
/**
 *  发送人的名称
 */
@property (nonatomic, copy) NSString *author_name;

/**
 *  发送方发送的图片
 */
@property (nonatomic, strong) NSArray *images;
/**
 *  发送状态
 */
@property (nonatomic, assign) KFMessageStatus cellLoad;

+ (NSArray *)commentWithDict:(NSDictionary *)dict;

@end
