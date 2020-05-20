//
//  DZ_Define.h
//  LJMster
//
//  Created by jiejie on 2018/4/16.
//  Copyright © 2020 jiejie. All rights reserved.
//

#ifndef DZ_Define_h
#define DZ_Define_h
#import <objc/runtime.h>
#import "DZKit_DefineFrame.h"

#pragma mark - weak / strong
    #define DZKit_WeakSelf        @DZKit_Weakify(self);
    #define DZKit_StrongSelf      @DZKit_Strongify(self);

/*！
 * 强弱引用转换，用于解决代码块（block）与强引用self之间的循环引用问题
 * 调用方式: `@DZKit_Weakify`实现弱引用转换，`@DZKit_Strongify`实现强引用转换
 *
 * 示例：
 * @DZKit_Weakify
 * [obj block:^{
     * @strongify_self
     * self.property = something;
 * }];
 */
#ifndef DZKit_Weakify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define DZKit_Weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
            #define DZKit_Weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define DZKit_Weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
            #define DZKit_Weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

/*！
 * 强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
 * 调用方式: `@BAKit_Weakify(object)`实现弱引用转换，`@BAKit_Strongify(object)`实现强引用转换
 *
 * 示例：
 * @BAKit_Weakify(object)
 * [obj block:^{
     * @BAKit_Strongify(object)
     * strong_object = something;
 * }];
 */
#ifndef DZKit_Strongify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define DZKit_Strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
            #define DZKit_Strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define DZKit_Strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
            #define DZKit_Strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

/*! 主线程同步队列 */
#define dispatch_main_sync_safe(block)\
    if ([NSThread isMainThread]) {\
    block();\
    } else {\
    dispatch_sync(dispatch_get_main_queue(), block);\
    }
/*! 主线程异步队列 */
#define dispatch_main_async_safe(block)\
    if ([NSThread isMainThread]) {\
    block();\
    } else {\
    dispatch_async(dispatch_get_main_queue(), block);\
    }


#define DZKit_ImageName(imageName)  [UIImage imageNamed:imageName]
#define DZKit_DefaultImage      DZKit_ImageName(@"image_default")

#pragma mark - 获取时间间隔
/*! 获取时间间隔 */
#define DZKit_CFAbsoluteTime_start  CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define DZKit_CFAbsoluteTime_end   CFAbsoluteTime end = CFAbsoluteTimeGetCurrent(); \


#pragma mark - 获取沙盒目录路径
/*! 获取沙盒 Cache 目录路径 */
#define DZKit_Path_Cache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject]

/*! 获取沙盒 home 目录路径 */
#define DZKit_Path_Home NSHomeDirectory()


#pragma mark - 简单警告框
    /*! view 用 BAKit_ShowAlertWithMsg */
    #define DZKit_ShowAlertWithMsg(msg) [[[UIAlertView alloc] initWithTitle:@"温馨提示" message:(msg) delegate:nil cancelButtonTitle:@"确 定" otherButtonTitles:nil] show];
    /*! VC 用 BAKit_ShowAlertWithMsg */
    #define DZKit_ShowAlertWithMsg_ios8(msg) UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"温馨提示" message:msg preferredStyle:UIAlertControllerStyleAlert];\
        UIAlertAction *sureAction = [UIAlertAction actionWithTitle:@"确 定" style:UIAlertActionStyleDefault handler:nil];\
        [alert addAction:sureAction];\
        [self presentViewController:alert animated:YES completion:nil];



#pragma mark - 内联函数
/*!
 为什么引入内联函数：
 引入内联函数是为了解决函数调用效率的问题
 由于函数之间的调用，会从一个内存地址调到另外一个内存地址，当函数调用完毕之后还会返回原来函数执行的地址。函数调用会有一定的时间开销，引入内联函数就是为了解决这一问题
 
 使用内联函数 和 宏定义的区别：
 1.使用 inline 修饰的函数，在编译的时候，会把代码直接嵌入调用代码中。就相当于用 #define 宏定义来定义一个 add 函数那样！与 #define 的区别是:
 1)#define 定义的格式要有要求，而使用inline则就行平常写函数那样，只要加上 inline 即可！
 2)使用 #define 宏定义的代码，编译器不会对其进行参数有效性检查，仅仅只是对符号表进行替换。
 3）#define 宏定义的代码，其返回值不能被强制转换成可转换的适合的转换类型。可参考百度文科 关于inline
 
 2.在 inline 加上 `static 修饰符，只是为了表明该函数只在该文件中可见！也就是说，在同一个工程中，就算在其他文件中也出现同名、同参数的函数也不会引起函数重复定义的错误！
 */

#pragma mark 随机数
/*!
 *  获取一个随机整数范围在：[0,i)包括0，不包括i
 *
 *  @param i 最大的数
 *
 *  @return 获取一个随机整数范围在：[0,i)包括0，不包括i
 */
/*!
 rand()和random()实际并不是一个真正的伪随机数发生器，在使用之前需要先初始化随机种子，否则每次生成的随机数一样。
 arc4random() 是一个真正的伪随机算法，不需要生成随机种子，因为第一次调用的时候就会自动生成。而且范围是rand()的两倍。在iPhone中，RAND_MAX是0x7fffffff (2147483647)，而arc4random()返回的最大值则是 0x100000000 (4294967296)。
 精确度比较：arc4random() > random() > rand()。
 */
CG_INLINE NSInteger
DZKit_RandomNumber(NSInteger i){
    return arc4random() % i;
}



#pragma mark - runtime
/*! runtime set */
#define DZKit_Objc_setObj(key, value) objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC)

