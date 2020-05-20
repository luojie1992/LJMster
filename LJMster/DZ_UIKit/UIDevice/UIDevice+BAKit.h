//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2016/2/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (BAKit)

/*!
 *  强制锁定屏幕方向
 *
 *  @param orientation 屏幕方向
 */
+ (void)DZ_deviceInterfaceOrientation:(UIInterfaceOrientation)orientation;

/**
 监测设备是否越狱

 @return YES/NO;
 */
- (BOOL)DZ_deviceIsJailBreak;

@end
