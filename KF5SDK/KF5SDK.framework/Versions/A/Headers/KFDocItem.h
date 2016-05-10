//
//  KFDocObject.h
//  Pods
//
//  Created by admin on 15/12/14.
//
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@interface KFDocItem : NSObject
/**
 *  Id
 */
@property (nonatomic, copy) NSString *Id;
/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;
/**
 *  描述
 */
@property (nonatomic, copy) NSString *content;
/**
 *  类型
 */
@property (nonatomic, assign) KFHelpCenterType type;


+ (NSMutableArray *)categoriesWithResult:(id)result;
+ (NSMutableArray *)forumsWithResult:(id)result;
+ (NSMutableArray *)postsWithResult:(id)result;

@end
