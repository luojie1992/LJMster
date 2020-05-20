//
//  NSObject+model.h
//  LJMster
//
//  Created by jiejie on 2020/4/1.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (model)

+ (instancetype)modelWithDict:(NSDictionary *)dict;
+ (instancetype)modelWithDict:(NSDictionary *)dict updateDict:(NSDictionary *)updateDict;

@end

NS_ASSUME_NONNULL_END
