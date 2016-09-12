//
//  KFPersonTableViewController.m
//  KF5SampleApp
//
//  Created by admin on 15/10/27.
//  Copyright © 2015年 kf5. All rights reserved.
//

#import "KFPersonTableViewController.h"
#import <KF5SDK/KF5SDK.h>

@interface KFPersonTableViewController ()
@property (weak, nonatomic) IBOutlet UITextField *nameTextField;
@property (weak, nonatomic) IBOutlet UITextField *emailTextField;
@property (weak, nonatomic) IBOutlet UITextField *phoneTextField;
@property (weak, nonatomic) IBOutlet UITextField *hostNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *appIdTextField;

@end

@implementation KFPersonTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    NSDictionary *userInfo = [[NSUserDefaults standardUserDefaults]objectForKey:kUserDefaultUserInfo];
    if (userInfo) {
        self.nameTextField.text = [userInfo objectForKey:kKeyUserName];
        self.emailTextField.text = [userInfo objectForKey:kKeyEmail];
        self.phoneTextField.text = [userInfo objectForKey:kKeyPhone];
        self.hostNameTextField.text = [userInfo objectForKey:kKeyHostName];
        self.appIdTextField.text = [userInfo objectForKey:kKeyAppId];
    }else{
        [self resetUserInfo:nil];
    }
    self.tableView.tableFooterView = [[UIView alloc]initWithFrame:CGRectZero];
}


- (IBAction)resetUserInfo:(UIBarButtonItem *)sender {
    NSString *idfv = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    self.emailTextField.text = [NSString stringWithFormat:@"%@@qq.com",[idfv substringToIndex:8]];
    
    self.hostNameTextField.text = @"https://tianxiang.kf5.com";
    self.appIdTextField.text = @"00155bee6f7945ea5aa21c6ffc35f7aa7ed0999d7c6b6029";
    self.nameTextField.text = @"IOS用户";
}

- (IBAction)login:(UIBarButtonItem *)sender {
    if (self.emailTextField.text.length == 0 && self.phoneTextField.text.length == 0) {
        [self showAlertWithTitle:@"邮箱和手机号必须填其一"];
        return;
    }
    if (self.emailTextField.text.length > 0 && ![self validateEmail:self.emailTextField.text]) {
        [self showAlertWithTitle:@"邮箱格式不正确"];
        return;
    }
    if (self.phoneTextField.text.length > 0 && ![self validatePhone:self.phoneTextField.text]) {
        [self showAlertWithTitle:@"手机号格式不正确"];
        return;
    }
    
    if (self.appIdTextField.text.length == 0) {
        [self showAlertWithTitle:@"密钥不能为空"];
        return;
    }
    
    if (self.hostNameTextField.text.length == 0) {
        [self showAlertWithTitle:@"云客服地址不能为空"];
        return;
    }
    
    NSString *token = [[NSUserDefaults standardUserDefaults]objectForKey:@"deviceToken"];
    
    KFUser *user = [[KFUser alloc]initWithHostName:self.hostNameTextField.text appId:self.appIdTextField.text email:self.emailTextField.text phone:self.phoneTextField.text verifyUserType:1 appName:@"sampleApp-iOS" deviceToken:token];
    user.userName = self.nameTextField.text;
    
    
    UIView *bgView = [[UIView alloc]initWithFrame:self.view.frame];
    bgView.backgroundColor = [UIColor blackColor];
    bgView.alpha = 0.3;
    [self.view addSubview:bgView];
    
    UIActivityIndicatorView *activityIndicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 32, 32)];
    [activityIndicator setCenter:bgView.center];
    [activityIndicator setActivityIndicatorViewStyle:UIActivityIndicatorViewStyleWhiteLarge];
    [bgView addSubview:activityIndicator];
    [activityIndicator startAnimating];
    
    // 初始化配置信息
    __weak typeof(self)weakSelf = self;
    [[KFConfig shareConfig]initializeWithUser:user successBlock:^(KFUser *user,NSString *message) {

        [[NSNotificationCenter defaultCenter]postNotificationName:@"loginSuccess" object:nil];
        
        NSDictionary *userInfo = @{kKeyHostName:self.hostNameTextField.text?:@"",kKeyAppId:self.appIdTextField.text?:@"",kKeyEmail:self.emailTextField.text?:@"",kKeyPhone:self.phoneTextField.text?:@"",kKeyUserName:self.nameTextField.text?:@"",KKeyIsLogin:@(YES)};
        [[NSUserDefaults standardUserDefaults]setObject:userInfo forKey:kUserDefaultUserInfo];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf.navigationController popViewControllerAnimated:YES];
            [bgView removeFromSuperview];
        });
        
    } failureBlock:^(KFError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf showAlertWithTitle:error.domain];
            [bgView removeFromSuperview];
        });
    }];
}

- (void)showAlertWithTitle:(NSString *)title{
        [[[UIAlertView alloc]initWithTitle:@"提示" message:title delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil]show];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 5;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    UITextField *textField = cell.contentView.subviews[0];
    if ([textField isKindOfClass:[UITextField class]])
        [textField becomeFirstResponder];
}

- (BOOL)validateEmail:(NSString *)email{
    if (![email isKindOfClass:[NSString class]]) return NO;
    if (email.length ==0) return NO;
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,10}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    BOOL b = [emailTest evaluateWithObject:email];
    return b;
}

- (BOOL)validatePhone:(NSString *)phone{
    if (![phone isKindOfClass:[NSString class]]) return NO;
    if (phone.length ==0) return NO;
    NSString *emailRegex = @"^1\\d{10}$";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    BOOL b = [emailTest evaluateWithObject:phone];
    return b;
}

@end
