//
//  KFChatMessageVoiceViewCell.h
//  Pods
//
//  Created by admin on 15/11/25.
//
//

#import "KFBaseMessageViewCell.h"

@interface KFMessageVoiceViewCell : KFBaseMessageViewCell<UIAppearance>

#pragma mark - UIAppearance
/**
 *  普通用户语音button的颜色
 */
@property (nonatomic, strong) UIColor *voiceForMeButtonColor;
/**
 *  普通用户语音button的字体
 */
@property (nonatomic, strong) UIFont *voiceForMeButtonFont;

/**
 *  客服语音button的颜色
 */
@property (nonatomic, strong) UIColor *voiceForOtherButtonColor;
/**
 *  客服语音button的字体
 */
@property (nonatomic, strong) UIFont *voiceForOtherButtonFont;

@end
