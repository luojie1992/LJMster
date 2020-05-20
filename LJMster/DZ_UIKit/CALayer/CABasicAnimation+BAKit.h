//
//  DZ_UIKit.h
//  LJMster
//
//  Created by jiejie on 2017/4/3.
//  Copyright © 2017 jiejie. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

static NSString *kDZKit_animationKeyPath_TransformScale     = @"transform.scale";
static NSString *kDZKit_animationKeyPath_TransformScaleX    = @"transform.scale.x";
static NSString *kDZKit_animationKeyPath_TransformScaleY    = @"transform.scale.y";

static NSString *kDZKit_animationKeyPath_TransformRotation  = @"transform.rotation";
static NSString *kDZKit_animationKeyPath_TransformRotationX = @"transform.rotation.x";
static NSString *kDZKit_animationKeyPath_TransformRotationY = @"transform.rotation.y";
static NSString *kDZKit_animationKeyPath_TransformRotationZ = @"transform.rotation.z";

static NSString *kDZKit_animationKeyPath_TransformTranslationX  = @"transform.translation.x";
static NSString *kDZKit_animationKeyPath_TransformTranslationY  = @"transform.translation.y";

static NSString *kDZKit_animationKeyPath_Position           = @"position";
static NSString *kDZKit_animationKeyPath_PositionX          = @"position.x";
static NSString *kDZKit_animationKeyPath_PositionY          = @"position.y";

static NSString *kDZKit_animationKeyPath_Opacity            = @"opacity";
static NSString *kDZKit_animationKeyPath_Bounds             = @"bounds";
static NSString *kDZKit_animationKeyPath_BGColor            = @"backgroundColor";
static NSString *kDZKit_animationKeyPath_CornerRadius       = @"cornerRadius";


@interface CABasicAnimation (DZKit)

