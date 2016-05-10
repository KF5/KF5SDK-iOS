//
//  KFDocBaseViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/5.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KF5BaseViewController.h"

#import "KFDispatcher.h"

@class KFHelpCenterListView;
@class KFDocItem;

@interface KFDocBaseViewController : KF5BaseViewController

@property (nonatomic, weak) UISearchBar *searchBar;

@property (nonatomic, weak) UITableView *tableView;
/**
 *  搜索到的文章列表
 */
@property (nonatomic, strong,readonly) NSArray *searchList;
/**
 *  当前显示列表项
 */
@property (nonatomic, strong,readonly) NSMutableArray *DocList;
/**
 *  服务器列表总数
 */
@property (nonatomic, assign,readonly) NSInteger count;
/**
 *  控制器的类型
 */
@property (nonatomic, assign) KFHelpCenterType type;
/**
 *  上一级列表项
 */
@property (nonatomic, strong) KFDocItem *superItem;
/**
 *  每页的数量
 */
@property (nonatomic, copy) NSString *pre_page;
/**
 *  点击navBar右侧按钮的事件处理,默认跳转到工单列表
 */
@property (nonatomic, copy) KFBarButtonActionBlock actionBlock;

@end
