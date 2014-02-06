//
//  TTSModel.h
//  WhiteLabelCartCheckout
//
//  Created by Abdul, Karim (Contractor) on 7/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@class STTModel;

@protocol STTModelDelegate <NSObject>
@optional

/**
 audioRecordingCompleted Method is optional method when used the delegate, which passes the LocatorView.
 @param convertedSTT Speech to text is being passed in form of a dictionary when converion is completed.
 */
- (void)audioConvertedToTextFromModel:(NSDictionary*)audioResponse;

/**
Speech To Text Method is optional method when used the delegate, which passes the Response.
@param response Speech to text is being passed in form of a dictionary when converion is completed.
*/

- (void)speechToTextCompletion:(NSURLResponse*)response
                          data:(NSData*)data
                         error:(NSError*)error;

@end


/** 
 A STTModel class set to retrieve Audio data, convert it to flac and store it in Document bundle.
 */
@interface STTModel : NSObject

@property (nonatomic, weak) id <STTModelDelegate> delegate;

- (id)init;

/** 
 convertWaveToFlac Converts Wav file to Flac extension. Both file does needs to be resided in Document Direcoty of NSBundle 2MainBundle.
 @param inputWaveFile Name of Input Wave file.
 @param outputFlacFile Name of Output Flac file.
 @return conversionResult Returns boolen expression if the file got successfully converted or not.
 */
- (BOOL)convertWaveFileToFlac:(NSString*)inputWaveFile
               OutputFileName:(NSString*)outputFlacFile;

/** 
 STTFromGoogle Method converts the flac file and returns the converted text as dictionary using Google's Api.
 @param fileName Name of the file which was being converted as flac extension in NSBundle Document Directory. Any other bundle can be utilized here to convert any flac file type and get the response, for easier purpose, the file is being getting saved in NSBundle's Document Directory.
 @return STTFromGoogle Return the result in JSON format in our case as an object of a Dictionary.
 */
- (void)STTFromGoogle:(NSString*)fileName;

/** 
 Method to get the NSBundle path of Document Directory.
 @return docsDir Returns document directory path in string format.
 */
- (NSString*)applicationDocumentDirectory;

/** 
 fileExistsInDocumentFolder Method checks if the file already exists in the document directory.
 @param fileName Name of the file to check in document directory.
 @return fileExists Returns the boolean if the file already exists or not.
 */
- (BOOL)fileExistsInDocumentFolder:(NSString*)fileName;

/** 
 successfullyCreateNewFileInApplicationDirectory Method to create a dummy file in Document Directory within NSBundle MainBundle.
 @param fileName Name of the file to check in document directory.
 @return fileResult Returns the boolean if the file got successfully created or not.
 */
- (BOOL)successfullyCreateNewFileInApplicationDirectory:(NSString*)fileName;

@end
