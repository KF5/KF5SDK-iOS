//
//  KFUser.h
//  SampleSDKApp
//
//  Created by admin on 15/2/4.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KFUser : NSObject

- (instancetype)initWithHostName:(NSString *)hostName appId:(NSString *)appId email:(NSString *)email appName:(NSString *)appName;

/**
 *  用户的ID
 */
@property (nonatomic, strong,readonly) NSNumber *Id;

/**
 *  用户邮箱
 */
@property (nonatomic, copy) NSString *email;

/**
 *  用户昵称
 */
@property (nonatomic, copy) NSString *userName;

/**
 *  公司秘钥
 */
@property (nonatomic, copy) NSString *appId;

/**
 *  公司云客服域名
 */
@property (nonatomic, copy) NSString *hostName;

/**
 *  用于标示应用的名称
 */
@property (nonatomic, copy) NSString *appName;
/**
 *  该用户是否已经被创建
 */
@property (nonatomic, assign, readonly) BOOL isCreated;

@end
