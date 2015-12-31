//
//  KFLog.h
//  SampleSDKApp
//
//  Created by admin on 15/3/30.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KFLogger : NSObject

/**
 *  SDK KFLogger
 *
 *  @param format 日志内容
 */
+ (void) log:(NSString *)format, ...;

/**
 *  Set KFLogger enabled
 *
 *  @param 是否输出日志
 */
+ (void) enable:(BOOL)enabled;
@end
