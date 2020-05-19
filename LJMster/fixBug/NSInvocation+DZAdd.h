//
//  NSInvocation+DZAdd.h
//  LYFix
//
//  Created by jiejie on 2020/1/9.
//  Copyright © 2020 Xly. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSInvocation (DZAdd)

@property (nonatomic, strong) id returnValue_obj;

@property (nonatomic, copy) NSArray *arguments;

- (void)setMyArgument:(id)obj atIndex:(NSInteger)argumentIndex;

- (id)myArgumentAtIndex:(NSUInteger)index;


@end

NS_ASSUME_NONNULL_END
