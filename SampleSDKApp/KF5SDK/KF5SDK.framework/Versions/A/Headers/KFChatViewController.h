//
//  ViewController.h
//  KF5ChatSDK
//
//  Created by admin on 15/11/5.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KF5BaseViewController.h"

#import "KFDispatcher.h"

@interface KFChatViewController : KF5BaseViewController
/**
 *  右侧的按钮
 */
@property (nonatomic, strong) UIBarButtonItem *rightButtonItem;
/**
 *  是否隐藏右侧按钮,默认NO
 */
@property (nonatomic, assign) BOOL isHideRightButton;
/**
 *  当退出KFChatViewController时是否断开连接,默认为YES
 *
 *  如果设置为NO,则需要在合适的位置调用[[KFChatManager sharedChatManager] setUserOffline]方法关闭与服务器的连接
 */
@property (nonatomic, assign) BOOL isDisConnectWhenDelloc;

/**
 *  当没有客服在线时,弹出alertView显示的title,默认为"当前没有客服在线,请提交留言"
 */
@property (nonatomic, copy) NSString *noAgentAlertShowTitle;
/**
 *  当没有客服在线弹出alertView,点击"确定"按钮的事件处理,默认跳转到反馈工单界面
 */
@property (nonatomic, copy) KFAlertActionBlock noAgentAlertActionBlock;

#pragma mark nav导航栏文字设置

/**
 *  正在连接服务器时nav导航栏显示的文字,默认为"正在连接..."
 */
@property (nonatomic, copy) NSString *connectingShowTitle;
/**
 *  连接服务器失败时nav导航栏显示的文字,默认为"未连接"
 */
@property (nonatomic, copy) NSString *connectErrorShowTitle;
/**
 *  正在分配客服时nav导航栏显示的文字,默认为"正在分配客服..."
 */
@property (nonatomic, copy) NSString *getAgentingShowTitle;
/**
 *  当分配客服失败时nav导航栏显示的文字,默认为"当前没有客服在线"
 */
@property (nonatomic, copy) NSString *noAgentShowTitle;
/**
 *  当客服结束会话时nav导航栏显示的文字,默认为"会话已结束"
 */
@property (nonatomic, copy) NSString *chatEndShowTitle;

@end

