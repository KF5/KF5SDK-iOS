//
//  KF5SDK.h
//  Pods
//
//  Created by admin on 16/1/22.
//
//

#ifndef KF5SDK_h
#define KF5SDK_h

/************************************************************************

 1.KFConfig为整个SDK的初始化,在使用SDK前,请务必前进行初始化,如
 KFUser *user = [[KFUser alloc]initWithHostName:@"xxxx.kf5.com" appId:@"xxxxxx" email:@"xxxx@xx.xxx" appName:@"IOSAPP" deviceToken:@"deviceToken"];
 [[KFConfig shareConfig]initializeWithUser:user successBlock:^(KFUser *user) {
 } failureBlock:^(KFError *error) {
 }];
 
 2.凡是标有UIAppearance的View即可使用如,
 [KFHelpCenterListView appearance].noResultsFoundLabelText = @"";
 方式进行配置.
 注:如果提供的方法不能满足您的需求,您可以继承这些类进行自定义,或者直接使用网络管理类,自己创建界面.
 
 
 更多信息请参见各类的头文件或官方文档http://developer.kf5.com/ios/sdk/
**************************************************************************/

#pragma mark 控制器

#import "KF5BaseTableViewController.h"
#import "KF5BaseViewController.h"
#import "KF5BaseTableViewCell.h"

#import "KFDocBaseViewController.h"         //文档控制器基类
#import "KFCategorieListViewController.h"   //文档分区控制器
#import "KFForumListViewController.h"       //文档分类控制器
#import "KFPostListViewController.h"        //文档列表控制器
#import "KFPostViewController.h"            //文档内容控制器

#import "KFRequestViewController.h"         //创建工单控制器
#import "KFTicketListViewController.h"      //工单列表控制器
#import "KFTicketViewController.h"          //工单内容控制器
#import "KFDetailMessageViewController.h"   //详细信息控制器

#import "KFChatViewController.h"            //chat控制器

#pragma mark 视图

#import "KFHelpCenterListView.h"            //文档相关UI
#import "KFTicketListView.h"                //工单列表相关UI
#import "KFDetailMessageTableViewCell.h"    //工单详情相关UI
#import "KFRequestCommentTableCell.h"       //工单内容相关UI
#import "KFCreateRequestView.h"             //创建工单相关UI

#import "KFBaseMessageViewCell.h"
#import "KFMessageImageViewCell.h"
#import "KFMessageSystemViewCell.h"
#import "KFMessageTextViewCell.h"
#import "KFMessageVoiceViewCell.h"

#import "KFHelpCenter.h"                    //帮助中心管理,即文档管理
#import "KFChatManager.h"                   //聊天管理
#import "KFRequests.h"                      //工单管理
#import "KFPushUtil.h"                      //推送相关
#import "KFConfig.h"                        //SDK配置类,使用SDK前,必须先初始化此类

#pragma mark 网络管理
#import "KFBaseHttpTool.h"                  //基类
#import "KFDocHttpTool.h"                   //文档相关
#import "KFTicketHttpTool.h"                //工单相关

#pragma mark 对象
#import "KFAttachment.h"
#import "KFComment.h"
#import "KFTicket.h"
#import "KFAgent.h"
#import "KFMessage.h"
#import "KFUser.h"
#import "KFDocItem.h"
#import "KFDocument.h"

#pragma mark 其他
#import "KFBaseStatus.h"
#import "KFDispatcher.h"
#import "KFError.h"
#import "KFLogger.h"
#import "interf_dec.h"
#import "interf_enc.h"


#endif 
