//
//  AppDelegate.m
//  SampleSDKApp
//
//  Created by admin on 15/2/2.
//  Copyright (c) 2015年 admin. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <KF5SDK/KF5SDK.h>

#define KFColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    ViewController *view = [[ViewController alloc] init];
    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:view];
    self.window.rootViewController = nav;
    
    [self.window makeKeyAndVisible];
    
    // 设置日志状态
#ifdef DEBUG
    [KFLogger enable:YES];
#else
    [KFLogger enable:NO];
#endif
    
    NSLog(@"当前版本%@",[KFConfig shareConfig].version);
    
    // 初始化配置信息,如果在此处填写了deviceToken,则无需主动调用KFPushUtil里的上传deviceToken的接口
    KFUser *user = [[KFUser alloc]initWithHostName:@"https://tianxiang.kf5.com" appId:@"00155bee6f7945ea5aa21c6ffc35f7aa7ed0999d7c6b6029" email:@"iossdk@kf5.com" appName:@"IOSAPP" deviceToken:nil];
    [[KFConfig shareConfig]initializeWithUser:user successBlock:^(KFUser *user) {
        
    } failureBlock:^(KFError *error) {
        
    }];
    
    // UI配置
    [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
    [[UINavigationBar appearance]setBarTintColor:KFColorFromRGB(0x282a2c)];
    
    NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                      [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
    [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];

    // 注：视图均遵守UIAppearance协议，可以用appearance修改界面样式
    [[KFCreateRequestView appearance]setTextViewFont:[UIFont systemFontOfSize:15.f]];
    [[KFHelpCenterListView appearance]setCellTextLabelColor:[UIColor blackColor]];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
