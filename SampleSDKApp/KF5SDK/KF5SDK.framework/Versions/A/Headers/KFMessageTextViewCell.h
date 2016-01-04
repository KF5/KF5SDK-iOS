//
//  KFChatTableTextViewCell.h
//  Pods
//
//  Created by admin on 15/11/25.
//
//

#import "KFBaseMessageViewCell.h"

@interface KFMessageTextViewCell : KFBaseMessageViewCell<UIAppearance>

#pragma mark - UIAppearance

/**
 *  普通用户消息Label的颜色
 */
@property (nonatomic, strong) UIColor *messageForMeLabelColor;
/**
 *  普通用户消息Label的字体
 */
@property (nonatomic, strong) UIFont *messageForMeLabelFont;

/**
 *  客服消息Label的颜色
 */
@property (nonatomic, strong) UIColor *messageForOtherLabelColor;
/**
 *  客服消息Label的字体
 */
@property (nonatomic, strong) UIFont *messageForOtherLabelFont;

@end