/*! runtime setCopy */
#define DZKit_Objc_setObjCOPY(key, value) objc_setAssociatedObject(self, key, value, OBJC_ASSOCIATION_COPY)

/*! runtime get */
#define DZKit_Objc_getObj objc_getAssociatedObject(self, _cmd)

/*! runtime exchangeMethod */
#define DZKit_Objc_exchangeMethodAToB(originalSelector,swizzledSelector) { \
Method originalMethod = class_getInstanceMethod(self, originalSelector); \
Method swizzledMethod = class_getInstanceMethod(self, swizzledSelector); \
if (class_addMethod(self, originalSelector, method_getImplementation(swizzledMethod), method_getTypeEncoding(swizzledMethod))) { \
class_replaceMethod(self, swizzledSelector, method_getImplementation(originalMethod), method_getTypeEncoding(originalMethod)); \
} else { \
method_exchangeImplementations(originalMethod, swizzledMethod); \
} \
}

CG_INLINE void
DZKit_Objc_ReplaceMethodAToB(Class _class, SEL _originSelector, SEL _newSelector) {
    Method oriMethod = class_getInstanceMethod(_class, _originSelector);
    Method newMethod = class_getInstanceMethod(_class, _newSelector);
    BOOL isAddedMethod = class_addMethod(_class, _originSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod));
    if (isAddedMethod) {
        class_replaceMethod(_class, _newSelector, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
    } else {
        method_exchangeImplementations(oriMethod, newMethod);
    }
}

#pragma mark - 判断字符串是否为空
CG_INLINE BOOL
DZKit_stringIsBlank(NSString *string) {
    NSCharacterSet *blank = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    for (NSInteger i = 0; i < string.length; ++i) {
        unichar c = [string characterAtIndex:i];
        if (![blank characterIsMember:c]) {
            return NO;
        }
    }
    return YES;
}

/**
 判断 object 是否为空

 @param object id
 @return YES/NO
 */
#pragma mark - 判断 object 是否为空
CG_INLINE BOOL
DZKit_ObjectIsNull(id object) {
    if (object == nil || [object isKindOfClass:[NSNull class]] || ([object respondsToSelector:@selector(length)] && [(NSData *)object length] == 0) || ([object respondsToSelector:@selector(count)] && [(NSArray *)object count] == 0))
    {
        return YES;
    }
    return NO;
}

CG_INLINE UIColor *
DZKit_HexWithInt16(NSInteger rgbValue){
    return [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0];
}

CG_INLINE NSUInteger
DZKit_HexStrToInt(NSString *str) {
    uint32_t result = 0;
    sscanf([str UTF8String], "%X", &result);
    return result;
}

CG_INLINE BOOL
DZKit_HexStrToRGBA(NSString *str, CGFloat *r, CGFloat *g, CGFloat *b, CGFloat *a) {
   // str = [[str ba_trimWhitespaceAndNewlines] uppercaseString];
    if ([str hasPrefix:@"#"]) {
        str = [str substringFromIndex:1];
    } else if ([str hasPrefix:@"0X"]) {
        str = [str substringFromIndex:2];
    }
    
    NSUInteger length = [str length];
    //         RGB            RGBA          RRGGBB        RRGGBBAA
    if (length != 3 && length != 4 && length != 6 && length != 8) {
        return NO;
    }
    
    //RGB,RGBA,RRGGBB,RRGGBBAA
    if (length < 5) {
        *r = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(0, 1)]) / 255.0f;
        *g = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(1, 1)]) / 255.0f;
        *b = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(2, 1)]) / 255.0f;
        if (length == 4)  *a = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(3, 1)]) / 255.0f;
        else *a = 1;
    } else {
        *r = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(0, 2)]) / 255.0f;
        *g = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(2, 2)]) / 255.0f;
        *b = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(4, 2)]) / 255.0f;
        if (length == 8) *a = DZKit_HexStrToInt([str substringWithRange:NSMakeRange(6, 2)]) / 255.0f;
        else *a = 1;
    }
    return YES;
}

#pragma mark 从本地文件读取数据
/*!
 从本地文件读取数据

 @param fileName 文件名
 @param type type 类型
 @return data
 */
CG_INLINE NSData *
DZKit_GetDataWithContentsOfFile(NSString *fileName, NSString *type){
    return [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:fileName ofType:type]];
}

#pragma mark json 解析 data 数据
/*!
 json 解析 data 数据

 @param data 需要解析的 data
 @return NSDictionary
 */
CG_INLINE NSDictionary *
DZKit_GetDictionaryWithData(NSData *data){
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:nil];
}

#pragma mark json 解析 ，直接从本地文件读取 json 数据，返回 NSDictionary
/*!
 json 解析 data 数据
 
 @param fileName 文件名
 @param type type 类型
 @return NSDictionary
 */
CG_INLINE NSDictionary *
DZKit_GetDictionaryWithContentsOfFile(NSString *fileName, NSString *type){
    NSData *data = [NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:fileName ofType:type]];
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:nil];
}

#pragma mark json 解析 ，json string 转 NSDictionary，返回 NSDictionary
/**
 json string 转 NSDictionary

 @param jsonString jsonString description
 @return NSDictionary
 */
CG_INLINE NSDictionary *
DZKit_GetDictionaryWithJsonString(NSString *jsonString){
    if (jsonString == nil)
    {
        return nil;
    }
    
    NSData *jsonData = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    NSError *err;
    NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&err];
    if(err)
    {
        NSLog(@"json 解析失败：%@",dict);
        return nil;
    }
    return dict;
}

#endif /* DZ_Define_h */
