//
//  CCClient.h
//  CCFramework
//
//  Created by Wan Kiwi on 14-6-3.
//  Copyright (c) 2014年 CC. All rights reserved.
//

#import "CCRequest.h"
#import <UIKit/UIKit.h>

@class CCClient;



@protocol BSClientDelegate <NSObject>
@required
// 网络请求完成的回调
- (BOOL)client:(CCClient*)sender didFinishLoadingWithResult:(id)result;
@optional
// callback while sending data
- (void)client:(CCClient*)sender didSendPercent:(CGFloat)percent;
// callback while receiving data
- (void)client:(CCClient*)sender didReceivePercent:(CGFloat)percent;
@end



@interface CCClient : NSObject {
    // object that respond while request is completed
    id <BSClientDelegate> _delegate;
    
    // if YES the request may not call back when completed, the default value is NO
    BOOL _workWithNoRespond;
    // if NO the request may ignore errors without alerts, the default value is YES
    BOOL _needAlert;
    
    // if YES the request may automatically add user token parameter for the request, the default value is YES
    BOOL _needLogin;
    // while _needLogin is YES and _canSkipLogin is YES, the reuqest may add user token parameter only if user token exists
    BOOL _canSkipLogin;
    
    BOOL _skipLog;
}

// description of error
@property (strong, nonatomic) NSString  * errorMessage;
// code of error
@property (assign, nonatomic) NSInteger   errorCode;
// YES if the request failed with some error
@property (assign, nonatomic) BOOL        hasError;

// identifier for different kinds of requests in one object
@property (assign, nonatomic) NSInteger   requestID;

// YES if this request need the loading HUD
@property (assign, nonatomic) BOOL        needLoadingHUD;



/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	初始化CCClient实例
 *
 *	@param 	delegate 回调对象实例
 *
 *	@return	return a BSClient object
 */
- (id)initWithDelegate:(id)delegate;

/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	通过UIAlertView展示错误信息
 */
- (void)showAlert;

/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	中断并取消请求
 */
- (void)cancel;

/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	发送GET请求
 *
 *	@param 	methodName URL后缀
 *	@param 	params     a dictionary with all parameters (NSNumber, NSString)
 */
- (void)getWithMethodName:(NSString *)methodName params:(NSMutableDictionary *)params;

/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	load a http request type as POST
 *
 *	@param 	methodName URL后缀
 *	@param 	params     a dictionary with all parameters (NSNumber, NSString, UIImage, NSData)
 */
- (void)postWithMethodName:(NSString *)methodName params:(NSMutableDictionary *)params;

/**
 *	Copyright © 2013 CC Inc. All rights reserved.
 *
 *	load a http request
 *
 *	@param 	methodName URL
 *	@param 	httpMethod @"GET" or @"POST"
 *	@param 	params     a dictionary with all parameters (NSNumber, NSString, UIImage, NSData)
 *	@param 	postDataType
 *	@param 	httpHeaderFields
 */
- (void)loadRequestWithMethodName:(NSString *)methodName
                       httpMethod:(NSString *)httpMethod
                           params:(NSMutableDictionary *)params
                     postDataType:(CCRequestPostDataType)postDataType
                 httpHeaderFields:(NSDictionary *)httpHeaderFields;

@end
