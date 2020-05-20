//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import "UIAlertAction+BAKit.h"

@implementation UIAlertAction (DZKit)

/**
 UIAlertAction：Default 样式

 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionDefaultStyleActionWithTitle:(NSString *)title
                                              actionBlock:(DZKit_AlertActionBlock)actionBlock
{
    return [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDefault handler:actionBlock];
}

/**
 UIAlertAction：Cancel 样式
 
 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionCancleStyleWithTitle:(NSString *)title
                                       actionBlock:(DZKit_AlertActionBlock)actionBlock
{
    return [UIAlertAction actionWithTitle:title style:UIAlertActionStyleCancel handler:actionBlock];
}

/**
 UIAlertAction：Destructive 样式
 
 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionDestructiveStyleWithTitle:(NSString *)title
                                            actionBlock:(DZKit_AlertActionBlock)actionBlock
{
    return [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDestructive handler:actionBlock];
}

@end
