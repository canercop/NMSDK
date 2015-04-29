# NMSDK - Framework For Native iOS Apps

![NMSDK logo](http://netbookmobile.com/NM_Logo.png)

**NM SDK**, is the native ios video player for presents advertisements according to roll types . It supports preroll,midroll and postroll. It has ability to show custom html objects over video player and triggger  **flashlight**, **vibration** and **camera** for improve your Advertisement strenght. Videoplayer also supports [Vast](http://en.wikipedia.org/wiki/Video_Ad_Serving_Template) standards for showing advertisements. 


## INSTALLATION

**NMSDK** is the framework library that you just need drag and drop in to your project and NM.bundle instead of display custom videoplayer assets properly.  

![Drag and Drop Framework](http://netbookmobile.com/img_02.png )

###You need to add these frameworks in to your project  instead of NM.framework works.###

### Framework Lists should be look like below

* MobileCoreServices.framework
* Acccelerate.framework
* CoreMedia.framework
* AddressBookUI.framework
* AddressBook.framework
* NM.framework
* QuartzCore.framework
* AudioToolbox.framework
* SystemConfiguration.framework
* CoreTelephony.framework
* AVFoundation.framework
* AssetsLibrary.framework



### Calling Player Class in to your ViewController
import VasPlayer.h file in to your current ViewController which you will  going to call VideoPlayer.

	#import <NM/Vasplayer.h>
	
### Keep reference VasPlayer class as nonatomic object in to your current ViewController header file. In given example below, we keeping as videoPlayerViewController.

	@property (nonatomic) VasPlayer *videoPlayerViewController;
	
### In your implementation file, you need to set delegate VasPlayer like

	@interface ViewController ()<VasPlayerDelegate>
	
### For initialise VasPlayer, create Dictionary as given example below
```
	NSDictionary * reQuestDictionary = @{
	@“publisherID":@"247”,
	@"mainURL":@"http://www.otodunya.com/uploads/video/Shell_5_SD.mp4”,
	@“title":@"2012 Yeni Hyundai - MP4 PREROLL”,
	@“category":@“Otodunya",
	@“tags":@“horro,comedy”,
	@"type”:@“0", //Indicates Video type is Stream or not. 1 is stream 0 is source
	@“thumbnail_url”:@"http://www.otodunya.com/fotograf.asp?Boyut=7&Resim=uploads/videothumb438011682536.JPG",
	@“fullScreen”:NSNumber numberWithInt:1,
	@"vastOnly":[NSNumber numberWithBool:NO],
};
```

### After creating Dictionary , You need to add videoPlayerViewController in to current UIView container as childViewContainer and set it delegate as self.
```
	[self setVideoPlayerViewController:[[VasPlayer alloc] initWithInfo:reQuestDictionary]];
    [self.videoPlayerViewController setDelegate:self];
    [self containerAddChildViewController:self.videoPlayerViewController]; 
```    

### containerAddChildViewController method will be responsible to add VasPlaye add as childView.
```
	//Adding SDK MPMovieController view as childViewController
	- (void)containerAddChildViewController:(UIViewController *)childViewController {
    [self.videoView setNeedsDisplay];
   
    [childViewController willMoveToParentViewController:self];
    [self addChildViewController:childViewController];
   
    [childViewController.view setFrame:self.videoView.bounds];
    [self.videoView addSubview:childViewController.view];
    [childViewController.view setAutoresizingMask:(UIViewAutoresizingFlexibleWidth
                                                   | UIViewAutoresizingFlexibleHeight)];
                                                   }
```                                                   
### @required VasPlayer delegation method will be pushing MPMoviePlayerController’s statement. 
```

	//Video Player Statements can be follow from that method.
	- (void) vasPlayerPlayerStateChanged:(VasPlayer *)vasPlayer :(int)playbackState
    	NSLog(@"Movie Player State = %d",playbackState);
	    if(playbackState == 4)
	    {
	      if playbackState is in seekingforward , do something.
	    }
    }
```    
### @required If user tap on Fullsreen when video is playing, you need to destroy childViewController with delegation medhod.
```
	-(void)userExitFromFullScreen:(VasPlayer *)vasPlayer
	{
    //remove current Videoplayer object from current UIViewController
    [self.videoPlayerViewController willMoveToParentViewController:nil];
    [self.videoPlayerViewController.view removeFromSuperview];
    [self.videoPlayerViewController removeFromParentViewController];
    }  
```        
### Seek method, sending NSTimeInterval for MediaPlayer for seeking movie for given time.
```
	//Seek Method Should be greater than 0
	- (void) seek :(NSTimeInterval)value 
	{
    	[self.videoPlayerViewController seek:value];
   }
```  
### Video Orientation delegation , you will let VasPlayer which orientation has supporting. Standard delegation method is given in example below.
```
	//Video Orientation Delegate
	- (UIInterfaceOrientationMask)vasPlayerSupportedInterfaceOrientations:(VasPlayer *)player {
    return (UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight);
    }
```    
### You can also fetch targeting data as NSDictionary
```
	-(NSDictionary *)getTargetting
	{
	VasPlayer *vas = [[VasPlayer alloc] init];
	return [vas customTargetting];
	}
```
