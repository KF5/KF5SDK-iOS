//
//  KF5.h
//  SampleSDKApp
//
//  Created by admin on 15/2/3.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KFUser.h"


@interface KF5 : NSObject

#pragma mark 初始化认证信息
+ (instancetype)sharedKF5;
/**
 *  初始化域名和通信秘钥
 *
 *  @param HostName 云客服平台域名
 *  @param token    通信秘钥
 */
- (void)initializeWithHostName:(NSString *)hostName token:(NSString *)token;
/**
 *  设置用户邮箱和用户名
 */
- (void)setEmail:(NSString *)email andUserName:(NSString *)userName;

#pragma mark 知识库控制器
/**
 *  显示知识库分区控制器,带分区列表、分区下的分类列表、分类下的文档列表
 *
 *  @param viewConrtoller 通过viewConrtoller推出知识库分区控制器
 */
+ (void)showDocumentListWithViewController:(UIViewController *)viewController;
/**
 *  显示知识库分类控制器,带所有分类列表、分类下的文档列表
 *
 *  @param viewConrtoller 通过viewConrtoller推出知识库分类控制器
 */
+ (void)showForumListWithViewController:(UIViewController *)viewController;
/**
 *  显示知识库文档列表控制器,只有所有文档列表
 *
 *  @param viewConrtoller viewConrtoller推出知识库控制器
 */
+ (void)showPostWithViewController:(UIViewController *)viewController;

#pragma mark 工单控制器

/**
 *  显示工单反馈列表控制器
 *
 *  @param viewConrtoller viewConrtoller推出工单反馈列表控制器
 */
+ (void)showTicketListWithViewController:(UIViewController *)viewController;
/**
 *  显示工单反馈控制器
 *
 *  @param viewConrtoller 通过viewConrtoller弹出工单反馈控制器
 */
+ (void)showRequestViewWithViewController:(UIViewController *)viewController;

/**
 *  全局tabBar颜色
 */
@property (nonatomic, strong) UIColor *tabBarColor;
/**
 *  全局tabBarItem标题颜色
 */
@property (nonatomic, strong) UIColor *tabBarItemColor;
/**
 *  全局tabBarItem标题样式
 */
@property (nonatomic, strong) NSDictionary *titleTextAttributes;

#pragma mark - 设置文档样式
/**
 *  文档控制器导航栏右侧按钮图标
 */
@property (nonatomic, copy) NSString *docRightBarBtnImageName;
/**
 *  文档控制器导航栏右侧按钮文字
 */
@property (nonatomic, copy) NSString *docRightBarBtnTitleName;
/**
 *  文档列表文字的字体
 */
@property (nonatomic, strong) UIFont *docLabelFont;
/**
 *  文档列表文字的颜色
 */
@property (nonatomic, strong) UIColor *docLabelColor;
/**
 *  工单列表文字的字体
 */
@property (nonatomic, strong) UIColor *ticketListLabelFont;
/**
 *  工单列表文字的颜色
 */
@property (nonatomic, strong) UIColor *ticketListLabelColor;


#pragma mark 工单反馈样式
/**
 *  工单反馈提示文字内容
 */
@property (nonatomic, copy) NSString *requestTextViewPlaceholderText;
/**
 *  工单反馈提示文字颜色
 */
@property (nonatomic, strong) UIColor *requestTextViewPlaceholderTextColor;
/**
 *  工单反馈文字字体
 */
@property (nonatomic, strong) UIFont *requestTextViewTextFont;
/**
 *  工单反馈文字颜色
 */
@property (nonatomic, strong) UIColor *requestTextViewTextColor;
/**
 *  工单反馈tabBar标题
 */
@property (nonatomic, copy) NSString *requestTabBarTitle;

/**
 *  用户数据
 */
@property (nonatomic, strong,readonly) KFUser *user;

#pragma mark 反馈内容页样式
/**
 *  反馈内容昵称颜色
 */
@property (nonatomic, strong) UIColor *ticketNameColor;
/**
 *  反馈内容昵称字体
 */
@property (nonatomic, strong) UIFont *ticketNameFont;
/**
 *  反馈内容时间颜色
 */
@property (nonatomic, strong) UIColor *ticketTimeColor;
/**
 *  反馈内容时间字体
 */
@property (nonatomic, strong) UIFont *ticketTimeFont;
/**
 *  反馈内容颜色
 */
@property (nonatomic, strong) UIColor *ticketContentColor;
/**
 *  反馈内容字体
 */
@property (nonatomic, strong) UIFont *ticketContentFont;
/**
 *  反馈内容页客服头像
 */
@property (nonatomic, strong) UIImage *ticketAgentImage;
/**
 *  反馈内容页用户头像
 */
@property (nonatomic, strong) UIImage *ticketUserImage;


@end
