//
//  KFDetailMessageViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/9/21.
//  Copyright © 2015年 admin. All rights reserved.
//

#import "KF5BaseTableViewController.h"

@interface KFDetailMessageViewController : KF5BaseTableViewController
/**
 *  初始化方法
 *
 *  @param ticket_id 工单的id
 */
- (instancetype)initWithTicket_id:(NSString *)ticket_id;

@end
