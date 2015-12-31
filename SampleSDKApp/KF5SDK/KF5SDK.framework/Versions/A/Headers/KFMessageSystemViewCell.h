//
//  KFChatMessageSystemViewCell.h
//  Pods
//
//  Created by admin on 15/12/23.
//
//

#import "KFBaseMessageViewCell.h"

@interface KFMessageSystemViewCell : KFBaseMessageViewCell

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

@end
