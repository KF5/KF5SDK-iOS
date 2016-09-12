//
//  KFCreateRequestView.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KFCreateRequestView : UIScrollView<UIAppearance>

@property (nonatomic, strong) UITextView *textView;

@property (nonatomic, weak) UIButton *attBtn;

@property (nonatomic, readonly, assign) CGFloat textViewHeight;

#pragma mark - UIAppearance

/**
 * placeholder的颜色
 */
@property (nonatomic, strong) UIColor *placeholderTextColor UI_APPEARANCE_SELECTOR;

/**
 * placeholder的内容
 */
@property (nonatomic, strong) NSString *placeholderText UI_APPEARANCE_SELECTOR;

/**
 * textView的颜色
 */
@property (nonatomic, strong) UIColor *textViewColor UI_APPEARANCE_SELECTOR;

/**
 * textView的背景颜色
 */
@property (nonatomic, strong) UIColor *textViewBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * textView的字体
 */
@property (nonatomic, strong) UIFont *textViewFont UI_APPEARANCE_SELECTOR;

/**
 * view的背景颜色
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 *  AttachmentButton的图片
 */
@property (nonatomic, strong) UIImage *attachmentButtonImage UI_APPEARANCE_SELECTOR;

@end
