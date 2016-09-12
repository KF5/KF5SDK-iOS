//
//  KFHomeViewController.m
//  KF5SampleApp
//
//  Created by admin on 15/10/27.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KFHomeViewController.h"
#import "KFPersonTableViewController.h"
#import <KF5SDK/KF5SDK.h>

@interface KFHomeViewController ()

@end

@implementation KFHomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    NSString *token = [[NSUserDefaults standardUserDefaults]objectForKey:@"deviceToken"];
    
    NSDictionary *userInfo = [[NSUserDefaults standardUserDefaults]objectForKey:kUserDefaultUserInfo];
    
    if (((NSNumber *)[userInfo objectForKey:KKeyIsLogin]).boolValue) {
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithTitle:@"注销" style:UIBarButtonItemStyleDone target:self action:@selector(login:)];
        KFUser *user = [[KFUser alloc]initWithHostName:[userInfo objectForKey:kKeyHostName] appId:[userInfo objectForKey:kKeyAppId] email:[userInfo objectForKey:kKeyEmail] phone:[userInfo objectForKey:kKeyPhone] verifyUserType:1 appName:@"sampleApp-iOS" deviceToken:token];
        user.userName = [userInfo objectForKey:kKeyUserName];
        // 初始化配置信息
        [[KFConfig shareConfig]initializeWithUser:user successBlock:^(KFUser *user,NSString *message) {
            
        } failureBlock:^(KFError *error) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [[[UIAlertView alloc]initWithTitle:@"提示" message:error.domain delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil]show];
            });
        }];
    }else{
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]initWithTitle:@"登录" style:UIBarButtonItemStyleDone target:self action:@selector(login:)];
    }
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(pushTicketList) name:@"homePush" object:nil];
    
    NSString *push = [[NSUserDefaults standardUserDefaults]objectForKey:@"push"];
    
    if (push.length > 0) {
        [self pushTicketList];
        [[NSUserDefaults standardUserDefaults]removeObjectForKey:@"push"];
    }
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(loginSuccess) name:@"loginSuccess" object:nil];
    
}

- (void)login:(UIBarButtonItem *)item
{
    if ([item.title isEqualToString:@"登录"]) {
        UIStoryboard* storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
        KFPersonTableViewController *preson = (KFPersonTableViewController*)[storyboard instantiateViewControllerWithIdentifier:@"KFPersonTableViewController"];
        [self.navigationController pushViewController:preson animated:YES];
    }else{
        item.title = @"登录";
        [[KFConfig shareConfig]logoutOfUser];
        
        NSMutableDictionary *userInfo = [NSMutableDictionary dictionaryWithDictionary:[[NSUserDefaults standardUserDefaults]objectForKey:kUserDefaultUserInfo]];
        [userInfo setValue:@(NO) forKey:KKeyIsLogin];
        [[NSUserDefaults standardUserDefaults]setObject:userInfo forKey:kUserDefaultUserInfo];
        [[NSUserDefaults standardUserDefaults]synchronize];
        
    }
}

#pragma mark - delegate
- (void)loginSuccess
{
    self.navigationItem.rightBarButtonItem.title = @"注销";
}

#pragma mark - push
- (void)pushTicketList
{
    [KFRequests showRequestListWithNavController:self.navigationController];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter]removeObserver:self];
}
@end
