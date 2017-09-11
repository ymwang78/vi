//
//  FlyVideoFrame.m
//  FlyRtmpPlayerEngine
//
//  Created by djy on 13-4-12.
//  Copyright (c) 2013年 djy. All rights reserved.
//

#import "FlyVideoFrame.h"

////////////////////////////////////////////////////////////////////////////////

@interface FlyMovieFrame()
@end

@implementation FlyMovieFrame
@end

@implementation FlyVideoFrame
- (FlyMovieFrameType) type { return FlyMovieFrameTypeVideo; }
@end

@interface FlyVideoFrameRGB ()
@end

@implementation FlyVideoFrameRGB
- (FlyPixelFormat) format { return FlyPixelFormatRGB; }
- (UIImage *) asImage
{
    UIImage *image = nil;
    
    CGDataProviderRef provider = CGDataProviderCreateWithCFData((__bridge CFDataRef)(_rgb));
    if (provider) {
        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        if (colorSpace) {
            CGImageRef imageRef = CGImageCreate(self.width,
                                                self.height,
                                                8,
                                                24,
                                                self.linesize,
                                                colorSpace,
                                                kCGBitmapByteOrderDefault,
                                                provider,
                                                NULL,
                                                YES, // NO
                                                kCGRenderingIntentDefault);
            
            if (imageRef) {
                image = [UIImage imageWithCGImage:imageRef];
                CGImageRelease(imageRef);
            }
            CGColorSpaceRelease(colorSpace);
        }
        CGDataProviderRelease(provider);
    }
    
    return image;
}
@end

@interface FlyVideoFrameYUV()
@end

@implementation FlyVideoFrameYUV
- (FlyPixelFormat) format { return FlyPixelFormatYUV; }
@end

