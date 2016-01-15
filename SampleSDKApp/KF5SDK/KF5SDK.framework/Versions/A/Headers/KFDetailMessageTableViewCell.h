//
//  KFDetailMessageTableViewCell.h
//  SampleSDKApp
//
//  Created by admin on 15/9/23.
//  Copyright © 2015年 admin. All rights reserved.
//

#import "KF5BaseTableViewCell.h"

@interface KFDetailMessageTableViewCell : KF5BaseTableViewCell<UIAppearance>
/**
 *  标题
 */
@property (nonatomic, weak) UILabel *titleLabel;
/**
 *  内容
 */
@property (nonatomic, weak) UILabel *contentLabel;

/**
 * titleLabel的字体
 */
@property (nonatomic, strong) UIFont *titleFont;

/**
 * titleLabel的颜色
 */
@property (nonatomic, strong) UIColor *titleColor;

/**
 * contentLabel的字体
 */
@property (nonatomic, strong) UIFont *contentFont;

/**
 * contentLabel的颜色
 */
@property (nonatomic, strong) UIColor *contentColor;
/**
 * cell的背景颜色
 */
@property (nonatomic, strong) UIColor *cellBackgroundColor;

@end
