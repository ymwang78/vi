//
//  FlyGLView.h
//  FlyRtmpPlayerEngine
//
//  Created by djy on 13-4-5.
//  Copyright (c) 2013年 djy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FlyVideoFrame.h"

@interface FlyGLView : UIView

-(void) dealloc;

- (UIView*) initWithFrame:(CGRect)frame
        videoPixelFormat:(FlyPixelFormat)format;

- (void) resetViewFrame:(CGRect)frame;
- (void) resetSrcVideoSize:(int)width videoHeight:(int)height;

- (void) render: (unsigned char *)pImage nWidth:(int)width nHeight:(int)height;

@end
