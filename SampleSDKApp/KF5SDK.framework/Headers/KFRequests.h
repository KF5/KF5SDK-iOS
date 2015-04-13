//
//  KFRequests.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KFDispatcher.h"
#import "KFCreateRequestUIDelegate.h"

@interface KFRequests : NSObject<KFCreateRequestUIDelegate>

/**
 *  初始化方法
 *
 *  @return 返回唯一KFRequests实例对象
 */
+ (instancetype) instance;

/**
 *  present创建工单视图控制器
 *
 *  @param navController 当前的navController
 */
+ (void) presentRequestCreationWithNavController:(UINavigationController*)navController;

/**
 *  present创建工单视图控制器
 *
 *  @param navController 当前的navController
 *  @param success       网络请求成功时返回
 *  @param error         网络请求失败时返回
 */
+ (void) presentRequestCreationWithNavController:(UINavigationController*)navController
                                  withSuccess:(KFAPISuccess)success
                                     andError:(KFAPIError)error;

/**
 *  present创建工单视图控制器
 *
 *  @param navController 当前的navController
 */
+ (void) presentRequestListWithNavController:(UINavigationController *)navController;

/**
 *  push工单列表视图控制器
 *
 *  @param navController 当前的navController
 */
+ (void) showRequestListWithNavController:(UINavigationController *)navController;

/**
 *  设置newRequest右侧navBarButton的图片名称
 *
 *  @param name 图片名称
 */
+ (void) setNewRequestBarButtonImage:(NSString *)name;

/**
 *  设置newRequest右侧navBarButton的内容
 *
 *  @param title 内容
 */
+ (void) setNewRequestBarButtonTitle:(NSString *)title;
/**
 *  设置newRequest右侧navBarButton的显示方式
 *
 *  @param type 显示方式
 */
+ (void) setNavBarCreateRequestUIType:(KFNavBarCreateRequestUIType)type;


@end
