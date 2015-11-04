//
//  KFPostView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/7.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KFPostView : UIView<UIAppearance>

/**
 *  titleLabel的颜色,以十六进制颜色为准,如:181818
 */
@property (nonatomic, strong) NSString *titleColor;

/**
 *  titleLabel的字体大小
 */
@property (nonatomic, strong) NSNumber *titleFontSize;

/**
 *  titleLabel的字体名称
 */
@property (nonatomic, strong) NSString *titleFontName;

/**
 *  timeLabel的颜色,以十六进制颜色为准,如:505050
 */
@property (nonatomic, strong) NSString *timeColor;

/**
 *  timeLabel的字体大小
 */
@property (nonatomic, strong) NSNumber *timeFontSize;

/**
 *  timeLabel的字体名称
 */
@property (nonatomic, strong) NSString *timeFontName;

/**
 *  contentLabel的颜色,以十六进制颜色为准,如:333333
 */
@property (nonatomic, strong) NSString *contentColor;

/**
 *  contentLabel的字体大小
 */
@property (nonatomic, strong) NSNumber *contentFontSize;

/**
 *  contentLabel的字体名称
 */
@property (nonatomic, strong) NSString *contentFontName;

/**
 *  link的字体大小
 */
@property (nonatomic, strong) NSNumber *linkFontSize;

/**
 *  link的颜色,以十六进制颜色为准,如:333333
 */
@property (nonatomic, strong) NSString *linkColor;

/**
 *  link的字体名称
 */
@property (nonatomic, strong) NSString *linkFontName;

/**
 *  左右间距
 */
@property (nonatomic, strong) NSNumber *spacingLeftRight;

/**
 *  上下间距
 */
@property (nonatomic, strong) NSNumber *spacingTopBottom;

/**
 *  行间距倍数
 */
@property (nonatomic, strong) NSNumber *lineHeight;

@end
