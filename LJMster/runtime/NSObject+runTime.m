//
//  NSObject+runTime.m
//  LJMster
//
//  Created by jiejie on 2020/4/1.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import "NSObject+runTime.h"

#import <objc/runtime.h>


@implementation NSObject (runTime)

+ (void)load {
    
//    [[self class] exchangeInstanceMethod:@selector(viewDidAppear:) SwizzledMethod:@selector(xxx_viewWillAppear:)];
   // [self exchangeViewDidLoad];
}



//- (void)gb_viewDidAppear:(BOOL)animated {
//    [self gb_viewDidAppear:YES];
//    NSLog(@"方法交换成功");
//}


- (void)gb_viewDidLoad {
    [self gb_viewDidLoad];
    NSLog(@"类的名字是%@",[self class]);
}


#pragma mark - Method Swizzling
// 交换方法
+ (void)exchangeInstanceMethod:(SEL)originalSelector SwizzledMethod:(SEL)swizzledSelector {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class class = [self class];
        
        Method originalMethod = class_getInstanceMethod(class, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
        ///判断是否添加成功
        //成功则拦截，失败则交换
        BOOL didAddMethod =
        class_addMethod(class,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}

// MARK: 实现方法交换和拦截
+ (void)exchangeInstanceMethod:(SEL)originalSelector SwizzledMethod:(SEL)swizzledSelector InClass: (Class)class {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Method originalMethod = class_getInstanceMethod(class, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
        ///判断是否添加成功
        //成功则拦截，失败则交换
        BOOL didAddMethod =
        class_addMethod(class,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}

@end
