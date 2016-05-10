//
//  KFTicket.h
//  Pods
//
//  Created by admin on 15/12/28.
//
//

#import <Foundation/Foundation.h>

@interface KFTicket : NSObject

/**
*  id
*/
@property (nonatomic, copy) NSString *Id;

/**
 *  标题
 */
@property (nonatomic, copy) NSString *title;

/**
 *  状态
 */
@property (nonatomic, copy) NSString *status;


/**
 *  描述
 */
@property (nonatomic, copy) NSString *Description;

/**
 *  创建时间
 */
@property (nonatomic, copy) NSString *created_at;

/**
 *  工单地址
 */
@property (nonatomic, copy) NSString *url;

/**
 *  更新时间
 */
@property (nonatomic, strong) NSString *updated_at;


+ (NSArray *)ticketWithDict:(NSDictionary *)dict;

@end
