//
//  DZ_AuthTool.m
//  KDS_Phone
//
//  Created by jie jie on 2018/12/4.
//  Copyright © 2018 kds. All rights reserved.
//

#import "DZ_AuthTool.h"
#import "SecurityUtil.h"
#import"part4.h"
#import "part2.h"

@implementation DZ_AuthTool

+ (NSString *)DZ_ToolWithAesEncryptWithString:(NSString *)encrypt {
    if (encrypt.length > 0) {
        NSString *encryptData=[SecurityUtil encryptAESData:encrypt];
        return encryptData ;
    }
    return  @"" ;

}

+ (NSString *)DZ_ToolWithAesDecryptWithString:(NSString *)encrypt {
    if (encrypt.length > 0) {
        NSString *decryptData=[SecurityUtil decryptAESData:encrypt];
        return decryptData ;
    }
    return  @"" ;

}


+ (NSString *)DZ_ToolWithSM2EncryptWithString:(NSString *)encrypt withPublciKey:(NSString *)pk {
    
    //04EB0899C1F2EEFAE02CD925AD9FC19BD797C39D8915E6E9345D5689D872C9257EDF2E204205013522134E2A7B8F81525E25D7DB9A64707A044EA37DC19FDACAD3
    // 公钥去掉04 后， 然后一分为二
    
    NSString *realKey = [pk substringFromIndex:2] ;
    NSInteger miWenLength = [encrypt dataUsingEncoding:NSUTF8StringEncoding].length + 32 +64  + 1 ;//这个1必须加 因为密文的长度包括04
    unsigned char miwen[miWenLength];
    NSString *px_ = [[realKey substringToIndex:realKey.length/2] stringByReplacingOccurrencesOfString:@" " withString:@""];
    NSString *py_ = [[realKey substringFromIndex:realKey.length/2] stringByReplacingOccurrencesOfString:@" " withString:@""];
    NSData *px_data = [self dataFromHexString:px_];
    NSData *py_data = [self dataFromHexString:py_];
    sm2JiaMiWithPublicKey(sm2_param_recommand, TYPE_GFp, 256, (char *)[encrypt dataUsingEncoding:NSUTF8StringEncoding].bytes ,(int)[encrypt dataUsingEncoding:NSUTF8StringEncoding].length ,miwen, (unsigned char *)px_data.bytes, (unsigned char *)py_data.bytes);

    NSData *miwendata = [[NSData alloc]initWithBytes:miwen length:  miWenLength  ];
    NSString *allString = [self convertDataToHexStr:miwendata] ;
    NSString *enString1 = [allString stringByReplacingOccurrencesOfString:@"<" withString:@""] ;
    NSString *enString2 = [enString1 stringByReplacingOccurrencesOfString:@">" withString:@""] ;
    if (enString2.length > 0) {
        return enString2 ;
    }
    return  nil ;
}

+ (NSString *)convertDataToHexStr:(NSData *)data
{
    if (!data || [data length] == 0) {
        return @"";
    }
    NSMutableString *string = [[NSMutableString alloc] initWithCapacity:[data length]];
    
    [data enumerateByteRangesUsingBlock:^(const void *bytes, NSRange byteRange, BOOL *stop) {
        unsigned char *dataBytes = (unsigned char*)bytes;
        for (NSInteger i = 0; i < byteRange.length; i++) {
            NSString *hexStr = [NSString stringWithFormat:@"%x", (dataBytes[i]) & 0xff];
            if ([hexStr length] == 2) {
                [string appendString:hexStr];
            } else {
                [string appendFormat:@"0%@", hexStr];
            }
        }
    }];
    return string;
}

+ (NSData *)dataFromHexString:(NSString *)input {
    const char *chars = [input UTF8String];
    int i = 0;
    NSUInteger len = input.length;
    
    NSMutableData *data = [NSMutableData dataWithCapacity:len / 2];
    char byteChars[3] = {'\0','\0','\0'};
    unsigned long wholeByte;
    
    while (i < len) {
        byteChars[0] = chars[i++];
        byteChars[1] = chars[i++];
        wholeByte = strtoul(byteChars, NULL, 16);
        [data appendBytes:&wholeByte length:1];
    }
    return data;
}
@end
