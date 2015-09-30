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

#import "KFDispatcher.h"
/**
 *  详细页面的显示方式
 */
typedef NS_ENUM(NSUInteger, KFNavBarDetailMessageUIType) {
    
    /**
     *  NavBarButton设置为文字
     */
    KFNavBarDetailMessageUITypeLocalizedLabel,
    
    /**
     *  NavBarButton设置为图片
     */
    KFNavBarDetailMessageUITypeUITypeImage,
};


@interface KFRequests : NSObject<KFCreateRequestUIDelegate>

/**
 *  初始化方法
 *
 *  @return 返回唯一KFRequests实例对象
 */
+ (instancetype) instance;

/**
 *  是否在工单内容视图的rightNavBar显示详细信息按钮，默认显示
 */
@property (nonatomic, assign) BOOL isShowDetailMessage;

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
 *  @param fieldDict     工单自定义字段字典，如@{@"field_123":@"内容"}]
 *  @param navController 当前的navController
 *  @param success       网络请求成功时返回
 *  @param error         网络请求失败时返回
 */
+ (void) presentRequestCreationWithNavController:(UINavigationController *)navController fieldDict:(NSDictionary *)fieldDict success:(KFAPISuccess)success
                                        andError:(KFAPIError)error;

/**
 *  push工单列表视图控制器
 *
 *  @param navController 当前的navController
 */
+ (void) showRequestListWithNavController:(UINavigationController *)navController;

/**
 *  push工单列表视图控制器(带actionBlock)
 *
 *  @param navController 当前的navController
 *  @param actionBlock   点击工单列表navBar右侧按钮的事件处理，
 *                          为NULL直接跳转到创建工单控制器（不带工单自定义参数）
 */
+ (void) showRequestListWithNavController:(UINavigationController *)navController rightBarButtonActionBlock:(KFBarButtonActionBlock)actionBlock;

/**
 *  present工单列表视图控制器
 *
 *  @param navController 当前的navController
 */
+ (void) presentRequestListWithNavController:(UINavigationController *)navController;
/**
 *  present工单列表视图控制器(带actionBlock)
 *
 *  @param navController 当前的navController
 *  @param actionBlock   点击工单列表navBar右侧按钮的事件处理，
 *                          为NULL直接跳转到创建工单控制器（不带工单自定义参数）
 */
+ (void) presentRequestListWithNavController:(UINavigationController *)navController rightBarButtonActionBlock:(KFBarButtonActionBlock)actionBlock;

/**
 *  设置工单列表右侧的navBarButton的图片名称
 *
 *  @param name 图片名称
 */
+ (void) setNewRequestBarButtonImage:(NSString *)name;

/**
 *  设置工单列表右侧的navBarButton的内容
 *
 *  @param title 内容
 */
+ (void) setNewRequestBarButtonTitle:(NSString *)title;
/**
 *  设置工单列表右侧的navBarButton的显示方式
 *
 *  @param type 显示方式
 */
+ (void) setNavBarCreateRequestUIType:(KFNavBarCreateRequestUIType)type;


/**
 *  设置详细工单右侧的navBarButton的图片名称
 *
 *  @param name 图片名称
 */
+ (void) setDetailMessageBarButtonImage:(NSString *)name;

/**
 *  设置详细工单右侧的navBarButton的内容
 *
 *  @param title 内容
 */
+ (void) setDetailMessageBarButtonTitle:(NSString *)title;
/**
 *  设置详细工单右侧的navBarButton的显示方式
 *
 *  @param type 显示方式
 */
+ (void) setNavBarDetailMessageUIType:(KFNavBarDetailMessageUIType)type;

@end
