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
 *  初始化信息(用于检测信息填写是否正确)
 *
 *  @param user         需要初始化的信息
 *  @param successBlock 成功的回调
 *  @param failureBlock 失败的回调
 */
- (void)initializeWithUser:(KFUser *)user successBlock:(KFInitSuccess)successBlock failureBlock:(KFAPIError)failureBlock;
/**
 *  获取普通用户可以编辑的自定义字段
 *
 *  @param success 获取成功的回调
 *  @param error 获取失败的回调
 */
- (void)getCustomFiledsWithSuccess:(KFAPISuccess)success failure:(KFAPIError)error;
/**
 *  当前SDK的版本
 *
 *  @return 版本号
 */
+ (NSString *)version;

@end