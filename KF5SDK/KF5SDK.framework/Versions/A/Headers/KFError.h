//
//  KFError.h
//  Pods
//
//  Created by admin on 15/12/10.
//
//

#import <Foundation/Foundation.h>
@interface KFError : NSObject
/**
 *  错误信息
 */
@property (nonatomic, copy) NSString *domain;
/**
 *  错误码
 */
@property (nonatomic, assign) NSInteger code;
/**
 *  错误具体描述
 */
@property (nonatomic, copy) NSString *localizedDescription;
/**
 *  快速创建一个error
 */
+ (instancetype)kf_errorWithDomain:(NSString *)domain code:(NSInteger)code;
/**
 *  快速创建一个error
 *
 *  @param dict   @{@"error":200,@"message":@"错误具体描述"}
 *
 */
+ (instancetype)kf_errorWithDomain:(NSString *)domain dict:(NSDictionary *)dict;
/**
 *  快速创建一个error
 */
+ (instancetype)kf_errorWithDomain:(NSString *)domain code:(NSInteger)code localizedDescription:(NSString *)localizedDescription;

@end
