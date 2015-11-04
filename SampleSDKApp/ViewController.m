//
//  ViewController.m
//  SampleSDKApp
//
//  Created by admin on 15/2/2.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "ViewController.h"
#import "TableViewCell.h"
#import <KF5SDK/KF5SDK.h>

#define KFColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

@interface KFCellData : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageName;

+(instancetype)cellDataWithTitle:(NSString *)title imageName:(NSString *)imageName;

@end

@implementation KFCellData
+ (instancetype)cellDataWithTitle:(NSString *)title imageName:(NSString *)imageName
{
    KFCellData *data = [[KFCellData alloc]init];
    data.title = title;
    data.imageName = imageName;
    return data;
}
@end

@interface ViewController ()

@property (nonatomic, strong) NSArray *cellDataList;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"逸创云客服";
    
    UIView *headerView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 150)];
    self.tableView.tableHeaderView = headerView;
    self.tableView.tableFooterView = [[UIView alloc]initWithFrame:CGRectZero];
    [self.tableView setSeparatorColor:KFColorFromRGB(0xdddddd)];
    
    UIView *topView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, headerView.frame.size.width, 116)];
    topView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    topView.backgroundColor = KFColorFromRGB(0xf2f5f9);
    [headerView addSubview:topView];
    
    UILabel *label1 = [[UILabel alloc]initWithFrame:CGRectMake(64, 41, 200, 19)];
    label1.font = [UIFont systemFontOfSize:14.f];
    label1.backgroundColor = [UIColor clearColor];
    label1.text = @"欢迎使用逸创云客服SDK";
    label1.textColor = KFColorFromRGB(0x3e4245);
    [topView addSubview:label1];
    
    UILabel *label2 = [[UILabel alloc]initWithFrame:CGRectMake(64, 60, 250, 19)];
    label2.textColor = KFColorFromRGB(0x45d8d0);
    label2.font = [UIFont systemFontOfSize:11.f];
    label2.text = @"以下是展示逸创云客服SDK功能的按钮";
    [topView addSubview:label2];
    
    self.cellDataList = @[
                          [KFCellData cellDataWithTitle:@"帮助中心" imageName:@"icon_document"],
                          [KFCellData cellDataWithTitle:@"反馈问题" imageName:@"icon_request"],
                          [KFCellData cellDataWithTitle:@"查看反馈" imageName:@"icon_ticketList"]
                          ];
    
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return  [[UIScreen mainScreen] bounds].size.height > 1136 ? 106 : 72;
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.cellDataList.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *cellID = @"cellID";
    TableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID];
    if (cell == nil) {
        cell = [[TableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellID];
    }
    KFCellData *data = self.cellDataList[indexPath.row];
    cell.imageView.image = [UIImage imageNamed:data.imageName];
    cell.textLabel.text = data.title;
    cell.textLabel.font = [UIFont systemFontOfSize:18.f];
    cell.textLabel.textColor = KFColorFromRGB(0x424345);
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
    switch (indexPath.row) {
        case 0:
            [self helpCenter];
            break;
        case 1:
            [self request];
            break;
        case 2:
            [self requestList];
            break;
        default:
            break;
    }
}

// 帮助中心
- (void)helpCenter {
    
    [KFHelpCenter showHelpCenterWithNavController:self.navigationController helpCenterType:KFHelpCenterTypeDocument];
    
    [KFHelpCenter setNavBarConversationsUIType:KFNavBarConversationsUITypeLocalizedLabel];
    /**
     [KFHelpCenter showHelpCenterWithNavController:self.navigationController helpCenterType:KFHelpCenterTypeDocument rightBarButtonActionBlock:^{
     [self buttonAction3];
     }];
     */

}
// 反馈问题
- (void)request {
    
    [KFRequests presentRequestCreationWithNavController:self.navigationController];
    /**
     [KFRequests presentRequestCreationWithNavController:self.navigationController fieldDict:@{@"field_3588":@"安装",@"field_4587":@"text123"} success:^(id result) {
     NSLog(@"------%@",result);
     } andError:^(NSError *error) {
     NSLog(@"%@",error);
     }];
     */
}

// 反馈列表
- (void)requestList {
    
    [KFRequests showRequestListWithNavController:self.navigationController];
    /**
     [KFRequests showRequestListWithNavController:self.navigationController rightBarButtonActionBlock:^{
     [self buttonAction2];
     }];
     */
}

// 获取自定义字段
- (void)getCustomFileds
{
    [[KFConfig instance] getCustomFiledsWithSuccess:^(id result) {
        NSLog(@"result--%@",result);
    } failure:^(NSError *error) {
    }];
}

#pragma mark 用于将cell分割线补全
-(void)viewDidLayoutSubviews {
    if ([self.tableView respondsToSelector:@selector(setSeparatorInset:)]) {
        [self.tableView setSeparatorInset:UIEdgeInsetsMake(0, 88, 0, 30)];
    }
    if ([self.tableView respondsToSelector:@selector(setLayoutMargins:)])  {
        [self.tableView setLayoutMargins:UIEdgeInsetsMake(0, 54, 0, 30)];
    }
}
-(void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath{
    if ([cell respondsToSelector:@selector(setSeparatorInset:)]){
        [cell setSeparatorInset:UIEdgeInsetsMake(0, 88, 0, 30)];
    }
    if ([cell respondsToSelector:@selector(setLayoutMargins:)]) {
        [cell setLayoutMargins:UIEdgeInsetsMake(0, 54, 0, 30)];
    }
}

@end