/**
 创建一个动画：无限闪烁
 
 @param duration 持续时间
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_opacityFlashingWithDuration:(CFTimeInterval)duration;

/**
 创建一个动画：有次数闪烁
 
 @param duration 持续时间
 @param repeatCount 重复次数
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_opacityFlashingWithDuration:(CFTimeInterval)duration
                                                        repeatCount:(CGFloat)repeatCount;

/**
 CABasicAnimation：透明度
 
 @param duration duration description
 @param repeatCount repeatCount description
 @param beginTime beginTime description
 @param fromValueOpacity fromValueOpacity description
 @param toValueOpacity toValueOpacity description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_opacityWithDuration:(CFTimeInterval)duration
                                                repeatCount:(float)repeatCount
                                                  beginTime:(CFTimeInterval)beginTime
                                           fromValueOpacity:(CGFloat)fromValueOpacity
                                             toValueOpacity:(CGFloat)toValueOpacity
                                               autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：缩放
 
 @param duration duration description
 @param repeatCount repeatCount description
 @param beginTime beginTime description
 @param fromValueScale fromValueScale description
 @param toValueScale toValueScale description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_scaleWithDuration:(CFTimeInterval)duration
                                              repeatCount:(float)repeatCount
                                                beginTime:(CFTimeInterval)beginTime
                                           fromValueScale:(CGFloat)fromValueScale
                                             toValueScale:(CGFloat)toValueScale
                                             autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：缩放 X
 
 @param duration duration description
 @param repeatCount repeatCount description
 @param beginTime beginTime description
 @param fromValueScale fromValueScale description
 @param toValueScale toValueScale description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_scaleXWithDuration:(CFTimeInterval)duration
                                               repeatCount:(float)repeatCount
                                                 beginTime:(CFTimeInterval)beginTime
                                            fromValueScale:(CGFloat)fromValueScale
                                              toValueScale:(CGFloat)toValueScale
                                              autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：缩放 Y
 
 @param duration duration description
 @param repeatCount repeatCount description
 @param beginTime beginTime description
 @param fromValueScale fromValueScale description
 @param toValueScale toValueScale description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_scaleYWithDuration:(CFTimeInterval)duration
                                               repeatCount:(float)repeatCount
                                                 beginTime:(CFTimeInterval)beginTime
                                            fromValueScale:(CGFloat)fromValueScale
                                              toValueScale:(CGFloat)toValueScale
                                              autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：圆角
 
 @param duration duration description
 @param repeatCount repeatCount description
 @param beginTime beginTime description
 @param fromValueCornerRadius fromValueCornerRadius description
 @param toValueCornerRadius toValueCornerRadius description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_cornerRadiusWithDuration:(CFTimeInterval)duration
                                                     repeatCount:(float)repeatCount
                                                       beginTime:(CFTimeInterval)beginTime
                                           fromValueCornerRadius:(CGFloat)fromValueCornerRadius
                                             toValueCornerRadius:(CGFloat)toValueCornerRadius
                                                    autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：改变背景颜色
 
 @param duration 持续时间
 @param repeatCount 重复次数
 @param fromValuebackgroundColor 开始的 backgroundColor
 @param toValuebackgroundColor 结束的 backgroundColor
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_backgroundColorWithDuration:(CFTimeInterval)duration
                                                        repeatCount:(float)repeatCount
                                                          beginTime:(CFTimeInterval)beginTime
                                           fromValuebackgroundColor:(UIColor *)fromValuebackgroundColor
                                             toValuebackgroundColor:(UIColor *)toValuebackgroundColor
                                                       autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：横向移动 x
 
 @param duration duration description
 @param beginTime beginTime description
 @param fromValueX fromValueX description
 @param toValueX toValueX description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_moveXWithDuration:(CFTimeInterval)duration
                                                beginTime:(CFTimeInterval)beginTime
                                               fromValueX:(CGFloat)fromValueX
                                                 toValueX:(CGFloat)toValueX
                                             autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：纵向移动 y
 
 @param duration duration description
 @param beginTime beginTime description
 @param fromValueY fromValueY description
 @param toValueY toValueY description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_moveYWithDuration:(CFTimeInterval)duration
                                                beginTime:(CFTimeInterval)beginTime
                                               fromValueY:(CGFloat)fromValueY
                                                 toValueY:(CGFloat)toValueY
                                             autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：旋转
 
 @param duration duration description
 @param beginTime beginTime description
 @param toValueAngle toValueAngle description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_rotationWithDuration:(CFTimeInterval)duration
                                                   beginTime:(CFTimeInterval)beginTime
                                                toValueAngle:(CGFloat)toValueAngle
                                                 repeatCount:(CGFloat)repeatCount
                                                autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：旋转 X
 
 @param duration duration description
 @param beginTime beginTime description
 @param toValueAngle toValueAngle description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_rotationXWithDuration:(CFTimeInterval)duration
                                                    beginTime:(CFTimeInterval)beginTime
                                                 toValueAngle:(CGFloat)toValueAngle
                                                  repeatCount:(CGFloat)repeatCount
                                                 autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：旋转 Y
 
 @param duration duration description
 @param beginTime beginTime description
 @param toValueAngle toValueAngle description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_rotationYWithDuration:(CFTimeInterval)duration
                                                    beginTime:(CFTimeInterval)beginTime
                                                 toValueAngle:(CGFloat)toValueAngle
                                                  repeatCount:(CGFloat)repeatCount
                                                 autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：旋转 Z
 
 @param duration duration description
 @param beginTime beginTime description
 @param toValueAngle toValueAngle description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_rotationZWithDuration:(CFTimeInterval)duration
                                                    beginTime:(CFTimeInterval)beginTime
                                                 toValueAngle:(CGFloat)toValueAngle
                                                  repeatCount:(CGFloat)repeatCount
                                                 autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：position
 
 @param duration duration description
 @param beginTime beginTime description
 @param fromValuePosition fromValuePosition description
 @param toValuePosition toValuePosition description
 @param repeatCount repeatCount description
 @param autoreverses autoreverses description
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_positionWithDuration:(CFTimeInterval)duration
                                                   beginTime:(CFTimeInterval)beginTime
                                           fromValuePosition:(CGPoint)fromValuePosition
                                             toValuePosition:(CGPoint)toValuePosition
                                                 repeatCount:(CGFloat)repeatCount
                                                autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：position X
 
 @param duration duration description
 @param beginTime beginTime description
 @param fromValuePositionX fromValuePositionX description
 @param toValuePositionX toValuePositionX description
 @param repeatCount repeatCount description
 @param autoreverses autoreverses description
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_positionXWithDuration:(CFTimeInterval)duration
                                                    beginTime:(CFTimeInterval)beginTime
                                           fromValuePositionX:(CGFloat)fromValuePositionX
                                             toValuePositionX:(CGFloat)toValuePositionX
                                                  repeatCount:(CGFloat)repeatCount
                                                 autoreverses:(BOOL)autoreverses;

/**
 CABasicAnimation：position Y
 
 @param duration duration description
 @param beginTime beginTime description
 @param fromValuePositionY fromValuePositionY description
 @param toValuePositionY toValuePositionY description
 @param repeatCount repeatCount description
 @param autoreverses autoreverses description
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_basicAnimation_positionYWithDuration:(CFTimeInterval)duration
                                                    beginTime:(CFTimeInterval)beginTime
                                           fromValuePositionY:(CGFloat)fromValuePositionY
                                             toValuePositionY:(CGFloat)toValuePositionY
                                                  repeatCount:(CGFloat)repeatCount
                                                 autoreverses:(BOOL)autoreverses;

#pragma mark - 重复型动画
/**
 CABasicAnimation：重复型动画
 
 @param keyPath keyPath description
 @param beginTime beginTime description
 @param toValue toValue description
 @param duration duration description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_baseAnimationWithKeyPath:(NSString *)keyPath
                                        beginTime:(CFTimeInterval)beginTime
                                          toValue:(NSValue *)toValue
                                         duration:(NSTimeInterval)duration
                                      repeatCount:(float)repeatCount
                                     autoreverses:(BOOL)autoreverses;

#pragma mark - 一次性动画
/**
 CABasicAnimation：一次性动画
 
 @param keyPath keyPath description
 @param beginTime beginTime description
 @param fromValue fromValue description
 @param toValue toValue description
 @param duration duration description
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_baseAnimationWithKeyPath:(NSString *)keyPath
                                        beginTime:(CFTimeInterval)beginTime
                                        fromValue:(id)fromValue
                                          toValue:(id)toValue
                                         duration:(NSTimeInterval)duration;

#pragma mark - 不回弹的动画

/**
 CABasicAnimation：不回弹的动画
 
 
 @param keyPath keyPath description
 @param beginTime beginTime description
 @param fromValue fromValue description
 @param toValue toValue description
 @param duration duration description
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_baseAnimationForwardsWithKeyPath:(NSString *)keyPath
                                                beginTime:(CFTimeInterval)beginTime
                                                fromValue:(id)fromValue
                                                  toValue:(id)toValue
                                                 duration:(NSTimeInterval)duration;

/**
 CABasicAnimation：总
 
 @param keyPath keyPath description
 @param fromValue fromValue description
 @param toValue toValue description
 @param beginTime beginTime description
 @param duration duration description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CABasicAnimation
 */
