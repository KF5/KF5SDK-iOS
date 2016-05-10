//
//  KFDocument.h
//  Pods
//
//  Created by admin on 15/12/30.
//
//



#import <Foundation/Foundation.h>

@interface KFDocument : NSObject
/**
 *  内容
 */
@property (nonatomic, copy) NSString *content;
/**
 *  文档id
 */
@property (nonatomic, copy) NSString *Id;
/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *  创建时间
 */
@property (nonatomic, copy) NSString *created_at;

+ (instancetype)documentWithDict:(NSDictionary *)dict;

@end
