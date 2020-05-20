//
//  ViewController.m
//  LJMster
//
//  Created by jiejie on 2020/2/27.
//  Copyright © 2020 jiejie. All rights reserved.
//

#import "ViewController.h"
#import "DZCommonAlgorithm.h"
#import "LJMster-Swift.h"
#import "DZ_Define.h"
#import <FLEX/FLEX.h>
struct xx_cc_objc_class{
    Class isa;
};
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[FLEXManager sharedManager] showExplorer];

    DZCommonAlgorithm *Algorithm = [[DZCommonAlgorithm alloc] init] ;
    [Algorithm fastSortWithWithArray:[NSMutableArray arrayWithArray:@[@"6",@"1",@"2",@"7",@"9",@"3",@"4",@"5",@"10",@"8"] ] leftIndex:0 rightIndex:9] ;
    
    NSObject *object = [[NSObject alloc] init];
    Class objectClass = [NSObject class];
    Class objectMetaClass = object_getClass([NSObject class]);
    struct xx_cc_objc_class *objectClass2 = (__bridge struct xx_cc_objc_class *)(objectClass);
    NSLog(@"%p %p %p %p", object, objectClass, objectMetaClass,objectClass2);

  
    CGSize size  = DZKit_LabelSizeWithTextAndFont(@"dfasd", [UIFont systemFontOfSize:12]);
    
   // NSThread *thread = [[NSThread alloc] initWithTarget:self selector:@selector(abc) object:nil] ;
    
//    [self performSelector:@selector(runTime) withObject:nil afterDelay:0.3  inModes:@[NSDefaultRunLoopMode]];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self lookUpSomethind:@"hah "];
    int a = 10 ;
    NSLog(@"%d",a) ;
}


-(void)lookUpSomethind:(NSString *)anything {
    NSLog(@"woshi lajia ren %@", anything) ;
}
@end
