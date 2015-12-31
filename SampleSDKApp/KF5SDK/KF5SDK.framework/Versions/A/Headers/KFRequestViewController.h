//
//  KFRequestViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/3.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KF5BaseViewController.h"

#import "KFDispatcher.h"

@interface KFRequestViewController : KF5BaseViewController

/**
 *  提交工单时添加的自定义工单字段数组
 */
@property (nonatomic, strong) NSDictionary *fieldDict;

/**
 *  初始化方法
 *
 *  @param fieldDict 工单自定义字段
 *  @param success   请求成功的回调
 *  @param error     请求失败的回调
 */
- (instancetype)initWithFieldDict:(NSDictionary *)fieldDict Success:(KFAPISuccess)success andError:(KFAPIError)error;

@end
