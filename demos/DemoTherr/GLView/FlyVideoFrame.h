//
//  FlyVideoFrame.h
//  FlyRtmpPlayerEngine
//
//  Created by djy on 13-4-12.
//  Copyright (c) 2013年 djy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

typedef enum {
    FlyMovieFrameTypeAudio,
    FlyMovieFrameTypeVideo,
    FlyMovieFrameTypeArtwork,
    FlyMovieFrameTypeSubtitle,
} FlyMovieFrameType;

typedef enum {
    
    FlyPixelFormatRGB,
    FlyPixelFormatYUV,
    
} FlyPixelFormat;

@interface FlyMovieFrame : NSObject
@property (readwrite, nonatomic) FlyMovieFrameType type;
@property (readwrite, nonatomic) CGFloat position;
@property (readwrite, nonatomic) CGFloat duration;
@end

@interface FlyVideoFrame : FlyMovieFrame
@property (readwrite, nonatomic) FlyPixelFormat format;
@property (readwrite, nonatomic) NSUInteger width;
@property (readwrite, nonatomic) NSUInteger height;
@end

@interface FlyVideoFrameRGB : FlyVideoFrame
@property (readwrite, nonatomic) NSUInteger linesize;
@property (readwrite, nonatomic, strong) NSData *rgb;
- (UIImage *) asImage;
@end

@interface FlyVideoFrameYUV : FlyVideoFrame
@property (readwrite, nonatomic, strong) NSData *luma;
@property (readwrite, nonatomic, strong) NSData *chromaB;
@property (readwrite, nonatomic, strong) NSData *chromaR;
@end
