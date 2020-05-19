//
//  DZ_Fix.h
//  LYFix
//
//  Created by jiejie on 2020/1/9.
//  Copyright © 2020 Xly. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface DZ_Fix : NSObject
+ (void)Fix;
+ (JSContext *)context;
+ (id)evalString:(NSString *)jsString;

+ (id)runWithClassname:(NSString *)className selector:(NSString *)selector arguments:(NSArray *)arguments;
+ (id)runWithInstance:(id)instance selector:(NSString *)selector arguments:(NSArray *)arguments;

@end

NS_ASSUME_NONNULL_END
