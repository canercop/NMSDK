//
//  ViewController.h
//  VasPlayer
//
//  Created by Önder ÖZCAN on 10/11/14.
//  Copyright (c) 2014 Önder ÖZCAN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
@class VasPlayer;

@protocol VasPlayerDelegate <NSObject>
@required

- (UIInterfaceOrientationMask)vasPlayerSupportedInterfaceOrientations:(VasPlayer *)player;

@optional
- (void)vasPlayerDidStartPlaying:(VasPlayer *)player;
- (void)vasPlayerDidStopPlaying:(VasPlayer *)player;

// VideoPlayer current state as enum type.
- (void)vasPlayerPlayerStateChanged:(VasPlayer *)vasPlayer :(int)playbackState;

// if you'll going to use self.view ( No container) . You need implement delegation method for remove Player View.
- (void)userExitFromFullScreen:(VasPlayer *)vasPlayer;

@end

@interface VasPlayer : UIViewController<UIWebViewDelegate,NSXMLParserDelegate,UIAlertViewDelegate,UIGestureRecognizerDelegate>

@property (nonatomic, weak) id<VasPlayerDelegate> delegate;

- (instancetype)initWithInfo:(NSDictionary *)info;

- (void)seek :(NSTimeInterval)value;

@end