//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>
@interface CAShapeLayer (DZCornerRadius)

/**
 CAShapeLayer：创建一个带不同圆角的 labyer
 
 @param frame frame description
 @param corners corners description
 @param radius radius description
 @return CAShapeLayer
 */
+ (CAShapeLayer *)DZ_shapLayerWithFrame:(CGRect)frame
                                corners:(UIRectCorner)corners
                                 radius:(CGFloat)radius;

@end
