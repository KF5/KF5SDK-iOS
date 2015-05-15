//
//  ViewController.m
//  SampleSDKApp
//
//  Created by admin on 15/2/2.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "ViewController.h"
#import <KF5SDK/KF5SDK.h>

// 获取设备屏幕的物理尺寸
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kScreenWidth [UIScreen mainScreen].bounds.size.width

#define KFColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"逸创云客服";
    
    self.view.backgroundColor = [UIColor colorWithRed:237.0/255.0 green:237.0/255.0 blue:237.0/255.0 alpha:1];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake((kScreenWidth-280)/2, 100, 280, 40)];
    label.textAlignment = NSTextAlignmentCenter;
    label.text = @"欢迎使用逸创云客服SDK";
    [self.view addSubview:label];
    
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake((kScreenWidth-280)/2, CGRectGetMaxY(label.frame), 280, 40)];
    label1.textAlignment = NSTextAlignmentCenter;
    label1.text = @"以下是展示逸创云客服SDK功能的按钮";
    label1.textColor = KFColorFromRGB(0x777777);
    label1.font = [UIFont systemFontOfSize:13.0f];
    [self.view addSubview:label1];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectMake((kScreenWidth-130)/2, 210, 130, 40);
    [button1 setTitle:@"帮助中心" forState:0];
    [button1 setTitleColor:[UIColor blackColor] forState:0];
    button1.layer.cornerRadius = 20;
    button1.layer.masksToBounds = YES;
    button1.layer.borderWidth = 1.2;
    button1.layer.borderColor = KFColorFromRGB(0x555555).CGColor;
    [button1 addTarget:self action:@selector(buttonAction1) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectMake((kScreenWidth-130)/2, 280, 130, 40);
    [button2 setTitle:@"反馈问题" forState:0];
    [button2 setTitleColor:[UIColor blackColor] forState:0];
    button2.layer.cornerRadius = 20;
    button2.layer.masksToBounds = YES;
    button2.layer.borderWidth = 1.2;
    button2.layer.borderColor = KFColorFromRGB(0x555555).CGColor;
    [button2 addTarget:self action:@selector(buttonAction2) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    button3.frame = CGRectMake((kScreenWidth-130)/2, 350, 130, 40);
    [button3 setTitle:@"查看反馈" forState:0];
    [button3 setTitleColor:[UIColor blackColor] forState:0];
    button3.layer.cornerRadius = 20;
    button3.layer.masksToBounds = YES;
    button3.layer.borderWidth = 1.2;
    button3.layer.borderColor = KFColorFromRGB(0x555555).CGColor;
    [button3 addTarget:self action:@selector(buttonAction3) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
}

// 帮助中心
- (void)buttonAction1 {
    [KFHelpCenter showHelpCenterWithNavController:self.navigationController helpCenterType:KFHelpCenterTypeDocument];
    
    [KFHelpCenter setNavBarConversationsUIType:KFNavBarConversationsUITypeImage];
}
// 反馈问题
- (void)buttonAction2 {
    
    [KFRequests presentRequestCreationWithNavController:self.navigationController withSuccess:^(id result) {
        NSLog(@"%@",result);
    } andError:^(NSError *error) {
        NSLog(@"%@",error);
    }];
    
}

// 反馈列表
- (void)buttonAction3 {
    [KFRequests showRequestListWithNavController:self.navigationController];
}
@end
