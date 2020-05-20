//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (BAKit)

/**
 创建一个 hex 颜色
 
 @param hexstring hex
 @param alpha alpha
 @return 颜色
 */
+ (UIColor *)DZ_colorWithHex:(NSString *)hexstring andAlpha:(CGFloat)alpha;

@end
