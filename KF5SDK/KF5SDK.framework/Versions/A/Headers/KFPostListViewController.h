//
//  KFPostListViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/5.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KFDocBaseViewController.h"

@interface KFPostListViewController : KFDocBaseViewController
/**
 *  初始化方法
 *
 *  @param forum 分类id
 *
 */
- (instancetype)initWithForum:(KFDocItem *)forum;

@end
