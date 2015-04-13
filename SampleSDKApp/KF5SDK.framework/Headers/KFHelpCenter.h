//
//  KFHelpCenter.h
//  SampleSDKApp
//
//  Created by admin on 15/3/31.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KFHelpCenterConversationUIDelegate.h"

typedef  enum{
    KFHelpCenterTypeDocument, // 展示分区列表,默认
    KFHelpCenterTypeForum,    // 直接展示所有分类列表
    KFHelpCenterTypePost,     // 直接展示所有文档列表
    KFHelpCenterTypeNone      // 使用默认
}KFHelpCenterType;

@interface KFHelpCenter : NSObject<KFHelpCenterConversationsUIDelegate>

/**
 *  push知识库文档控制器
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 */
+ (void)showHelpCenterWithNavController:(UINavigationController*)navController helpCenterType:(KFHelpCenterType)helpCenterType;

/**
 *  present知识库文档控制器
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController*)navController helpCenterType:(KFHelpCenterType)helpCenterType;

/**
 *  设置右侧NavBarButton的image
 *
 *  @param name 图片名称
 */
+ (void) setConversationsBarButtonImage:(NSString *)name;

/**
 *  设置右侧NavBarButton的内容
 *
 *  @param title 内容
 */
+ (void) setConversationsBarButtonTitle:(NSString *)title;

/**
 *  设置右侧NavBarButton显示方式
 *
 *  @param type 显示方式,默认为KFNavBarConversationsUITypeLocalizedLabel
 */
+ (void) setNavBarConversationsUIType:(KFNavBarConversationsUIType)type;


@end
