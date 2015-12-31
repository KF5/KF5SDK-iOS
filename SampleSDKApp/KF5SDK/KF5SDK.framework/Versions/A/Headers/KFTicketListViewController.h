//
//  KFTicketListViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/3.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KF5BaseTableViewController.h"

#import "KFDispatcher.h"

@interface KFTicketListViewController : KF5BaseTableViewController
/**
 *  刷新界面
 */
- (void)headerRefresh;

@property (nonatomic, copy) KFBarButtonActionBlock actionBlock;

@end
