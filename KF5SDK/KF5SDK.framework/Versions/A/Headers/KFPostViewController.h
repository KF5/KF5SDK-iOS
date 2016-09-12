//
//  KFPostViewController.h
//  SampleSDKApp
//
//  Created by admin on 15/2/5.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KF5BaseViewController.h"
#import "KFDocItem.h"

@interface KFPostViewController : KF5BaseViewController
/**
 *  是否允许刷新
 */
@property (nonatomic, assign) BOOL isHasRefresh;
/**
 *  加载css,默认加载KFBaseDocument.css和KFUserDocument.css,用户可修改KFUserDocument.css,也可以自定义
 *
 *  @param name css名称
 */
- (void)loadCssWithName:(NSString *)name;
/**
 *  初始化方法
 *
 *  @param post 文档id
 */
- (instancetype)initWithPost:(KFDocItem *)post;

@end
