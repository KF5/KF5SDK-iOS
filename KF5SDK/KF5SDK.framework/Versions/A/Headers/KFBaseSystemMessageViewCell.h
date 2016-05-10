//
//  KFChatMessageSystemViewCell.h
//  Pods
//
//  Created by admin on 15/12/23.
//
//

#import "KFBaseChatMessageViewCell.h"

@interface KFBaseSystemMessageViewCell : KFBaseChatMessageViewCell<UIAppearance>
/**
 *  systemLabel背景
 */
@property (nonatomic, weak) UIView *systemBackgroundView;
/**
 *  systemLabel
 */
@property (nonatomic, weak) UILabel *systemLabel;
/**
 *  systemContent
 */
@property (nonatomic, copy) NSString *systemContent;

#pragma mark - UIAppearance
/**
 *  systemLabel背景颜色
 */
@property (nonatomic, strong) UIColor *systemBackgroundColor;
/**
 *  systemLabel文字颜色
 */
@property (nonatomic, strong) UIColor *systemLabelTextColor;
/**
 *  systemLabel字体大小
 */
@property (nonatomic, strong) UIFont *systemLabelFont;

@end
