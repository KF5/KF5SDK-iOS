//
//  KFWorkListCell.h
//  云客服
//
//  Created by admin on 15/1/29.
//  Copyright (c) 2015年 Hydom. All rights reserved.
//
#import "KF5BaseTableViewCell.h"

@interface KFRequestCommentTableCell : KF5BaseTableViewCell<UIAppearance>

/**
 *  头像
 */
@property (nonatomic, strong) UIImageView *headImageView;

/**
 *  时间
 */
@property (nonatomic, strong) UILabel *timeLabel;

/**
 *  角色
 */
@property (nonatomic, strong) UILabel *nameLabel;

/**
 *  内容
 */
@property (nonatomic, strong) UILabel *ctnLabel;

#pragma mark - UIAppearance

/**
 *  头像
 */
@property (nonatomic, strong) UIImage *headerImage UI_APPEARANCE_SELECTOR;

/**
 * avatar的image
 */
@property (nonatomic, strong) UIImage *avatar UI_APPEARANCE_SELECTOR;

/**
 * 附件之间的间距
 */
@property (nonatomic, strong) NSNumber *avatarSpace UI_APPEARANCE_SELECTOR;

/**
 * nameLabel的字体
 */
@property (nonatomic, strong) UIFont *nameLabelFont UI_APPEARANCE_SELECTOR;

/**
 * nameLabel的颜色
 */
@property (nonatomic, strong) UIColor *nameLabelColor UI_APPEARANCE_SELECTOR;

/**
 * contentLabel的字体
 */
@property (nonatomic, strong) UIFont *contentFont UI_APPEARANCE_SELECTOR;

/**
 * contentLabel的颜色
 */
@property (nonatomic, strong) UIColor *contentColor UI_APPEARANCE_SELECTOR;
/**
 * contentLabel链接的颜色
 */
@property (nonatomic, strong) UIColor *urlColor UI_APPEARANCE_SELECTOR;

/**
 * timeLabel的字体
 */
@property (nonatomic, strong) UIFont *timeLabelFont UI_APPEARANCE_SELECTOR;

/**
 * timeLabel的颜色
 */
@property (nonatomic, strong) UIColor *timeLabelColor UI_APPEARANCE_SELECTOR;

/**
 * cell的背景颜色
 */
@property (nonatomic, strong) UIColor *cellBackgroundColor UI_APPEARANCE_SELECTOR;

@end


#pragma mark - agent

@interface KFAgentCommentTableCell : KFRequestCommentTableCell<UIAppearance>


@end

@interface KFEndUserCommentTableCell : KFRequestCommentTableCell<UIAppearance>


@end