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

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"KF5";
    
    self.view.backgroundColor = [UIColor colorWithRed:237.0/255.0 green:237.0/255.0 blue:237.0/255.0 alpha:1];
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake((kScreenWidth-170)/2, 100, 170, 40)];
    label.text = @"欢迎使用KF5 SDK";
    [self.view addSubview:label];
    
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake((kScreenWidth-280)/2, 150, 280, 40)];
    label1.text = @"以下是展示KF5 SDK功能的按钮";
    [self.view addSubview:label1];
    
    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeCustom];
    button1.frame = CGRectMake((kScreenWidth-130)/2, 210, 130, 40);
    [button1 setTitle:@"帮助文档" forState:0];
    [button1 setTitleColor:[UIColor blackColor] forState:0];
    button1.layer.cornerRadius = 3;
    button1.layer.masksToBounds = YES;
    button1.layer.borderWidth = 1.2;
    button1.layer.borderColor = [UIColor blackColor].CGColor;
    [button1 addTarget:self action:@selector(buttonAction1) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    button2.frame = CGRectMake((kScreenWidth-130)/2, 280, 130, 40);
    [button2 setTitle:@"提交问题" forState:0];
    [button2 setTitleColor:[UIColor blackColor] forState:0];
    button2.layer.cornerRadius = 3;
    button2.layer.masksToBounds = YES;
    button2.layer.borderWidth = 1.2;
    button2.layer.borderColor = [UIColor blackColor].CGColor;
    [button2 addTarget:self action:@selector(buttonAction2) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    button3.frame = CGRectMake((kScreenWidth-130)/2, 350, 130, 40);
    [button3 setTitle:@"查看问题" forState:0];
    [button3 setTitleColor:[UIColor blackColor] forState:0];
    button3.layer.cornerRadius = 3;
    button3.layer.masksToBounds = YES;
    button3.layer.borderWidth = 1.2;
    button3.layer.borderColor = [UIColor blackColor].CGColor;
    [button3 addTarget:self action:@selector(buttonAction3) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
}

// 帮助文档
- (void)buttonAction1 {
    [KF5 showPostWithViewController:self];
}
// 反馈问题
- (void)buttonAction2 {
    [KF5 showRequestViewWithViewController:self];
    
}

// 反馈列表
- (void)buttonAction3 {
    [KF5 showTicketListWithViewController:self];
}

@end
