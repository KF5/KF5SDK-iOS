//
//  ViewController.h
//  KF5ChatSDK
//
//  Created by admin on 15/11/5.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KF5BaseViewController.h"

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
 *  当退出KFChatViewController时是否断开连接,默认为NO
 */
@property (nonatomic, assign) BOOL isDisconnectWhenDelloc;

@end

