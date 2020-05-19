//
//  DZ_AuthTool.h
//  KDS_Phone
//
//  Created by jie jie on 2018/12/4.
//  Copyright © 2018 kds. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DZ_AuthTool : NSObject


/// AES 加密
/// @param encrypt
+ (NSString *)DZ_ToolWithAesEncryptWithString:(NSString *)encrypt ;


/// AES解密
/// @param encrypt
+ (NSString *)DZ_ToolWithAesDecryptWithString:(NSString *)encrypt ;


/// 国密加密
/// @param encrypt
/// @param pk
+ (NSString *)DZ_ToolWithSM2EncryptWithString:(NSString *)encrypt withPublciKey:(NSString *)pk ;

+ (NSData *)dataFromHexString:(NSString *)input ; 
@end

NS_ASSUME_NONNULL_END
