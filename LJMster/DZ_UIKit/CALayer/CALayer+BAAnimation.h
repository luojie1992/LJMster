//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

@interface CALayer (DZAnimation)

/**
 摇晃动画：用于错误提示
 
 @param value 晃动的幅度，默认：5.0f
 @param repeatCount 晃动的次数，默认：5.0f
 */
- (void)ba_layer_animationShakeWithValue:(CGFloat)value repeatCount:(CGFloat)repeatCount;

@end
