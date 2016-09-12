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
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * tableView的背景颜色
 */
@property (nonatomic, strong) UIColor *tableBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * searchbar的UIBarstyle
 */
@property (nonatomic, strong) NSNumber *searchBarStyle UI_APPEARANCE_SELECTOR;

/**
 * tableView的separator颜色
 */
@property (nonatomic, strong) UIColor *separatorColor UI_APPEARANCE_SELECTOR;


#pragma mark noResultsFoundLabel appearance

/**
 * noResultsFoundLabel的字体
 */
@property (nonatomic, strong) UIFont *noResultsFoundLabelFont UI_APPEARANCE_SELECTOR;

/**
 * noResultsFoundLabel的颜色
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelColor UI_APPEARANCE_SELECTOR;

/**
 *  noResultsFoundLabel的提示内容
 */
@property (nonatomic, strong) NSString *noResultsFoundLabelText UI_APPEARANCE_SELECTOR;

/**
 * noResultsFoundLabel的背景颜色
 */
@property (nonatomic, strong) UIColor *noResultsFoundLabelBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 *  cellTextLabel的字体
 */
@property (nonatomic, strong) UIFont *cellTextLabelFont UI_APPEARANCE_SELECTOR;
/**
 *  cellTextLabel的颜色
 */
@property (nonatomic, strong) UIColor *cellTextLabelColor UI_APPEARANCE_SELECTOR;
/**
 *  cell的背景颜色
 */
@property (nonatomic, strong) UIColor *cellBackgroundColor;

@end
