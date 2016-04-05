//
//  KFBaseChatMessageViewCell.h
//  Pods
//
//  Created by admin on 16/3/18.
//
//

#import "KF5BaseTableViewCell.h"

#import "KFMessage.h"

@interface KFBaseChatMessageViewCell : KF5BaseTableViewCell

/**
 *  聊天内容
 */
@property (nonatomic, strong,readonly) KFMessage *chatMessage;

- (void)setChatMessage:(KFMessage *)chatMessage prevChatMessage:(KFMessage *)prevChatMessage;

@end
