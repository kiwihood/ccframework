//
//  CCRequest.h
//  DrivingNeighborSchool
//
//  Created by Wan Kiwi on 14-6-3.
//  Copyright (c) 2014年 Kiwi Private. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CCRequestPostDataType) {
    CCRequestPostDataTypeNone      = 10,
    CCRequestPostDataTypeNormal    = 11, // for normal data post, such as "user=name&password=psd"
    CCRequestPostDataTypeMultipart = 12,  // for uploading images and files.
    CCRequestPostDataTypeJson = 13,  //
};

typedef NS_ENUM(NSInteger, CCErrorCode) {
	CCErrorCodeInterface = 100,
	CCErrorCodeSDK       = 101
};

typedef NS_ENUM(NSInteger, CCSDKErrorCode) {
	CCSDKErrorCodeParseError     = 200,
	CCSDKErrorCodeRequestError   = 201,
	CCSDKErrorCodeAccessError    = 202,
	CCSDKErrorCodeAuthorizeError = 203
};

@class CCRequest;

@protocol CCRequestDelegate <NSObject>
@optional
- (void)request:(CCRequest*)request didReceiveResponse:(NSURLResponse *)response;
- (void)request:(CCRequest*)request didReceiveRawData:(NSData *)data;
- (void)request:(CCRequest*)request didFailWithError:(NSError *)error;
- (void)request:(CCRequest*)request didFinishLoadingWithResult:(id)result;
- (void)request:(CCRequest*)request didSendPercent:(CGFloat)percent;
- (void)request:(CCRequest*)request didReceivePercent:(CGFloat)percent;
@end

@interface CCRequest : NSObject 

@property (unsafe_unretained, nonatomic) id <CCRequestDelegate> delegate;
@property (assign, nonatomic) BOOL skipLog;

+ (CCRequest*)requestWithURL:(NSString *)url
                  httpMethod:(NSString *)httpMethod
                      params:(NSDictionary *)params
                postDataType:(CCRequestPostDataType)postDataType
            httpHeaderFields:(NSDictionary *)httpHeaderFields
                    delegate:(id<CCRequestDelegate>)delegate;

- (void)connect;
- (void)disconnect;

@end
