//
//  KFDocHttpTppl.h
//  Pods
//
//  Created by admin on 15/12/11.
//
//

#import "KFBaseHttpTool.h"

#import "KFDispatcher.h"

@class KFDocHttpTool;
@protocol KFDocHttpToolDelegate <NSObject>

@required
/**
 *  请求成功的代理方法
 */
- (void)docHttpTool:(KFDocHttpTool *)docHttpTool successWithResult:(NSDictionary *)result;
@optional
/**
 *  请求失败的代理方法
 */
- (void)docHttpTool:(KFDocHttpTool *)docHttpTool failureWithError:(KFError *)error;

@end

@interface KFDocHttpTool : KFBaseHttpTool

/**
 *  代理对象
 */
@property (nonatomic, weak) id<KFDocHttpToolDelegate> delegate;
/**
 *  列表类型
 */
@property (nonatomic, assign) KFHelpCenterType type;

#pragma mark - 对象方法
/**
 *  获取列表内容
 *
 *  @param type     列表的类型,如:分区,分类,类别
 *  @param super_id 上一级的id.如果获取分类的列表,则上级id为分区的id;获取分区的列表,则没有上级id
 *  @param pageSize 每页的数量
 *  @param page     当前请求第几页
 */
- (NSURLSessionDataTask *)getDocListWithType:(KFHelpCenterType)type super_id:(NSString *)super_id pageSize:(NSString *)pageSize page:(NSString *)page;
/**
 *  获取文档内容
 *
 *  @param post_id 文档的id
 */
- (NSURLSessionDataTask *)getDocumentWithPost_id:(NSString *)post_id;

/**
 *  搜索工单
 *
 *  @param queryStr 搜索关键字
 */
- (NSURLSessionDataTask *)searchDocumentWithQueryStr:(NSString *)queryStr;

#pragma mark - 类方法
/**
 *  获取文档分区列表
 *
 *  @param pageSize     每页的数量
 *  @param page         当前请求第几页
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getDocCategoriesListWithPageSize:(NSString *)pageSize page:(NSString *)page successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;
/**
 *  获取文档分类列表
 *
 *  @param category_id  分区的id
 *  @param pageSize     每页的数量
 *  @param page         当前请求第几页
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getDocForumListWithCategory_id:(NSString *)category_id pageSize:(NSString *)pageSize page:(NSString *)page successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  获取文档列表
 *
 *  @param forum_id  分类的id
 *  @param pageSize     每页的数量
 *  @param page         当前请求第几页
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getPostListWithForum_id:(NSString *)forum_id pageSize:(NSString *)pageSize page:(NSString *)page successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  获取文档内容
 *
 *  @param post_id       文档的id
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)getDocumentWithPost_id:(NSString *)post_id successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

/**
 *  搜索工单
 *
 *  @param queryStr     搜索关键字
 *  @param successBlock 获取成功的回调
 *  @param failureBlock 获取失败的回调
 */
+ (NSURLSessionDataTask *)searchDocumentWithQueryStr:(NSString *)queryStr successBlock:(KFAPISuccess)successBlock failureBlock:(KFAPIError)failureBlock;

@end
