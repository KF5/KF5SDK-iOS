//
//  KFAgent.h
//  Pods
//
//  Created by admin on 15/12/23.
//
//

#import <Foundation/Foundation.h>
#import "KFDispatcher.h"

@interface KFAgent : NSObject
/**
 *  客服的id
 */
@property (nonatomic, assign) int Id;
/**
 *  客服的头像
 */
@property (nonatomic, copy) NSString *photo;
/**
 *  客服的昵称
 */
@property (nonatomic, copy) NSString *displayName;
/**
 *  客服角色(人工客服/机器人客服)
 */
@property (nonatomic, assign) KFAgentRole agentRole;

@end

