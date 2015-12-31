//
//  KFTicketViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/3.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KF5BaseViewController.h"

@interface KFTicketViewController : KF5BaseViewController
/**
 *  初始化方法
 *
 *  @param ticket_id 工单id
 *  @param isClose   工单是否为已关闭工单
 */
- (instancetype)initWithTicket_id:(NSString *)ticket_id isClose:(BOOL)isClose;

@end
