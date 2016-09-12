//
//  KFChatTableViewCell.h
//  KF5ChatSDK
//
//  Created by admin on 15/11/5.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KFBaseChatMessageViewCell.h"


@interface KFBaseContentMessageViewCell : KFBaseChatMessageViewCell<UIAppearance>

- (void)setMessageStatus:(KFMessageStatus)messageStatus;

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
 *  时间
 */
@property (nonatomic, weak) UILabel *timeLabel;

#pragma mark - UIAppearance
/**
 *  systemLabel文字颜色
 */
@property (nonatomic, strong) UIColor *timeLabelTextColor UI_APPEARANCE_SELECTOR;
/**
 *  systemLabel字体大小
 */
@property (nonatomic, strong) UIFont *timeLabelFont UI_APPEARANCE_SELECTOR;
/**
 *  客服头像图片
 */
@property (nonatomic, strong) UIImage *agentImage UI_APPEARANCE_SELECTOR;
/**
 *  访客头像
 */
@property (nonatomic, strong) UIImage *visitorImage UI_APPEARANCE_SELECTOR;

@end