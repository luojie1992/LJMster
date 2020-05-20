//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//
#import <UIKit/UIKit.h>

typedef void (^DZKit_AlertActionBlock)(UIAlertAction *action);

@interface UIAlertAction (DZKit)

/**
 UIAlertAction：Default 样式
 
 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionDefaultStyleActionWithTitle:(NSString *)title
                                              actionBlock:(DZKit_AlertActionBlock)actionBlock;

/**
 UIAlertAction：Cancel 样式
 
 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionCancleStyleWithTitle:(NSString *)title
                                       actionBlock:(DZKit_AlertActionBlock)actionBlock;

/**
 UIAlertAction：Destructive 样式
 
 @param title title description
 @param actionBlock actionBlock description
 @return UIAlertAction
 */
+ (instancetype)DZ_alertActionDestructiveStyleWithTitle:(NSString *)title
                                            actionBlock:(DZKit_AlertActionBlock)actionBlock;

@end

CG_INLINE UIAlertAction *
ba_alertActionDefault(NSString *title, DZKit_AlertActionBlock actionBlock){
    return [UIAlertAction DZ_alertActionDefaultStyleActionWithTitle:title actionBlock:actionBlock];
}

CG_INLINE UIAlertAction *
ba_alertActionCancle(NSString *title, DZKit_AlertActionBlock actionBlock){
    return [UIAlertAction DZ_alertActionCancleStyleWithTitle:title actionBlock:actionBlock];
}

CG_INLINE UIAlertAction *
ba_alertActionDestructive(NSString *title, DZKit_AlertActionBlock actionBlock){
    return [UIAlertAction DZ_alertActionDestructiveStyleWithTitle:title actionBlock:actionBlock];
}
