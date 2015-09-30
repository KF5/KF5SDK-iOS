//
//  KFConfig.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KFUser.h"
#import "KFLogger.h"
#import "KFDispatcher.h"

@interface KFConfig : NSObject

/**
 *  初始化方法
 *
 *  @return 返回唯一KFConfig实例对象
 */
+ (instancetype)instance;

/**
 *  初始化域名和通信秘钥
 *
 *  @param HostName 云客服平台域名
 *  @param appId    通信秘钥
 */
- (void)initializeWithHostName:(NSString *)hostName appId:(NSString *)appId;

/**
 *  初始化用户名和密码
 *
 *  @param email    用户邮箱
 *  @param userName 昵称
 *  @param password 密码
 *  @param failure  密码错误,或网络请求错误的处理
 */
- (void)setEmail:(NSString *)email andUserName:(NSString *)userName PassWord:(NSString *)password  WithFailure:(void (^)(id failure))failure;

/**
 *  初始化用户名和昵称   注：所有用户无视密码即可初始化成功（不推荐使用）
 *
 *  @param email    用户邮箱
 *  @param userName 昵称
 *  @param failure  密码错误,或网络请求错误的处理
 */
- (void)setEmail:(NSString *)email andUserName:(NSString *)userName WithFailure:(void (^)(id failure))failure;

/**
 *  获取普通用户可以编辑的自定义字段
 *
 *  @param success 获取成功的回调
 *  @param error 获取失败的回调
 */
- (void)getCustomFiledsWithSuccess:(KFAPISuccess)success failure:(KFAPIError)error;

/**
 *  用户数据
 */
@property (nonatomic, strong,readonly) KFUser *user;

@end