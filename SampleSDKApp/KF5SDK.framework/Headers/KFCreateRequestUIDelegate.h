//
//  KFCreateRequestUIDelegate.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  创建工单页NavBarButton的显示方式
 */
typedef NS_ENUM(NSUInteger, KFNavBarCreateRequestUIType) {
    
    /**
     *  NavBarButton设置为文字
     */
    KFNavBarCreateRequestUITypeLocalizedLabel,
    
    /**
     *  NavBarButton设置为图片
     */
    KFNavBarCreateRequestUITypeImage,
};

@protocol KFCreateRequestUIDelegate <NSObject>

/**
 *  获取当前NavBarButton的显示方式
 *
 *  @return NavBarButton的显示方式
 */
- (KFNavBarCreateRequestUIType) navBarCreateRequestUIType;

/**
 *  获取当前NavBarButton的图片
 *
 *  @return NavBarButton的图片
 */
- (UIImage *) createRequestBarButtonImage;

/**
 *  获取当前NavBarButton的内容
 *
 *  @return NavBarButton的内容
 */
- (NSString *) createRequestBarButtonLocalizedLabel;


@end