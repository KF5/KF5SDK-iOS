//
//  KFBaseStatus.h
//  KFBaseStatus
//
//  Created by admin on 15/5/2.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>


/** 网络状态 */
typedef enum{
    
    /** 无网络 */
    KFBaseNetWorkStatusNone=0,
    
    /** Wifi网络 */
    KFBaseNetWorkStatusWifi,
    
    /** 蜂窝网络 */
    KFBaseNetWorkStatusWWAN,
    
    /** 2G网络 */
    KFBaseNetWorkStatus2G,
    
    /** 3G网络 */
    KFBaseNetWorkStatus3G,
    
    /** 4G网络 */
    KFBaseNetWorkStatus4G,
    
    //未知网络
    KFBaseNetWorkStatusUnkhow
    
}KFBaseNetWorkStatus;

@protocol KFBaseStatusProtocol <NSObject>

/** 网络状态变更 */
-(void)coreNetworkChangeNote:(NSNotification *)note;

@end

@interface KFBaseStatus : NSObject

+ (instancetype)sharedBaseStatus;

/** 获取当前网络状态：枚举 */
+(KFBaseNetWorkStatus)currentNetWorkStatus;

/** 获取当前网络状态：字符串 */
+(NSString *)currentNetWorkStatusString;


/** 开始网络监听 */
+(void)beginNotiNetwork:(id<KFBaseStatusProtocol>)listener;

/** 停止网络监听 */
+(void)endNotiNetwork:(id<KFBaseStatusProtocol>)listener;

/*
 *  新增API
 */
/** 是否是Wifi */
+(BOOL)isWifiEnable;

/** 是否有网络 */
+(BOOL)isNetworkEnable;

/** 是否处于高速网络环境：3G、4G、Wifi */
+(BOOL)isHighSpeedNetwork;

@end
