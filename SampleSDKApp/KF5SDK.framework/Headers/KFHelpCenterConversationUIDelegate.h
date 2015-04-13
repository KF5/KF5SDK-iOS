//
//  KFHelpCenterConversationUIDelegate.h
//  SampleSDKApp
//
//  Created by admin on 15/3/31.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  NavBarButton的显示方式
 */
typedef NS_ENUM(NSUInteger, KFNavBarConversationsUIType) {

    /**
     *  NavBarButton设置为文字
     */
    KFNavBarConversationsUITypeLocalizedLabel,

    /**
     *  NavBarButton设置为图片
     */
    KFNavBarConversationsUITypeImage,
};

@protocol KFHelpCenterConversationsUIDelegate <NSObject>

/**
 *  获取当前NavBarButton的显示方式
 *
 *  @return NavBarButton的显示方式
 */
- (KFNavBarConversationsUIType) navBarConversationsUIType;

/**
 *  获取当前NavBarButton的图片
 *
 *  @return NavBarButton的图片
 */
- (UIImage *) conversationsBarButtonImage;

/**
 *  获取当前NavBarButton的内容
 *
 *  @return NavBarButton的内容
 */
- (NSString *) conversationsBarButtonLocalizedLabel;


@end
