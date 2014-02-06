//
//  testViewController.h
//  GoogleApiSTT
//
//  Created by Karim Abdul on 8/20/13.
//  Copyright (c) 2013 Karim Abdul. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "STTModel.h"


@interface testViewController : UIViewController <STTModelDelegate>

@property (nonatomic, strong) STTModel *sttModel;

- (IBAction)playAudio:(id)sender;
- (IBAction)stopAudio:(id)sender;
- (IBAction)convertAudioFileToText:(id)sender;

@end
