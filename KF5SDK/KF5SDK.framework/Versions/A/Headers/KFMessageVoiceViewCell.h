//
//  KFChatMessageVoiceViewCell.h
//  Pods
//
//  Created by admin on 15/11/25.
//
//

#import "KFBaseContentMessageViewCell.h"

@interface KFMessageVoiceViewCell : KFBaseContentMessageViewCell<UIAppearance>

#pragma mark - UIAppearance
/**
 *  button的字体
 */
@property (nonatomic, strong) UIFont *voiceForButtonFont UI_APPEARANCE_SELECTOR; 


/**
 *  普通用户语音button的颜色
 */
@property (nonatomic, strong) UIColor *voiceForMeButtonColor UI_APPEARANCE_SELECTOR;

/**
 *  客服语音button的颜色
 */
@property (nonatomic, strong) UIColor *voiceForOtherButtonColor UI_APPEARANCE_SELECTOR;
@end
