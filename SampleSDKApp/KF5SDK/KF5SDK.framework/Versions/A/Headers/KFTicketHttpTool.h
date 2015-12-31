//
//  KFTicketHttpTool.h
//  SampleSDKApp
//
//  Created by admin on 15/2/3.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "KFBaseHttpTool.h"

@class KFTicketHttpTool;
@protocol KFTicketHttpToolDelegate <NSObject>

@required
/**
 *  请求成功的代理方法
 */
- (void)ticketHttpTool:(KFTicketHttpTool *)ticketHttpTool successWithResult:(NSDictionary *)result;
@optional
/**
 *  请求失败的代理方法
 */
- (void)ticketHttpTool:(KFTicketHttpTool *)ticketHttpTool failureWithError:(KFError *)error;

@end

@interface KFTicketHttpTool : KFBaseHttpTool

/**
 *  代理对象
 */
@property (nonatomic, weak) id<KFTicketHttpToolDelegate> delegate;

#pragma mark - 对象方法
/**
 *  获取工单列表
 *
 *  @param pageSize     每页工单的数量
 *  @param page         当前请求第几页
 */
- (NSURLSessionDataTask *)getTicketListWithPageSize:(NSString *)pageSize page:(NSString *)page;
/**
 *  获取工单内容
 *
 *  @param ticket_id    工单的id
 *  @param pageSize     每页工单的数量
 *  @param page         当前请求第几页
 */
- (NSURLSessionDataTask *)getTicketWithTicket_id:(NSString *)ticket_id pageSize:(NSString *)pageSize page:(NSString *)page;

/**
 *  获取工单详情
 *
 *  @param ticket_id     工单的id
 */
- (NSURLSessionDataTask *)getTicketDetailMessageWithTicket_id:(NSString *)ticket_id;

/**
 *  回复工单
 *
 *  @param ticket_id     工单的id
 *  @param content       回复内容
 *  @param imageTokens   附件图片token数组
 */
- (NSURLSessionDataTask *)replyTicketWithTicket_id:(NSString *)ticket_id content:(NSString *)content imageTokens:(NSArray *)imageTokens;

/**
 *  创建工单
 *
 *  @param title         工单标题
 *  @param content       回复内容
 *  @param imageTokens   附件图片token数组
 *  @param custom_fields 自定义字段,如@{@"field_123":@"手机端"},
                            自定义字段的key需要使用获取自定义字段的接口获取
 */
- (NSURLSessionDataTask *)createTicketWithTitle:(NSString *)title content:(NSString *)content imageTokens:(NSArray *)imageTokens custom_fields:(NSDictionary *)custom_fields;

/**
 *  获取自定义字段
 */
- (NSURLSessionDataTask *)getCustom_fields;

#pragma mark - 类方法
/**
 *  获取工单列表
 *
 *  @param pageSize     每页工单的数量
 *  @param page         当前请求第几页
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getTicketListWithPageSize:(NSString *)pageSize page:(NSString *)page successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;
/**
 *  获取工单内容
 *
 *  @param ticket_id    工单的id
 *  @param pageSize     每页工单的数量
 *  @param page         当前请求第几页
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getTicketWithTicket_id:(NSString *)ticket_id pageSize:(NSString *)pageSize page:(NSString *)page successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  获取工单详情
 *
 *  @param ticket_id     工单的id
 *  @param successBlock  获取成功的回调
 *  @param failureBlock  获取失败的回调
 */
+ (NSURLSessionDataTask *)getTicketDetailMessageWithTicket_id:(NSString *)ticket_id successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  回复工单
 *
 *  @param ticket_id     工单的id
 *  @param content       回复内容
 *  @param imageTokens   附件图片token数组
 *  @param successBlock  回复成功的回调
 *  @param failureBlock  回复失败的回调
 */
+ (NSURLSessionDataTask *)replyTicketWithTicket_id:(NSString *)ticket_id content:(NSString *)content imageTokens:(NSArray *)imageTokens successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  创建工单
 *
 *  @param title         工单标题
 *  @param content       回复内容
 *  @param imageTokens   附件图片token数组
 *  @param custom_fields 自定义字段,如@{@"field_123":@"手机端"},
                                     自定义字段的key需要使用获取自定义字段的接口获取
 *  @param successBlock  回复成功的回调
 *  @param failureBlock  回复失败的回调
 */
+ (NSURLSessionDataTask *)createTicketWithTitle:(NSString *)title content:(NSString *)content imageTokens:(NSArray *)imageTokens custom_fields:(NSDictionary *)custom_fields successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  获取自定义字段
 *
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getCustom_fieldsWithSuccessBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

@end




