//
//  KFDispatcher.h
//  SampleSDKApp
//
//  Created by admin on 15/4/1.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KFDispatcher : NSObject

/**
 * API success block.
 */
typedef void (^KFAPISuccess) (id result);

/**
 * API error block
 */
typedef void (^KFAPIError) (NSError *error);

/**
 *  点击BarButton的回调
 */
typedef void (^KFBarButtonActionBlock)();


@end
