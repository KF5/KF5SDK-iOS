//
//  KFConfig.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@class KFUser;
@class KFLogger;

@interface KFConfig : NSObject
/**
 *  用户数据
 */
@property (nonatomic, strong,readonly) KFUser *user;

/**
 *  初始化方法
 *
 *  @return 返回唯一KFConfig实例对象
 */
+ (instancetype)shareConfig;
/**
 *  初始化信息(block用于检测信息填写是否正确,SDK不会将用户信息保存到本地,所以在使用SDK前,必须先调用此方法)
 *
 *  @param user         需要初始化的信息
 *  @param successBlock 成功的回调
 *  @param failureBlock 失败的回调
 *
 *  当系统已经存在一个用户时,会先注销原来的用户,在初始化新的用户
 */
- (void)initializeWithUser:(KFUser *)user successBlock:(KFInitSuccess)successBlock failureBlock:(KFAPIError)failureBlock;
/**
 *  获取普通用户可以编辑的自定义字段
 *
 *  @param success 获取成功的回调
 *  @param error   获取失败的回调
 */
- (void)getCustomFiledsWithSuccess:(KFAPISuccess)success failure:(KFAPIError)error;
/**
 *  当前SDK的版本
 *
 *  @return 版本号
 */
- (NSString *)version;
/**
 *  注销用户
 *
 *  会删除该用户的deviceToken,清除初始化的用户信息,再次访问KF5接口,需重新初始化
 */
- (void)logoutOfUser;

@end