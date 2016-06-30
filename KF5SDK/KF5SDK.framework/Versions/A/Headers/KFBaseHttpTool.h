//
//  KFHttpTool.h
//  kf5
//
//  Created by admin on 15/6/26.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "KFDispatcher.h"

@interface KFBaseHttpTool : NSObject
/**
*  get请求
*
*  @param path             请求子路径
*  @param param            请求参数
*  @param successBlock     请求成功的回调
*  @param failureBlock     请求失败的回调
*/
+(NSURLSessionDataTask *)getWithPath:(NSString *)path
                               param:(NSDictionary *)param
                             successBlock:(KFAPISuccess)successBlock
                             failureBlock:(KFAPIError)failureBlock;

/**
 *  post请求
 *
 *  @param path             请求子路径
 *  @param param            请求参数
 *  @param successBlock     请求成功的回调
 *  @param failureBlock     请求失败的回调
 */
+ (NSURLSessionDataTask *)postWithPath:(NSString *)path
                                 param:(NSDictionary *)param
                               successBlock:(KFAPISuccess)successBlock
                               failureBlock:(KFAPIError)failureBlock;

/**
 *  工单上传图片
 *
 *  @param images              图片数组
 *  @param uploadProgressBlock 上传进度
 *  @param successBlock        上传成功的回调
 *  @param failureBlock        上传失败的回调
 */
+ (NSURLSessionDataTask *)uploadWithImages:(NSArray *)images uploadProgress:(void  (^)(NSProgress * progress))uploadProgressBlock successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock ;

/**
 *  IM上传图片
 *
 *  @param image               图片
 *  @param successBlock        上传成功的回调
 *  @param failureBlock        上传失败的回调
 */
+ (NSURLSessionDataTask *)chatWithImage:(UIImage *)image successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock ;

/**
 *  IM上传语音
 *
 *  @param voice        语音
 *  @param successBlock 上传成功的回调
 *  @param failureBlock 上传失败的回调
 */
+ (NSURLSessionDataTask *)chatWithVoice:(NSData *)voice successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock ;


@end
