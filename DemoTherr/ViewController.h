//
//  ViewController.h
//  DemoTherr
//
//  Created by 丁寅初 on 2017/8/29.
//  Copyright © 2017年 dyc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

- (void)messageCallback:(int)msgtype errorCode:(int)errorcode context:(void*)ctx;

- (void)eventCallback:(int)evttype context:(void*)ctx;

- (void)mediaCallback;
@end

