//
//  KFAttachment.h
//  SampleSDKApp
//
//  Created by admin on 15/8/17.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KFAttachment : NSObject
/**
 *  附件id
 */
@property (nonatomic, copy) NSString *Id;
/**
 *  附件名称
 */
@property (nonatomic, copy) NSString *name;
/**
 *  附件的大小
 */
@property (nonatomic, copy) NSString *size;
/**
 *  附件的token,用于服务器存储
 */
@property (nonatomic, copy) NSString *token;
/**
 *  附件的网络地址
 */
@property (nonatomic, copy) NSString *content_url;
/**
 *  附件是否为图片
 */
@property (nonatomic, assign) BOOL isImage;

+ (NSArray *)attachmentsWithDict:(NSArray *)array;
@end
