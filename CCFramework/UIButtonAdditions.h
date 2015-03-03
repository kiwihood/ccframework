//
//  UIButtonAdditions.h
//  CCFramework
//
//  Created by kiwi on 8/23/13.
//  Copyright (c) 2013 Kiwi Private. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIButton (Additions)

+ (UIButton*)btnWithTitle:(NSString*)title
                      wid:(CGFloat)wid
                      hei:(CGFloat)height
                    image:(UIImage*)img
                   himage:(UIImage*)himg;

@end
