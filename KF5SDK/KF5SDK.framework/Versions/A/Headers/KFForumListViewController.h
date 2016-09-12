//
//  KFForumListViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/4.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KFDocBaseViewController.h"

@interface KFForumListViewController : KFDocBaseViewController
/**
 *  初始化方法
 *
 *  @param category 分区id
 *
 */
- (instancetype)initWithCategory:(KFDocItem *)category;

@end
