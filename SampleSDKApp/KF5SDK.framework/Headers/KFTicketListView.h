//
//  KFTicketListView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KFTicketListView : UIView<UIAppearance>

#pragma mark cell appearance

/**
 * cell contentLabel的字体
 */
@property (nonatomic, strong) UIFont *cellcontentFont;

/**
 * cell contentLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellcontentColor;

/**
 * cell timeLabel的字体
 */
@property (nonatomic, strong) UIFont *cellTimeFont;

/**
 * cell timeLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellTimeColor;

/**
 * tableView的背景颜色
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor;

/**
 * tableView seperator的颜色
 */
@property (nonatomic, strong) UIColor *separatorColor;


#pragma mark noResultsFoundLabel appearance

/**
 * noResultsLabel的字体
 */
@property (nonatomic, strong) UIFont *noResultsLabelFont;

/**
 * noResultsLabel的颜色
 */
@property (nonatomic, strong) UIColor *noResultsLabelColor;

/**
 * noResultsLabel的颜色
 */
@property (nonatomic, strong) NSString *noResultsLabelText;

/**
 * noResultsLabel的背景颜色
 */
@property (nonatomic, strong) UIColor *noResultsLabelBackground;

@end
