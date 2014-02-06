//
//  testViewController.m
//  GoogleApiSTT
//
//  Created by Karim Abdul on 8/20/13.
//  Copyright (c) 2013 Karim Abdul. All rights reserved.
//

#import "testViewController.h"

@interface testViewController ()

@property (nonatomic, strong) AVAudioPlayer *audioPlayer;

@end

@implementation testViewController

@synthesize sttModel, audioPlayer;

- (void)viewDidLoad
{
    [super viewDidLoad];

	// Do any additional setup after loading the view, typically from a nib.
    
    if (!self.audioPlayer) {
        self.audioPlayer = [[AVAudioPlayer alloc] init];
    }
    
    if (!self.sttModel) {
        self.sttModel = [[STTModel alloc] init];
        self.sttModel.delegate = self;
    }

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)speechToTextCompletion:(NSURLResponse *)response data:(NSData *)data error:(NSError *)error
{
    
    if (!error) {
        NSDictionary *json = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions
                                                               error:&error];
        
        NSString *value = [NSString stringWithFormat:@"%@",[json valueForKey:@"hypotheses"]];
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"STT" message:value delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:nil, nil];
        
        [alert show];
    }
    
}

- (IBAction)playAudio:(id)sender {
    
    //Read the song off the bundle.
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"wav"];
    NSData *myData = [NSData dataWithContentsOfFile:filePath];
    
    AVAudioPlayer *newAudio = [[AVAudioPlayer alloc] initWithData:myData error:NULL];
    self.audioPlayer = newAudio; // automatically retain audio and dealloc old file if new file is loaded
    
    [audioPlayer play];
    
}

- (IBAction)stopAudio:(id)sender
{
    [audioPlayer stop];
    
}

- (IBAction)convertAudioFileToText:(id)sender
{
    //First we convert the file from input type to Flac (the flac files gets stored to the document directory)
    if ([self.sttModel convertWaveFileToFlac:@"test.wav" OutputFileName:@"test.flac"] == 0) {
        
        //If converted successfully, then upload the flac file and get the conversion.
        [self.sttModel STTFromGoogle:@"test.flac"];
    }
}

- (BOOL)listen:(NSError **)err {
    
    return YES;
}

@end
