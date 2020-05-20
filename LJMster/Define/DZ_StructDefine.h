//
//  DZ_StructDefine.h
//  LJMster
//
//  Created by jiejie on 2020/4/21.
//  Copyright © 2020 jiejie. All rights reserved.
//

#ifndef DZ_StructDefine_h
#define DZ_StructDefine_h

struct dz_blockLayout {
    void *isa ;
    int flags ;
    int reserved;
    void (*inovke)(void *,...);
    struct block_descriptor{
        unsigend long int reserved ;
        unsigend long int size ;
        void (*copy)(void *dst ,void *src) ;
        const char *signature;
    } *descriptor ;
};

#endif /* DZ_StructDefine_h */
