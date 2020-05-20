//
//  StructRuntime.h
//  LJMster
//
//  Created by jiejie on 2020/3/5.
//  Copyright © 2020 jiejie. All rights reserved.
//

#ifndef StructRuntime_h
#define StructRuntime_h
struct Block_descriptro_1{
    int reserved ;
    int size ;
}

struct  Block_layout {
    void *isa ;
    volatile int32_t flag ;
    int32_t reserved ;
  //  void (*invoke)(void*,..);
    struct Block_descriptro_1 *decriptor ;
    /*
    void (^blk)(void) = ^{
           a++;
           b++;
           d++;
           [str appendString:@"world"];
           NSLog(@"1----------- a = %d,b = %d,c = %d,d = %d,str = %@",a,b,c,d,str);
       };
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int *_d, NSMutableString *_str, int _c, int flags=0) : d(_d), str(_str), c(_c) {
    */
};



#endif /* StructRuntime_h */
