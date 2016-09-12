//
//  KFUser.h
//  SampleSDKApp
//
//  Created by admin on 15/2/4.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@interface KFUser : NSObject
/**
 *  快速初始化
 *
 *  @param hostName    云客服域名,必填
 *  @param appId       公司密钥,必填
 *  @param email       用户邮箱,必填
 *  @param appName     应用名称,选填
 *  @param deviceToken 用户推送token,选填,填写后,不需要主动调用enablePush上传deviceToken
 */
- (instancetype)initWithHostName:(NSString *)hostName appId:(NSString *)appId email:(NSString *)email appName:(NSString *)appName deviceToken:(NSString *)deviceToken;
/**
 *  快速初始化
 *
 *  @param hostName    云客服域名,必填
 *  @param appId       公司密钥,必填
 *  @param phone       用户手机号,必填
 *  @param appName     应用名称,选填
 *  @param deviceToken 用户推送token,选填,填写后,不需要主动调用enablePush上传deviceToken
 */
- (instancetype)initWithHostName:(NSString *)hostName appId:(NSString *)appId phone:(NSString *)phone appName:(NSString *)appName deviceToken:(NSString *)deviceToken;
/**
 *  快速初始化
 *
 *  @param hostName         云客服域名,必填
 *  @param appId            公司密钥,必填
 *  @param email            用户邮箱(手机和邮箱,必须传其一)
 *  @param phone            用户手机号(手机和邮箱,必须传其一)
 *  @param verifyUserType   用户信息验证方式,只有当邮箱和手机号同时传入时才生效,默认以邮箱作为验证方式
 *  @param appName          应用名称,选填
 *  @param deviceToken      用户推送token,选填,填写后,不需要主动调用enablePush上传deviceToken
 */
- (instancetype)initWithHostName:(NSString *)hostName appId:(NSString *)appId email:(NSString *)email phone:(NSString *)phone verifyUserType:(KFVerifyUserType)verifyUserType appName:(NSString *)appName deviceToken:(NSString *)deviceToken;
/**
 *  用户的ID
 */
@property (nonatomic, strong,readonly) NSString *Id;
/**
 *  用户邮箱
 */
@property (nonatomic, copy,readonly) NSString *email;
/**
 *  用户手机号
 */
@property (nonatomic, copy,readonly) NSString *phone;
/**
 *  用户信息验证方式,默认以邮箱作为验证方式,只有当手机号和邮箱同时存在时生效
 */
@property (nonatomic, assign,readonly)KFVerifyUserType verifyUserType;
/**
 *  用户昵称
 */
@property (nonatomic, copy) NSString *userName;
/**
 *  用户推送token
 */
@property (nonatomic, copy) NSString *deviceToken;

/**
 *  公司秘钥,必填
 */
@property (nonatomic, copy,readonly) NSString *appId;

/**
 *  公司云客服域名,必填
 */
@property (nonatomic, copy,readonly) NSString *hostName;

/**
 *  用于标示应用的名称
 */
@property (nonatomic, copy) NSString *appName;
/**
 *  该用户是否已经被创建
 */
@property (nonatomic, assign, readonly) BOOL isCreated;

@end
