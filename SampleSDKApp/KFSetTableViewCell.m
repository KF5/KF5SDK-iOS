//
//  TableViewCell.m
//  SampleSDKApp
//
//  Created by admin on 15/11/4.
//  Copyright © 2015年 admin. All rights reserved.
//

#import "KFSetTableViewCell.h"

@implementation KFSetTableViewCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        UIImageView *imageView = [[UIImageView alloc]init];
        [self.contentView addSubview:imageView];
        self.headerImageView = imageView;
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    self.imageView.frame = CGRectMake(CGRectGetMinX(self.textLabel.frame) - 10 - 29, 0, 29, 29);
    self.imageView.center = CGPointMake(self.imageView.center.x, self.textLabel.center.y);
}



@end
