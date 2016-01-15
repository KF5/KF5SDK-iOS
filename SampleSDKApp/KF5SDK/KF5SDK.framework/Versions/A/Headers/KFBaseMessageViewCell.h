//
//  KFChatTableViewCell.h
//  KF5ChatSDK
//
//  Created by admin on 15/11/5.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KF5BaseTableViewCell.h"

@class KFMessage;

@interface KFBaseMessageViewCell : KF5BaseTableViewCell
/**
 *  头像
 */
@property (nonatomic, weak) UIImageView *headerImageView;
/**
 *  信息内容按钮
 */
@property (nonatomic, weak) UIView *chatMessageView;
/**
 *  messageStatueView
 */
@property (nonatomic, weak) UIView *messageStatueView;

/**
 *  聊天内容
 */
@property (nonatomic, strong) KFMessage *chatMessage;


@end