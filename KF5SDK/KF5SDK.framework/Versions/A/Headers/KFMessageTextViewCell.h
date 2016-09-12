//
//  KFChatTableTextViewCell.h
//  Pods
//
//  Created by admin on 15/11/25.
//
//

#import "KFBaseContentMessageViewCell.h"

@interface KFMessageTextViewCell : KFBaseContentMessageViewCell<UIAppearance>

#pragma mark - UIAppearance
/**
 *  Label的字体
 */
@property (nonatomic, strong) UIFont *messageForLabelFont UI_APPEARANCE_SELECTOR;


/**
 *  普通用户消息Label的颜色
 */
@property (nonatomic, strong) UIColor *messageForMeLabelColor UI_APPEARANCE_SELECTOR;
/**
 *  普通用户消息Label中链接的颜色
 */
@property (nonatomic, strong) UIColor *messageForMeLabelUrlColor UI_APPEARANCE_SELECTOR;

/**
 *  客服消息Label的颜色
 */
@property (nonatomic, strong) UIColor *messageForOtherLabelColor UI_APPEARANCE_SELECTOR;
/**
 *  客服消息Label中链接的颜色
 */
@property (nonatomic, strong) UIColor *messageForOtherLabelUrlColor UI_APPEARANCE_SELECTOR;



@end
