//
//  KFPushUtil.h
//  SampleSDKApp
//
//  Created by admin on 15/4/16.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KFDispatcher.h"

@interface KFPushUtil : NSObject

/**
 *  发送设备的deviceToken
 *  deviceToken   设备的deviceToken
 *  success       成功时回调函数
 *  error         失败时回调函数
 */
+ (void)enablePush:(NSData *)deviceToken withSuccess:(KFAPISuccess)success
          andError:(KFAPIError)error;

/**
 *  删除设备的deviceToken
 *  deviceToken   设备的deviceToken
 *  success       成功时回调函数
 *  error         失败时回调函数
 */
+ (void)disablePush:(NSData *)deviceToken withSuccess:(KFAPISuccess)success
           andError:(KFAPIError)error;

@end
