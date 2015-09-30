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

#define kViewLandscape UIInterfaceOrientationIsLandscape([UIApplication sharedApplication].statusBarOrientation)

#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define iOS6 ([[UIDevice currentDevice].systemVersion doubleValue] >= 6.0 && [[UIDevice currentDevice].systemVersion doubleValue] < 7.0)

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"逸创云客服";
    
    self.view.backgroundColor = [UIColor colorWithRed:237.0/255.0 green:237.0/255.0 blue:237.0/255.0 alpha:1];
    
    UILabel *label1 = [self labelWithText:@"欢迎使用逸创云客服SDK"];
    [self.view addSubview:label1];
    
    UILabel *label2 = [self labelWithText:@"以下是展示逸创云客服SDK功能的按钮"];
    label2.textColor = KFColorFromRGB(0x777777);
    label2.font = [UIFont systemFontOfSize:13.0f];
    [self.view addSubview:label2];
    
    UIButton *button1 = [self buttonWithTitle:@"帮助中心"];
    [button1 addTarget:self action:@selector(buttonAction1) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button1];
    
    UIButton *button2 = [self buttonWithTitle:@"反馈问题"];
    [button2 addTarget:self action:@selector(buttonAction2) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button2];
    
    UIButton *button3 = [self buttonWithTitle:@"查看反馈"];
    [button3 addTarget:self action:@selector(buttonAction3) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button3];
    
    CGFloat orignY = 80;
    CGFloat spacing = 30;
    if (kViewLandscape && !isPad) {
        orignY = 20;
        spacing = 10;
    }
    
    NSDictionary *dict = NSDictionaryOfVariableBindings(label1,label2,button1,button2,button3);
    NSDictionary *metrics = @{@"orignY":@(orignY), @"btnW":@130,@"btnH":@40,@"labelH":@40,@"spacing":@(spacing)};
    NSString *vf1 = @"V:|-orignY-[label1(btnH)]-[label2(btnH)]-spacing-[button1(btnH)]-spacing-[button2(btnH)]-spacing-[button3(btnH)]";
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:vf1 options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-[label1]-|" options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"|-[label2]-|" options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[button1(btnW)]" options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[button2(btnW)]" options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"[button3(btnW)]" options:NSLayoutFormatAlignAllCenterX metrics:metrics views:dict]];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];

}

- (UILabel *)labelWithText:(NSString *)text
{
    UILabel *label = [[UILabel alloc]init];
    label.backgroundColor = [UIColor clearColor];
    label.textAlignment = NSTextAlignmentCenter;
    label.text = text;
    [label setTranslatesAutoresizingMaskIntoConstraints:NO];
    return label;
}
- (UIButton *)buttonWithTitle:(NSString *)title
{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:title forState:0];
    [button setTitleColor:[UIColor blackColor] forState:0];
    button.layer.cornerRadius = 20;
    button.layer.masksToBounds = YES;
    button.layer.borderWidth = 1.2;
    button.layer.borderColor = KFColorFromRGB(0x555555).CGColor;
    [button setTranslatesAutoresizingMaskIntoConstraints:NO];
    return button;
}

// 帮助中心
- (void)buttonAction1 {
    
    [KFHelpCenter showHelpCenterWithNavController:self.navigationController helpCenterType:KFHelpCenterTypeDocument];
    
    [KFHelpCenter setNavBarConversationsUIType:KFNavBarConversationsUITypeLocalizedLabel];
    
//    [KFHelpCenter showHelpCenterWithNavController:self.navigationController helpCenterType:KFHelpCenterTypeDocument rightBarButtonActionBlock:^{
//        [self buttonAction3];
//    }];
}
// 反馈问题
- (void)buttonAction2 {
    
    [KFRequests presentRequestCreationWithNavController:self.navigationController];
    
//    [KFRequests presentRequestCreationWithNavController:self.navigationController fieldDict:@{@"field_3588":@"安装",@"field_4587":@"text123"} success:^(id result) {
//        NSLog(@"------%@",result);
//    } andError:^(NSError *error) {
//        NSLog(@"%@",error);
//    }];
}

// 反馈列表
- (void)buttonAction3 {
    
    [KFRequests showRequestListWithNavController:self.navigationController];
    
//    [KFRequests showRequestListWithNavController:self.navigationController rightBarButtonActionBlock:^{
//        [self buttonAction2];
//    }];
}

// 获取自定义字段
- (void)getCustomFileds
{
    [[KFConfig instance] getCustomFiledsWithSuccess:^(id result) {
        NSLog(@"result--%@",result);
    } failure:^(NSError *error) {
    }];
}

@end
