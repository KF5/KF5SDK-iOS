//
//  KFTicketListView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KFTicketListView : UIView <UIAppearance>

#pragma mark cell appearance

/**
 * cell contentLabel的字体
 */
@property (nonatomic, strong) UIFont *cellContentFont UI_APPEARANCE_SELECTOR;

/**
 * cell contentLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellContentColor UI_APPEARANCE_SELECTOR;

/**
 * cell timeLabel的字体
 */
@property (nonatomic, strong) UIFont *cellTimeFont UI_APPEARANCE_SELECTOR;

/**
 * cell timeLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellTimeColor UI_APPEARANCE_SELECTOR;

/**
 * cell statusLabel的字体
 */
@property (nonatomic, strong) UIFont *cellStatusFont UI_APPEARANCE_SELECTOR;

/**
 * cell statusLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellStatusColor UI_APPEARANCE_SELECTOR;
/**
 *  是否隐藏statusLabel，默认不隐藏
 */
@property (nonatomic, strong) NSNumber *isHiddenStatusLabel UI_APPEARANCE_SELECTOR;
/**
 * tableView的背景颜色
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor UI_APPEARANCE_SELECTOR;
/**
 * cell的背景颜色
 */
@property (nonatomic, strong) UIColor *cellBackgroundColor;

/**
 * tableView seperator的颜色
 */
@property (nonatomic, strong) UIColor *separatorColor UI_APPEARANCE_SELECTOR;


#pragma mark noResultsFoundLabel appearance

/**
 * noResultsLabel的字体
 */
@property (nonatomic, strong) UIFont *noResultsLabelFont UI_APPEARANCE_SELECTOR;

/**
 * noResultsLabel的颜色
 */
@property (nonatomic, strong) UIColor *noResultsLabelColor UI_APPEARANCE_SELECTOR;

/**
 * noResultsLabel的内容
 */
@property (nonatomic, strong) NSString *noResultsLabelText UI_APPEARANCE_SELECTOR;

/**
 * noResultsLabel的背景颜色
 */
@property (nonatomic, strong) UIColor *noResultsLabelBackgroundColor UI_APPEARANCE_SELECTOR;

@end
