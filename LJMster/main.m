//
//  main.m
//  LJMster
//
//  Created by jiejie on 2020/2/27.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

void swap111 (int a, int b) {
    a = a+ b ;
    b = a - b ;
    a = a - b ;
}


int maxCommonDivisor(int a , int b ) {
    int r ;
    while (a % b > 0) {
        r = a % b ;
        a = b ;
        b = r ;
    }
    return  b ;
}
int main(int argc, char * argv[]) {

    int a = maxCommonDivisor(3 , 9);
    swap111(1, 2) ;
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}