+ (CABasicAnimation *)DZ_baseAnimatioWithKeyPath:(NSString *)keyPath
                                       beginTime:(CFTimeInterval)beginTime
                                       fromValue:(NSValue *)fromValue
                                         toValue:(NSValue *)toValue
                                        duration:(NSTimeInterval)duration
                                     repeatCount:(float)repeatCount
                                    autoreverses:(BOOL)autoreverses;

#pragma mark - 组合动画
/**
 CAAnimationGroup：组合动画
 
 @param animations animations description
 @param duration duration description
 @param repeatCount repeatCount description
 @param removedOnCompletion removedOnCompletion description
 @return CAAnimationGroup
 */
+ (CAAnimationGroup *)DZ_animationGroupAnimations:(NSArray *)animations
                                         duration:(float)duration
                                      repeatCount:(float)repeatCount
                              removedOnCompletion:(BOOL)removedOnCompletion;

#pragma mark - 根据路径执行的位移关键帧动画
/**
 CAKeyframeAnimation：根据路径执行的位移关键帧动画
 
 @param beginTime beginTime description
 @param duration duration description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @param path path description
 @return CAKeyframeAnimation
 */
+ (CAKeyframeAnimation *)DZ_keyframeAnimationWithBeginTime:(CFTimeInterval)beginTime
                                                  duration:(NSTimeInterval)duration
                                               repeatCount:(float)repeatCount
                                              autoreverses:(BOOL)autoreverses
                                                      path:(CGPathRef)path;

#pragma mark - 关键帧动画
/**
 CAKeyframeAnimation：关键帧动画
 
 @param keyPath keyPath description
 @param beginTime beginTime description
 @param duration duration description
 @param times times description
 @param toValues toValues description
 @param repeatCount repeatCount description
 @param autoreverses 是否自动重复
 @return CAKeyframeAnimation
 */
+ (CAKeyframeAnimation *)DZ_keyFrameAnimationForwardsWithKeyPath:(NSString *)keyPath
                                                       beginTime:(CFTimeInterval)beginTime
                                                        duration:(NSTimeInterval)duration
                                                           times:(NSArray<NSNumber *> *)times
                                                        toValues:(NSArray<id> *)toValues
                                                     repeatCount:(float)repeatCount
                                                    autoreverses:(BOOL)autoreverses;

@end
