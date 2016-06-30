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
 *  当没有客服在线时是否弹出alertView,默认为YES
 *
 *  注:当设置为NO时,noAgentAlertShowTitle,agentBusyAlertShowTitle和noAgentAlertActionBlock将失效
 */
@property (nonatomic, assign) BOOL isShowAlertWhenNoAgent;
/**
 *  当没有客服在线时,弹出alertView显示的title,默认为"当前没有客服在线,请提交留言"
 */
@property (nonatomic, copy) NSString *noAgentAlertShowTitle;
/**
 *  当没有客服在线或取消排队留言时,弹出alertView,点击"确定"按钮的事件处理,默认跳转到反馈工单界面
 */
@property (nonatomic, copy) void (^noAgentAlertActionBlock)() ;
/**
 *  当在用户在排队时,弹出alertView显示的title,默认为"是否取消排队并留言"
 *
 * @warning 如果在排队中,出现alertView,点击确定会取消排队,所以在自定义时需明确提示给用户.
            alertView的点击事件使用noAgentAlertActionBlock属性.
 */
@property (nonatomic, copy) NSString *leaveMessageAlertShowTitle;
/**
 *  当客服请求进行满意度评价时的提示文字,默认:"感谢使用我们的服务,请为此次服务评价:"
 */
@property (nonatomic, copy) NSString *ratingAlertTitle;
/**
 *  当用户点击评价后的系统提示文字,默认:"感谢您的评价!"
 *
 *  注:该系统提示不保存到数据库
 */
@property (nonatomic, copy) NSString *ratingFinishSystemTitle;

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
 *  正在排队时nav导航栏显示的文字,默认为"排队中..."
 */
@property (nonatomic, copy) NSString *queueUpShowTitle;
/**
 *  当分配客服失败或没有客服在线时nav导航栏显示的文字,默认为"当前没有客服在线"
 */
@property (nonatomic, copy) NSString *noAgentShowTitle;
/**
 *  当客服结束对话时nav导航栏显示的文字,默认为"对话已结束"
 */
@property (nonatomic, copy) NSString *chatEndShowTitle;


#pragma mark deprecated
/**
 *  正在分配客服时nav导航栏显示的文字,默认为"正在分配客服..."
 */
@property (nonatomic, copy) NSString *getAgentingShowTitle __deprecated_msg("该变量已被弃用,连接到服务器后,第一步会加入排队,请使用queueUpShowTitle");

@end

