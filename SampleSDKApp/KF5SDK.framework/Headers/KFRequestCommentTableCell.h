//
//  KFWorkListCell.h
//  云客服
//
//  Created by admin on 15/1/29.
//  Copyright (c) 2015年 Hydom. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface KFRequestCommentTableCell : UITableViewCell

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
@property (nonatomic, strong) UITextView *ctnTextView;

/**
 *  头像
 */
@property (nonatomic, strong) UIImage *headerImage;

/**
 * avatar的image
 */
@property (nonatomic, strong) UIImage *avatar;

/**
 * 附件之间的间距
 */
@property (nonatomic, strong) NSNumber *avatarSpace;

/**
 * nameLabel的字体
 */
@property (nonatomic, strong) UIFont *nameLabelFont;

/**
 * nameLabel的颜色
 */
@property (nonatomic, strong) UIColor *nameLabelColor;

/**
 * contentLabel的字体
 */
@property (nonatomic, strong) UIFont *contentFont;

/**
 * contentLabel的颜色
 */
@property (nonatomic, strong) UIColor *contentColor;

/**
 * timeLabel的字体
 */
@property (nonatomic, strong) UIFont *timeLabelFont;

/**
 * timeLabel的颜色
 */
@property (nonatomic, strong) UIColor *timeLabelColor;

/**
 * cell的背景颜色
 */
@property (nonatomic, strong) UIColor *cellBackground;

@end


#pragma mark - agent

@interface KFAgentCommentTableCell : KFRequestCommentTableCell<UIAppearance>


@end

@interface KFEndUserCommentTableCell : KFRequestCommentTableCell<UIAppearance>


@end