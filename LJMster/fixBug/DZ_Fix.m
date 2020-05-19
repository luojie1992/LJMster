//
//  DZ_Fix.m
//  LYFix
//
//  Created by jiejie on 2020/1/9.
//  Copyright © 2020 Xly. All rights reserved.
//

#import "DZ_Fix.h"
#import <objc/runtime.h>
#import "Aspects.h"
#import "NSInvocation+DZAdd.h"

@implementation DZ_Fix

+ (JSContext *)context {
    static JSContext *context;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        context = [[JSContext alloc] init];
    });
    return context;
}

+ (void)Fix {
    // 初始化
    JSContext *context = [self context];

    context[@"fixMethod"] = ^(NSString *className, NSString *selectorName, AspectOptions options, JSValue *fixImp) {
        [self fixWithClassName:className opthios:options selector:selectorName fixImp:fixImp];
    };
    
    // 执行类方法
    context[@"runMethod"] = ^id(NSString * className, NSString *selectorName, id arguments) {
        id obj = [self runWithClassname:className selector:selectorName arguments:arguments];
        return obj;
    };
    // 实例方法
    context[@"runInstanceMethod"] = ^id(id instance, NSString *selectorName, id arguments) {
        id obj = [self runWithInstance:instance selector:selectorName arguments:arguments];
        return obj;
    };
    // 设置类的某个属性的值
    context[@"setInstaceValue"] = ^(id instance, NSString *argumentName ,id arguments){
      //  Class cla = NSClassFromString(className) ;
        if (instance) {
            unsigned  int count = 0;
            Ivar *members = class_copyIvarList([instance class], &count);
            
            for (int i = 0; i < count; i++)
            {
                Ivar var = members[i];
                const char *memberAddress = ivar_getName(var);
                const char *memberType = ivar_getTypeEncoding(var);
                ptrdiff_t offset = ivar_getOffset(var) ;
                if ([argumentName isEqualToString:[NSString stringWithCString:memberAddress encoding:NSUTF8StringEncoding ]]) {
                    object_setIvar(instance, var,arguments[0]) ;
                    NSLog(@"address = %s ; type = %s  %td",memberAddress,memberType,offset);

                }
            }
            
        }
    };
    context[@"runSuperMethos"]= ^(id instance, NSString *className,NSString *selectorName) {
       // objc_msgSendSuper();
      //  objc_msgSendSuper({self, class_getSuperclass(objc_getClass("Person"))}, sel_registerName("description"));

    };
    
    // 执行类方法
    context[@"runClassMethod"] = ^id(NSString * className, NSString *selectorName, id arguments) {
        id obj = [self runWithClassname:className selector:selectorName arguments:arguments];
        return obj;
    };
    //执行方法
    context[@"runInvocation"] = ^(NSInvocation *invocation) {
        [invocation invoke];
    };
    //设置参数
    context[@"setInvocationArguments"] = ^(NSInvocation *invocation, id arguments) {
        if ([arguments isKindOfClass:NSArray.class]) {
            invocation.arguments = arguments;
        } else {
            [invocation setMyArgument:arguments atIndex:0];
        }
    };
    //设置某个index 的参数
    context[@"setInvocationArgumentAtIndex"] = ^(NSInvocation *invocation, id argument,NSInteger index) {
        [invocation setMyArgument:argument atIndex:index];
    };
    // 设置方法的返回值
    context[@"setInvocationReturnValue"] = ^(NSInvocation *invocation, id returnValue) {
        invocation.returnValue_obj = returnValue;
    };

    context[@"runError"] = ^(NSString *instanceName, NSString *selectorName) {
        NSLog(@"runError: instanceName = %@, selectorName = %@", instanceName, selectorName);
    };
    context[@"runLog"] = ^(id logs) {
        NSLog(@"%@",logs);
    };
}


/// 执行js 方法
/// @param jsString <#jsString description#>
+ (id)evalString:(NSString *)jsString {
    if (jsString == nil || jsString == (id)[NSNull null] || ![jsString isKindOfClass:[NSString class]]) return nil;
    JSValue *jsValue = [[self context] evaluateScript:jsString];
    id obj = jsValue.toObject;
    if (obj) {
        return obj;
    } else {
        return nil;
    }
}


/// 执行类方法
/// @param className <#className description#>
/// @param options <#options description#>
/// @param selector <#selector description#>
/// @param fixImp <#fixImp description#>
+ (void)fixWithClassName:(NSString *)className opthios:(AspectOptions)options selector:(NSString *)selector fixImp:(JSValue *)fixImp {
    Class cla = NSClassFromString(className);
    SEL sel = NSSelectorFromString(selector);
    if ([cla instancesRespondToSelector:sel]) {
        
    } else if ([cla respondsToSelector:sel]){
        cla = object_getClass(cla);
    } else {
        return;
    }
    [cla aspect_hookSelector:sel withOptions:options usingBlock:^(id<AspectInfo> aspectInfo) {
        [fixImp callWithArguments:@[aspectInfo.instance, aspectInfo.originalInvocation, aspectInfo.arguments]];
    } error:nil];
}


/// 实例方法实现
/// @param instance <#instance description#>
/// @param selector <#selector description#>
/// @param arguments <#arguments description#>
+ (id)runWithInstance:(id)instance selector:(NSString *)selector arguments:(NSArray *)arguments {
    if (!instance) {
        return nil;
    }
    if (arguments && [arguments isKindOfClass:NSArray.class] == NO) {
        arguments = @[arguments];
    }
    SEL sel = NSSelectorFromString(selector);

    if ([instance isKindOfClass:JSValue.class]) {
        instance = [instance toObject];
    }
    NSMethodSignature *signature = [instance methodSignatureForSelector:sel];
    if (!signature) {
        return nil;
    }
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
    invocation.selector = sel;
    invocation.arguments = arguments;
    [invocation invokeWithTarget:instance];
    return invocation.returnValue_obj;
}

+ (id)runWithClassname:(NSString *)className selector:(NSString *)selector arguments:(NSArray *)arguments {
    Class cla = NSClassFromString(className);
    SEL sel = NSSelectorFromString(selector);
    if (arguments && [arguments isKindOfClass:NSArray.class] == NO) {
        arguments = @[arguments];
    }
    if ([cla instancesRespondToSelector:sel]) {
        id instance = [[cla alloc] init];
        NSMethodSignature *signature = [instance methodSignatureForSelector:sel];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
        invocation.selector = sel;
        invocation.arguments = arguments;
        [invocation invokeWithTarget:instance];
        return invocation.returnValue_obj;
    } else if ([cla respondsToSelector:sel]){
        NSMethodSignature *signature = [cla methodSignatureForSelector:sel];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];
        invocation.selector = sel;
        invocation.arguments = arguments;
        [invocation invokeWithTarget:cla];
        return invocation.returnValue_obj;
    } else {
        return nil;
    }
}
@end
