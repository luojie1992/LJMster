//
//  NSObject+model.m
//  LJMster
//
//  Created by jiejie on 2020/4/1.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import "NSObject+model.h"
#import <objc/runtime.h>



@implementation NSObject (model)
+ (instancetype)modelWithDict:(NSDictionary *)dict updateDict:(NSDictionary *)updateDict {
    id model = [[self alloc] init] ;
    unsigned int count = 0 ;
    Ivar *ivars = class_copyIvarList(self, &count) ;
    for (int i = 0 ; i < count ; i++) {
        NSString *ivarName = [NSString stringWithUTF8String:ivar_getName(ivars[i])] ;
        ivarName = [ivarName substringFromIndex:1];
        id value = dict[ivarName] ;
        if (value == nil) {
            if (updateDict) {
                NSString *keyName = updateDict[ivarName] ;
                value = dict[keyName] ;
            }
            [model setValue:value forKey:ivarName];
        }
    }
    return model ; 
}

@end
