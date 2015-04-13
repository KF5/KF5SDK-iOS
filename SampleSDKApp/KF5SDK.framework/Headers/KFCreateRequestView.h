//
//  KFCreateRequestView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface KFCreateRequestView : UIView<UIAppearance>

/**
 * placeholder的颜色
 */
@property (nonatomic, strong) UIColor *placeholderTextColor;

/**
 * placeholder的内容
 */
@property (nonatomic, strong) NSString *placeholderText;

/**
 * textView的颜色
 */
@property (nonatomic, strong) UIColor *textViewColor;

/**
 * textView的背景颜色
 */
@property (nonatomic, strong) UIColor *textViewBackgroundColor;

/**
 * textView的字体
 */
@property (nonatomic, strong) UIFont *textViewFont;

/**
 * view的背景颜色
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor;

/**
 *  AttachmentButton的图片
 */
@property (nonatomic, strong) UIImage *attachmentButtonImage;

/**
 *  textView的高度
 */
@property (nonatomic, readonly, assign) CGFloat textViewHeight;

@end
