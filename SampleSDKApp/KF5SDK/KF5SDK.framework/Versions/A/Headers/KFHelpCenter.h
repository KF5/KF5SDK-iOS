//
//  KFHelpCenter.h
//  SampleSDKApp
//
//  Created by admin on 15/3/31.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "KFDispatcher.h"


@interface KFHelpCenter : NSObject

+ (instancetype)sharedHelpCenter;
/**
 * rightBarButtonItem的显示方式
 */
@property (nonatomic, assign) KFNavBarUIType rightBarType;
/**
 *  rightBarButtonItem的图片名称
 */
@property (nonatomic, strong) NSString *rightImageName;
/**
 *  rightBarButtonItem的标题名称
 */
@property (nonatomic, strong) NSString *rightTitle;
/**
 *  第一个控制器是否使用present的方式展现
 */
@property (nonatomic, assign) BOOL isPresent;
/**
 *  第一个控制器的title
 */
@property (nonatomic, strong) NSString *firstNavigationItemTitle;

/**
 *  push知识库文档控制器
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 */
+ (void)showHelpCenterWithNavController:(UINavigationController*)navController
                         helpCenterType:(KFHelpCenterType)helpCenterType;
/**
 *  push知识库文档控制器(带actionBlock)
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 *  @param actionBlock    点击navBar右侧按钮的事件处理，为NULL直接跳转到工单列表
 */
+ (void)showHelpCenterWithNavController:(UINavigationController*)navController
                         helpCenterType:(KFHelpCenterType)helpCenterType rightBarButtonActionBlock:(KFBarButtonActionBlock)actionBlock;

/**
 *  present知识库文档控制器
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController*)navController
                             helpCenterType:(KFHelpCenterType)helpCenterType;

/**
 *  present知识库文档控制器(带actionBlock)
 *
 *  @param navController  当前的navController
 *  @param helpCenterType 展示方式
 *  @param actionBlock    点击navBar右侧按钮的事件处理，为NULL直接跳转到工单列表
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController*)navController
                             helpCenterType:(KFHelpCenterType)helpCenterType rightBarButtonActionBlock:(KFBarButtonActionBlock)actionBlock;


#pragma mark - 导航栏显示初始化
/**
 *  设置右侧NavBarButton显示方式
 *
 *  @param type 显示方式,默认为KFNavBarUITypeLocalizedLabel
 */
+ (void) setNavBarConversationsUIType:(KFNavBarUIType)type;
/**
 *  设置右侧NavBarButton的内容(自动设置显示方式为KFNavBarUITypeLocalizedLabel)
 *
 *  @param title 内容
 */
+ (void) setConversationsBarButtonTitle:(NSString *)title;
/**
 *  设置右侧NavBarButton的image(自动设置显示方式为KFNavBarUITypeImage)
 *
 *  @param name 图片名称
 */
+ (void) setConversationsBarButtonImage:(NSString *)name;

/**
 *  设置首个文档控制器标题,如选择KFHelpCenterTypeDocument,则设置的是文档分区的title
 *
 *  @param title 标题
 */
+ (void) setFirstNavigationItemTitle:(NSString *)title;

@end
