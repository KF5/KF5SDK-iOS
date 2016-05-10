//
//  KFDocumentView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface KFHelpCenterListView : UIView <UIAppearance>

#pragma mark - View Appearance

/**
 * view的背景颜色
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor;

/**
 * tableView的背景颜色
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor;

/**
 * searchbar的UIBarstyle
 */
@property (nonatomic, strong) NSNumber *searchBarStyle;

/**
 * tableView的separator颜色
 */
@property (nonatomic, strong) UIColor *separatorColor;


#pragma mark noResultsFoundLabel appearance

/**
 * noResultsFoundLabel的字体
 */
@property (nonatomic, strong) UIFont *noResultsFoundLabelFont;

/**
 * noResultsFoundLabel的颜色
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelColor;

/**
 *  noResultsFoundLabel的提示内容
 */
@property (nonatomic, strong) NSString *noResultsFoundLabelText;

/**
 * noResultsFoundLabel的背景颜色
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelBackgroundColor;

/**
 *  cellTextLabel的字体
 */
@property (nonatomic, strong) UIFont *cellTextLabelFont;
/**
 *  cellTextLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellTextLabelColor;

@end
